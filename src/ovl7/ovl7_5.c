// based on debug print, JL.cc?
// prefix: JL_
#include "common.h"
#include "buffers.h"
#include "GObj.h"
#include "Player.h"
#include "unk_structs/D_800E1B50.h"
#include "ovl1/ovl1_6.h"
#include "ovl1/ovl1_7.h"
#include "ovl1/util.h"
#include "enelib.h"

// ovl7_3
/* LEVER 55: defined in src/ovl2/ovl2_3.c, prototyped in src/ovl11 and src/ovl3
   but in no header this TU includes, so the call was an implicit `int f()`. */
s32 func_800F98EC(s32, f32);
extern void func_801A3864_ovl7(GObj *);
/* LEVER 117: prototyped in src/ovl14/ovl14.h and src/ovl2/ovl2_10.c, in no
   header this TU includes, so every `func_800AECC0(<f32>)` here was an
   implicit `int f()` and K&R-promoted its argument to double. */
void func_800AECC0(f32);
void func_800AED20(f32);
void func_800AF408(void);

// --- declarations used only by the guarded m2c drafts below ---
struct Unk801D0A78 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
};
extern struct Unk801D0A78 D_801D0A78_ovl7;
extern s32 D_801D0AA4_ovl7;
extern struct Entity *D_801290E0;
extern u8 D_800D6C68[];
extern u8 D_800D71E8;
extern u32 D_8012BCA0;
extern u8 D_801CA6F4_ovl7, D_801CA7DC_ovl7;
extern u8 D_801CAF28_ovl7, D_801CAF3C_ovl7;
extern u8 D_801CAFCC_ovl7, D_801CB008_ovl7, D_801CB080_ovl7;
extern u8 D_801CB0F8_ovl7, D_801CB134_ovl7, D_801CB170_ovl7;
extern u8 D_801CB4DC_ovl7, D_801CB590_ovl7, D_801CD240_ovl7;
struct EnemyEventTable;
extern struct EnemyEventTable D_801CB500_ovl7;
extern u8 D_801D0A38_ovl7, D_801D0A58_ovl7;
void func_800B4954(GObj *);
void func_800B4D70(GObj *);
void func_800B4EBC(GObj *);
void func_800B799C(GObj *);
void func_801A8FFC_ovl7(GObj *);
extern s32 D_800D7090;
/* K&R form is load-bearing here: func_801AB174_ovl7 (unguarded, already matched)
 * calls this with 0 args against a real 1-arg (GObj *) signature -- the ROM
 * relies on whatever is already sitting in $a0. An ANSI prototype breaks that
 * compile with "too few arguments". */
void func_801ABBA0_ovl7();
void func_801A9268_ovl7(void);
void func_801A9FC4_ovl7(GObj *);
void func_801AA344_ovl7(GObj *);
/* K&R form is load-bearing here: struct AnimReq/AnimReqSet aren't defined
 * until further down this file. A `struct AnimReq *` parameter here would
 * only get IDO's function-prototype-scope tag (a distinct, incomplete type
 * that dies at the closing paren), so it clashes with the real struct at
 * these functions' definitions below ("Incompatible type for the function
 * parameter"); `void *` clashes the same way, since it's a different type
 * from `struct AnimReq *` for prototype-matching purposes. Fixing this needs
 * a new standalone `struct AnimReq;` forward declaration ahead of the struct
 * definition, which is out of scope for a declaration-only edit. */
void func_801AA600_ovl7();
void func_801AA690_ovl7();
void func_801AA78C_ovl7();
void func_801AA850_ovl7();
void func_801AAE60_ovl7(void);
void func_801A9930_ovl7(s32);
void func_801A8CDC_ovl7(GObj *);
void func_801AA1D4_ovl7(GObj *);
void func_801AAAF8_ovl7(s32);
void func_801AB884_ovl7(s32);
void func_801AC33C_ovl7(GObj *);
void func_801AC448_ovl7(GObj *);


// ovl1_8
extern void func_800B6474(GObj *);

struct AnimReq {
    s32 unk0;
    s32 unk4;
    f32 unk8;
};

