#ifndef __BATTLE_CLIENT_H
#define __BATTLE_CLIENT_H

#define BTL_STYLE_ROTATION 3

C_DECL_BEGIN

extern void PokeParty_SetParam(void*, int, int);
extern u32 PokeParty_GetPkmCount(void *);
extern void *PokeParty_GetPkm(void *, int );
extern void PokeParty_Copy(void *, void *);
extern int PokeParty_GetParam(void *, int, int*);

extern int PokeParty_DecryptPkm(void*);
extern int PokeParty_EncryptPkm(void*, int);

C_DECL_END

#endif