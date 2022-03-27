#pragma once

#include <cmath>
#include <vector>

class IException
{
  public:
    IException (const char *value) : m_value (value) {}
    const char *get_message () const { return m_value; }
  private:
    const char *m_value = nullptr;
};

class ZeroExeption : public IException
{
public:
  ZeroExeption () : IException ("Сoefficient a is zero") {}
};

bool fuzzy_eq (double a, double b, double min_compare = 10e-12)
{
  return fabs (a - b) < min_compare;
}

std::vector<double> solve (double a, double b, double c)
{
  if (fuzzy_eq (a, 0.))
    throw ZeroExeption ();

  double D = b * b - 4 * a * c;

  if (D > 0)
    return {(- b - sqrt (D)) / (2 * a), (- b + sqrt (D)) / (2 * a)};

  if (fuzzy_eq (D, 0.))
    return {- b / (2 * a)};

  return {};
}