struct EneScaleSet {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

struct EneVtable {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[2];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 filler14[0x28];
    /* 0x3C */ void (*unk3C)(s32, s32 *, s32 *, f32 *);
    /* 0x40 */ void (*unk40)(GObj *);
    /* 0x44 */ void *unk44;
};

struct EneInfo {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ struct Unk801D0A78 *unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ struct EneVtable *unk14;
};

struct EneAnimSetup {
    u8 filler0[0x10];
    f32 unk10;
    u8 filler14[8];
    struct EneInfo *unk1C;
};

struct AnimTrack {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
};

struct AnimReqSet {
    u8 filler0[0x14];
    struct AnimReq unk14;
    struct AnimReq unk20;
    struct AnimReq unk2C;
    void (*unk38)(s32, s32, f32);
};

// weird structs
extern void *D_801CB044_ovl7;
extern void *D_801CA738_ovl7;


// 168A20 - 168A30 is ovl7_5 .data
extern FUNCLIST D_801C29B0_ovl7;

// ovl1 bss
extern f32 gameTicksPerDraw;

extern u32 D_800DFA10[];
extern f32 D_80198820_ovl3;
extern u8 D_8012E860[];
extern s32 D_801D0A98_ovl7;
extern s32 D_801D0A9C_ovl7;
extern s32 D_801D0AA0_ovl7;
extern s32 D_801D0AA8_ovl7;

extern void func_800FD570(s32, s32, f32, f32, f32);
extern void func_800A9F98(s32, f32);
extern void func_800A9760(s32);

// ovl7_14
extern void func_801C06FC_ovl7(void);
extern void func_801C1E08_ovl7(void);
extern f32 func_800A52F0(f32, f32);

// ovl7_5.h
void func_801A7524_ovl7(GObj *);
void func_801AA33C_ovl7(GObj *);
void func_801AB174_ovl7(GObj *);
void func_801AC11C_ovl7(GObj *);
void func_801AC1F4_ovl7(GObj *);
void func_801AC2D8_ovl7(GObj *);
void func_801AB5A4_ovl7(GObj *);

void func_801A7000_ovl7(GObj *gobj) {
    func_800AECC0(gameTicksPerDraw);
    func_800AED20(gameTicksPerDraw);
    func_800AF408();
    D_800E64D0[omCurrentObj->objId] = D_800E6690[omCurrentObj->objId] = 0.0f;
    D_800E6850[omCurrentObj->objId] = 65535.0f;
    D_800E3210[omCurrentObj->objId] = D_800E3750[omCurrentObj->objId] = 0.0f;
    D_800E3C90[omCurrentObj->objId] = 65535.0f;
    utilFuncTableJump(D_800E8220[omCurrentObj->objId], 2, &D_801C29B0_ovl7);
}

#ifdef NON_MATCHING
/* FACTORY: 201/264 words, dz home 0x24 vs ROM 0x20 with target*4 spill below it, sqrtf-block schedule, reg naming */
void func_801A7104_ovl7(GObj *arg0) {
    s32 target;
    struct Sub800E1B50_Unk34 *tmp;
    struct SubSub800E1B50_Unk88_UnkC *cc;
    struct SubSub800E1B50_Unk88_UnkC_Unk0 *info;
    f32 sp2C;
    f32 dz;
    struct EnemyRecord *ent;

    ent = D_800E1B50[omCurrentObj->objId];
    target = D_800E0D50[omCurrentObj->objId];
    cc = ent->unk88->unkC;
    func_800B19F4(0x30, omCurrentObj->objId);
    D_800DEF90[omCurrentObj->objId] = func_800B4EBC;
    D_800DF150[omCurrentObj->objId] = func_801A7524_ovl7;
    ent->unk48 = 0;
    ent->unk98 = (struct EnemyEventTable *) &D_801CB590_ovl7;
    ent->unk42 = 1;
    *(s8 *) &ent->unk38 = -1;
    ent->unk39 = -1;
    D_800E8920[omCurrentObj->objId] = 0;
    info = cc->unk0;
    D_800E2090[omCurrentObj->objId] = gEntitiesNextPosXArray[omCurrentObj->objId] - gEntitiesNextPosXArray[target];
    D_800E2250[omCurrentObj->objId] = gEntitiesNextPosYArray[omCurrentObj->objId] - (gEntitiesNextPosYArray[0] + 20.0f);
    D_800E2410[omCurrentObj->objId] = gEntitiesNextPosZArray[omCurrentObj->objId] - gEntitiesNextPosZArray[target];
    D_800E4C50[omCurrentObj->objId] = gEntitiesAngleYArray[omCurrentObj->objId];
    D_800E4E10[omCurrentObj->objId] = gEntitiesAngleZArray[omCurrentObj->objId];
    D_800E33D0[omCurrentObj->objId] = 0.0f;
    sp2C = D_800E33D0[omCurrentObj->objId];
    D_800E3210[omCurrentObj->objId] = sp2C;
    D_800E3050[omCurrentObj->objId] = sp2C;
    D_800EB6A0[omCurrentObj->objId] = 0x2D;
    D_800E9C60[omCurrentObj->objId] = 0;
    D_800E9E20[omCurrentObj->objId] = 0;
    D_800EA6E0[omCurrentObj->objId] = info->scale;
    D_800EA8A0[omCurrentObj->objId] = 0.0f;
    dz = gEntitiesNextPosZArray[omCurrentObj->objId] - gEntitiesNextPosZArray[target];
    D_800EAA60[omCurrentObj->objId] = sqrtf((dz * dz) + (((gEntitiesNextPosXArray[omCurrentObj->objId] - gEntitiesNextPosXArray[target]) * (gEntitiesNextPosXArray[omCurrentObj->objId] - gEntitiesNextPosXArray[target])) + ((gEntitiesNextPosYArray[omCurrentObj->objId] - (gEntitiesNextPosYArray[0] + 20.0f)) * (gEntitiesNextPosYArray[omCurrentObj->objId] - (gEntitiesNextPosYArray[0] + 20.0f)))));
    D_800EAC20[omCurrentObj->objId] = 0.0f;
    D_800E8E60[omCurrentObj->objId] = 1;
    D_800EB4E0[omCurrentObj->objId] = func_801AC6D0_ovl7(info);
    D_800DF310[omCurrentObj->objId] = NULL;
    if (ent->unk34 != NULL) {
        tmp = ent->unk34;
        func_800A22D4(tmp);
    }
    func_800A2300(arg0);
    ent->unk34 = NULL;
    D_800E7B20[omCurrentObj->objId] = 0.0f;
    func_8019B7D8_ovl7(arg0);
    D_800E83E0[omCurrentObj->objId] = 0;
    while (TRUE) {
        if (func_801A8BAC_ovl7() != 0) {
            break;
        }
        ohSleep(1);
    }
    if (D_800E8060[target] == -1) {
        ohSleep(1);
    }
    func_801A9268_ovl7();
    *(s16 *) &D_8012E860[0x1A] = 0;
    func_801A8CDC_ovl7(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ovl7/ovl7_5/func_801A7104_ovl7.s")
#endif
/* FACTORY: 1421/1441 words DIFFER, re-measured 2026-08-25.
   The residue is the FRAME and nothing downstream of it can be read.  Diff 0
   is `addiu $sp, -600` against the ROM's `addiu $sp, -0xB8` (184): m2c has
   turned IDO's spill slots into declarations (LEVER 31), so every stack
   offset in the function is wrong and the positional score is near-total by
   construction (LEVER 48).  Cut the declaration count onto LEVER 57's frame
   law before measuring anything else here.

   LEVER 70 SURVEYED 2026-08-25 -- confirmed present, deliberately NOT applied.
   absf_sweep.py ranks this the second strongest candidate in the tree
   (23 compares / 22 neg.s) and the macro reading is right, but with the frame
   this far off an ABSF edit cannot show up in the score at all.  It is not a
   negative result for the lever; it is an unmeasurable one.  Do the frame
   first, re-measure, and only then convert the abs sites.

   LEVER 117c RESOLVED 2026-08-26: the "second undeclared callee" this draft
   still shows cvt.d.s for is func_801A0D74_ovl7 -- declared s32(GObj *) in
   ovl7_17.c, called here (line ~661) with SIX m2c-invented arguments
   including floats, so K&R promotion doubles them (cvt.d.s at diff words
   749/758 and 939/943). Same class as func_801ABBA0_ovl7's invented third
   argument. When the frame pass happens, fix the call to one GObj* argument
   and declare it at file scope; it cannot be measured before then for the
   same reason as LEVER 70 above. (func_801A8CDC_ovl7's cvt.d.s, the other
   117c leftover, is GONE -- the banked func_800AF408 prototype was its
   second callee.) */
#ifdef NON_MATCHING
void func_801A7524_ovl7(GObj *arg0) {
    s32 spB4;
    s32 spB0;
    f32 spA8;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    struct EnemyRecord *sp88;
    struct EnemyProbe *sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    s32 sp3C;
    GObj *temp_a2;
    f32 *temp_a0;
    f32 *temp_a0_2;
    f32 *temp_a0_4;
    f32 *temp_v1_4;
    f32 *temp_v1_5;
    f32 *temp_v1_6;
    f32 *var_a0;
    f32 *var_a1;
    f32 *var_at;
    f32 *var_v1;
    f32 *var_v1_2;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f12_5;
    f32 temp_f12_6;
    f32 temp_f12_7;
    f32 temp_f12_8;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f2_8;
    f32 temp_f2_9;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f8;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f14;
    f32 var_f14_2;
    f32 var_f14_3;
    f32 var_f14_4;
    f32 var_f16;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f2_4;
    f32 var_f2_5;
    f32 var_f2_6;
    f32 var_f2_7;
    f32 var_f2_8;
    s32 *temp_v1_2;
    s32 *temp_v1_8;
    s32 *temp_v1_9;
    s32 *var_v1_3;
    s32 *var_v1_4;
    s32 temp_a3;
    s32 temp_v0_18;
    s32 temp_v1_7;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    struct EnemyRecord *temp_t8;
    u16 temp_v0;
    struct EneScaleSet *temp_a0_3;
    u32 temp_v0_10;
    u32 temp_v0_11;
    u32 temp_v0_12;
    u32 temp_v0_13;
    u32 temp_v0_14;
    u32 temp_v0_15;
    u32 temp_v0_16;
    u32 temp_v0_17;
    u32 temp_v0_19;
    u32 temp_v0_20;
    u32 temp_v0_21;
    u32 temp_v0_22;
    u32 temp_v0_23;
    u32 temp_v0_24;
    u32 temp_v0_25;
    u32 temp_v0_26;
    u32 temp_v0_27;
    u32 temp_v0_28;
    u32 temp_v0_29;
    u32 temp_v0_2;
    u32 temp_v0_30;
    u32 temp_v0_31;
    u32 temp_v0_32;
    u32 temp_v0_33;
    u32 temp_v0_3;
    u32 temp_v0_4;
    u32 temp_v0_5;
    u32 temp_v0_6;
    u32 temp_v0_7;
    u32 temp_v0_9;
    u32 temp_v1;
    u32 temp_v1_3;
    u32 var_a3;

    temp_v1 = omCurrentObj->objId;
    temp_t8 = D_800E1B50[temp_v1];
    temp_a3 = D_800E0D50[temp_v1];
    spB0 = 0;
    sp88 = temp_t8;
    sp84 = temp_t8->unk84;
    if (D_800E7730[temp_v1] == 6) {
        temp_v0 = D_800E77A0[temp_v1];
        if ((temp_v0 > 0) && (temp_v0 < 0x2C)) {
            spB4 = temp_a3;
            if (func_801C05E0_ovl7(D_800E0D50, temp_a3) != 0) {
                spB0 = 1;
                gKirbyState.numberInhaling -= 1;
            }
        }
    }
    temp_v1_2 = &D_800EB6A0[omCurrentObj->objId];
    *temp_v1_2 -= 1;
    temp_v0_2 = omCurrentObj->objId;
    var_v0 = temp_v0_2 * 4;
    if (D_800EB6A0[temp_v0_2] < 0) {
        spB0 = 1;
        gKirbyState.numberInhaling -= 1;
        var_v0 = omCurrentObj->objId * 4;
    }
    if (D_800E8060[temp_a3] == -1) {
        spB0 = 1;
    }
    *(D_800E6A10 + var_v0) = D_800E6A10[*(D_800E0D50 + var_v0)];
    temp_v0_3 = omCurrentObj->objId;
    if (D_800E6A10[temp_v0_3] == 1.0f) {
        D_800E17D0[temp_v0_3] = D_800E17D0[D_800E0D50[temp_v0_3]];
    } else {
        D_800E17D0[temp_v0_3] = D_800E17D0[D_800E0D50[temp_v0_3]] + 3.1415927f;
    }
    sp3C = temp_a3 * 4;
    if ((sinf(D_800E17D0[omCurrentObj->objId]) * 4.0f) < 0.0f) {
        spA8 = -(sinf(D_800E17D0[omCurrentObj->objId]) * 4.0f);
    } else {
        spA8 = sinf(D_800E17D0[omCurrentObj->objId]) * 4.0f;
    }
    if ((cosf(D_800E17D0[omCurrentObj->objId]) * 4.0f) < 0.0f) {
        var_f16 = -(cosf(D_800E17D0[omCurrentObj->objId]) * 4.0f);
    } else {
        var_f16 = cosf(D_800E17D0[omCurrentObj->objId]) * 4.0f;
    }
    temp_v1_3 = omCurrentObj->objId;
    temp_a0 = &D_800E4FD0[temp_v1_3];
    temp_f12 = D_800EA6E0[temp_v1_3];
    if (temp_f12 < *temp_a0) {
        temp_f0 = (*(&D_800E6F50->originOffset + (temp_v1_3 * 0x10)) - 26.0f) / (D_800EAA60[temp_v1_3] - 26.0f);
        if (temp_f0 < 0.0f) {
            var_f2 = -temp_f0;
        } else {
            var_f2 = temp_f0;
        }
        *temp_a0 = temp_f12 + (var_f2 * (sp88->unk18 - temp_f12));
    } else {
        *temp_a0 = temp_f12;
    }
    temp_v0_4 = omCurrentObj->objId;
    var_v0_2 = temp_v0_4 * 4;
    temp_a0_2 = &D_800E4FD0[temp_v0_4];
    var_f2_2 = *temp_a0_2;
    if (var_f2_2 > 1.0f) {
        *temp_a0_2 = 1.0f;
        temp_v0_5 = omCurrentObj->objId;
        var_v0_2 = temp_v0_5 * 4;
        var_f2_2 = D_800E4FD0[temp_v0_5];
    }
    *(D_800E5350 + var_v0_2) = var_f2_2;
    D_800E5190[omCurrentObj->objId] = var_f2_2;
    gEntitiesScaleZArray[omCurrentObj->objId] = var_f2_2;
    gEntitiesScaleYArray[omCurrentObj->objId] = var_f2_2;
    gEntitiesScaleXArray[omCurrentObj->objId] = var_f2_2;
    temp_v0_6 = omCurrentObj->objId;
    temp_f12_2 = D_800E2250[temp_v0_6];
    if ((temp_f12_2 > 6.0f) || (temp_f12_2 < 10.0f)) {
        var_v1 = &D_800D71E8 + 0x50;
        var_a0 = &D_800D71E8 + 0x54;
        *var_v1 = ((*gEntitiesNextPosYArray + 20.0f + 8.0f) - gEntitiesNextPosYArray[temp_v0_6]) * 0.4f;
        var_f2_3 = *var_v1;
        if (var_f2_3 > 12.0f) {
            *var_v1 = 12.0f;
            goto block_32;
        }
        if (var_f2_3 < -12.0f) {
            *var_v1 = -12.0f;
block_32:
            var_f2_3 = *var_v1;
        }
        if (var_f2_3 < 0.0f) {
            var_a0 = &D_800D71E8 + 0x54;
            *var_a0 = -var_f2_3;
        } else {
            *var_a0 = var_f2_3;
        }
        var_f0 = *var_a0;
    } else {
        var_a0 = &D_800D71E8 + 0x54;
        *var_a0 = 0.0f;
        var_f0 = *var_a0;
        var_v1 = &D_800D71E8 + 0x50;
        *var_v1 = var_f0;
        var_f2_3 = *var_v1;
    }
    D_800E3750[omCurrentObj->objId] = var_f2_3 * 0.3f;
    if (var_f0 < 0.0f) {
        D_800E3C90[omCurrentObj->objId] = -var_f0;
    } else {
        D_800E3C90[omCurrentObj->objId] = var_f0;
    }
    temp_v0_7 = omCurrentObj->objId;
    temp_f0_2 = D_800E2090[temp_v0_7];
    if (temp_f0_2 < 0.0f) {
        var_f2_4 = -temp_f0_2;
    } else {
        var_f2_4 = temp_f0_2;
    }
    if (spA8 < var_f2_4) {
        *var_v1 = (*(sp3C + gEntitiesNextPosXArray) - gEntitiesNextPosXArray[temp_v0_7]) * 0.4f;
        temp_f2 = *var_v1;
        if (temp_f2 > 10.0f) {
            *var_v1 = 10.0f;
        } else if (temp_f2 < -10.0f) {
            *var_v1 = -10.0f;
        }
        if (*var_v1 < 0.0f) {
            *var_a0 = -*var_v1;
        } else {
            *var_a0 = *var_v1;
        }
    } else {
        *var_a0 = 0.0f;
        *var_v1 = *var_a0;
    }
    D_800E3590[omCurrentObj->objId] = *var_v1 * 0.25f;
    if (*var_a0 < 0.0f) {
        D_800E3AD0[omCurrentObj->objId] = -*var_a0;
    } else {
        D_800E3AD0[omCurrentObj->objId] = *var_a0;
    }
    temp_f0_3 = D_800E2410[omCurrentObj->objId];
    if (temp_f0_3 < 0.0f) {
        var_f2_5 = -temp_f0_3;
    } else {
        var_f2_5 = temp_f0_3;
    }
    if (var_f16 < var_f2_5) {
        *var_v1 = (*(gEntitiesNextPosZArray + sp3C) - gEntitiesNextPosZArray[omCurrentObj->objId]) * 0.4f;
        temp_f2_2 = *var_v1;
        if (temp_f2_2 > 10.0f) {
            *var_v1 = 10.0f;
        } else if (temp_f2_2 < -10.0f) {
            *var_v1 = -10.0f;
        }
        if (*var_v1 < 0.0f) {
            *var_a0 = -*var_v1;
        } else {
            *var_a0 = *var_v1;
        }
        var_f0_2 = *(&D_800D71E8 + 0x54);
    } else {
        *var_a0 = 0.0f;
        var_f0_2 = *var_a0;
        *var_v1 = var_f0_2;
    }
    D_800E3910[omCurrentObj->objId] = *var_v1 * 0.25f;
    if (var_f0_2 < 0.0f) {
        D_800E3E50[omCurrentObj->objId] = -var_f0_2;
    } else {
        D_800E3E50[omCurrentObj->objId] = var_f0_2;
    }
    temp_v1_4 = &D_800E4C50[omCurrentObj->objId];
    *temp_v1_4 -= 0.34906587f;
    temp_v0_9 = omCurrentObj->objId;
    var_v0_3 = temp_v0_9 * 4;
    temp_v1_5 = &D_800E4C50[temp_v0_9];
    temp_f0_4 = *temp_v1_5;
    if (temp_f0_4 < 0.0f) {
        *temp_v1_5 = temp_f0_4 + 6.2831855f;
        var_v0_3 = omCurrentObj->objId * 4;
    }
    var_v1_2 = D_800E4E10 + var_v0_3;
    var_f0_3 = *var_v1_2;
    if ((var_f0_3 > 0.69813174f) && (var_f0_3 < 1.5707964f)) {
        *(D_800EA8A0 + var_v0_3) = -0.06981317f;
        temp_v0_10 = omCurrentObj->objId;
        var_v0_3 = temp_v0_10 * 4;
        var_v1_2 = &D_800E4E10[temp_v0_10];
        goto block_83;
    }
    if ((var_f0_3 < 5.585054f) && (var_f0_3 > 1.5707964f)) {
        *(D_800EA8A0 + var_v0_3) = 0.06981317f;
        temp_v0_11 = omCurrentObj->objId;
        var_v0_3 = temp_v0_11 * 4;
        var_v1_2 = &D_800E4E10[temp_v0_11];
block_83:
        var_f0_3 = *var_v1_2;
    }
    *var_v1_2 = var_f0_3 + *(D_800EA8A0 + var_v0_3);
    temp_v0_12 = omCurrentObj->objId;
    gEntitiesAngleYArray[temp_v0_12] = D_800E4C50[temp_v0_12];
    temp_v0_13 = omCurrentObj->objId;
    gEntitiesAngleZArray[temp_v0_13] = D_800E4E10[temp_v0_13];
    temp_a0_3 = (struct EneScaleSet *) sp88->unk88->unk10;
    if ((temp_a0_3 != 0) && (sp84 != NULL)) {
        *(f32 *) &sp84->headOffsetY = D_800E4FD0[omCurrentObj->objId] * 0.9f * temp_a0_3->unk4;
        *(f32 *) &sp84->footOffsetY = D_800E4FD0[omCurrentObj->objId] * 0.9f * ((struct EneScaleSet *) sp88->unk88->unk10)->unk8;
        sp84->forwardReachPos = D_800E4FD0[omCurrentObj->objId] * 0.8f * ((struct EneScaleSet *) sp88->unk88->unk10)->unkC;
        sp84->forwardReachNeg = D_800E4FD0[omCurrentObj->objId] * 0.8f * ((struct EneScaleSet *) sp88->unk88->unk10)->unk10;
    }
    temp_v0_14 = omCurrentObj->objId;
    temp_f0_5 = gEntitiesNextPosXArray[temp_v0_14];
    temp_f2_3 = gEntitiesNextPosYArray[temp_v0_14];
    temp_f12_3 = gEntitiesNextPosZArray[temp_v0_14];
    if (sp84 != NULL) {
        sp8C = temp_f0_5;
        sp90 = temp_f2_3;
        sp94 = temp_f12_3;
        func_801A0D74_ovl7(temp_f12_3, 0.0f, arg0, D_800E4C50, omCurrentObj, D_800E4E10);
    }
    var_a3 = D_8012BCA0 >> 0x13;
    if (((var_a3 & 7) && (var_a3 & 0x38)) || ((var_a3 & 0x1C0) && (var_a3 & 0xE00))) {
        spB0 = 1;
        gKirbyState.numberInhaling -= 1;
    }
    var_a1 = NULL;
    if (spB0 == 1) {
        D_80198820_ovl3 = 0.0f;
        func_800FD570(temp_f12_3, 0, 0.0f, 0.0f, 0.0f);
        play_sound(0x158);
        func_8019D958_ovl7(*(u16 *) ((u8 *) omCurrentObj + 2));
        return;
    }
    temp_a2 = omCurrentObj;
    temp_v0_15 = temp_a2->objId;
    var_v0_4 = temp_v0_15 * 4;
    if (var_a3 & 0xFFF) {
        temp_a0_4 = &D_800E2090[temp_v0_15];
        *temp_a0_4 -= temp_f0_5 - gEntitiesNextPosXArray[temp_v0_15];
        temp_v0_16 = temp_a2->objId;
        temp_v1_6 = &D_800E2250[temp_v0_16];
        *temp_v1_6 -= temp_f2_3 - gEntitiesNextPosYArray[temp_v0_16];
        temp_v0_17 = temp_a2->objId;
        var_a1 = &D_800E2410[temp_v0_17];
        *var_a1 -= temp_f12_3 - gEntitiesNextPosZArray[temp_v0_17];
        var_v0_4 = temp_a2->objId * 4;
    }
    var_v1_3 = D_800E9C60 + var_v0_4;
    if (*(D_800EB6A0 + var_v0_4) < 0x2A) {
        var_a0_2 = *var_v1_3;
        if (var_a0_2 == 0) {
            temp_f0_6 = *(gEntitiesPosXArray + var_v0_4);
            temp_f12_4 = *(gEntitiesNextPosXArray + var_v0_4);
            if (temp_f12_4 < temp_f0_6) {
                var_f2_6 = -(temp_f12_4 - temp_f0_6);
            } else {
                var_f2_6 = temp_f12_4 - temp_f0_6;
            }
            if (var_f2_6 < 0.5f) {
                temp_f0_7 = *(gEntitiesNextPosYArray + var_v0_4);
                temp_f2_4 = *(f32 *) ((u8 *) gEntitiesPosYArray + var_v0_4);
                if (temp_f0_7 < temp_f2_4) {
                    var_f14 = -(temp_f0_7 - temp_f2_4);
                } else {
                    var_f14 = temp_f0_7 - temp_f2_4;
                }
                if (var_f14 < 0.5f) {
                    temp_f0_8 = *(gEntitiesNextPosZArray + var_v0_4);
                    temp_f2_5 = *(f32 *) ((u8 *) gEntitiesPosZArray + var_v0_4);
                    if (temp_f0_8 < temp_f2_5) {
                        var_f14_2 = -(temp_f0_8 - temp_f2_5);
                    } else {
                        var_f14_2 = temp_f0_8 - temp_f2_5;
                    }
                    if ((var_f14_2 < 0.5f) && (var_a3 & 0x3F)) {
                        sp78 = temp_f12_4;
                        temp_f8 = gEntitiesNextPosYArray[temp_a2->objId];
                        sp7C = temp_f8;
                        temp_f4 = gEntitiesNextPosZArray[temp_a2->objId];
                        sp80 = temp_f4;
                        temp_f12_5 = gEntitiesNextPosXArray[temp_a2->objId];
                        temp_f4_2 = ((*(gEntitiesNextPosXArray + sp3C) - temp_f12_5) * 0.5f) + temp_f12_5;
                        sp6C = temp_f4_2;
                        sp70 = gEntitiesNextPosYArray[temp_a2->objId];
                        temp_f0_9 = gEntitiesNextPosZArray[temp_a2->objId];
                        temp_f6 = ((*(gEntitiesNextPosZArray + sp3C) - temp_f0_9) * 0.5f) + temp_f0_9;
                        sp74 = temp_f6;
                        sp60 = temp_f4_2 - sp78;
                        sp64 = sp70 - temp_f8;
                        sp68 = temp_f6 - temp_f4;
                        lbvector_Normalize(temp_f12_5, var_f14_2, &sp60, var_a1, temp_a2, var_a3);
                        temp_f4_3 = gEntitiesNextPosYArray[omCurrentObj->objId] + *(f32 *) &sp84->headOffsetY;
                        sp70 = temp_f4_3;
                        sp7C = temp_f4_3;
                        if (func_8010423C(&sp78, &sp6C, &sp60, 0, 0, 0, 0, 0) != 0) {
                            D_8012BCA0 = (((D_8012BCA0 >> 0x13) | 0x12) * 8) | (D_8012BCA0 & 7);
                        }
                        temp_f6_2 = gEntitiesNextPosYArray[omCurrentObj->objId] + *(f32 *) &sp84->footOffsetY;
                        sp70 = temp_f6_2;
                        sp7C = temp_f6_2;
                        if (func_8010423C(&sp78, &sp6C, &sp60, 0, 0, 0, 0, 0) != 0) {
                            D_8012BCA0 = (((D_8012BCA0 >> 0x13) | 0x24) * 8) | (D_8012BCA0 & 7);
                        }
                        var_a3 = D_8012BCA0 >> 0x13;
                        temp_v0_18 = var_a3 & 2;
                        if (((temp_v0_18 != 0) && !(var_a3 & 4)) || ((temp_v1_7 = var_a3 & 0x10, (temp_v1_7 != 0)) && !(var_a3 & 0x20))) {
                            D_800E9C60[omCurrentObj->objId] = 0xE;
                            D_800EAC20[omCurrentObj->objId] = -1.0f;
                            temp_v0_19 = omCurrentObj->objId;
                            var_v0_4 = temp_v0_19 * 4;
                            var_v1_3 = &D_800E9C60[temp_v0_19];
                        } else if (((temp_v0_18 == 0) && (var_a3 & 4)) || ((temp_v1_7 == 0) && (var_a3 & 0x20))) {
                            D_800E9C60[omCurrentObj->objId] = 0xE;
                            D_800EAC20[omCurrentObj->objId] = 1.0f;
                            temp_v0_20 = omCurrentObj->objId;
                            var_v0_4 = temp_v0_20 * 4;
                            var_v1_3 = &D_800E9C60[temp_v0_20];
                        } else {
                            temp_v0_21 = omCurrentObj->objId;
                            if (gEntitiesNextPosYArray[temp_v0_21] < (*gEntitiesNextPosYArray + 20.0f + 8.0f)) {
                                D_800E9C60[temp_v0_21] = 0xE;
                                D_800EAC20[omCurrentObj->objId] = 1.0f;
                                temp_v0_22 = omCurrentObj->objId;
                                var_v0_4 = temp_v0_22 * 4;
                                var_v1_3 = &D_800E9C60[temp_v0_22];
                            } else {
                                D_800E9C60[temp_v0_21] = 0xE;
                                D_800EAC20[omCurrentObj->objId] = -1.0f;
                                temp_v0_23 = omCurrentObj->objId;
                                var_v0_4 = temp_v0_23 * 4;
                                var_v1_3 = &D_800E9C60[temp_v0_23];
                            }
                        }
                        var_a0_2 = *var_v1_3;
                    }
                }
            }
        }
        if (var_a0_2 > 0) {
            if (var_a3 & 0x3F) {
                if (var_a0_2 > 7.0f) {
                    *(D_800E3210 + var_v0_4) = *(D_800EAC20 + var_v0_4) * (0x10 - var_a0_2);
                    temp_v0_24 = temp_a2->objId;
                    D_800E3C90[temp_v0_24] = 0x10 - D_800E9C60[temp_v0_24];
                } else {
                    *(D_800E3210 + var_v0_4) = *(D_800EAC20 + var_v0_4) * (var_a0_2 + 2);
                    temp_v0_25 = temp_a2->objId;
                    D_800E3C90[temp_v0_25] = D_800E9C60[temp_v0_25] + 2;
                }
                temp_v1_8 = &D_800E9C60[temp_a2->objId];
                *temp_v1_8 -= 1;
            } else {
                *var_v1_3 = 0;
            }
            var_v0_4 = temp_a2->objId * 4;
        }
        var_v1_4 = var_v0_4 + D_800E9E20;
        var_a0_3 = *var_v1_4;
        if (var_a0_3 == 0) {
            temp_f12_6 = *(gEntitiesNextPosXArray + var_v0_4);
            temp_f0_10 = *(gEntitiesPosXArray + var_v0_4);
            temp_f14 = temp_f12_6 - temp_f0_10;
            if (temp_f12_6 < temp_f0_10) {
                var_f2_7 = -temp_f14;
            } else {
                var_f2_7 = temp_f14;
            }
            if (var_f2_7 < 0.5f) {
                temp_f0_11 = *(gEntitiesNextPosYArray + var_v0_4);
                temp_f2_6 = *(gEntitiesPosYArray + var_v0_4);
                temp_f12_7 = temp_f0_11 - temp_f2_6;
                if (temp_f0_11 < temp_f2_6) {
                    var_f14_3 = -temp_f12_7;
                } else {
                    var_f14_3 = temp_f12_7;
                }
                if (var_f14_3 < 0.5f) {
                    temp_f0_12 = *(gEntitiesNextPosZArray + var_v0_4);
                    temp_f2_7 = *(gEntitiesPosZArray + var_v0_4);
                    temp_f12_8 = temp_f0_12 - temp_f2_7;
                    if (temp_f0_12 < temp_f2_7) {
                        var_f14_4 = -temp_f12_8;
                    } else {
                        var_f14_4 = temp_f12_8;
                    }
                    if ((var_f14_4 < 0.5f) && (var_a3 & 0xFC0)) {
                        *var_v1_4 = 4;
                        temp_v0_26 = temp_a2->objId;
                        var_v0_4 = temp_v0_26 * 4;
                        var_v1_4 = &D_800E9E20[temp_v0_26];
                        var_a0_3 = *var_v1_4;
                    }
                }
            }
        }
        if (var_a0_3 > 0) {
            if (var_a3 & 0xFC0) {
                temp_f0_13 = var_a0_3;
                if (temp_f0_13 > 2.0f) {
                    sp5C = -*(D_800E6A10 + var_v0_4) * (2.0f * (5 - var_a0_3));
                    D_800E3050[omCurrentObj->objId] = sinf(*(D_800E17D0 + var_v0_4)) * sp5C;
                    temp_v0_27 = omCurrentObj->objId;
                    temp_f2_8 = D_800E3050[temp_v0_27];
                    if (temp_f2_8 < 0.0f) {
                        D_800E3AD0[temp_v0_27] = -temp_f2_8;
                    } else {
                        D_800E3AD0[temp_v0_27] = temp_f2_8;
                    }
                    D_800E33D0[omCurrentObj->objId] = cosf(D_800E17D0[omCurrentObj->objId]) * sp5C;
                    temp_v0_28 = omCurrentObj->objId;
                    var_f2_8 = D_800E33D0[temp_v0_28];
                    var_at = &D_800E3E50[temp_v0_28];
                    if (var_f2_8 < 0.0f) {
                        D_800E3E50[temp_v0_28] = -var_f2_8;
                    } else {
                        goto block_168;
                    }
                } else {
                    sp5C = *(D_800E6A10 + var_v0_4) * (2.0f * temp_f0_13);
                    D_800E3050[omCurrentObj->objId] = sinf(*(D_800E17D0 + var_v0_4)) * sp5C;
                    temp_v0_29 = omCurrentObj->objId;
                    temp_f2_9 = D_800E3050[temp_v0_29];
                    if (temp_f2_9 < 0.0f) {
                        D_800E3AD0[temp_v0_29] = -temp_f2_9;
                    } else {
                        D_800E3AD0[temp_v0_29] = temp_f2_9;
                    }
                    D_800E33D0[omCurrentObj->objId] = cosf(D_800E17D0[omCurrentObj->objId]) * sp5C;
                    temp_v0_30 = omCurrentObj->objId;
                    var_f2_8 = D_800E33D0[temp_v0_30];
                    var_at = &D_800E3E50[temp_v0_30];
                    if (var_f2_8 < 0.0f) {
                        D_800E3E50[temp_v0_30] = -var_f2_8;
                    } else {
block_168:
                        *var_at = var_f2_8;
                    }
                }
                temp_v1_9 = &D_800E9E20[omCurrentObj->objId];
                *temp_v1_9 -= 1;
                temp_v0_31 = omCurrentObj->objId;
                if (D_800E9E20[temp_v0_31] == 0) {
                    gEntitiesPosXArray[temp_v0_31] = gEntitiesNextPosXArray[temp_v0_31];
                    temp_v0_32 = omCurrentObj->objId;
                    gEntitiesPosYArray[temp_v0_32] = gEntitiesNextPosYArray[temp_v0_32];
                    temp_v0_33 = omCurrentObj->objId;
                    gEntitiesPosZArray[temp_v0_33] = gEntitiesNextPosZArray[temp_v0_33];
                }
            } else {
                *var_v1_4 = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ovl7/ovl7_5/func_801A7524_ovl7.s")
#endif
/* MATCHED 2026-08-24. The two-word residue sealed here (the compiler spill at
 * 0x18($sp) where the ROM has 0x1C) was NOT reachable by adding a pad, and the
 * old note was right that every pad grows the frame -- but it was looking in
 * the wrong direction. Measured on this function, with n = the number of
 * DECLARED scalars (register-allocated ones included, they are not free):
 *     frame     = align8(0x1C + 4n + 4)
 *     spill slot = frame - 4n - 8
 * so n=4 gives frame 0x30 / spill 0x18 and n=5 gives 0x38 / 0x1C -- which is
 * why every pad moved the spill and the frame together. n=3 gives the ROM's
 * 0x30 / 0x1C. The fix was therefore to DELETE a declaration, not add one:
 * temp_f0's last read is inside the sqrtf argument, so the sqrt result reuses
 * it and the separate temp_f4 disappears. */
s32 func_801A8BAC_ovl7(void) {
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_a0;

    temp_a0 = D_800E0D50[omCurrentObj->objId];
    if (D_800E6F50[omCurrentObj->objId].originOffset < 50.0f) {
        temp_f0 = gEntitiesNextPosZArray[omCurrentObj->objId] - gEntitiesNextPosZArray[temp_a0];
        temp_f2 = gEntitiesNextPosXArray[omCurrentObj->objId] - gEntitiesNextPosXArray[temp_a0];
        temp_f0 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
        D_80198820_ovl3 = -func_800A52F0(gEntitiesNextPosYArray[omCurrentObj->objId] - (gEntitiesNextPosYArray[temp_a0] + 28.0f), temp_f0);
    }
    if (D_800E6F50[omCurrentObj->objId].originOffset < 26.0f) {
        return 1;
    }
    return 0;
}
void func_801A8CDC_ovl7(GObj *arg0) {
    struct EnemyRecord *rec;
    struct SubSub800E1B50_Unk88_UnkC *ptr;
    struct SubSub800E1B50_Unk88_UnkC_Unk0 *info;
    struct Sub800E1B50_Unk34 *tmp;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;

    rec = D_800E1B50[omCurrentObj->objId];
    ptr = rec->unk88->unkC;
    info = ptr->unk0;
    D_800DEF90[omCurrentObj->objId] = func_800B4D70;
    D_800DF150[omCurrentObj->objId] = func_801A8FFC_ovl7;
    D_800DDA90[omCurrentObj->objId] = 0x23;
    func_800AFBB4(0, omCurrentObj);
    func_800AECC0(0.0f);
    func_800AED20(0.0f);
    if (rec->unk34 != NULL) {
        tmp = rec->unk34;
        func_800A22D4(tmp);
    }
    func_800A2300(arg0);
    rec->unk34 = NULL;
    D_800E2090[omCurrentObj->objId] = 0.0f;
    D_800E2250[omCurrentObj->objId] = 0.0f;
    D_800E2410[omCurrentObj->objId] = 0.0f;
    D_800E4E10[omCurrentObj->objId] = 0.0f;
    D_800E4C50[omCurrentObj->objId] = D_800E4E10[omCurrentObj->objId];
    D_800EA6E0[omCurrentObj->objId] = info->scale;
    f1 = D_800EA6E0[omCurrentObj->objId];
    gEntitiesScaleZArray[omCurrentObj->objId] = f1;
    gEntitiesScaleYArray[omCurrentObj->objId] = f1;
    gEntitiesScaleXArray[omCurrentObj->objId] = f1;
    D_800E5350[omCurrentObj->objId] = 1.0f;
    f2 = D_800E5350[omCurrentObj->objId];
    D_800E5190[omCurrentObj->objId] = f2;
    D_800E4FD0[omCurrentObj->objId] = f2;
    D_800E3910[omCurrentObj->objId] = 0.0f;
    f3 = D_800E3910[omCurrentObj->objId];
    D_800E3750[omCurrentObj->objId] = f3;
    D_800E3590[omCurrentObj->objId] = f3;
    D_800E33D0[omCurrentObj->objId] = f3;
    D_800E3210[omCurrentObj->objId] = f3;
    D_800E3050[omCurrentObj->objId] = f3;
    D_800E3E50[omCurrentObj->objId] = 65535.0f;
    f4 = D_800E3E50[omCurrentObj->objId];
    D_800E3C90[omCurrentObj->objId] = f4;
    D_800E3AD0[omCurrentObj->objId] = f4;
    D_800E8E60[omCurrentObj->objId] = 1;
    D_800E8220[omCurrentObj->objId] = 0;
    *(s32 *) &D_8012E860[0xC] = 0;
    func_800AF408();
    curObjSleepForever();
}
#ifdef NON_MATCHING
/* FACTORY: 0/155 words, MATCH; keep guarded until func_801A96C4_ovl7 is C (its void decl clashes with func_801AC4EC's implicit call) */
void func_801A8FFC_ovl7(GObj *arg0) {
    void func_801AA914_ovl7(GObj *);
    void func_801A96C4_ovl7(GObj *);
    struct EnemyRecord *ent;
    struct SubSub800E1B50_Unk88_UnkC *cc;
    struct SubSub800E1B50_Unk88_UnkC_Unk0 *info;
    struct SubSub800E1B50_Unk88_UnkC_Unk4 *anim;
    s32 var;

    ent = D_800E1B50[omCurrentObj->objId];
    cc = ent->unk88->unkC;
    info = cc->unk0;
    anim = cc->unk4;
    switch (gKirbyState.unkD) {
        case 6:
            var = 1;
            break;
        case 7:
            var = 2;
            break;
        case 1:
            do { } while (0);
        case 2:
            D_800EA6E0[omCurrentObj->objId] = anim->unk10;
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801A96C4_ovl7);
            return;
        case -3:
            var = 3;
            break;
        default:
            gEntitiesScaleXArray[omCurrentObj->objId] = gEntitiesScaleYArray[omCurrentObj->objId] = gEntitiesScaleZArray[omCurrentObj->objId] = D_800EA6E0[omCurrentObj->objId] = info->scale;
            var = 0;
            break;
    }
    if ((gKirbyState.numberInhaled >= 2) && ((D_800E7730[omCurrentObj->objId] != 6) || (D_800E77A0[omCurrentObj->objId] < 8) || (D_800E77A0[omCurrentObj->objId] >= 0x2C) || (D_800D7090 != omCurrentObj->objId))) {
        var = 2;
    }
    if (var == 1) {
        if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] >= 8) && (D_800E77A0[omCurrentObj->objId] < 0x2C)) {
            gKirbyState.numberInhaled = 0;
            if (gKirbyState.unk8 == 0) {
                assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AA914_ovl7);
                return;
            }
        }
        if (gKirbyState.numberInhaled < 2) {
            gKirbyState.numberInhaled = 0;
            if (gKirbyState.unk8 == 0) {
                assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AA914_ovl7);
            }
        }
    } else if (var == 2) {
        func_8019D958_ovl7((u16) omCurrentObj->objId);
    } else if (var == 3) {
        func_8019D958_ovl7((u16) omCurrentObj->objId);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ovl7/ovl7_5/func_801A8FFC_ovl7.s")
#endif

void func_801A9268_ovl7(void) {
    extern u8 D_800D6C90[];
    struct EnemyRecord *rec;
    struct SubSub800E1B50_Unk88_UnkC *cc;
    u8 idx;
    struct SubSub800E1B50_Unk88_UnkC_Unk0 *info;

    rec = D_800E1B50[omCurrentObj->objId];
    cc = rec->unk88->unkC;
    info = cc->unk0;
    gKirbyState.numberInhaled++;
    if ((info != NULL) && (*(s32 *) (rec = (struct EnemyRecord *) info->unk1C) != 0)) {
        gKirbyState.unk8++;
    }
    if (gKirbyState.numberInhaled == 1) {
        gKirbyState.isHoldingEntity = 0;
        gKirbyState.inhaledEntityData = D_800E76C0[omCurrentObj->objId] << 24;
        gKirbyState.inhaledEntityData |= D_800E7730[omCurrentObj->objId] << 16;
        gKirbyState.inhaledEntityData |= D_800E77A0[omCurrentObj->objId] << 8;
        gKirbyState.inhaledEntityData |= D_800E7880[omCurrentObj->objId];
    }
    if (gKirbyState.firstInhale == 0) {
        gKirbyState.firstInhale = info->unk1C->unk4;
    } else if (gKirbyState.secondInhale == 0) {
        gKirbyState.secondInhale = info->unk1C->unk4;
    } else if (((s32) gKirbyState.firstInhale < 8) && (info->unk1C->unk4 >= 8)) {
        gKirbyState.firstInhale = info->unk1C->unk4;
    }
    func_801A94D8_ovl7();
    if (gKirbyState.numberInhaled != gKirbyState.numberInhaling) {
        D_80198820_ovl3 = 0.0f;
    }
    gEntitiesScaleXArray[omCurrentObj->objId] = info->scale;
    gEntitiesScaleYArray[omCurrentObj->objId] = info->scale;
    gEntitiesScaleZArray[omCurrentObj->objId] = info->scale;
    idx = D_800E76C0[omCurrentObj->objId];
    if (idx < 0x40) {
        if (D_801290E0[idx].unk5 & 1) {
            D_800D6C90[idx] &= 0x80;
        }
    }
    D_800E76C0[omCurrentObj->objId] = 0xFF;
    func_8019BB58_ovl7();
    func_800A2300(D_800DE350[omCurrentObj->objId]);
}
s32 func_801A94D8_ovl7(void) {
    struct EnemyRecord *ent;
    struct SubSub800E1B50_Unk88_UnkC *temp_a0;
    struct SubSub800E1B50_Unk88_UnkC_Unk0 *temp_a1;
    struct SubSub800E1B50_Unk88_UnkC_Unk0_Unk1C *temp_a2;
    u32 temp_v0;

    temp_v0 = omCurrentObj->objId;
    ent = D_800E1B50[temp_v0];
    temp_a0 = ent->unk88->unkC;
    temp_a1 = temp_a0->unk0;
    temp_a2 = temp_a1->unk1C;
    if (temp_a2 != NULL) {
        if (temp_a2->unk8 != 0.0f) {
            *(f32 *)&gKirbyState.unk84 = *(f32 *)&gKirbyState.unk84 + temp_a2->unk8;
            return 1;
        }
    }
    if ((D_800E7730[temp_v0] == 3) && (D_800E77A0[temp_v0] == 5)) {
        gKirbyState.unk8C |= 1;
        return 1;
    }
    if ((D_800E7730[temp_v0] == 3) && (D_800E77A0[temp_v0] == 9)) {
        gKirbyState.unk88 += 1;
        return 1;
    }
    if ((D_800E7730[temp_v0] == 3) && (D_800E77A0[temp_v0] == 7)) {
        gKirbyState.unk8C |= 2;
        return 1;
    }
    return 0;
}

void func_801A9610_ovl7(GObj *gobj) {
}

void func_801A9618_ovl7(GObj *gobj) {
    func_80199568_ovl7();
    func_8019BB58_ovl7();
    gKirbyState.inhaledEntityData = D_800E76C0[omCurrentObj->objId] << 0x18;
    gKirbyState.inhaledEntityData |= D_800E7730[omCurrentObj->objId] << 0x10;
    gKirbyState.inhaledEntityData |= D_800E77A0[omCurrentObj->objId] << 8;
    gKirbyState.inhaledEntityData |= D_800E7880[omCurrentObj->objId];
    func_801A8CDC_ovl7(gobj);
}

#ifdef NON_MATCHING
/* FACTORY: 29/155 words, v0/v1 swap of var_v1 vs objId*4 throughout (xor-0 forces the ROM's a0 copy) */
void func_801A96C4_ovl7(GObj *arg0) {
    struct EnemyRecord *rec;
    struct EneInfo *info;
    struct EneVtable *vt;
    s32 var_v1;

    rec = D_800E1B50[omCurrentObj->objId];
    info = ((struct EneAnimSetup *) rec->unk88->unkC->unk4)->unk1C;
    vt = info->unk14;
    D_800DF150[omCurrentObj->objId] = func_801A9930_ovl7;
    func_801AA344_ovl7(arg0);
    switch (D_8012E860[0x18]) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 9:
            break;
        case 5:
        case 6:
        case 7:
        case 8:
            func_801A9FC4_ovl7(arg0);
            break;
    }
    func_801AA850_ovl7(vt);
    while (TRUE) {
        if (vt != NULL) {
            func_801AA78C_ovl7(vt);
        }
        D_800E9C60[omCurrentObj->objId] = D_800E8920[D_800E0D50[omCurrentObj->objId]];
        D_800E9E20[omCurrentObj->objId] = D_800E8AE0[D_800E0D50[omCurrentObj->objId]] & 6;
        var_v1 = D_800E0D50[omCurrentObj->objId];
        do {
            if (func_800AA8E4(var_v1 ^ 0, 0x20007) != 0) {
                D_800E0F10[omCurrentObj->objId] = 0xE;
            } else {
                D_800E0F10[omCurrentObj->objId] = 0x10;
            }
            ohSleep(1);
            var_v1 = ((u32) D_800DD8D0[omCurrentObj->objId] >> 0x1E) ? 1 : 0;
            if (var_v1 != 0) {
                break;
            }
            var_v1 = D_800E0D50[omCurrentObj->objId];
            if (D_800E9C60[omCurrentObj->objId] != D_800E8920[var_v1]) {
                break;
            }
        } while (D_800E9E20[omCurrentObj->objId] == (D_800E8AE0[var_v1] & 6));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ovl7/ovl7_5/func_801A96C4_ovl7.s")
#endif
#ifdef NON_MATCHING
/* FACTORY: 246/422 words, same frame and mnemonic stream bar entry/tail scheduling; reg naming (omCurrentObj t0, gKirbyState t5) */
void func_801A9930_ovl7(s32 arg0) {
    struct EnemyRecord *rec;
    struct SubSub800E1B50_Unk88_UnkC *cc;
    struct EneAnimSetup *setup;
    struct SubSub800E1B50_Unk88_UnkC_Unk0 *info;
    struct EneInfo *ei;
    struct EneVtable *vt;
    struct EnemyProbe *probe;
    s32 id;

    rec = D_800E1B50[omCurrentObj->objId];
    cc = rec->unk88->unkC;
    setup = (struct EneAnimSetup *) cc->unk4;
    info = cc->unk0;
    ei = setup->unk1C;
    vt = ei->unk14;
    probe = rec->unk84;
    if (D_800E83E0[omCurrentObj->objId] != 0) {
        gKirbyState.unkD = -2;
        if (D_800E83E0[omCurrentObj->objId] == 0x12) {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC33C_ovl7);
        } else {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC448_ovl7);
        }
        return;
    }
    switch (gKirbyState.unkD) {
        case 4:
            D_800EA6E0[omCurrentObj->objId] = setup->unk10;
            break;
        case 5:
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AA1D4_ovl7);
            return;
        case 3:
            if (setup->unk10 == gEntitiesScaleXArray[omCurrentObj->objId]) {
                D_800EA6E0[omCurrentObj->objId] = info->scale;
            }
            break;
        case -1:
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801A8CDC_ovl7);
            gKirbyState.currentInhale = cc->unk0->unk1C->unk4;
            return;
        case 8:
            if (func_801AA190_ovl7() != 0) {
                return;
            }
            break;
        case -3:
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC448_ovl7);
            return;
        case 1:
            if (info->scale == gEntitiesScaleXArray[omCurrentObj->objId]) {
                D_800EA6E0[omCurrentObj->objId] = setup->unk10;
            }
            break;
        case -2:
        case 0:
        case 2:
        case 6:
        case 7:
        default:
            gEntitiesScaleXArray[omCurrentObj->objId] = gEntitiesScaleYArray[omCurrentObj->objId] = gEntitiesScaleZArray[omCurrentObj->objId] = D_800EA6E0[omCurrentObj->objId] = setup->unk10;
            break;
    }
    if ((gKirbyState.unkD == 2) && (D_801D0AA4_ovl7 != -1) && (--D_801D0AA4_ovl7 <= 0)) {
        gKirbyState.unkD = -2;
        if (vt->unk44 == NULL) {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC448_ovl7);
        } else {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], vt->unk44);
        }
        return;
    }
    gEntitiesAngleYArray[omCurrentObj->objId] = gEntitiesAngleYArray[D_800E0D50[omCurrentObj->objId]];
    D_800E5F90[omCurrentObj->objId] = D_800E5F90[D_800E0D50[omCurrentObj->objId]];
    D_800E6BD0[omCurrentObj->objId] = D_800E6BD0[D_800E0D50[omCurrentObj->objId]];
    if ((gKirbyState.unkD == 3) && ((D_800EA6E0[omCurrentObj->objId] - 0.001f) < gEntitiesScaleXArray[omCurrentObj->objId])) {
        gEntitiesScaleXArray[omCurrentObj->objId] -= (setup->unk10 - info->scale) / 5.0f;
    }
    if ((gKirbyState.unkD == 1) && (gEntitiesScaleXArray[omCurrentObj->objId] < (D_800EA6E0[omCurrentObj->objId] + 0.001f))) {
        gEntitiesScaleXArray[omCurrentObj->objId] += (setup->unk10 - info->scale) / 5.0f;
    }
    gEntitiesScaleYArray[omCurrentObj->objId] = gEntitiesScaleZArray[omCurrentObj->objId] = gEntitiesScaleXArray[omCurrentObj->objId];
    if ((vt != NULL) && (vt->unk3C != NULL)) {
        vt->unk3C(arg0, D_800E0D50, D_800E5F90, D_800E6BD0);
    }
    D_800E6A10[omCurrentObj->objId] = D_800E6A10[D_800E0D50[omCurrentObj->objId]];
    if (D_800E6A10[omCurrentObj->objId] == 1.0f) {
        D_800E17D0[omCurrentObj->objId] = D_800E17D0[D_800E0D50[omCurrentObj->objId]];
    } else {
        D_800E17D0[omCurrentObj->objId] = D_800E17D0[D_800E0D50[omCurrentObj->objId]] + 3.1415927f;
    }
    if ((gKirbyState.unkD == 2) && ((gKirbyState.action != 0x1D) || (gKirbyState.unkB != 1)) && (gKirbyState.unkB != 2)) {
        if (func_801A0D74_ovl7(arg0) != 0) {
            func_801A3938(&D_801CAFCC_ovl7);
            func_801A36CC(&func_801A3864_ovl7);
        }
        if (D_800E8920[omCurrentObj->objId] == 1) {
            D_800E8920[omCurrentObj->objId] = 0;
        }
        func_80111C4C(func_801117BC(&D_801D0A78_ovl7, id = omCurrentObj->objId));
        return;
    }
    if (probe != NULL) {
        probe->posX = gEntitiesNextPosXArray[omCurrentObj->objId];
        probe->posY = gEntitiesNextPosYArray[omCurrentObj->objId];
        probe->posZ = gEntitiesNextPosZArray[omCurrentObj->objId];
        func_801051AC(probe);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ovl7/ovl7_5/func_801A9930_ovl7.s")
#endif
// m2c draft, measured 47/117 diffs
void func_801A9FC4_ovl7(GObj *arg0) {
    struct EnemyRecord *rec;
    struct EneInfo *vt;
    s32 temp_s4;
    s32 temp_s5;

    rec = D_800E1B50[omCurrentObj->objId];
    vt = ((struct EneAnimSetup *) rec->unk88->unkC->unk4)->unk1C;
    temp_s4 = (s32) vt->unk14;
    func_800AF408();
    func_800A9D64(omCurrentObj->objId);
    temp_s5 = temp_s4 + 0x20;
    func_801AA690_ovl7(temp_s5);
loop_1:
    if (func_800AA8E4(D_800E0D50[omCurrentObj->objId], 0x20007) != 0) {
        D_800E0F10[omCurrentObj->objId] = 0xE;
    } else {
        D_800E0F10[omCurrentObj->objId] = 0x10;
    }
    switch (gKirbyState.unkB8) {                    /* irregular */
        case 5:
            if (gKirbyState.action == 0x14) {
                func_801AA600_ovl7(temp_s4 + 0x2C);
            } else {
                func_801AA600_ovl7(temp_s5);
            }
            break;
        case 6:
        case 7:
        case 8:
            if (gKirbyState.action == 0x14) {
                func_801AA600_ovl7(temp_s4 + 0x14);
            } else {
                func_801AA600_ovl7(temp_s5);
            }
            break;
    }
    ohSleep(1);
    goto loop_1;
}
s32 func_801AA190_ovl7(void) {
    assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AB5A4_ovl7);
    return 1;
}

