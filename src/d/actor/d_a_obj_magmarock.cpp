/**
 * d_a_obj_magmarock.cpp
 * Object - Dragon Roost Cavern - Lava slab
 */

#include "d/dolzel_rel.h" // IWYU pragma: keep
#include "d/actor/d_a_obj_magmarock.h"
#include "d/d_procname.h"
#include "d/d_priority.h"
#include "d/d_s_play.h"
#include "d/d_bg_s_movebg_actor.h"
#include "d/res/res_kyjim.h"
#include "d/d_lib.h"

const char daObjMagmarock::Act_c::M_arcname[] = "Kyjim";

/* 00000078-00000128       .text set_mtx__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::set_mtx() {
    model->setBaseScale(scale);
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::ZXYrotM(shape_angle);
    Quaternion quat;
    mDoMtx_quatMultiply(&field_0x2B0, &field_0x2D0, &quat);
    mDoMtx_stack_c::quatM(&quat);

    model->setBaseTRMtx(mDoMtx_stack_c::get());
    PSMTXCopy(mDoMtx_stack_c::get(), field_0x328);
}

/* 00000128-00000258       .text demo_move__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::demo_move() {
    if (dComIfGs_isEventBit(0x380) || *((u8*)this + 0x29F) != 0) {
        return;
    }
    if (field_0x45A == 0) {
        if (eventInfo.checkCommandDemoAccrpt()) {
            field_0x45A += 1;
        } else {
            fopAcM_orderOtherEvent2(this, "magma_cam", 1, 0xFFFF);
            eventInfo.onCondition(2);
        }
    } else if (field_0x45A == 1) {
        int staffId = dComIfGp_evmng_getMyStaffId("Magrock", NULL, 0);

        if (dComIfGp_evmng_endCheck("magma_cam")) {
            dComIfGp_event_reset();
            field_0x45A += 1;
            dComIfGs_onEventBit(0x380);
        } else {
            dComIfGp_evmng_cutEnd(staffId);
        }
    }
}

/* 00000258-00000410       .text ControlEffect__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::ControlEffect() {
    if (field_0x45C != NULL) {
        if (field_0x45E != NULL) {
            if (field_0x2A8 == NULL) {
                field_0x2A8 = dComIfGp_particle_set(dPa_name::ID_AK_SN_MAGMAISLAND00, &current.pos, NULL, NULL, 0xff, NULL, -1, NULL, NULL, NULL);
            } else {
                field_0x2A8->setGlobalTranslation(current.pos.x, current.pos.y, current.pos.z);
            }
        } else {
            if (field_0x2A8 != NULL) {
                field_0x2A8->becomeInvalidEmitter();
                field_0x2A8 = NULL;
            }

            if (field_0x2AC == NULL) {
                dComIfGp_getVibration().StartShock(4, 1, cXyz(0.0f, 1.0f, 0.0f));
                field_0x2AC = dComIfGp_particle_setToon(dPa_name::ID_AK_SN_MAGMAISLAND01, &current.pos, NULL, NULL, 0xFF, NULL, -1, NULL, NULL, NULL);
            } else {
                field_0x2AC->setGlobalTranslation(current.pos.x, current.pos.y, current.pos.z);
            }
        }
    } else {
        if (field_0x2AC != NULL) {
            field_0x2AC->becomeInvalidEmitter();
            field_0x2AC = NULL;
        }
    }
}

/* 0000044C-00000560       .text play_anim__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::play_anim() {
    if (field_0x44C > 375 && field_0x438 > 0.0f) {
        field_0x438 -= 1.0f;
    } else {
        if ((field_0x44C < 15 || field_0x44C > 60) && field_0x438 < M_brk->getFrameMax()) {
            field_0x438 += 1.0f;
        }
    }
    if (field_0x44C < 60 && field_0x434 < M_bck->getFrameMax()) {
        field_0x434 += 1.0f;
        return;
    }
    if (field_0x44C > 375 && field_0x434 > 0.0f) {
        field_0x434 -= 1.0f;
    }
}

/* 00000560-0000058C       .text appear_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::appear_proc_init() {
    field_0x448 = 30;
    setProcess(&daObjMagmarock::Act_c::appear_proc);
}

/* 0000058C-000005EC       .text appear_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::appear_proc() {
    if (field_0x448 == 10) {
        dComIfG_Bgsp()->Regist(field_0x358, this);
    }

    if (field_0x448 == 0) {
        wait_proc_init();
    }
}

/* 000005EC-00000618       .text wait_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::wait_proc_init() {
    field_0x448 = 300;
    setProcess(&daObjMagmarock::Act_c::wait_proc);
}

/* 00000618-00000644       .text wait_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::wait_proc() {
    if (field_0x448 == 0) {
        quake_proc_init();
    }
}

/* 00000644-000006E0       .text stay_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::stay_proc_init() {
    u8 prm = fopAcM_GetParam(this) & 0xFF;
    if (prm == 0xFF) {
        prm = 0;
    }

    field_0x438 = 30.0f;
    field_0x434 = 30.0f;
    field_0x448 = prm * 15 + 30;
    field_0x44C = 330;

    dComIfG_Bgsp()->Regist(field_0x358, this);
    setProcess(&daObjMagmarock::Act_c::stay_proc);
}

/* 000006E0-00000720       .text stay_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::stay_proc() {
    if (field_0x29E != 0 && field_0x448-- == 0) {
        quake_proc_init();
    }
}

/* 00000720-000007B8       .text quake_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::quake_proc_init() {
    fopAcM_seStart(this, 0x380F, 0);

    field_0x448 = 45;
    setProcess(&daObjMagmarock::Act_c::quake_proc);
}

/* 000007B8-0000084C       .text quake_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::quake_proc() {
    field_0x454 += field_0x456;
    cLib_addCalcAngleS2(&field_0x456, 0x1000, 2, 0x100);

    cLib_addCalc2(&field_0x430, g_regHIO.mChild[10].mFloatRegs[10] + 750.0f, 0.25f, 50.0f);
    if (field_0x448 == 0) {
        vanish_proc_init();
    }
}

/* 0000084C-00000878       .text vanish_proc_init__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::vanish_proc_init() {
    field_0x448 = 90;
    setProcess(&daObjMagmarock::Act_c::vanish_proc);
}

/* 00000878-000008F8       .text vanish_proc__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::vanish_proc() {
    field_0x454 += field_0x456;
    cLib_addCalcAngleS2(&field_0x456, 0, 4, 0x40);

    if (field_0x448 == 80) {
        dComIfG_Bgsp()->Release(field_0x358);
    }

    if (field_0x448 < 0) {
        fopAcM_delete(this);
    }
}

/* 000008F8-00000AEC       .text ride_call_back__14daObjMagmarockFP4dBgWP10fopAc_ac_cP10fopAc_ac_c */
void daObjMagmarock::ride_call_back(dBgW* bgw, fopAc_ac_c* i_magmarock, fopAc_ac_c* i_rider) {
    daObjMagmarock::Act_c* rock = (daObjMagmarock::Act_c*)i_magmarock;

    cXyz vec = i_rider->current.pos - rock->current.pos;
    cXyz up(0.0f, 1.0f, 0.0f);
    vec = vec.outprod(up);
    f32 mag = vec.abs();

    if (vec.normalizeRS()) {
        short target_angle = (-mag * ((rock->current.pos.y - rock->home.pos.y) * 0.001f * 4.0f + 2.0f));

        cLib_addCalcAngleS2(&rock->field_0x298, target_angle, 8, 0x200);

        rock->field_0x29C = 1;
        rock->field_0x29E = 1;

        f32 sin_val = cM_ssin(rock->field_0x298);

        rock->field_0x2C0.x = vec.x * sin_val;
        rock->field_0x2C0.y = vec.y * sin_val;
        rock->field_0x2C0.z = vec.z * sin_val;
        rock->field_0x2C0.w = cM_scos(rock->field_0x298);
    }
}

