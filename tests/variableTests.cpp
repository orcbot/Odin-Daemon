#include "../lib/variables/variable.h"
#include "../lib/errors/variable_error.h"
#include <gtest/gtest.h>
#include <iostream>

/*
  Test Case #1: Testing the variable class, used by Odin-Daemon
  Description:  Testing to make sure the variable class will create objects as expected,
                store data correctly, retrieve data correctly, update data correctly,
                and will believe correctly when it is given an invalid JSON string.
  Expected:     All tests will pass.
*/
class VariableTest : public ::testing::Test {
  protected:
    variable* x;
    variable* y;
    variable* z;

    virtual void SetUp() {
      x = new variable("{\"name\":\"harry\",\"save\":0,\"values\":[1.1,1,20,1,1],\"rank\":2,\"dimensions\":[5,1]}");
      y = new variable();
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

/* @todo
  Test #1:      Testing object consrtuction.
  Description:  Testing object construction with JSON string input, both valid and invalid,
                and seeing how it will react when it does not get its required fields.
  Expected:     All conditions will be met
*/
TEST_F(VariableTest, Create) {
  /*
    Condition #1:   Testing constructor with fully valid input.
    Description:    Passing the constrctor a valid JSON string, with
                    all the required fields needed to creat the object.
    Expected:       No error thrown.
  */
  EXPECT_NO_THROW(variable("{\"name\":\"x\",\"save\":0,\"values\":[1,1,1,1,1],\"rank\":1,\"dimensions\":[5]}"));
  /*
    Condition #2:   Testing constructor with invalid input.
    Description:    Passing the constructor an invalid JSON string,
                    which it will not be able to use to create the object.
    Expected:       Throws a NotObjectError object.
  */
  EXPECT_THROW(variable("{"), NotObjectError);
  /*
    Condition #3:   A valid JSON string missing the name field.
    Description:    Passing the constructor a valid JSON string, which
                    is missing the name field required to make the object
    Expected:       Throws a NoNameError object.
  */
  EXPECT_THROW(variable("{}"), NoNameError);
  /*
    Condition #4:   A valid JSON string missing the save field.
    Description:    Passing the constructor a valid JSON string, which
                    is missing the save field required to make the object
    Expected:       Throws a NoSaveError object.
  */
  EXPECT_THROW(variable("{\"name\":\"x\"}"), NoSaveError);
  /*@todo
    Condition #5:   A valid JSON string missing the name field.
    Description:    Passing the constructor a valid JSON string, which
                    is missing the save field required to make the object
    Expected:       Throws a NoSaveError object.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":0}"), NoRankError);
  /*@todo
    Condition #6:   A valid JSON string missing the name field.
    Description:    Passing the constructor a valid JSON string, which
                    is missing the save field required to make the object
    Expected:       Throws a NoSaveError object.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":0,\"rank\":1}"), NoDimensionsError);
  /*@todo
    Condition #7:   A valid JSON string missing the name field.
    Description:    Passing the constructor a valid JSON string, which
                    is missing the save field required to make the object
    Expected:       Throws a NoSaveError object.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":0,\"rank\":1,\"dimensions\":[5]}"), NoValuesError);
  /*@todo
    Condition #8:   A valid JSON string missing the name field.
    Description:    Passing the constructor a valid JSON string, which
                    is missing the save field required to make the object
    Expected:       Throws a NoSaveError object.
  */
  EXPECT_THROW(variable("{\"name\":12345,\"save\":0,\"rank\":1,\"dimensions\":[5],\"values\":[1,1,1,1,1]}"), NameNotStringError);
  /*@todo
    Condition #9:   Testing constructor with fully valid input.
    Description:    Passing the constrctor a valid JSON string, with
                    all the required fields needed to creat the object.
    Expected:       No error thrown.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":\"\",\"values\":[1,1,1,1,1],\"rank\":1,\"dimensions\":[5]}"), SaveNotBoolError);
  /*@todo
    Condition #10:  Testing constructor with fully valid input.
    Description:    Passing the constrctor a valid JSON string, with
                    all the required fields needed to creat the object.
    Expected:       No error thrown.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":0,\"values\":[1,1,1,1,1],\"rank\":\"\",\"dimensions\":[5]}"), RankNotInt);
  /*@todo
    Condition #11:  Testing constructor with fully valid input.
    Description:    Passing the constrctor a valid JSON string, with
                    all the required fields needed to creat the object.
    Expected:       No error thrown.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":0,\"values\":[1,1,1,1,1],\"rank\":1,\"dimensions\":5}"), DimensionsNotArray);
  /*@todo
    Condition #12:  Testing constructor with fully valid input.
    Description:    Passing the constrctor a valid JSON string, with
                    all the required fields needed to creat the object.
    Expected:       No error thrown.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":0,\"values\":1,\"rank\":1,\"dimensions\":[5]}"), ValuesNotArray);
  /*@todo
    Condition #13:  Testing constructor with fully valid input.
    Description:    Passing the constrctor a valid JSON string, with
                    all the required fields needed to creat the object.
    Expected:       No error thrown.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":0,\"values\":[1,1,1,1,1],\"rank\":1,\"dimensions\":[5,2]}"), DimensionsWrongSizeError);
  /*@todo
    Condition #14:  Testing constructor with fully valid input.
    Description:    Passing the constrctor a valid JSON string, with
                    all the required fields needed to creat the object.
    Expected:       No error thrown.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":0,\"values\":[1,1,1,1],\"rank\":1,\"dimensions\":[5]}"), ValuessWrongSizeError);
  /*@todo
    Condition #15:  Testing constructor with fully valid input.
    Description:    Passing the constrctor a valid JSON string, with
                    all the required fields needed to creat the object.
    Expected:       No error thrown.
  */
  EXPECT_THROW(variable("{\"name\":\"x\",\"save\":0,\"values\":[1,1,1,1,1],\"rank\":-5,\"dimensions\":[5]}"), Rank0Error);
}

/* @todo
  Test #2:      Testing object consrtuction.
  Description:  Testing object construction with JSON string input, both valid and invalid,
                and seeing how it will react when it does not get its required fields.
  Expected:     All conditions will be met
*/
TEST_F(VariableTest, Values) {
  /*
    Condition #1:
    Description:
    Expected:
  */
  EXPECT_EQ(x->getRank(), 2);
  /*
    Condition #2:
    Description:
    Expected:
  */
  EXPECT_EQ(x->getDimension(0), 5);
  /*
    Condition #3:
    Description:
    Expected:
  */
  EXPECT_EQ(x->getValue(2), 20);
  /*
    Condition #4:
    Description:
    Expected:
  */
  EXPECT_EQ(x->getValue(0), 1.1);
  /*
    Condition #5:
    Description:
    Expected:
  */
  EXPECT_FALSE(x->getSave());
  /*
    Condition #6:
    Description:
    Expected:
  */
  EXPECT_EQ(x->getName(), "harry");
  /*
    Condition #7:
    Description:
    Expected:
  */
  EXPECT_THROW(x->getValue(20), OutOfBounds);
  /*
    Condition #8:
    Description:
    Expected:
  */
  EXPECT_THROW(x->getValue(-1), OutOfBounds);
  /*
    Condition #9:
    Description:
    Expected:
  */
  EXPECT_THROW(x->getDimension(5), OutOfBounds);
  /*
    Condition #10:
    Description:
    Expected:
  */
  EXPECT_THROW(x->getDimension(5), OutOfBounds);
}

TEST_F(VariableTest, Updates) {
  /*
    Condition #1:
    Description:
    Expected:
  */
  EXPECT_THROW(y->setName(""), NoNameError);
  /*
    Condition #2:
    Description:
    Expected:
  */
  EXPECT_NO_THROW(y->setName("potter"));
  /*
    Condition #3:
    Description:
    Expected:
  */
  EXPECT_EQ(y->getName(), "potter");
}