void func_801AA1D4_ovl7(GObj *gobj) {
    struct EnemyRecord *rec;
    struct SubSub800E1B50_Unk88_UnkC *ptr;
    struct EneAnimSetup *anim;
    struct EneInfo *vt;
    struct EneVtable *sp1C;
    struct Sub800E1B50_Unk34 *tmp;

    rec = D_800E1B50[omCurrentObj->objId];
    ptr = rec->unk88->unkC;
    anim = (struct EneAnimSetup *)ptr->unk4;
    vt = ((struct EneAnimSetup *)rec->unk88->unkC->unk4)->unk1C;
    sp1C = vt->unk14;
    D_800DF150[omCurrentObj->objId] = func_801AA33C_ovl7;
    func_800AF408();
    D_800DF310[omCurrentObj->objId] = NULL;
    if (rec->unk34 != NULL) {
        tmp = rec->unk34;
        func_800A22D4(tmp);
    }
    func_800A2300(gobj);
    D_801D0A98_ovl7 = D_801D0A9C_ovl7 = D_801D0AA0_ovl7 = 0;
    D_801D0AA8_ovl7 = 0;
    rec->unk34 = NULL;
    D_8012E860[0x18] = 0;
    gEntitiesScaleXArray[omCurrentObj->objId] = anim->unk10;
    gEntitiesScaleYArray[omCurrentObj->objId] = anim->unk10;
    gEntitiesScaleZArray[omCurrentObj->objId] = anim->unk10;
    if (sp1C != NULL) {
        if (sp1C->unk40 != NULL) {
            sp1C->unk40(gobj);
            return;
        }
    }
    func_801AB174_ovl7(gobj);
}
void func_801AA33C_ovl7(GObj *gobj) {
}

