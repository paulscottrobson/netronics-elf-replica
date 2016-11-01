
	cpu 	1802
	
r0 = 0
r1 = 1
r2 = 2
r3 = 3
r4 = 4
r5 = 5

	ghi 	r0
	phi		r1
	phi		r2

	plo		r3
	plo 	r4

	ldi 	Main & 255
	plo 	r3
	ldi 	Stack & 255
	plo 	r2
	ldi 	Interrupt & 255
	plo 	r1
	sep 	r3

Return:
	ldxa
	ret
Interrupt:
	dec 	r2
	sav
	dec 	r2
	str 	r2
	nop
	nop
	nop
	ldi 	0
	phi 	r0
	ldi 	0
	plo 	r0
Refresh:
	glo 	r0
	sex 	r2

	sex 	r2
	dec 	r0
	plo 	r0

	sex 	r2
	dec 	r0
	plo 	r0

	sex 	r2
	dec 	r0
	plo 	r0

	bn1 	Refresh
	br 		Return

Main:
	sex 	r2
	inp		1
Wait:
	ldi 	0FCh
	plo 	r5
	sex 	r5
	ldi 	081h
	bn4		NoKey
	ldi 	0FFh
NoKey:
	str 	r5
	inc 	r5
	inc 	r5
	inp 	4
	out 	4
	br 		Wait

Stack = 04Eh	

	org 	50h
;	db 000h,000h,000h,000h,000h,000h,000h,000h
;	db 000h,000h,000h,000h,000h,000h,000h,000h
	db 07Bh,0DEh,0DBh,0DEh,000h,000h,000h,000h
	db 04Ah,050h,0DAh,052h,000h,000h,000h,000h
	db 042h,05Eh,0ABh,0D0h,000h,000h,000h,000h
	db 04Ah,042h,08Ah,052h,000h,000h,000h,000h
	db 07Bh,0DEh,08Ah,05Eh,000h,000h,000h,000h
	db 000h,000h,000h,000h,000h,000h,000h,000h
	db 000h,000h,000h,000h,000h,000h,007h,0E0h
	db 000h,000h,000h,000h,0FFh,0FFh,0FFh,0FFh
	db 000h,006h,000h,001h,000h,000h,000h,001h
	db 000h,07Fh,0E0h,001h,000h,000h,000h,002h
	db 07Fh,0C0h,03Fh,0E0h,0FCh,0FFh,0FFh,0FEh
	db 040h,00Fh,000h,010h,004h,080h,000h,000h
	db 07Fh,0C0h,03Fh,0E0h,004h,080h,000h,000h
	db 000h,03Fh,0D0h,040h,004h,080h,000h,000h
	db 000h,00Fh,008h,020h,004h,080h,07Ah,01Eh
	db 000h,000h,007h,090h,004h,080h,042h,010h
	db 000h,000h,018h,07Fh,0FCh,0F0h,072h,01Ch
	db 000h,000h,030h,000h,000h,010h,042h,010h
	db 000h,000h,073h,0FCh,000h,010h,07Bh,0D0h
	db 000h,000h,030h,000h,03Fh,0F0h,000h,000h
	db 000h,000h,018h,00Fh,0C0h,000h,000h,000h
	db 000h,000h,007h,0F0h,000h,000h,000h,000h

