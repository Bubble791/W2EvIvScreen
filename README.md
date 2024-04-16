# White 2 EV&IV View Item
![Screenshots1](https://github.com/Bubble791/W2EvIvScreen/blob/main/png/w2.png)

## Setup
1. Add `armips` to folder

1. Type `make`, build all code

2. Unzip the ROM and place `output/overlay345.bin` in the `overlay` code folder

3. Open `ARM9OVT.bin` and add the following byte at the end
    * ```59 01 00 00 A0 9B 1A 02 A0 46 00 00 00 00 00 00 DC E1 1A 02 E0 E1 1A 02 59 01 00 00 A0 46 00 00```

4. Add `data/text/495.bin` to text narc `a/0/0/2`

5. Refer to [tutorial](#CodeInjection) inject `output/eviv.ll` into ROM

[CodeInjection]: https://ds-pokemon-hacking.github.io/docs/generation-v/guides/bw_b2w2-code_injection/
