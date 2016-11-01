// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		processor.c
//		Purpose:	Processor Emulation.
//		Created:	19th October 2015
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <stdlib.h>
#ifdef WINDOWS
#include <stdio.h>
#endif
#include "sys_processor.h"
#include "sys_debug_system.h"
#include "hardware.h"

// *******************************************************************************************************************************
//														   Timing
// *******************************************************************************************************************************

#define CRYSTAL_CLOCK 	(1789773L)													// Clock cycles per second (1.79Mhz)
#define CYCLE_RATE 		(CRYSTAL_CLOCK/8)											// Cycles per second (8 clocks per cycle)
#define FRAME_RATE		(60)														// Frames per second (60)
#define CYCLES_PER_FRAME (CYCLE_RATE / FRAME_RATE)									// Cycles per frame (3,728)

//	3,668 Cycles per frame
// 	262 lines per video frame
//	14 cycles per scanline (should be :))

// *******************************************************************************************************************************
//														CPU / Memory
// *******************************************************************************************************************************

static BYTE8 ramMemory[MEMORYSIZE];													

// *******************************************************************************************************************************
//													   Port Interfaces
// *******************************************************************************************************************************

#define INPORT1() 	(HWISetScreenOn(1),DEFAULT_BUS_VALUE)							// INP 1 screen on
#define INPORT4()	HWIReadKeypadLatch()											// INP 4 Keypad latch.
#define OUTPORT1(n)	HWISetScreenOn(0)												// OUT 1 screen off
#define OUTPORT4(n) HWISetDigitDisplay(n)											// OUT 4 led display

#define EFLAG1() 	(1)																// EF1 is always set.
#define EFLAG4() 	(HWIIsInPressed() != 0)											// EF4 is the IN Key.

#include "__1802ports.h"															// Default connections.

// *******************************************************************************************************************************
//											 Memory and I/O read and write macros.
// *******************************************************************************************************************************

static inline void _Read(void);
static inline void _Write(void);

#define READ() 		_Read()															
#define WRITE() 	_Write()

#include "__1802support.h"

static inline void _Read(void) {
	MB = (MA < MEMORYSIZE) ? ramMemory[MA] : DEFAULT_BUS_VALUE; 					// Reading RAM (0000 up)
}

static inline void _Write(void) {
	if (MA < MEMORYSIZE) ramMemory[MA] = MB;
}

// *******************************************************************************************************************************
//														Reset the CPU
// *******************************************************************************************************************************

void CPUReset(void) {
	HWIReset();
	__1802Reset();
}

// *******************************************************************************************************************************
//												Execute a single instruction
// *******************************************************************************************************************************

BYTE8 CPUExecuteInstruction(void) {

	FETCH();																		// Read the opcode

	switch(MB) {																	// Execute it.
		#include "__1802opcodes.h"
	}
	Cycles += 2;																	// Instruction is two cycles
	if (Cycles >= CYCLES_PER_FRAME-29) {											// If we are at INT time.
		if (IE != 0) {																// and interrupts are enabled
			__1802Interrupt();														// Fire an interrupt
			Cycles = CYCLES_PER_FRAME - 29;											// Make it EXACTLY 29 cycles to display start
																					// When breaks on FRAME_RATE then will be at render
		}
	}	
	if (Cycles < CYCLES_PER_FRAME) return 0;										// Not completed a frame.
	BYTE8 *ptr = NULL;																// NULL if R0 is a bad pointer.							
	if (R0 <= MEMORYSIZE-256) ptr = ramMemory+R0;									// If in memory range, get pointer
	HWISetPageAddress(R0,ptr);														// Set the display address.
	HWIEndFrame();																	// End of Frame code
	Cycles = Cycles - CYCLES_PER_FRAME;												// Adjust this frame rate.
	return FRAME_RATE;																// Return frame rate.
}

#ifdef INCLUDE_DEBUGGING_SUPPORT

// *******************************************************************************************************************************
//		Execute chunk of code, to either of two break points or frame-out, return non-zero frame rate on frame, breakpoint 0
// *******************************************************************************************************************************

BYTE8 CPUExecute(WORD16 breakPoint1,WORD16 breakPoint2) { 
	do {
		BYTE8 r = CPUExecuteInstruction();											// Execute an instruction
		if (r != 0) return r; 														// Frame out.
	} while (*pP != breakPoint1 && *pP != breakPoint2);								// Stop on breakpoint.
	return 0; 
}

// *******************************************************************************************************************************
//									Return address of breakpoint for step-over, or 0 if N/A
// *******************************************************************************************************************************

WORD16 CPUGetStepOverBreakpoint(void) {
	BYTE8 opcode = CPUReadMemory(*pP);												// Current opcode.
	if (opcode >= 0xD0 && opcode <= 0xDF) return ((*pP)+1) & 0xFFFF;				// If SEP Rx then step is one after.
	return 0;																		// Do a normal single step
}

// *******************************************************************************************************************************
//												Read/Write Memory
// *******************************************************************************************************************************

BYTE8 CPUReadMemory(WORD16 address) {
	BYTE8 _MB = MB;WORD16 _MA = MA;BYTE8 result;
	MA = address;READ();result = MB;
	MB = _MB;MA = _MA;
	return result;
}

void CPUWriteMemory(WORD16 address,BYTE8 data) {
	BYTE8 _MB = MB;WORD16 _MA = MA;
	MA = address;MB = data;WRITE();
	MB = _MB;MA = _MA;
}

// *******************************************************************************************************************************
//												Load a binary file into RAM
// *******************************************************************************************************************************

#include <stdio.h>

void CPULoadBinary(const char *fileName) {
	FILE *f = fopen(fileName,"rb");
	fread(ramMemory,1,MEMORYSIZE,f);
	fclose(f);
}

// *******************************************************************************************************************************
//											Retrieve a snapshot of the processor
// *******************************************************************************************************************************

static CPUSTATUS s;																	// Status area

CPUSTATUS *CPUGetStatus(void) {
	s.d = D;s.df = DF;s.p = P;s.x = X;s.t = T;s.q = Q;s.ie = IE;					// Registers
	for (int i = 0;i < 16;i++) s.r[i] = *__RPtr[i];									// 16 bit Registers
	s.cycles = Cycles;s.pc = *pP;													// Cycles and "PC"
	return &s;
}

#endif
