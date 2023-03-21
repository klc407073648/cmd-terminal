#ifndef UserControllerTest_H_
#define UserControllerTest_H_

#include <iostream> 
#include "gtest/gtest.h"

class UserControllerTest : public ::testing::Test
{
    // You can remove any or all of the following functions if its body
    // is empty.
protected:
    UserControllerTest()
    {
        // You can do set-up work for each test here.
    }

    virtual ~UserControllerTest()
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

public:
};

#endif /* UserControllerTest */