void func_801AA344_ovl7(GObj *arg0) {
    struct EnemyRecord *rec;
    struct EneInfo *info;
    struct SubSub800E1B50_Unk88_UnkC *cc;
    struct EneAnimSetup *setup;
    struct EneVtable *vt;

    rec = D_800E1B50[omCurrentObj->objId];
    cc = rec->unk88->unkC;
    setup = (struct EneAnimSetup *) cc->unk4;
    info = setup->unk1C;
    vt = info->unk14;
    D_800DEF90[omCurrentObj->objId] = func_800B799C;
    func_801A2558_ovl7(info->unk10);
    rec->unk98 = (struct EnemyEventTable *) &D_801CD240_ovl7;
    D_800E8920[omCurrentObj->objId] = 0;
    D_800E8E60[omCurrentObj->objId] = 1;
    func_800AFBB4(1, omCurrentObj);
    func_800AECC0(2.0f);
    func_800AED20(2.0f);
    D_800DDA90[omCurrentObj->objId] = 0x23;
    D_800E0D50[omCurrentObj->objId] = 0;
    D_800EA6E0[omCurrentObj->objId] = setup->unk10;
    rec->unk40 = 0;
    *(s8 *) &rec->unk38 = -1;
    rec->unk39 = -1;
    D_800E2250[omCurrentObj->objId] = info->unk4;
    func_801AC6D0_ovl7(setup);
    D_800E0F10[omCurrentObj->objId] = 0xE;
    D_801D0A98_ovl7 = D_801D0A9C_ovl7 = D_801D0AA0_ovl7 = 0;
    D_801D0AA8_ovl7 = 0;
    rec->unk34 = NULL;
    D_801D0AA4_ovl7 = info->unk0;
    D_801D0A78_ovl7 = *info->unkC;
    if (cc->unk0->unk1C->unk4 != 0) {
        D_801D0A78_ovl7.unk1C = cc->unk0->unk1C->unk4;
    }
    if (vt != NULL) {
        gKirbyState.unkB8 = vt->unk0;
        gKirbyState.unkBC = *(f32 *) &vt->unk4;
        gKirbyState.unkC0 = *(f32 *) &vt->unk8;
        gKirbyState.unkC4 = *(f32 *) &vt->unkC;
        gKirbyState.unkC8 = *(f32 *) &vt->unk10;
        gKirbyState.unkB9 = vt->unk1;
    } else {
        gKirbyState.unkB8 = 0;
    }
    D_800E83E0[omCurrentObj->objId] = 0;
    gKirbyState.numberInhaled = 1;
    ((u32 *) D_800E8220)[omCurrentObj->objId] = 1;
    gKirbyState.isHoldingEntity = 1;
    gKirbyState.unkE = info->unk8;
}
void func_801AA600_ovl7(struct AnimReq *arg0) {
    if (arg0->unk0 != -1) {
        func_800A9EA4(arg0->unk0);
        func_800AECC0(arg0->unk8);
        if (arg0->unk4 != -1) {
            func_800A9EA4(arg0->unk4);
            func_800AED20(arg0->unk8);
        }
    } else {
        func_800AFA54(D_800DFA10[omCurrentObj->objId]);
    }
}

