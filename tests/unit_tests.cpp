#include <gtest/gtest.h>
#include "armsim.h"
#include <numbers>

TEST(ArmTest, JointCountDefaultLinks) {
    armsim::Arm arm;
    
    EXPECT_EQ(arm.get_dof(), 2);
}

TEST(ArmTest, JointCountCustomLinksPass) {
    armsim::Arm arm = {1.0, 1.0};
    
    EXPECT_EQ(arm.get_dof(), 2);
}

TEST(ArmTest, JointCountCustomLinksFail){
    EXPECT_THROW(armsim::Arm {1.0}, armsim::TooManyLinksException);
}


TEST(ArmTest, JointCountCustomLinksSetterFail){
    armsim::Arm arm;
    EXPECT_THROW(arm.set_link_lengths({1.0}), armsim::TooManyLinksException);
}

TEST(ArmTest, ForwardKinematicsTest){
    armsim::Arm arm;
    double pi = std::numbers::pi;
    double tolerance = 0.000000001;
    std::vector<Eigen::Vector2d> test_angles = {Eigen::Vector2d(0, 0), Eigen::Vector2d(pi/2, 0), Eigen::Vector2d(0, pi/2), Eigen::Vector2d(pi/2, pi/2)}; 
    std::vector<Eigen::Vector2d> answers = {Eigen::Vector2d(2, 0), Eigen::Vector2d(0, 2), Eigen::Vector2d(1, 1), Eigen::Vector2d(-1, 1)}; 

    ASSERT_EQ(test_angles.size(), answers.size()) << "Vector sizes must match!";

    for (size_t i = 0; i < test_angles.size(); ++i) {
        Eigen::Vector2d actual = arm.forward_kinematics(test_angles[i]);
        
        EXPECT_NEAR(actual(0), answers[i](0), tolerance)
        << "Failure at vector index: " << i << " (X coordinate)"
        << "\nInput angles: " << test_angles[i].transpose()
        << "\nExpected: " << answers[i].transpose()
        << "\nActual: " << actual.transpose();

    EXPECT_NEAR(actual(1), answers[i](1), tolerance)
        << "Failure at vector index: " << i << " (Y coordinate)"
        << "\nInput angles: " << test_angles[i].transpose()
        << "\nExpected: " << answers[i].transpose()
        << "\nActual: " << actual.transpose();
    }

}