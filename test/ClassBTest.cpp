#include "ClassB.h"
#include <gtest/gtest.h>

TEST(sumB1, normal)
{
	ClassB target = {};
	ASSERT_EQ(3, target.sumB1(1, 2));
}

TEST(sumB2, normal)
{
	ClassB target = {};
	ASSERT_EQ(3, target.sumB2(1, 2));
}
