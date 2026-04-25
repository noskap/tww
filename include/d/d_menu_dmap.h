#ifndef D_MENU_DMAP_H
#define D_MENU_DMAP_H

#include "dolphin/types.h"
#include "JSystem/JUtility/TColor.h"
#include "d/d_menu_base.h"

class J2DPane;
struct fopMsgM_pane_class;
class JKRArchive;
class JUTFont;

class dMenu_Dmap_c : public dMenu_base_c {
public:
    void alphaChange(fopMsgM_pane_class*, float) {}
    virtual void draw() {}
    void setArchive(JKRArchive* arc) { mpArc = arc; }
    void setFont(JUTFont* font, JUTFont* rfont) {
        mFont = font;
        mRFont = rfont;
    }
    void setItemTexBuffer(int, void*) {}
    void setTextArea(char* name0, char* name1, char* note0, char* note1, char* dummy0, char* dummy1) {
        name[0] = name0;
        name[1] = name1;
        note[0] = note0;
        note[1] = note1;
        dummy[0] = dummy0;
        dummy[1] = dummy1;
    }

    void changeFloorTexture(J2DPane*, int);
    void screenSet();
    void initialize();
    void treasureSet();
    void treasureDraw();
    void paneMove(float);
    void paneAlpha(float);
    void decAlpha(float);
    void cursorMove();
    void cursorAnime();
    void noteInit();
    bool noteCheck();
    void noteAppear();
    void noteOpen();
    void noteClose();
    void noteOpenProc(short);
    void itemScale();
    void floorInit();
    void mapMove();
    f32 mapOffsetY();
    void itemnameMove();
    void dnameSet();
    void itemnameSet();
    void itemnoteSet();
    void outFontInit();
    void linkAnime();
    void bossAnime();
    void bossEyeAnime();
    virtual void _create();
    virtual void _delete();
    virtual void _move();
    virtual void _draw();
    virtual bool _open();
    virtual bool _close();

public:
    /* 0x0004 */ J2DScreen* mpScreen;
    /* 0x0008 */ J2DScreen* mpScreen2;
    /* 0x000C */ fopMsgM_pane_class mFtPanes[15];
    /* 0x0354 */ fopMsgM_pane_class mFdPanes[15];
    /* 0x069C */ fopMsgM_pane_class mCarPanes[4];
    /* 0x077C */ fopMsgM_pane_class mNm00Pane;
    /* 0x07B4 */ fopMsgM_pane_class mNm01Pane;
    /* 0x07EC */ fopMsgM_pane_class mItnmPane;
    /* 0x0824 */ fopMsgM_pane_class mItnkPane;
    /* 0x085C */ fopMsgM_pane_class mMsk0Pane;
    /* 0x0894 */ fopMsgM_pane_class mStroPane;
    /* 0x08CC */ fopMsgM_pane_class mSt00Pane;
    /* 0x0904 */ fopMsgM_pane_class mNt00Pane;
    /* 0x093C */ fopMsgM_pane_class mNk00Pane;
    /* 0x0974 */ fopMsgM_pane_class mNo11Pane;
    /* 0x09AC */ fopMsgM_pane_class mDtlePane;
    /* 0x09E4 */ fopMsgM_pane_class mDt00Pane;
    /* 0x0A1C */ fopMsgM_pane_class mDk00Pane;
    /* 0x0A54 */ fopMsgM_pane_class mItPanes[3];
    /* 0x0AFC */ fopMsgM_pane_class mIkPanes[3];
    /* 0x0BA4 */ fopMsgM_pane_class mIpPanes[3];
    /* 0x0C4C */ fopMsgM_pane_class mIp01Pane;
    /* 0x0C84 */ fopMsgM_pane_class mLnkPanes[3];
    /* 0x0D2C */ fopMsgM_pane_class mBey1Pane;
    /* 0x0D64 */ fopMsgM_pane_class mBey2Pane;
    /* 0x0D9C */ fopMsgM_pane_class mBossPane;
    /* 0x0DD4 */ fopMsgM_pane_class mBos2Pane;
    /* 0x0E0C */ u8 padding_0E0C[0x0E7C - 0x0E0C];
    /* 0x0E7C */ fopMsgM_pane_class mFlPanes[6];
    /* 0x0FCC */ fopMsgM_pane_class mFbPanes[6];
    /* 0x111C */ fopMsgM_pane_class mFbkPanes[6];
    /* 0x126C */ fopMsgM_pane_class mFw00Pane;
    /* 0x12A4 */ fopMsgM_pane_class mFw01Pane;
    /* 0x12DC */ fopMsgM_pane_class mCc38Pane;
    /* 0x1314 */ fopMsgM_pane_class mCc31Pane;
    /* 0x134C */ fopMsgM_pane_class mCc24Pane;
    /* 0x1384 */ fopMsgM_pane_class mCc17Pane;
    /* 0x13BC */ fopMsgM_pane_class mCc10Pane;
    /* 0x13F4 */ fopMsgM_pane_class mCc05Pane;
    /* 0x142C */ fopMsgM_pane_class mCc00Pane;
    /* 0x1464 */ fopMsgM_pane_class mMskPane;
    /* 0x149C */ u8 padding_149C[0x14A0 - 0x149C];
    /* 0x14A0 */ dMap_Dmap_c* field_0x14a0;
    /* 0x14A4 */ JKRArchive* mpArc;
    /* 0x14A8 */ JUTFont* mFont;
    /* 0x14AC */ JUTFont* mRFont;
    /* 0x14B0 */ u8 field_0x14B0[0x14B4 - 0x14B0];
    /* 0x14B4 */ JUtility::TColor color_0x14B4;
    /* 0x14B8 */ JUtility::TColor color_0x14B8;
    /* 0x14BC */ JUtility::TColor color_0x14BC;
    /* 0x14C0 */ JUtility::TColor color_0x14C0;
    /* 0x14C4 */ JUtility::TColor color_0x14C4;
    /* 0x14C8 */ JUtility::TColor color_0x14C8;
    /* 0x14CC */ u8 padding_0x14CC[0x1AFC - 0x14CC];
    /* 0x1AFC */ void* arr_0x1AFC[3];
    /* 0x1B08 */ fopMsgM_msgDataProc_c mMsgProc;
    /* 0x1DA8 */ char* name[2];
    /* 0x1DB0 */ char* note[2];
    /* 0x1DB8 */ char* dummy[2];
    /* 0x1DC0 */ u8 padding_0x1DC0[0x1DCC - 0x1DC0];
    /* 0x1DCC */ f32 field_0x1dcc;
    /* 0x1DD0 */ f32 field_0x1dd0;
    /* 0x1DD4 */ u8 padding_0x1DD4[0x1DDC - 0x1DD4];
    /* 0x1DDC */ f32 field_0x1ddc;
    /* 0x1DE0 */ u8 padding_0x1DE0[0x1E0E - 0x1DE0];
    /* 0x1E0E */ s16 field_0x1e0e;
    /* 0x1E10 */ s16 field_0x1e10;
    /* 0x1E12 */ s16 field_0x1e12;
    /* 0x1E14 */ s16 field_0x1e14;
    /* 0x1E16 */ s16 field_0x1e16;
    /* 0x1E18 */ s16 field_0x1e18;
    /* 0x1E1A */ s16 field_0x1e1a;
    /* 0x1E1C */ s16 field_0x1e1c;
    /* 0x1E1E */ s16 field_0x1e1e;
    /* 0x1E20 */ s16 field_0x1e20;
    /* 0x1E22 */ s16 field_0x1e22;
    /* 0x1E24 */ s16 field_0x1e24;
    /* 0x1E26 */ s16 field_0x1e26;
    /* 0x1E28 */ s16 field_0x1e28;
    /* 0x1E2A */ s16 field_0x1e2a;
    /* 0x1E2C */ s16 field_0x1e2c;
    /* 0x1E2E */ u8 field_0x1e2e;
    /* 0x1E2F */ u8 field_0x1e2f;
    /* 0x1E30 */ u8 field_0x1e30;
    /* 0x1E31 */ u8 field_0x1e31;
    /* 0x1E32 */ u8 field_0x1e32;
    /* 0x1E33 */ u8 field_0x1e33;
    /* 0x1E34 */ u8 field_0x1e34;
    /* 0x1E35 */ u8 padding_0x1E35; 
    /* 0x1E36 */ u8 field_0x1e36;
    /* 0x1E37 */ u8 padding_0x1E37;
}; // Size: 0x1E38

