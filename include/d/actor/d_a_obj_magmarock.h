#ifndef D_A_OBJ_MAGMAROCK_H
#define D_A_OBJ_MAGMAROCK_H

#include "f_op/f_op_actor.h"

class dBgW;

namespace daObjMagmarock {
    static void ride_call_back(dBgW*, fopAc_ac_c*, fopAc_ac_c*);
    static BOOL CheckCreateHeap(fopAc_ac_c*);
    
    class Act_c : public fopAc_ac_c {
    public:
        void MeltDownRequest() {}
        inline cPhs_State _create();
        inline bool _delete();
        inline bool _draw();
        inline bool _execute();
        void checkProcess(void (daObjMagmarock::Act_c::*)()) {}
        void setProcess(void (daObjMagmarock::Act_c::*)()) {}
    
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
        void CreateHeap();
        void CreateInit();
        void LiftUpRequest(cXyz&);
        void BeforeLiftRequest(cXyz&);
        void calc_ground_quat();
    
    public:
        /* 0x290 */ void* vtbl;
        /* 0x294 */ u8 field_0x294[0x2B0 - 0x294];
        /* 0x2B0 */ Quaternion field_0x2B0;
        /* 0x2B4 */ u8 field_0x2B4[0x2D0 - 0x2B4];
        /* 0x2D0 */ Quaternion field_0x2D0;
        /* 0x2D4 */ u8 field_0x2D4[0x460 - 0x2D4];
    };  // Size: 0x460
    
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