/* 00000AEC-00000B0C       .text CheckCreateHeap__14daObjMagmarockFP10fopAc_ac_c */
BOOL daObjMagmarock::CheckCreateHeap(fopAc_ac_c* i_this) {
    return static_cast<daObjMagmarock::Act_c*>(i_this)->CreateHeap();
}

/* 00000B0C-00000DA0       .text CreateHeap__Q214daObjMagmarock5Act_cFv */
int daObjMagmarock::Act_c::CreateHeap() {
    void* modelData = dComIfG_getObjectRes(M_arcname, KYJIM_BDL_KYJIM_00);

    JUT_ASSERT(0x14D, modelData != 0);
    model = mDoExt_J3DModel__create((J3DModelData*)modelData,  0, 0x11020203);

    M_brk = (J3DAnmTevRegKey*)dComIfG_getObjectRes(M_arcname, KYJIM_BRK_KYJIM_00);
    M_bck = (J3DAnmTransform*)dComIfG_getObjectRes(M_arcname, KYJIM_BCK_KYJIM_00);

    JUT_ASSERT(0x155, M_brk != NULL);
    JUT_ASSERT(0x156, M_bck != NULL);

    int brk_res = field_0x2FC.init((J3DModelData*)modelData, M_brk, FALSE, 2, 1.0f, 0, -1, FALSE, 0);
    int bck_res = field_0x318.init((J3DModelData*)modelData, M_bck, FALSE, 2, 1.0f, 0, -1, FALSE);

    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::YrotM(shape_angle.y);
    mDoMtx_stack_c::scaleM(scale);
    cMtx_copy(mDoMtx_stack_c::get(), field_0x328);

    cBgD_t* bgd = (cBgD_t*)dComIfG_getObjectRes(M_arcname, KYJIM_DZB_KYJIM_00);
    field_0x358 = dBgW_NewSet(bgd, cBgW::MOVE_BG_e, &field_0x328);

    field_0x358->SetCrrFunc(dBgS_MoveBGProc_Typical);
    if (field_0x358 == NULL) {
        return 0;
    }

    bool ret = FALSE;
    if (model != NULL && brk_res != 0 && bck_res != 0) {
        ret = TRUE;
    }

    return ret;
}

