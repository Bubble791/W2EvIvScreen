#ifndef __IRQ_H
#define __IRQ_H

#include "swantypes.h"
#include "swan_cpp_enum_ops.h"

STRUCT_DECLARE(IRQFlagReg)

ENUM_DECLARE(CPUInterrupt)
ENUM_DECLARE(CPUInterruptBit)

enum CPUInterrupt
#ifdef __cplusplus
: u32
#endif
{
    CPU_INTR_VBLANK = 0x0,
    CPU_INTR_HBLANK = 0x1,
    CPU_INTR_VCOUNT_MATCH = 0x2,
    CPU_INTR_TIMER_0 = 0x3,
    CPU_INTR_TIMER_1 = 0x4,
    CPU_INTR_TIMER_2 = 0x5,
    CPU_INTR_TIMER_3 = 0x6,
    CPU_INTR_NDS7_RTC = 0x7,
    CPU_INTR_DMA_0 = 0x8,
    CPU_INTR_DMA_1 = 0x9,
    CPU_INTR_DMA_2 = 0xA,
    CPU_INTR_DMA_3 = 0xB,
    CPU_INTR_KEYPAD = 0xC,
    CPU_INTR_GBA_SLOT = 0xD,
    CPU_INTR_IPC_SYNC = 0xE,
    CPU_INTR_IPC_SEND_FIFO_EMPTY = 0xF,
    CPU_INTR_IPC_RECV_FIFO_NOT_EMPTY = 0x10,
    CPU_INTR_CART_TRANSFER_DONE = 0x11,
    CPU_INTR_CART_IREQ_MC = 0x12,
    CPU_INTR_NDS9_GE_FIFO = 0x13,
    CPU_INTR_NDS7_SCREEN_UNFOLD = 0x14,
    CPU_INTR_NDS7_SPI = 0x15,
    CPU_INTR_NDS7_WIFI = 0x16,
    CPU_INTR_NDS9_MAX = 0x16,
    CPU_INTR_DSI9_CAMERA = 0x17,
    CPU_INTR_DSI9_UNDOC = 0x18,
    CPU_INTR_DSI_IREQ_MC_2 = 0x19,
    CPU_INTR_DSI_DMA_EX_0 = 0x1A,
    CPU_INTR_DSI_DMA_EX_1 = 0x1B,
    CPU_INTR_DSI_DMA_EX_2 = 0x1C,
    CPU_INTR_DSI_DMA_EX_3 = 0x1D,
};

enum CPUInterruptBit
#ifdef __cplusplus
: u32
#endif
{
    CPU_INTRB_VBLANK = 0x1,
    CPU_INTRB_HBLANK = 0x2,
    CPU_INTRB_VCOUNT_MATCH = 0x4,
    CPU_INTRB_TIMER_0 = 0x8,
    CPU_INTRB_TIMER_1 = 0x10,
    CPU_INTRB_TIMER_2 = 0x20,
    CPU_INTRB_TIMER_3 = 0x40,
    CPU_INTRB_NDS7_RTC = 0x80,
    CPU_INTRB_DMA_0 = 0x100,
    CPU_INTRB_DMA_1 = 0x200,
    CPU_INTRB_DMA_2 = 0x400,
    CPU_INTRB_DMA_3 = 0x800,
    CPU_INTRB_KEYPAD = 0x1000,
    CPU_INTRB_GBA_SLOT = 0x2000,
    CPU_INTRB_IPC_SYNC = 0x10000,
    CPU_INTRB_IPC_SEND_FIFO_EMPTY = 0x20000,
    CPU_INTRB_IPC_RECV_FIFO_NOT_EMPTY = 0x40000,
    CPU_INTRB_CART_TRANSFER_DONE = 0x80000,
    CPU_INTRB_CART_IREQ_MC = 0x100000,
    CPU_INTRB_NDS9_GE_FIFO = 0x200000,
    CPU_INTRB_NDS7_SCREEN_UNFOLD = 0x400000,
    CPU_INTRB_NDS7_SPI = 0x800000,
    CPU_INTRB_NDS7_WIFI = 0x1000000,
    CPU_INTRB_DSI9_CAMERA = 0x2000000,
    CPU_INTRB_DSI9_UNDOC = 0x4000000,
    CPU_INTRB_DSI_IREQ_MC_2 = 0x8000000,
    CPU_INTRB_DSI_DMA_EX_0 = 0x10000000,
    CPU_INTRB_DSI_DMA_EX_1 = 0x20000000,
    CPU_INTRB_DSI_DMA_EX_2 = 0x40000000,
    CPU_INTRB_DSI_DMA_EX_3 = 0x80000000,
};
DEFINE_ENUM_FLAG_OPERATORS(CPUInterruptBit)

C_DECL_BEGIN

extern void    irq_waitFor(b32 clear, CPUInterruptBit mask);

C_DECL_END

struct IRQFlagReg {
union {
    struct {
    u32 VBlank:1;
    u32 HBlank:1;
    u32 VCountMatch:1;
    u32 Timer0:1;
    u32 Timer1:1;
    u32 Timer2:1;
    u32 Timer3:1;
    u32 RTC:1;
    u32 DMA0:1;
    u32 DMA1:1;
    u32 DMA2:1;
    u32 DMA3:1;
    u32 Keypad:1;
    u32 GBASlot:1;
    u32 IPCSync:1;
    u32 IPCSendEmpty:1;
    u32 IPCRecvNotEmpty:1;
    u32 CartTransferDone:1;
    u32 CartIreqMC:1;
    u32 GEFIFO:1;
    u32 ScreenUnfold:1;
    u32 SPI:1;
    u32 WiFi:1;
    };
    CPUInterruptBit RawBits;
};
};

extern volatile IRQFlagReg IE;

extern volatile IRQFlagReg IF;

extern volatile int IME;

#endif //__IRQ_H
// Tchaikovsky code generator
