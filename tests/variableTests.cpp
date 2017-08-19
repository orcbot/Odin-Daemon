#include "../lib/variables/variable.h"
#include <gtest/gtest.h>
#include <iostream>

class VariableTest : public ::testing::Test {
  protected:
    variable* x;
    variable* y;
    variable* z;

    virtual void SetUp() {
    }

    virtual void TearDown() {
      if (x == NULL) {
        delete x;
      }
      if (y == NULL) {
        delete y;
      }
      if (z == NULL) {
        delete z;
      }
    }
};

TEST_F(VariableTest, Create) {
  ASSERT_NO_THROW(x = new variable("{\"name\":\"x\",\"save\":0,\"values\":[1,1,1,1,1],\"rank\":1,\"dimensions\":[5]}"););
}

TEST_F(VariableTest, Values) {
}
