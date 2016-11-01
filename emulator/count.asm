
	cpu 	1802
	
r0 = 0
r1 = 1
r2 = 2
r3 = 3
r4 = 4
r5 = 5

	dis
Delay:
	ldi 	1
	phi 	r4
DLoop:
	dec 	r4
	ghi 	r4
	bnz 	DLoop
	glo 	r4
	bnz 	DLoop

	ldi 	020h
	plo 	r3
	inc 	r2
	glo 	r2
	str 	r3
	sex 	r3
	out 	4
	br 		Delay

