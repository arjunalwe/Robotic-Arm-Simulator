#pragma once
#include "armsim_export.h"
#include <vector>
#include <iostream>
#include <string>
#include <numbers>
#include <initializer_list>
#include <Eigen/Dense>

namespace armsim {

    class ARMSIM_EXPORT Arm {
        private:
            const static int dof = 2;
        public:
            Eigen::VectorXd lengths; 
            Arm();
            Arm(std::initializer_list<double> l);
            int get_dof();
            void set_link_lengths(std::initializer_list<double> l);
            Eigen::Vector2d forward_kinematics(Eigen::Vector2d& angles);
    };  

    class ARMSIM_EXPORT TooManyLinksException : public std::exception {
        public:
            const char* what() const noexcept override;

    };
}