/* 00000DA0-000013B4       .text CreateInit__Q214daObjMagmarock5Act_cFv */
BOOL daObjMagmarock::Act_c::CreateInit() {
    scale.setall(1.0f);
    cullMtx = model->getBaseTRMtx();
    fopAcM_setCullSizeBox(this, -200.0f, -30.0f, -200.0f, 200.0f, 30.0f, 200.0f);
    PSMTXCopy(model->getBaseTRMtx(), field_0x328);
    field_0x430 = 0;
    field_0x298 = 0;
    field_0x29A = 0;
    field_0x450 = 0;
    field_0x448 = 0x1E;
    field_0x44C = 0;
    field_0x438 = 0;
    field_0x454 = 0;
    field_0x456 = 0;
    field_0x45A = 0;
    field_0x29E = 0;

    speed.setall(0.0f);
    home.pos = current.pos;
    home.pos.y += 15.0f;
    gravity = -2.5f;

    field_0x2B0 = field_0x2C0 = field_0x2D0 = ZeroQuat;

    set_mtx();
    field_0x358->SetRideCallback(ride_call_back);
    field_0x29F = (fopAcM_GetParam(this) >> 24) & 0xFF;
    if (field_0x29F != 0) {
        stay_proc_init();
    } else {
        appear_proc_init();
        if (field_0x2A0 == 0) {
            s8 reverb = dComIfGp_getReverb(fopAcM_GetRoomNo(this));
            mDoAud_seStart(JA_SE_MAGMA_TO_ISLE, &eyePos, 0, reverb);

            dComIfGp_getVibration().StartShock(4, 1, cXyz(0.0f, 1.0f, 0.0f));
            field_0x35C = tevStr;
            g_env_light.settingTevStruct(TEV_TYPE_ACTOR, &current.pos, &field_0x35C);

            field_0x35C.mColorC0.r = (u8)(field_0x35C.mColorC0.r + (int)(0.12f * (0xFF - field_0x35C.mColorC0.r)));
            field_0x35C.mColorC0.g = (u8)(field_0x35C.mColorC0.g + (int)(0.12f * (0xFF - field_0x35C.mColorC0.g)));
            field_0x35C.mColorC0.b = (u8)(field_0x35C.mColorC0.b + (int)(0.12f * (0xFF - field_0x35C.mColorC0.b)));

            field_0x35C.mColorK0.r = (u8)(field_0x35C.mColorK0.r + (int)(0.12f * (0xFF - field_0x35C.mColorK0.r)));
            field_0x35C.mColorK0.g = (u8)(field_0x35C.mColorK0.g + (int)(0.12f * (0xFF - field_0x35C.mColorK0.g)));
            field_0x35C.mColorK0.b = (u8)(field_0x35C.mColorK0.b + (int)(0.12f * (0xFF - field_0x35C.mColorK0.b)));

            u8 alpha1 = (u8)(g_regHIO.mChild[10].mFloatRegs[0x19] * 102.0f + 153.0f);
            field_0x2A0 = dComIfGp_particle_setToon(dPa_name::ID_AK_SN_YOGANYUGE00, &current.pos, NULL, NULL, alpha1, NULL, -1, NULL, NULL, NULL);

            u8 alpha2 = (u8)(g_regHIO.mChild[10].mFloatRegs[0x1A] * 102.0f + 153.0f);
            field_0x2A4 = dComIfGp_particle_setToon(dPa_name::ID_AK_SN_YOGANYUGE01, &current.pos, NULL, NULL, alpha2, NULL, -1, NULL, NULL, NULL);

            if (field_0x2A0 != NULL) {
                field_0x2A0->setGlobalPrmColor(default_color.r, default_color.g, default_color.b);
                field_0x2A0->setGlobalEnvColor(default_color.r, default_color.g, default_color.b);
            }

            if (field_0x2A4 != NULL) {
                field_0x2A4->setGlobalPrmColor(default_color.r, default_color.g, default_color.b);
                field_0x2A4->setGlobalEnvColor(default_color.r, default_color.g, default_color.b);
            }
        }
    }

    return TRUE;
}

