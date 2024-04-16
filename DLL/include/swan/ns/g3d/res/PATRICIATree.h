#ifndef __PATRICIATREE_H
#define __PATRICIATREE_H

#include "swantypes.h"

STRUCT_DECLARE(NNSPatriciaTreeNode)
STRUCT_DECLARE(NNSPatriciaTreeEntries)
STRUCT_DECLARE(NNSPatriciaTree)

SWAN_CPPTYPE_EX(ns::g3d::res, TreeNode, NNSPatriciaTreeNode)
SWAN_CPPTYPE_EX(ns::g3d::res, TreeEntries, NNSPatriciaTreeEntries)
SWAN_CPPTYPE_EX(ns::g3d::res, Tree, NNSPatriciaTree)

struct NNSPatriciaTreeNode
{
    u8 RefBit;
    u8 LeftNodeIdx;
    u8 RightNodeIdx;
    u8 DataEntryNo;
};

struct NNSPatriciaTreeEntries
{
    u16 EntrySize;
    u16 NamesOffset;
    char Entries[];
};

struct NNSPatriciaTree
{
    u8 field_0;
    u8 EntryCount;
    u16 Size;
    u16 NodesOffset;
    u16 EntriesOffset;
    NNSPatriciaTreeNode Nodes[];
};

#endif //__PATRICIATREE_H
// Tchaikovsky code generator
