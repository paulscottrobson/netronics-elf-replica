make
ASM=starship
asl -L $ASM.asm
p2bin -r 0-511 -l 0 $ASM.p
rm *.p
./elf2 $ASM.bin
