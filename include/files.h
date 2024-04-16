#ifndef __FILES_H
#define __FILES_H

typedef struct
{
    char dummy[92];
}FileSystem;

typedef struct 
{
    FileSystem* m_FileSystem;
    int FileID;
}FSFileID;

typedef struct
{
    FSFileID FileID;
    u32 field_8;
    int IsDirectory;
    u32 NameLength;
    char Name[128];
}FSFileIterDirResult;
typedef struct 
{
    FSFileIterDirResult* ResultPtr;
    int DontNeedReadName;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
}FSFileIterDirParam;


typedef struct 
{
    u32 field_0;
    u32 TableData;
    FileSystem* m_FileSystem;
    u32 CommandQueue;
    void* Request;
    u32 field_14;
    u32 field_18;
    u32 field_1C;
    u32 field_20;
    u16 NowDirID;
    u16 DirIterFileID;
    u32 SubTableOffset;
    u32 ParentDirID;
    union {
    FSFileIterDirParam IterDir;
    };
} FSFile;

typedef struct
{
    FSFile File;
    u32 FIMGOffset;
    u16 NARCHeaderSize;
    u16 NARCFileCount;
}ArcTool;

#endif // __FILES_H