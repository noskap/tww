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
    void mapOffsetY();
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
    /* 0x0004 */ u8 field_0x0004[0x972 - 0x4];
    /* 0x0972 */ s16 field_0x0972;
    /* 0x0974 */ u8 field_0x0974[0xD62 - 0x974];
    /* 0x0D62 */ s16 field_0xd62;
    /* 0x0D64 */ u8 field_0x0d64[0x14A4 - 0xD64];
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
    /* 0x1DC0 */ u8 padding_0x1DC0[0x1E2C - 0x1DC0];
    /* 0x1E2C */ s16 field_0x1e2c;
    /* 0x1E2E */ u8 padding_0x1E2E[0x1E36 - 0x1E2E];
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
