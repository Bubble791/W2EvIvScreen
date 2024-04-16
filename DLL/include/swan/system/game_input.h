#ifndef __GAME_INPUT_H
#define __GAME_INPUT_H

#include "swantypes.h"

#define HID_CHECK_KEY_PRESS(key) (GCTX_HIDGetPressedKeys() & (key))
#define HID_CHECK_KEY_TYPED(key) (GCTX_HIDGetTypedKeys() & (key))
#define HID_CHECK_KEY_DOWN(key) (GCTX_HIDGetHeldKeys() & (key))
#define HID_CHECK_KEY_UP(key) (!HID_CHECK_KEY_DOWN(key))
#define HID_CHECK_COMBO(combo) ((GCTX_HIDGetHeldKeys() & (combo)) == (combo))

namespace game { struct HID; }

#include "nds/hid.h"

C_DECL_BEGIN

extern InputButton GCTX_HIDGetPressedKeys();
extern InputButton GCTX_HIDGetHeldKeys();
extern InputButton GCTX_HIDGetTypedKeys();
extern void        GCTX_HIDSetUpdateRate(u8 updateRate);
extern u8          GCTX_HIDGetUpdateRate();
extern void        GCTX_HIDChangeFPS(u8 fps);
extern void        GCTX_HIDUpdate();

C_DECL_END

#ifdef __cplusplus
struct game::HID {
    INLINE static InputButton GetPressedKeys() {
        return GCTX_HIDGetPressedKeys();
    }

    INLINE static InputButton GetHeldKeys() {
        return GCTX_HIDGetHeldKeys();
    }

    INLINE static InputButton GetTypedKeys() {
        return GCTX_HIDGetTypedKeys();
    }

    INLINE static u8 GetUpdateRate() {
        return GCTX_HIDGetUpdateRate();
    }

    INLINE static void SetUpdateRate(u8 updateRate) {
        GCTX_HIDSetUpdateRate(updateRate);
    }

    INLINE static void ChangeFPS(u8 fps) {
        GCTX_HIDChangeFPS(fps);
    }

    INLINE static void Update() {
        GCTX_HIDUpdate();
    }

};
#endif //__cplusplus

#endif //__GAME_INPUT_H
// Tchaikovsky code generator
