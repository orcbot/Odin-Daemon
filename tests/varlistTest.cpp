#include "../lib/variables/variable.h"
#include "../lib/varList/varlist.h"
#include "../lib/errors/varlist_error.h"
#include <gtest/gtest.h>
#include <iostream>

/*
  Test Case #2: Testing the variable list class, used by Odin-Daemon
  Description:  Testing the class to ensure that it will correctly save variables,
                correctly retrieve variables, and behave in a way that will prevent
                the program from crashing when unexpected input is given.
  Expected:     All tests will pass.
*/

class VariableListTest : public ::testing::Test {
  protected:
    varlist vars;
    variable* w;
    variable* x;
    variable* y;
    variable* z;

    virtual void SetUp() {
      w = new variable("{\"name\":\"ron\",\"save\":0,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");
      x = new variable("{\"name\":\"harry\",\"save\":1,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");
      y = new variable("{\"name\":\"potter\",\"save\":0,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");
      z = new variable("{\"name\":\"harry\",\"save\":0,\"values\":[5,5,5,5,5],\"rank\":2,\"dimensions\":[5,1]}");
    }

    virtual void TearDown() {
      delete z;
    }
};

/* @todo
  Test #1:      Testing variable adding.
  Description:  ---
  Expected:     All conditions will be met
*/
TEST_F(VariableListTest, Adding) {
  /* @todo
    Condition #1:
    Description:
    Expected:       Will return 0
  */
  EXPECT_EQ(vars.count(), 0);
  /* @todo
    Condition #2:
    Description:
    Expected:       Will return 0
  */
  EXPECT_NO_THROW(vars.add(x));
  /* @todo
    Condition #3:
    Description:
    Expected:       Will return 0
  */
  EXPECT_NO_THROW(vars.add(y));
  /* @todo
    Condition #4:
    Description:
    Expected:       Throw a VariableAlreadyExistsError object
  */
  EXPECT_THROW(vars.add(z), VariableAlreadyExistsError);
  /* @todo
    Condition #5:
    Description:
    Expected:       Throw a VariableAlreadyExistsError object
  */
  EXPECT_THROW(vars.add(z), VariableAlreadyExistsError);
  /* @todo
    Condition #6:
    Description:
    Expected:       Throw a VariableAlreadyExistsError object
  */
  EXPECT_THROW(vars.add(NULL), VariableNotDefinedError);
  /* @todo
    Condition #7:
    Description:
    Expected:       Will return 0
  */
  EXPECT_EQ(vars.count(), 2);
}

/* @todo
  Test #2:      Testing variable retriving.
  Description:  ---
  Expected:     All conditions will be met
*/
TEST_F(VariableListTest, Retriving) {
  /* @todo
    Condition #1:
    Description:
    Expected:       Will throw VariableNotFoundError
  */
  EXPECT_THROW(vars.find("harry"), VariableNotFoundError);
  vars.add(x);
  vars.add(w);
  vars.add(y);
  /* @todo
    Condition #2:
    Description:
    Expected:       Will return x
  */
  EXPECT_EQ(vars.find("harry"), x);
  /* @todo
    Condition #2:
    Description:
    Expected:       Will return w
  */
  EXPECT_EQ(vars.find("ron"), w);
  /* @todo
    Condition #3:
    Description:
    Expected:       Will return w
  */
  EXPECT_THROW(vars.find("snape"), VariableNotFoundError);
}

/* @todo
  Test #3:      Testing variable reseting.
  Description:  ---
  Expected:     All conditions will be met
*/
TEST_F(VariableListTest, Reset) {
  vars.add(y);
  vars.add(x);
  vars.add(w);
  /* @todo
    Condition #1:
    Description:
    Expected:       Will not throw an error
  */
  EXPECT_NO_THROW(vars.reset());
  /* @todo
    Condition #2:
    Description:
    Expected:       Will return 1
  */
  EXPECT_EQ(vars.count(), 1);
  /* @todo
    Condition #3:
    Description:
    Expected:       Will not throw an error
  */
  EXPECT_NO_THROW(vars.fullReset());
  /* @todo
    Condition #4:
    Description:
    Expected:       Will return 0
  */
  EXPECT_EQ(vars.count(), 0);

  w = new variable("{\"name\":\"ron\",\"save\":0,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");
  x = new variable("{\"name\":\"harry\",\"save\":1,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");
  y = new variable("{\"name\":\"potter\",\"save\":0,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");

  vars.add(x);
  vars.add(y);
  vars.add(w);
  /* @todo
    Condition #5:
    Description:
    Expected:       Will not throw an error
  */
  EXPECT_NO_THROW(vars.reset());
  /* @todo
    Condition #6:
    Description:
    Expected:       Will return 1
  */
  EXPECT_EQ(vars.count(), 1);

  vars.fullReset();

  w = new variable("{\"name\":\"ron\",\"save\":0,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");
  x = new variable("{\"name\":\"harry\",\"save\":1,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");
  y = new variable("{\"name\":\"potter\",\"save\":0,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");

  vars.add(y);
  vars.add(w);
  vars.add(x);
  /* @todo
    Condition #7:
    Description:
    Expected:       Will not throw an error
  */
  EXPECT_NO_THROW(vars.reset());
  /* @todo
    Condition #8:
    Description:
    Expected:       Will return 1
  */
  EXPECT_EQ(vars.count(), 1);
}
