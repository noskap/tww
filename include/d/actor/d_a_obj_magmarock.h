#ifndef D_A_OBJ_MAGMAROCK_H
#define D_A_OBJ_MAGMAROCK_H

#include "f_op/f_op_actor.h"

class dBgW;

namespace daObjMagmarock {
    static void ride_call_back(dBgW*, fopAc_ac_c*, fopAc_ac_c*);
    static BOOL CheckCreateHeap(fopAc_ac_c* i_this);
    class Act_c : public fopAc_ac_c {
    public:
        typedef void (Act_c::*ProcFunc)();

        void MeltDownRequest() {}
        inline cPhs_State _create();
        inline bool _delete();
        inline bool _draw();
        inline bool _execute();
        void checkProcess(void (daObjMagmarock::Act_c::*func)()) {}
        void setProcess(ProcFunc func) { field_0x2E0 = func; }

        void set_mtx();
        void demo_move();
        void ControlEffect();
        void play_anim();
        void appear_proc_init();
        void appear_proc();
        void wait_proc_init();
        void wait_proc();
        void stay_proc_init();
        void stay_proc();
        void quake_proc_init();
        void quake_proc();
        void vanish_proc_init();
        void vanish_proc();
        int CreateHeap();
        void CreateInit();
        void LiftUpRequest(cXyz&);
        void BeforeLiftRequest(cXyz&);
        void calc_ground_quat();

    public:
        /* 0x290 */ void* vtbl;
        /* 0x294 */ u8 field_0x294[0x29E - 0x294];
        /* 0x29E */ u8 field_0x29E;
        /* 0x29F */ u8 field_0x29F[0x2B0 - 0x29F];
        /* 0x2B0 */ Quaternion field_0x2B0;
        /* 0x2C0 */ u8 field_0x2C0[0x2D0 - 0x2C0];
        /* 0x2D0 */ Quaternion field_0x2D0;
        /* 0x2E0 */ ProcFunc field_0x2E0;
        /* 0x2EC */ u8 field_0x2EC[0x2F4 - 0x2EC];
        /* 0x2F4 */ J3DModel* model;
        /* 0x2F8 */ u8 field_0x2F8[0x328 - 0x2F8];
        /* 0x328 */ Mtx field_0x328;
        /* 0x358 */ dBgW* field_0x358;
        /* 0x35C */ u8 field_0x35C[0x430 - 0x35C];
        /* 0x430 */ f32 field_0x430;
        /* 0x434 */ f32 field_0x434;
        /* 0x438 */ f32 field_0x438;
        /* 0x43C */ u8 field_0x43C[0x448 - 0x43C];
        /* 0x448 */ int field_0x448;
        /* 0x44C */ int field_0x44C;
        /* 0x450 */ u8 field_0x450[0x454 - 0x450];
        /* 0x454 */ s16 field_0x454;
        /* 0x456 */ s16 field_0x456;
        /* 0x458 */ u8 field_0x458[0x460 - 0x458];
    }; // Size: 0x460
    
    namespace Method {
        cPhs_State Create(void*);
        BOOL Delete(void*);
        BOOL Execute(void*);
        BOOL Draw(void*);
        BOOL IsDelete(void*);
        extern actor_method_class Table;
    };
};

#endif /* D_A_OBJ_MAGMAROCK_H */
