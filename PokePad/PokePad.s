.nds
.thumb

.create "output/overlay_0345.bin", 0x21A9BA0
.incbin "build/PokePad_out.bin"

.org 0x469F + 0x21A9BA0
.byte 0
.close