void func_801AA690_ovl7(struct AnimReq *arg0) {
    if (arg0->unk0 != -1) {
        func_800AA018(arg0->unk0);
        func_800AECC0(arg0->unk8);
        if (arg0->unk4 != -1) {
            func_800AA018(arg0->unk4);
            func_800AED20(arg0->unk8);
        }
    } else {
        func_800AFA54(D_800DFA10[omCurrentObj->objId]);
    }
}

void func_801AA720_ovl7(struct AnimReq *arg0) {
    s32 var_v0;

    var_v0 = ((u32)D_800DD8D0[omCurrentObj->objId] >> 0x1E) ? 1 : 0;
    if (var_v0 != 0) {
        func_801AA690_ovl7(arg0);
    } else {
        func_801AA600_ovl7(arg0);
    }
}

void func_801AA78C_ovl7(struct AnimReqSet *arg0) {
    void (*temp_v0_2)(s32, s32, f32);

    if (arg0 != NULL) {
        if (D_800E8AE0[D_800E0D50[omCurrentObj->objId]] & 6) {
            func_801AA720_ovl7(&arg0->unk2C);
        } else if (D_800E8920[D_800E0D50[omCurrentObj->objId]] == 0) {
            func_801AA720_ovl7(&arg0->unk14);
        } else {
            func_801AA720_ovl7(&arg0->unk20);
        }
        temp_v0_2 = arg0->unk38;
        if (temp_v0_2 != NULL) {
            D_800DF310[omCurrentObj->objId] = temp_v0_2;
        }
    }
}

