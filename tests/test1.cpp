#include <gtest/gtest.h>
#include "armsim.h" 

TEST(ArmTest, JointCount) {
    armsim::Sim sim; 
    
    EXPECT_EQ(sim.get_joint_count(), 7);
}