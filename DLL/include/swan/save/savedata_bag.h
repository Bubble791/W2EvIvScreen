#ifndef __SAVEDATA_BAG_H
#define __SAVEDATA_BAG_H

#include "swantypes.h"

STRUCT_DECLARE(BagItem)
STRUCT_DECLARE(BagSaveData)

SWAN_CPPTYPE(savedata, BagItem)
SWAN_CPPTYPE_EX(savedata, Bag, BagSaveData)

#define NORMAL_ITEM_MAX     310
#define KEY_ITEM_MAX        83
#define TMHM_ITEM_MAX       109
#define MEDICINE_ITEM_MAX   48
#define BERRIES_ITEM_MAX    64

struct BagItem
{
    u16 ItemID;
    u16 Count;
};

struct BagSaveData
{ 
    BagItem Items[NORMAL_ITEM_MAX];
    BagItem KeyItems[KEY_ITEM_MAX];
    BagItem TMsHMs[TMHM_ITEM_MAX];
    BagItem Medicine[MEDICINE_ITEM_MAX];
    BagItem Berries[BERRIES_ITEM_MAX];
    u32 FreeSpaceBits[21];
};

#endif //__SAVEDATA_BAG_H