void func_801AA850_ovl7(struct AnimReqSet *arg0) {
    void (*temp_v0_2)(s32, s32, f32);

    if (arg0 != NULL) {
        if (D_800E8AE0[D_800E0D50[omCurrentObj->objId]] & 6) {
            func_801AA690_ovl7(&arg0->unk2C);
        } else if (D_800E8920[D_800E0D50[omCurrentObj->objId]] == 0) {
            func_801AA690_ovl7(&arg0->unk14);
        } else {
            func_801AA690_ovl7(&arg0->unk20);
        }
        temp_v0_2 = arg0->unk38;
        if (temp_v0_2 != NULL) {
            D_800DF310[omCurrentObj->objId] = temp_v0_2;
        }
    }
}

void func_801AA914_ovl7(GObj *arg0) {
    struct EnemyRecord *rec;
    struct SubSub800E1B50_Unk88_UnkC *ptr;
    struct SubSub800E1B50_Unk88_UnkC_Unk0 *info;
    s32 objId;

    objId = omCurrentObj->objId;
    rec = D_800E1B50[objId];
    ptr = rec->unk88->unkC;
    if (omCurrentObj->objId) {}
    info = ptr->unk0;
    func_800B19F4(0, objId, ptr);
    D_800EC660[omCurrentObj->objId] = 0.0f;
    D_800EC820[omCurrentObj->objId] = 0.0f;
    func_801ABBA0_ovl7(arg0);
    D_800DF150[omCurrentObj->objId] = func_801AAAF8_ovl7;
    rec->unk48 = NULL;
    rec->unk98 = &D_801CB500_ovl7;
    D_800E8920[omCurrentObj->objId] = 0;
    D_800EA6E0[omCurrentObj->objId] = 0.06981317f;
    D_800E4C50[omCurrentObj->objId] = 0.0f;
    if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] >= 8) && (D_800E77A0[omCurrentObj->objId] < 0x2C)) {
        play_sound(0x11B);
    } else {
        play_sound(0xE1);
    }
    func_801AC6D0_ovl7(info);
    gEntitiesScaleXArray[omCurrentObj->objId] = info->scale;
    gEntitiesScaleYArray[omCurrentObj->objId] = info->scale;
    gEntitiesScaleZArray[omCurrentObj->objId] = info->scale;
    func_800AFBB4(1, omCurrentObj);
    func_801AAE60_ovl7();
    func_801AC11C_ovl7(arg0);
}
void func_801AAAF8_ovl7(s32 arg0) {
    void func_801AB008_ovl7(void);
    s32 id;

    if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] > 0) && (D_800E77A0[omCurrentObj->objId] < 0x2C) && (func_801C0588_ovl7() != 0)) {
        return;
    }
    if ((D_800E83E0[omCurrentObj->objId] != 0) || (D_800E8760[omCurrentObj->objId] != 0)) {
        if (D_800E83E0[omCurrentObj->objId] == 0x12) {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC33C_ovl7);
        } else {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC11C_ovl7);
        }
        return;
    }
    func_801AB008_ovl7();
    if (D_800E8AE0[omCurrentObj->objId] & 1) {
        D_800E64D0[omCurrentObj->objId] = D_800E6A10[omCurrentObj->objId] * 7.0f;
        D_800E6690[omCurrentObj->objId] = 0.0f;
        D_800E6850[omCurrentObj->objId] = 7.0f;
    } else {
        D_800E64D0[omCurrentObj->objId] = D_800E6A10[omCurrentObj->objId] * 14.0f;
        D_800E6690[omCurrentObj->objId] = 0.0f;
        D_800E6850[omCurrentObj->objId] = 14.0f;
    }
    if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] >= 8) && (D_800E77A0[omCurrentObj->objId] < 0x2C)) {
        func_801A3938(&D_801CB0F8_ovl7);
        func_801A36CC(&func_801A3864_ovl7);
        func_801A0D74_ovl7(arg0);
        if ((D_800E77A0[omCurrentObj->objId] >= 8) && (D_800E77A0[omCurrentObj->objId] < 0x24)) {
            func_80111C4C(func_801117BC(&D_801D0A38_ovl7, id = omCurrentObj->objId));
        } else {
            func_80111C4C(func_801117BC(&D_801CA7DC_ovl7, id = omCurrentObj->objId));
        }
    } else if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] > 0) && (D_800E77A0[omCurrentObj->objId] < 8)) {
        if (func_801A0D74_ovl7(arg0) != 0) {
            func_801A3938(&D_801CB008_ovl7);
            func_801A36CC(&func_801A3864_ovl7);
        }
        func_80111C4C(func_801117BC(&D_801D0A58_ovl7, omCurrentObj->objId));
    } else {
        if (func_801A0D74_ovl7(arg0) != 0) {
            func_801A3938(&D_801CB008_ovl7);
            func_801A36CC(&func_801A3864_ovl7);
        }
        func_80111C4C(func_801117BC(&D_801CA6F4_ovl7, omCurrentObj->objId));
    }
    if (D_800E8920[omCurrentObj->objId] == 1) {
        D_800E8920[omCurrentObj->objId] = 0;
    }
}
void func_801AAE60_ovl7(void) {
    if (D_800E8AE0[D_800E0D50[omCurrentObj->objId]] & 6) {
        D_800E64D0[omCurrentObj->objId] = D_800E6A10[omCurrentObj->objId] * 7.0f;
        D_800E6690[omCurrentObj->objId] = 0.0f;
        D_800E6850[omCurrentObj->objId] = 7.0f;
        D_800E3750[omCurrentObj->objId] = 0.0f;
        D_800E3210[omCurrentObj->objId] = D_800E3750[omCurrentObj->objId];
        D_800E3C90[omCurrentObj->objId] = 65535.0f;
        ohSleep(0x78);
        return;
    }
    D_800E64D0[omCurrentObj->objId] = D_800E6A10[omCurrentObj->objId] * 14.0f;
    D_800E6690[omCurrentObj->objId] = 0.0f;
    D_800E6850[omCurrentObj->objId] = 14.0f;
    D_800E3750[omCurrentObj->objId] = 0.0f;
    D_800E3210[omCurrentObj->objId] = D_800E3750[omCurrentObj->objId];
    D_800E3C90[omCurrentObj->objId] = 65535.0f;
    ohSleep(0x3C);
}

