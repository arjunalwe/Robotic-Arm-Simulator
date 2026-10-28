#include "armsim.h"

namespace armsim {

    const char* TooManyLinksException::what() const noexcept{
        return "Number of link lengths must be equal to Arm's degrees of freedom.";
    }

    Arm::Arm() {
        lengths.resize(dof, 1.0);
    }

    Arm::Arm(std::initializer_list<double>& l) : lengths(l){
        if (lengths.size() != dof){
            throw(TooManyLinksException());
        }
    }

    void Arm::set_link_lengths(std::initializer_list<double>& l){
        if (l.size() != dof){
            throw(TooManyLinksException());
        }
        lengths = l;
    }

    int Arm::get_dof(){
        return dof;
    }

}