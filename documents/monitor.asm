;
; monitor.asm
;
;   Netronics ELF II monitor program from the Giant board
;
;       This monitor program was based on the Popular Electronics EHOP and
;       ETOP monitor programs published in the original COSMAC ELF articles.
;       It can be assembled to any location as long as it starts on a page
;       boundary. The entire program fits into one 256 byte page.
;
;       NOTE: Minimal error checking is performed by the monitor program.
;             It will crash if incorrect parameter values are used.
;
;   Instructions:
;
;       1) Run the monitor program
;       2) Enter the monitor command on the keypad and press the input key
;          An invalid command will, display EE, set the Q LED on, and stop
;          program execution.
;
;       Monitor Commands:
;
;       00 - Run a program
;
;               a) Enter the starting address high byte on the keypad and
;                  press the input key
;               b) Enter the starting address low byte on the keypad and
;                  press the input key
;               c) The program will start executing at the entered address
;
;       01 - Examine a memory location
;
;               a) Enter the starting address high byte on the keypad and
;                  press the input key
;               b) Enter the starting address low byte on the keypad and
;                  press the input key
;               c) The monitor displays the low address byte until the input
;                  key is pressed.  
;               d) Press the input key and the data is displayed until the
;                  input key is released.
;               e) Steps c and d are repeated to step through memory.
;
;       02 - Modify a memory location
;
;               a) Enter the starting address high byte on the keypad and
;                  press the input key
;               b) Enter the starting address low byte on the keypad and
;                  press the input key
;               c) The Q LED turns on
;               d) The monitor displays the low address byte
;               e) Enter the new value on the keypad and press the input key
;               f) The new value is displayed until the input key is released
;               g) Steps d through f are repeated to change the next memory
;                  location
;               
;       03 - Save a memory block on cassette tape
;            The values in the memory block can a program or data
;
;               a) Enter the starting address high byte on the keypad and
;                  press the input key
;               b) Enter the starting address low byte on the keypad and
;                  press the input key
;               c) Enter the ending address high byte on the keypad and
;                  press the input key
;               d) Enter the ending address low byte on the keypad and
;                  press the input key
;               e) Start the recording on the cassette tape
;               f) Press the input key to start transferring the program to tape
;               g) The display will rapidly flash the low address byte on the
;                  display as the program is transferred to tape
;               h) The display will stop on the last address byte when the
;                  transfer is complete
;               i) Stop recording on the cassette
;               j) The program is waiting for a command input with the starting
;                  address set to the value in steps a and b    
;
;       04 - Load a memory block (program) from cassette tape
;            The values in the memory block can be a program or data
;
;               a) Enter the starting address high byte on the keypad and
;                  press the input key
;               b) Enter the starting address low byte on the keypad and
;                  press the input key
;               c) Enter the ending address high byte on the keypad and
;                  press the input key
;               d) Enter the ending address low byte on the keypad and
;                  press the input key
;               e) Start the playing the cassette tape with a couple of seconds
;                  of tape before the program starts
;               f) Press the input key to start transferring the program to
;                  memory
;               g) The display will rapidly flash the low address byte on the
;                  display as the program is transferred from tape
;               h) The display will stop on the last address byte when the
;                  transfer is complete. If the Q LED is on there was an error
;                  loading the program  
;               i) Stop playing the cassette
;               i) The program is waiting for a command input with the starting
;                  address set to the value in steps c and d    
;
;       05 - Search for a byte
;
;               a) Enter the starting address high byte on the keypad and
;                  press the input key
;               b) Enter the starting address low byte on the keypad and
;                  press the input key
;               c) Enter the byte to search for on the keypad and press the
;                  input key
;               d) The monitor displays the low address byte where the search
;                  byte was found until the input key is pressed.   
;               e) Press the input key and the data is displayed until the
;                  input key is released.
;               f) Steps d and e are repeated to step through memory.
;
; Register use:
;
; R0 = PC for DAGB subroutine
; R1 = multipurpose scratch pad
; R2 = data storage pointer
; R3 = PC for main program
; R4 = PC for GBEB subroutine
; R5 = PC for DDB subroutine
; R6 = command offset for table, PC for WRITE subroutine
; R7 = PC for READ subroutine
; RA = user starting memory address, memory pointer
; RB = data to cassette tape
; RC = load/save byte counter
; RD = multipurpose, data from cassette
;

;
; Equates
;
        .EQU    START, H'0000

;
; Assembler directives
;
        .ORG    START

;
; Initialize
;
        GHI R0              ; Get current high byte of address from R0
        PLO R1              ; Set R1.0, R4.1, R5.1, R6.1, R7.1
        PHI R3              ;   to current high address byte
        PHI R4
        PHI R5
        PHI R6
        PHI R7

