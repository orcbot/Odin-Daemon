#include "../lib/variables/variable.h"
#include <gtest/gtest.h>

class VariableCreationTest : public ::testing::Test {
  protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(VariableCreationTest, PositiveNos) {
    ASSERT_EQ(1, 1);
    ASSERT_EQ(1, 1);
    ASSERT_EQ(1, 1);
    ASSERT_EQ(1, 1);
}
