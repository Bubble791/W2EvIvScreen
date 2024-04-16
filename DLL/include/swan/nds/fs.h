#ifndef __FS_H
#define __FS_H

#include "swantypes.h"

STRUCT_DECLARE(FileSystem)
STRUCT_DECLARE(FSFileIterDirParam)
STRUCT_DECLARE(FSFileID)
STRUCT_DECLARE(FSFileIterDirResult)
STRUCT_DECLARE(FSFileOpenRequest)
STRUCT_DECLARE(FSFile)

ENUM_DECLARE(FSFileCommand)
ENUM_DECLARE(FSCommand)
ENUM_DECLARE(SeekOrigin)

enum FSFileCommand
#ifdef __cplusplus
: u32
#endif
{
    FSF_READ = 0x0,
    FSF_WRITE = 0x1,
    FSF_CHANGE_DIR = 0x2,
    FSF_ITERATE_DIR = 0x3,
    FSF_FIND_PATH = 0x4,
    FSF_GET_LENGTH = 0x5,
    FSF_OPEN_FAST = 0x6,
    FSF_OPEN_DIRECT = 0x7,
    FSF_CLOSE = 0x8
};
SWAN_CPPTYPE_EX(nn::fs, FileCommand, FSFileCommand)

enum FSCommand
#ifdef __cplusplus
: u32
#endif
{
    FS_READ_FILE = 0x0,
    FS_WRITE_FILE = 0x1,
    FS_FIND_PATH = 0x4,
    FS_CLOSE_FILE = 0x8,
    FS_OPEN_FILE = 0xD,
    FS_SEEK_FILE = 0xE,
    FS_GET_FILE_LENGTH = 0xF,
    FS_GET_FILE_POS = 0x10,
    FS_OPEN_DIR = 0x20,
    FS_CLOSE_DIR = 0x21
};
SWAN_CPPTYPE_EX(nn::fs, SystemCommand, FSCommand)

enum SeekOrigin
#ifdef __cplusplus
: u32
#endif
{
    IO_SEEK_SET = 0x0,
    IO_SEEK_CUR = 0x1,
    IO_SEEK_END = 0x2,
};
SWAN_CPPTYPE(nn::fs, SeekOrigin)

SWAN_CPPTYPE(nn::fs, FileSystem)
SWAN_CPPTYPE_EX(nn::fs::detail, IterDirParam, FSFileIterDirParam)
SWAN_CPPTYPE_EX(nn::fs, FileID, FSFileID)
SWAN_CPPTYPE_EX(nn::fs, IterDirResult, FSFileIterDirResult)
SWAN_CPPTYPE_EX(nn::fs, FileOpenRequest, FSFileOpenRequest)
SWAN_CPPTYPE_EX(nn::fs, File, FSFile)

C_DECL_BEGIN

extern FSFile*     finit(FSFile* file);
extern b32         fs_resolve_file(FSFile* file, char* path);
extern FileSystem* fs_normalize_path(const char* src, u32* destId, char* dest);
extern b32         fs_call_syscmd(FSFile* file, FSCommand command, b32 blocking);
extern int         fs_call_filecmd(FSFile* file, unsigned int commandId, b32 blocking);
extern b32         romfs_fopen(FSFile* file, const char* path);
extern b32         romfs_fopen_core(FSFile* file, const char* path, u32 mode);
extern b32         romfs_fopen_id(FSFile* file, FSFileID id);
extern b32         romfs_fclose(FSFile* file);
extern u32         romfs_fgetsize(FSFile* file);
extern b32         romfs_fseek(FSFile* file, u32 offset, SeekOrigin origin);
extern u32         romfs_ftell(FSFile* file);
extern u32         romfs_fread(FSFile* file, void* dest, u32 length);

C_DECL_END

struct FileSystem
{
    char dummy[92];
};

struct FSFileIterDirParam
{
    FSFileIterDirResult* ResultPtr;
    b32 DontNeedReadName;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

struct FSFileID
{
    FileSystem* m_FileSystem;
    int FileID;
};

struct FSFileIterDirResult
{
    FSFileID FileID;
    u32 field_8;
    b32 IsDirectory;
    u32 NameLength;
    char Name[128];
};

struct FSFileOpenRequest
{
    u32 BaseID;
    char* Path;
    u32 Mode;
};

struct FSFile
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
  
    #ifdef __cplusplus
  
    INLINE nn::fs::File* Init() {
        return finit(this);
    }

    INLINE b32 Open(const char* path) {
        return romfs_fopen(this, path);
    }

    INLINE b32 OpenID(nn::fs::FileID id) {
        return romfs_fopen_id(this, id);
    }

    INLINE b32 Close() {
        return romfs_fclose(this);
    }

    INLINE u32 GetSize() {
        return romfs_fgetsize(this);
    }

    INLINE b32 Seek(u32 offset, nn::fs::SeekOrigin origin) {
        return romfs_fseek(this, offset, origin);
    }

    INLINE u32 Tell() {
        return romfs_ftell(this);
    }

    INLINE u32 Read(void* dest, u32 length) {
        return romfs_fread(this, dest, length);
    }

    INLINE b32 CallSystemCommand(nn::fs::SystemCommand command, b32 blocking) {
        return fs_call_syscmd(this, command, blocking);
    }

    INLINE int CallFileCommand(unsigned int commandId, b32 blocking) {
        return fs_call_filecmd(this, commandId, blocking);
    }

    #endif
};

#endif //__FS_H
// Tchaikovsky code generator