;
; Search for the top of RAM
;
        LDI H'FF            ; Look for the top of RAM
        PLO R2
        SEX R2
RTOP:   DEC R1
        GLO R1
        PHI R2
        GLO R0
        STR R2
        XOR
        BNZ RTOP            ; Top of RAM not found? ,look some more

;
; Set up main PC and subroutine PC's
;

; When exiting this section, at DAGB, R0 will be set up to use
;    as the PC for the display address and fetch data subroutine

; Main program entry point, R3 is main PC       
        LDI H'00FF & MAIN
        PLO R3

; PC for keyboard fetch and echo subroutine, GBEG       
        LDI H'00FF & (GBEB + 1)
        PLO R4

; PC for data display subroutine, DDB
        LDI H'00FF & (DDB + 1)
        PLO R5

;
; DAGB - Display Address Get Byte
;
; Subroutine to display low address byte on LED's
; and get a byte from keyboard
;
DAGB:   SEP R3
        BN4 *               ; Wait for input key release
        DEC R2              ; Output data to LED display
        GLO RA
        STR R2
        OUT 4
        B4  *               ; Wait for input key press
        INP 4               ; Get keyboard data
        BR  DAGB            ; Return, data at M(R2) & in D

;
; GBEB - Get Byte Echo Byte
;
; Subroutine to get a byte of data from the keyboard
; and echo it to the LED's
;
GBEB:   SEP R3
        BN4 *               ; Wait for input key to toggle
        B4  *
        INP 4               ; Get keyboard data
        OUT 4               ;    echo to display
        DEC R2              ;    adjust data pointer
        BR  GBEB            ; Return, data at M(R2) & in D

;
; DDB - Display Data Byte
;
; Subroutine to display a byte of data on the LED's
;
DDB:    SEP R3
        DEC R2              ; Point to free memory location
        STR R2              ;    save byte there
        OUT 4               ;    then display it
        BR  DDB             ; Return

;
; Main program
;
;   initial entry is from the DAGB subroutine where the
;   program dropped down to the SEP R3 instruction
;
MAIN:   SEP R4              ; Get command from keyboard and echo it
        LDI CTBL            ; Calculate command offset address in table
        ADD
        PLO R6
        LDN R2              ; Check for valid command
        SDI 5
        BDF MAIN + 15       ;    yes, jump ahead
        LDI H'EE            ;    no, signal an error by displaying EE and
                            ;    setting Q on
        SEP R5
        SEQ
        IDL                 ; Stop program, wait for hardware restart

;
; Get memory address from keyboard and jump to command using table
;
        SEP R4              ; Get user memory address from the
        PHI RA              ;   keyboard, echo it, then save it in RA
        SEP R4
        PLO RA
        LDN R6              ; Jump to command address from table CTBL
        PLO R3
;
; CTBL - Command addresses
;
CTBL:   .DB EXEC            ; 0 - Run program at RA address
        .DB EXAM - 1        ; 1 - Examine memory starting at RA address
        .DB MODIFY          ; 2 - Modify memory starting at RA address
        .DB SAVE            ; 3 - Save memory to cassette tape
        .DB LOAD            ; 4 - Load cassette tape to memory
        .DB SEARCH          ; 5 - Search memory for user byte starting at
                            ;     RA address

;
; Execute - Command 0
;
;   Run a program at the address stored in RA
;
EXEC:   GHI RA              ; Get program memory address
        PHI R0              ;    put in R0
        GLO RA
        PLO R0
        SEX R0              ; Set X to initial restart condition
        SEP R0              ; Go run the program

;
; Examine - Command 1
;
;   Display the memory location pointed to by RA
;
;   NOTE: Routine entry is at EXAM - 1 address. R0 is used to call
;         the DAGB subroutine to display the lower address byte 
;
EXAM:   LDA RA              ; Get data at M(RA)
        SEP R5              ;    and display it on the LED's
        BR  EXAM - 1        ; Examine the next memory location

;
; Modify - Command 2
;
;   Modify the memory location pointed to by RA
;
MODIFY: SEQ                 ; Turn on Q to signal memory modification
        SEP R0              ; Display the lower address byte & get new value
                            ; location
        SEP R5              ;    display it
        STR RA              ;    save it 
        INC RA              ; Modify the next location
        BR  MODIFY

