#pragma once

#include <gtest/gtest.h>

#include "solve.h"

using namespace testing;

TEST (hw1_tests, no_roots_test)
{
  std::vector<double> roots = solve (1., 0., 1.);
  EXPECT_TRUE (roots.empty ());
}

TEST (hw1_tests, two_roots_test)
{
  std::vector<double> roots = solve (1., 0., -1.);
  EXPECT_TRUE (roots.size () == 2);
  auto contain_root = [roots] (double value)
  {
    return fuzzy_eq (roots[0], value) || fuzzy_eq (roots[1], value);
  };

  EXPECT_TRUE (contain_root (1.) && contain_root (-1.));
}

TEST (hw1_tests, one_root_test)
{
  std::vector<double> roots = solve (1., 2., 1.);
  EXPECT_TRUE (roots.size () == 1);
  EXPECT_TRUE (fuzzy_eq (roots[0], -1));
}
