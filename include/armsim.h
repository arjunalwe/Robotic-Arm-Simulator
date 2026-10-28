#pragma once
#include "armsim_export.h"

namespace armsim {

    class ARMSIM_EXPORT Sim {
    public:
        Sim();
        int get_joint_count();
    };

}