void func_801AB008_ovl7(void) {
    D_800E4C50[omCurrentObj->objId] += 0.34906587f;
    if (D_800E4C50[omCurrentObj->objId] >= 6.2831855f) {
        D_800E4C50[omCurrentObj->objId] -= 6.2831855f;
    }
    gEntitiesAngleYArray[omCurrentObj->objId] = D_800E4C50[omCurrentObj->objId];
    if ((gEntitiesAngleZArray[omCurrentObj->objId] > 0.69813174f) && (gEntitiesAngleZArray[omCurrentObj->objId] < 1.5707964f)) {
        D_800EA6E0[omCurrentObj->objId] = -0.06981317f;
    } else if ((gEntitiesAngleZArray[omCurrentObj->objId] < 5.585054f) && (gEntitiesAngleZArray[omCurrentObj->objId] > 1.5707964f)) {
        D_800EA6E0[omCurrentObj->objId] = 0.06981317f;
    }
    gEntitiesAngleZArray[omCurrentObj->objId] += D_800EA6E0[omCurrentObj->objId];
}
s32 func_801AC6D0_ovl7(struct AnimTrack *);
void func_801AB2F4_ovl7(GObj *);
extern struct EnemyEventTable D_801CB500_ovl7;

void func_801AB174_ovl7(GObj *gobj) {
    struct EnemyRecord *ent = D_800E1B50[omCurrentObj->objId];
    struct SubSub800E1B50_Unk88_UnkC *mid = ent->unk88->unkC;
    struct SubSub800E1B50_Unk88_UnkC_Unk4 *temp = mid->unk4;

    D_800EC660[omCurrentObj->objId] = 40.0f;
    D_800EC820[omCurrentObj->objId] = 0.0f;
    func_801ABBA0_ovl7();
    D_800DF150[omCurrentObj->objId] = func_801AB2F4_ovl7;
    ent->unk48 = 0;
    ent->unk98 = &D_801CB500_ovl7;
    ent->unk42 = 1;
    *(s8 *) &ent->unk38 = -1;
    ent->unk39 = -1;
    D_800E8920[omCurrentObj->objId] = 0;
    D_800EA6E0[omCurrentObj->objId] = 0.06981317f;
    D_800E4C50[omCurrentObj->objId] = 0.0f;
    func_801AC6D0_ovl7((struct AnimTrack *) temp);
    gEntitiesScaleXArray[omCurrentObj->objId] = temp->unk10;
    gEntitiesScaleYArray[omCurrentObj->objId] = temp->unk10;
    gEntitiesScaleZArray[omCurrentObj->objId] = temp->unk10;
    func_801AAE60_ovl7();
    func_801AC11C_ovl7(gobj);
}
void func_801AB2F4_ovl7(GObj *arg0) {
    if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] > 0) && (D_800E77A0[omCurrentObj->objId] < 0x2C) && (func_801C0588_ovl7() != 0)) {
        return;
    }
    if ((D_800E83E0[omCurrentObj->objId] != 0) || (D_800E8760[omCurrentObj->objId] != 0)) {
        if (D_800E83E0[omCurrentObj->objId] == 0x12) {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC33C_ovl7);
        } else {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC11C_ovl7);
        }
        return;
    }
    func_801AB008_ovl7();
    if (D_800E8AE0[omCurrentObj->objId] & 1) {
        D_800E64D0[omCurrentObj->objId] = D_800E6A10[omCurrentObj->objId] * 7.0f;
        D_800E6690[omCurrentObj->objId] = 0.0f;
        D_800E6850[omCurrentObj->objId] = 7.0f;
    } else {
        D_800E64D0[omCurrentObj->objId] = D_800E6A10[omCurrentObj->objId] * 14.0f;
        D_800E6690[omCurrentObj->objId] = 0.0f;
        D_800E6850[omCurrentObj->objId] = 14.0f;
    }
    if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] >= 8) && (D_800E77A0[omCurrentObj->objId] < 0x2C)) {
        func_801A3938(&D_801CB134_ovl7);
        func_801A36CC(&func_801A3864_ovl7);
        func_801A0D74_ovl7(arg0);
        func_80111C4C(func_801117BC(&D_801CA7DC_ovl7, omCurrentObj->objId));
    } else {
        if (func_801A0D74_ovl7(arg0) != 0) {
            func_801A3938(&D_801CB044_ovl7);
            func_801A36CC(&func_801A3864_ovl7);
        }
        func_80111C4C(func_801117BC(&D_801CA738_ovl7, omCurrentObj->objId));
    }
    if (D_800E8920[omCurrentObj->objId] == 1) {
        D_800E8920[omCurrentObj->objId] = 0;
    }
}
void func_801AB5A4_ovl7(GObj *gobj) {
    struct EnemyRecord *ent = D_800E1B50[omCurrentObj->objId];
    struct SubSub800E1B50_Unk88_UnkC *mid = ent->unk88->unkC;
    struct SubSub800E1B50_Unk88_UnkC_Unk4 *temp = mid->unk4;

    D_800EC660[omCurrentObj->objId] = 0.0f;
    D_800EC820[omCurrentObj->objId] = 25.0f;
    func_801ABBA0_ovl7();
    D_800DF150[omCurrentObj->objId] = func_801AB884_ovl7;
    ent->unk48 = 0;
    ent->unk98 = (struct EnemyEventTable *) &D_801CB4DC_ovl7;
    ent->unk42 = 1;
    *(s8 *) &ent->unk38 = -1;
    ent->unk39 = -1;
    D_800E8920[omCurrentObj->objId] = 0;
    D_800EA6E0[omCurrentObj->objId] = 0.06981317f;
    D_800E4C50[omCurrentObj->objId] = 0.0f;
    func_801AC6D0_ovl7((struct AnimTrack *) temp);
    gEntitiesScaleXArray[omCurrentObj->objId] = temp->unk10;
    gEntitiesScaleYArray[omCurrentObj->objId] = temp->unk10;
    gEntitiesScaleZArray[omCurrentObj->objId] = temp->unk10;
    if (D_800E8AE0[D_800E0D50[omCurrentObj->objId]] & 6) {
        D_800E6690[omCurrentObj->objId] = 0.0f;
        D_800E64D0[omCurrentObj->objId] = D_800E6690[omCurrentObj->objId];
        D_800E6850[omCurrentObj->objId] = 65535.0f;
        D_800E3210[omCurrentObj->objId] = 7.0f;
        D_800E3750[omCurrentObj->objId] = 0.0f;
        D_800E3C90[omCurrentObj->objId] = 7.0f;
        ohSleep(0x3C);
    } else {
        D_800E6690[omCurrentObj->objId] = 0.0f;
        D_800E64D0[omCurrentObj->objId] = D_800E6690[omCurrentObj->objId];
        D_800E6850[omCurrentObj->objId] = 65535.0f;
        D_800E3210[omCurrentObj->objId] = 14.0f;
        D_800E3750[omCurrentObj->objId] = 0.0f;
        D_800E3C90[omCurrentObj->objId] = 14.0f;
        ohSleep(0x1E);
    }
    func_801AC11C_ovl7(gobj);
}
void func_801AB884_ovl7(s32 arg0) {
    s32 id;

    if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] > 0) && (D_800E77A0[omCurrentObj->objId] < 0x2C) && (func_801C0588_ovl7() != 0)) {
        return;
    }
    if ((D_800E83E0[omCurrentObj->objId] != 0) || (D_800E8760[omCurrentObj->objId] != 0)) {
        if (D_800E83E0[omCurrentObj->objId] == 0x12) {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC33C_ovl7);
        } else {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC11C_ovl7);
        }
        return;
    }
    func_801AB008_ovl7();
    if (D_800E8AE0[omCurrentObj->objId] & 1) {
        D_800E3210[omCurrentObj->objId] = 7.0f;
        D_800E3750[omCurrentObj->objId] = 0.0f;
        D_800E3C90[omCurrentObj->objId] = 7.0f;
    } else {
        D_800E3210[omCurrentObj->objId] = 14.0f;
        D_800E3750[omCurrentObj->objId] = 0.0f;
        D_800E3C90[omCurrentObj->objId] = 14.0f;
    }
    if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] >= 8) && (D_800E77A0[omCurrentObj->objId] < 0x2C)) {
        func_801A3938(&D_801CB170_ovl7);
        func_801A36CC(&func_801A3864_ovl7);
        func_801A0D74_ovl7(arg0);
        if ((D_800E77A0[omCurrentObj->objId] >= 8) && (D_800E77A0[omCurrentObj->objId] < 0x24)) {
            func_80111C4C(func_801117BC(&D_801D0A38_ovl7, id = omCurrentObj->objId));
        } else {
            func_80111C4C(func_801117BC(&D_801CA7DC_ovl7, id = omCurrentObj->objId));
        }
    } else if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] > 0) && (D_800E77A0[omCurrentObj->objId] < 8)) {
        if (func_801A0D74_ovl7(arg0) != 0) {
            func_801A3938(&D_801CB080_ovl7);
            func_801A36CC(&func_801A3864_ovl7);
        }
        func_80111C4C(func_801117BC(&D_801D0A58_ovl7, omCurrentObj->objId));
    } else {
        if (func_801A0D74_ovl7(arg0) != 0) {
            func_801A3938(&D_801CB080_ovl7);
            func_801A36CC(&func_801A3864_ovl7);
        }
        func_80111C4C(func_801117BC(&D_801CA738_ovl7, omCurrentObj->objId));
    }
}
#ifdef NON_MATCHING
/* FACTORY: 101/351 words, pure register rotation (omCurrentObj/objId*4/D_800E0D50 base; D_800E7730 block), instruction stream identical */
void func_801ABBA0_ovl7(GObj *arg0) {
    struct EnemyRecord *rec;
    struct EnemyProbe *probe;
    struct EneInfo *info;
    struct Sub800E1B50_Unk34 *tmp;

    rec = D_800E1B50[omCurrentObj->objId];
    info = ((struct EneAnimSetup *) rec->unk88->unkC->unk4)->unk1C;
    D_800DEF90[omCurrentObj->objId] = func_800B4954;
    gEntitiesNextPosXArray[omCurrentObj->objId] = gEntitiesNextPosXArray[D_800E0D50[omCurrentObj->objId]];
    gEntitiesNextPosYArray[omCurrentObj->objId] = (gEntitiesNextPosYArray[0] + 20.0f) + (D_800EC820[omCurrentObj->objId] * 0.5f);
    gEntitiesNextPosZArray[omCurrentObj->objId] = gEntitiesNextPosZArray[D_800E0D50[omCurrentObj->objId]];
    D_800E6A10[omCurrentObj->objId] = D_800E6A10[D_800E0D50[omCurrentObj->objId]];
    D_800E5F90[omCurrentObj->objId] = D_800E5F90[D_800E0D50[omCurrentObj->objId]];
    D_800E6BD0[omCurrentObj->objId] = D_800E6BD0[D_800E0D50[omCurrentObj->objId]];
    if (D_800E6A10[omCurrentObj->objId] == 1.0f) {
        D_800E17D0[omCurrentObj->objId] = D_800E17D0[D_800E0D50[omCurrentObj->objId]];
    } else {
        D_800E17D0[omCurrentObj->objId] = D_800E17D0[D_800E0D50[omCurrentObj->objId]] + 3.1415927f;
    }
    D_800E8E60[omCurrentObj->objId] = 0;
    D_800DF310[omCurrentObj->objId] = NULL;
    if (rec->unk34 != NULL) {
        tmp = rec->unk34;
        func_800A22D4(tmp);
    }
    func_800A2300(arg0);
    rec->unk34 = NULL;
    if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] > 0) && (D_800E77A0[omCurrentObj->objId] < 8)) {
        func_801BC1AC_ovl7(D_800E77A0[omCurrentObj->objId]);
        D_800D7090 = omCurrentObj->objId;
    } else if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] >= 8) && (D_800E77A0[omCurrentObj->objId] < 0x24)) {
        func_801BC44C_ovl7(D_800E77A0[omCurrentObj->objId]);
        D_800D7090 = omCurrentObj->objId;
    } else if ((D_800E7730[omCurrentObj->objId] == 6) && (D_800E77A0[omCurrentObj->objId] >= 0x24) && (D_800E77A0[omCurrentObj->objId] < 0x2C)) {
        func_801BC72C_ovl7(D_800E77A0[omCurrentObj->objId] - 0x24);
        D_800D7090 = omCurrentObj->objId;
    }
    switch (D_800E8220[omCurrentObj->objId]) {
        case 0:
            func_801A2558_ovl7(&D_801CAF28_ovl7);
            break;
        case 1:
            func_801A2558_ovl7(&D_801CAF3C_ovl7);
            break;
    }
    func_80161CE0_ovl3(arg0);
    if ((D_800EC660[omCurrentObj->objId] != 0) && (func_800F98EC(omCurrentObj->objId, D_800E6A10[omCurrentObj->objId] * D_800EC660[omCurrentObj->objId]) != 0)) {
        func_801AC11C_ovl7(arg0);
    }
    gEntitiesNextPosYArray[omCurrentObj->objId] = gEntitiesNextPosYArray[0] + 20.0f;
    if ((D_800E8220[omCurrentObj->objId] == 1) && (info->unk8 == 1)) {
        gEntitiesNextPosYArray[omCurrentObj->objId] += 30.0f;
    }
    if (D_800EC820[omCurrentObj->objId] != 0) {
        gEntitiesNextPosYArray[omCurrentObj->objId] += D_800EC820[omCurrentObj->objId];
    }
    D_800E2090[omCurrentObj->objId] = 0.0f;
    D_800E2250[omCurrentObj->objId] = 0.0f;
    D_800E2410[omCurrentObj->objId] = 0.0f;
    probe = rec->unk84;
    if (probe != NULL) {
        probe->posX = gEntitiesNextPosXArray[omCurrentObj->objId];
        probe->posY = gEntitiesNextPosYArray[omCurrentObj->objId];
        probe->posZ = gEntitiesNextPosZArray[omCurrentObj->objId];
        func_801051AC(probe);
    }
    gEntityFuncListIDArray[omCurrentObj->objId] = 0;
    func_8019BB58_ovl7();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ovl7/ovl7_5/func_801ABBA0_ovl7.s")
