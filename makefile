# Directory
build_dir 		 = build

as 	  			:= arm-none-eabi-as
objcopy			:= arm-none-eabi-objcopy
gcc 	  		:= arm-none-eabi-gcc
ld				:= arm-none-eabi-ld
armips			:= armips.exe

as_flags := -mthumb -march=armv5t -r
c_flags  := -mthumb -mno-thumb-interwork -march=armv5t -mno-long-calls -Wall -Wextra -Os -fira-loop-pressure -fipa-pta 

.PHONY: all

all:
	mkdir -p build
	mkdir -p output
	$(as) $(as_flags) -c asm/thumb_help.s -o build/thumb_help.o
	$(gcc) $(c_flags) -I include -c PokePad/PokePad.c -o build/PokePad.o
	$(ld) rom.ld -T link.ld -o build/PokePad_out.o build/PokePad.o build/thumb_help.o
	$(objcopy) -O binary build/PokePad_out.o build/PokePad_out.bin

	$(gcc) $(c_flags) -I DLL/include -I DLL/include/swan -c DLL/field_item_use.cpp -o build/field_item_use.o
	$(as) $(as_flags) -c DLL/item_expansion.s -o build/item_expansion.o
	$(ld) -o output/eviv.elf -r build/field_item_use.o build/item_expansion.o

	objdump -t build/PokePad_out.o > w2.map

	$(armips) PokePad/PokePad.s