/* 000013B4-00001560       .text LiftUpRequest__Q214daObjMagmarock5Act_cFR4cXyz */
void daObjMagmarock::Act_c::LiftUpRequest(cXyz&) {
    /* Nonmatching */
}

/* 00001560-0000167C       .text BeforeLiftRequest__Q214daObjMagmarock5Act_cFR4cXyz */
void daObjMagmarock::Act_c::BeforeLiftRequest(cXyz&) {
    /* Nonmatching */
}

/* 0000167C-000017DC       .text calc_ground_quat__Q214daObjMagmarock5Act_cFv */
void daObjMagmarock::Act_c::calc_ground_quat() {
    /* Nonmatching */
}

/* 000017DC-0000198C       .text Create__Q214daObjMagmarock6MethodFPv */
cPhs_State daObjMagmarock::Method::Create(void*) {
    /* Nonmatching */
}

/* 00001A90-00001B14       .text Delete__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::Delete(void*) {
    /* Nonmatching */
}

/* 00001B14-00001B38       .text Execute__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::Execute(void*) {
    /* Nonmatching */
}

/* 00001B38-00001EC0       .text _execute__Q214daObjMagmarock5Act_cFv */
bool daObjMagmarock::Act_c::_execute() {
    /* Nonmatching */
}

/* 00001EC0-00002128       .text Draw__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::Draw(void*) {
    /* Nonmatching */
}

/* 00002128-00002130       .text IsDelete__Q214daObjMagmarock6MethodFPv */
BOOL daObjMagmarock::Method::IsDelete(void*) {
    /* Nonmatching */
}

actor_method_class daObjMagmarock::Method::Table = {
    (process_method_func)daObjMagmarock::Method::Create,
    (process_method_func)daObjMagmarock::Method::Delete,
    (process_method_func)daObjMagmarock::Method::Execute,
    (process_method_func)daObjMagmarock::Method::IsDelete,
    (process_method_func)daObjMagmarock::Method::Draw,
};

actor_process_profile_definition g_profile_Obj_Magmarock = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0003,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Magmarock,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjMagmarock::Act_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ PRIO_Obj_Magmarock,
    /* Actor SubMtd */ &daObjMagmarock::Method::Table,
    /* Status       */ fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
