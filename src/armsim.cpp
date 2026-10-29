#include "armsim.h"

namespace armsim {

    const char* TooManyLinksException::what() const noexcept{
        return "Number of link lengths must be equal to Arm's degrees of freedom.";
    }

    Arm::Arm() {
        lengths.resize(dof, 1.0);
    }

    Arm::Arm(std::initializer_list<double> l): lengths(l){
        if (l.size() != dof){
            throw(TooManyLinksException());
        }
    }

    void Arm::set_link_lengths(std::initializer_list<double> l){
        if (l.size() != dof){
            throw(TooManyLinksException());
        }
        lengths = Eigen::VectorXd(l);
    }

    int Arm::get_dof(){
        return dof;
    }

    Eigen::Vector2d Arm::forward_kinematics(Eigen::Vector2d& angles){
        Eigen::Vector2d cumulative_angles;
        cumulative_angles << angles(0), angles(0) + angles(1);

        auto l = lengths.head<2>().array();
        auto theta = cumulative_angles.array();

        Eigen::Vector2d position;
        position << (l * theta.cos()).sum(),
                    (l * theta.sin()).sum();

        return position;
    }

}