;
;  WRITE - Write data to the cassette tape
;
;   DF=0, write a 0 to the tape
;   DF=1, write a 1 to the tape
;
WRITE:  SEP R3              ; Modulate the Q line to write 1's & 0's on tape
        SEQ                 ;   Sorter pulse widths are 0's
        LDI H'1D            ;   Longer pulse widths are 1's
        BNF WRITE + 9
        LDI 7
        INC RD
        STR R2
        SMI 1
        BDF WRITE + 10
        BNQ WRITE
        REQ
        LDN R2
        BR  WRITE + 10

;
; Save - Command 3
;
;   Save memory to cassette tape
;
;   RB = data to cassette tape
;   RC = number of bytes to load/save
;   RA = starting address and pointer for memory
;   R1 = used to save return address for subroutine calls
;   R6 = PC for WRITE subroutine
;
SAVE:   LDI SAVER           ; Save return address in R1
        PLO R1
        SEP R4              ; Get ending address high byte and echo it
        STXD                ;    save it to M(R2) and dec pointer
        SEP R4              ; Get ending address low byte and echo it
        GLO RA              ; Calculate # of bytes to load/save
        SD                  ;    save result in RC
        PLO RC              ;    save it in RC.0
        INC R2
        GHI RA
        SDB
        ADI 1
        PHI RC
        SEP R0              ; Display low starting address
        LDI WRITE + 1       ; Initialize R6 as PC for WRITE subroutine
        PLO R6
        GLO R1              ; Get return address in R1
        PLO R3              ;    jump to it

;
; Section above is shared by both the load and save routines
;
SAVER:  LDI H'80            ; Write leader to tape
        PHI RD
WLEAD:  SMI 0
        SEP R6
        GHI RD
        BNZ WLEAD
WBYTE:  GLO RA              ; Display the first address
        SEP R5
        SEQ                 ; Write the start bit to tape
        LDA RA
        PHI RB
        ADI 0
        LDI 9
        PLO RB
        PLO RD
WBIT:   SEP R6              ; Write the data bit to the tape
        DEC RB
        GLO RB
        BZ  WPAR            ;   byte done?, branch if yes
        GHI RB
        SHL                 ;   shift data into DF
        PHI RB              ;   save new value
        BR  WBIT            ;   go do another bit
WPAR:   GLO RD              ; Write parity bits
        SHR
        SEP R6
        DEC RC              ; Dec the byte count
        GHI RC              ; Check to see if done
        BNZ WBYTE           ;   branch if no
        SEP R6              ; Write trailer to tape
        SEP R6
        SEP R6
        SEP R6
        BR  MAIN            ; Reenter main program, wait for command

;
; READ - Read data from the cassette tape
;
READ:   INC RD
        SEP R3
        LDI H'0D
        B2  *               ; Wait for *EF2 to go low
        B2  READ            ; Return if *EF2 is low
        SMI 1
        BDF READ + 6
        BN2 *               ; Wait for *EF2 to go high
        BR  READ + 1


;
; Load - Command 4
;   Load memory from cassette tape
;
;   RD = data from cassette
;   RC = number of bytes to load/save
;   RA = starting address and pointer for memory
;   R1 = used to save return address for subroutine calls
;   R7 = PC for READ subroutine
;
LOAD:   LDI H'CD            ; Save return address in R1
        PLO R1
        BR  SAVE + 3        ; Go get # of bytes to load
        LDI READ + 2        ; Initialize R7 as PC for READ subroutine
        PLO R7
RLEAD:  LDI H'F9            ; Read the tape leader
        PHI RD
        SEP R7
        BNF RLEAD
        GHI RD
        BNZ RLEAD + 3
RBYTE:  SEP R7
        BDF RBYTE
        LDI 1               ; Read the tape data
        PHI RD
        PLO RD
RBIT:   SEP R7
        GHI RD              ; Form the byte of data
        SHLC
        PHI RD              ;   save the new value
        BNF RBIT            ; Branch if not end of byte
        SEP R7              ; Check the parity bit
        GLO RD
        SHR
        BDF MAIN+ 13        ;   ERROR - display address, set Q and stop
        GHI RD              ; Save data to memory
        STR RA
        GLO RA              ; Display address
        SEP R5
        INC RA              ; next memory address
        DEC RC              ; Dec byte counter
        GHI RC
        BNZ RBYTE           ;   branch if not done
        BR  MAIN            ; Reenter main program, wait for command

;
; Search - Command 5
;
;   Search for a byte in memory then display the address and contents
;
SEARCH: SEP R4              ; Get search byte from keyboard and echo
        LDA RA              ;    get memory contents from starting address
        XOR                 ;    compare it to search byte
        BNZ SEARCH + 1      ; No match, continue memory search
        DEC RA              ; Match
        GHI RA              ;   display address and contents
        SEP R5              ;   then continue to examine memory from there
        BR  EXAM - 1

        .END
 