#endif
void func_801AC11C_ovl7(GObj *gobj) {
    struct EnemyRecord *temp_s0;
    u32 temp_a0;
    u32 var_v1;

    temp_s0 = D_800E1B50[omCurrentObj->objId];
    func_801AC1F4_ovl7(gobj);
    if (temp_s0->unk40 != 1) {
        temp_a0 = temp_s0->unk94->unk1C;
        if (temp_a0 != 0x80000000) {
            play_sound(temp_a0);
        }
        func_800FD570(0, temp_s0->unk94->unk18, 0.0f, 0.0f, 0.0f);
        if (temp_s0->unk94 != NULL) {
            var_v1 = temp_s0->unk94->unk18;
            if (var_v1 == 6) {
                func_801A41D4_ovl7(gobj);
                var_v1 = temp_s0->unk94->unk18;
            }
            if (var_v1 == 7) {
                func_801A42D8_ovl7(gobj);
            }
        }
    }
    func_801AC2D8_ovl7(gobj);
}

void func_801AC1F4_ovl7(GObj *gobj) {
    struct EnemyRecord *sp1C;
    struct Sub800E1B50_Unk34 *temp_v0;

    sp1C = D_800E1B50[omCurrentObj->objId];
    func_800AF408();
    D_800DF150[omCurrentObj->objId] = NULL;
    D_800DEF90[omCurrentObj->objId] = func_800B6474;
    func_800AECC0(gameTicksPerDraw);
    func_800AED20(gameTicksPerDraw);
    func_800B33F4();
    gobj->onAnimate = NULL;
    D_800DF310[omCurrentObj->objId] = NULL;
    if (sp1C->unk34 != NULL) {
        temp_v0 = sp1C->unk34;
        func_800A22D4(temp_v0);
    }
    func_800A2300(gobj);
    sp1C->unk34 = NULL;
}

void func_801AC2D8_ovl7(GObj *gobj) {
    D_800DF150[omCurrentObj->objId] = NULL;
    func_800B19F4(0x7D, omCurrentObj->objId);
    func_8019BB58_ovl7();
    ohSleep(0xF);
    func_8019D958_ovl7((u16)omCurrentObj->objId);
}

void func_801AC33C_ovl7(GObj *gobj) {
    func_801AC1F4_ovl7(gobj);
    func_801AC2D8_ovl7(gobj);
}

void func_801AC364_ovl7(GObj *gobj) {
    s32 temp_v0;

    func_801AC1F4_ovl7(gobj);
    temp_v0 = func_801693C4_ovl3(5);
    if (temp_v0 != -1) {
        gEntitiesNextPosXArray[temp_v0] = gEntitiesNextPosXArray[omCurrentObj->objId];
        gEntitiesNextPosYArray[temp_v0] = gEntitiesNextPosYArray[omCurrentObj->objId];
        gEntitiesNextPosZArray[temp_v0] = gEntitiesNextPosZArray[omCurrentObj->objId];
        D_800EA6E0[temp_v0] = D_800E17D0[omCurrentObj->objId];
        D_800EC2E0[temp_v0].as_u32 = 0;
        D_800E0D50[temp_v0] = -1;
    }
    play_sound(0xE);
    func_801AC2D8_ovl7(gobj);
}

void func_801AC448_ovl7(GObj *gobj) {
    struct EnemyRecord *sp24;

    sp24 = D_800E1B50[omCurrentObj->objId];
    func_801AC1F4_ovl7(gobj);
    D_801D0A98_ovl7 = D_801D0A9C_ovl7 = D_801D0AA0_ovl7 = 0;
    D_801D0AA8_ovl7 = 0;
    sp24->unk34 = NULL;
    D_8012E860[0x18] = 0;
    func_800FD570(0, 0, 0.0f, 0.0f, 0.0f);
    play_sound(0x158);
    func_801AC2D8_ovl7(gobj);
}

void func_801AC4EC_ovl7(GObj *arg0) {
    gEntitiesNextPosXArray[omCurrentObj->objId] = gEntitiesNextPosXArray[D_800E0D50[omCurrentObj->objId]];
    gEntitiesNextPosYArray[omCurrentObj->objId] = gEntitiesNextPosYArray[D_800E0D50[omCurrentObj->objId]];
    gEntitiesNextPosZArray[omCurrentObj->objId] = gEntitiesNextPosZArray[D_800E0D50[omCurrentObj->objId]];
    func_80199568_ovl7();
    if (D_800E7730[omCurrentObj->objId] == 4) {
        if (D_800E77A0[omCurrentObj->objId] == 1) {
            func_800A9864(0x10087, 0x23, 0x10);
        }
        if (D_800E77A0[omCurrentObj->objId] == 0x13) {
            func_800A9864(0x10094, 0x23, 0x10);
        }
    }
    func_8019BB58_ovl7();
    switch (D_800E8220[omCurrentObj->objId]) {
        case 0:
            func_801A8CDC_ovl7(arg0);
            break;
        case 1:
            func_801A96C4_ovl7(arg0);
            break;
    }
    utilPrintf("JL_CatchOver: No CatchInfo Address ID:%x\n", D_800E8060[omCurrentObj->objId]);
    while (1) {}
}

s32 func_801AC6D0_ovl7(struct AnimTrack *arg0) {
    s32 sp1C;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_v0;

    sp1C = 0;
    D_800DF310[omCurrentObj->objId] = NULL;
    if ((D_800DD710[omCurrentObj->objId] == 0x1A) && (D_800E77A0[omCurrentObj->objId] == 0x39)) {
        return func_801AEFFC_ovl7();
    }
    func_800A9760(arg0->unk0);
    if (D_800E7730[omCurrentObj->objId] == 6) {
        var_v0 = D_800E77A0[omCurrentObj->objId];
        if ((var_v0 > 0) && (var_v0 < 8)) {
            func_801C06FC_ovl7();
            var_v0 = D_800E77A0[omCurrentObj->objId];
        }
        if ((var_v0 >= 8) && (var_v0 < 0x24)) {
            func_801C1E08_ovl7();
        }
    }
    temp_a0 = arg0->unk4;
    if (temp_a0 != -1) {
        func_800A9F98(temp_a0, 1.0f);
        func_800AECC0(arg0->unkC);
        sp1C = 1;
    }
    temp_a0_2 = arg0->unk8;
    if (temp_a0_2 != -1) {
        func_800A9F98(temp_a0_2, 1.0f);
        func_800AED20(arg0->unkC);
    }
    return sp1C;
}

void func_801AC840_ovl7(GObj *gobj) {
    if (D_800E83E0[omCurrentObj->objId] != 0) {
        if (D_800E83E0[omCurrentObj->objId] == 0x12) {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC33C_ovl7);
        } else {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC11C_ovl7);
        }
    } else {
        if (func_801A0D74_ovl7(gobj) != 0) {
            func_801A3938(&D_801CB044_ovl7);
            func_801A36CC(&func_801A3864_ovl7);
        }
        func_80111C4C(func_801117BC(&D_801CA738_ovl7, omCurrentObj->objId));
    }
}

void func_801AC908_ovl7(void) {
    if (D_800E83E0[omCurrentObj->objId] != 0) {
        if (D_800E83E0[omCurrentObj->objId] == 0x12) {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC33C_ovl7);
        } else {
            assign_new_process_entry(gEntityGObjProcessArray[omCurrentObj->objId], &func_801AC364_ovl7);
        }
    } else {
        if (func_801A0D74_ovl7() != 0) {
            func_801A3938(&D_801CB044_ovl7);
            func_801A36CC(&func_801A3864_ovl7);
        }
        func_80111C4C(func_801117BC(&D_801CA738_ovl7, omCurrentObj->objId));
    }
}
