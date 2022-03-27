#pragma once

#include <cmath>
#include <vector>

bool fuzzy_eq (double a, double b, double min_compare = 10e-12)
{
  return fabs (a - b) < min_compare;
}

std::vector<double> solve (double, double, double)
{
  return {};
}
