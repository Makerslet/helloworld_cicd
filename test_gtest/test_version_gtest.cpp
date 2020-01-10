#include "lib/lib.h"

#include <gtest/gtest.h>

TEST(VERSION, GREATER_THAN_ZERO)
{
    ASSERT_GT(version(), 0);
}
