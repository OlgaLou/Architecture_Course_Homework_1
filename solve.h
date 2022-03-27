#pragma once

#include <cmath>
#include <vector>

bool fuzzy_eq (double a, double b, double min_compare = 10e-12)
{
  return fabs (a - b) < min_compare;
}

std::vector<double> solve (double a, double b, double c)
{
  double D = b * b - 4 * a * c;

  if (D > 0)
    return {(- b - sqrt (D)) / (2 * a), (- b + sqrt (D)) / (2 * a)};

  if (fuzzy_eq (D, 0.))
    return {- b / (2 * a)};

  return {};
}
