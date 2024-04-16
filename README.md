# White 2 EV&IV View Item
![Screenshots1](https://github.com/Bubble791/W2EvIvScreen/blob/main/png/w2.png)

## Setup
1. Add `armips` to folder

2. Change `DLL/item_expansion.s` and `DLL/include/constant/items.h` `ITEM_IV_EV_SCREEN` to your item id

3. Type `make`, build all code

4. Unzip the ROM and place `output/overlay345.bin` to `overlay` code folder

5. Open `ARM9OVT.bin` and add the following byte at the end
    * ```59 01 00 00 A0 9B 1A 02 A0 46 00 00 00 00 00 00 DC E1 1A 02 E0 E1 1A 02 59 01 00 00 A0 46 00 00```

6. Add `data/text/495.bin` to text narc `a/0/0/2`

7. Refer to tutorial inject `output/eviv.elf` into ROM
    * ```https://ds-pokemon-hacking.github.io/docs/generation-v/guides/bw_b2w2-code_injection/```