STATIC_ASSERT(sizeof(dMenu_Dmap_c) == 0x1E38);

class dMd_HIO_c {
public:
    dMd_HIO_c();
    virtual ~dMd_HIO_c() {}

    /* 0x04 */ u8 _pad_0x04[2];
    /* 0x06 */ s16 field_0x06;
    /* 0x08 */ s16 field_0x08;
    /* 0x0a */ s16 field_0x0a;
    /* 0x0c */ s16 field_0x0c;
    /* 0x0e */ u8 _pad_0x0e[2];
    /* 0x10 */ JUtility::TColor mColor0;
    /* 0x14 */ JUtility::TColor mColor1;
    /* 0x18 */ s16 field_0x18;
    /* 0x1a */ s16 field_0x1a;
    /* 0x1c */ JUtility::TColor mColor2;
    /* 0x20 */ JUtility::TColor mColor3;
    /* 0x24 */ s16 field_0x24;
    /* 0x26 */ s16 field_0x26;
    /* 0x28 */ JUtility::TColor mColor4;
    /* 0x2c */ JUtility::TColor mColor5;
    /* 0x30 */ s16 field_0x30;
    /* 0x32 */ s16 field_0x32;
    /* 0x34 */ JUtility::TColor mColor6;
    /* 0x38 */ JUtility::TColor mColor7;
    /* 0x3c */ s16 field_0x3c;
    /* 0x3e */ s16 field_0x3e;
    /* 0x40 */ s16 field_0x40;
    /* 0x42 */ s16 field_0x42;
    /* 0x44 */ s16 field_0x44;
    /* 0x46 */ s16 field_0x46;
    /* 0x48 */ s16 field_0x48;
}; // Size: 0x4c

#endif /* D_MENU_DMAP_H */
