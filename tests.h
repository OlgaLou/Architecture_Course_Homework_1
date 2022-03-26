#pragma once

#include <gtest/gtest.h>

using namespace testing;

TEST (hw1_tests, no_roots_test)
{
  std::vector<double> roots = solve (1., 0., 1.);
  EXPECT_TRUE (roots.empty ());
}
