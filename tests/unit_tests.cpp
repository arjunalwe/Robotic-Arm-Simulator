#include <gtest/gtest.h>
#include "armsim.h" 

TEST(ArmTest, JointCount) {
    armsim::Arm arm;
    
    EXPECT_EQ(arm.get_dof(), 2);
}