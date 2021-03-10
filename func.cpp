#include "func.h"

double mypow(double x, unsigned n) {
  double res = 1;
  for (unsigned i = 0; i < n; ++i)
    res *= x;

  return res;
}

double Func(double x) {
  double res = (mypow(x, 5) - 8.2 * mypow(x, 3) + 4.5 * mypow(x, 2) - 7 * x + 6.5) * cos(0.4 * x);
  return res;
}

double AntiDer(double x) {
  double res = (31.25 * mypow(x, 4) - 2497.5 * x * x + 56.25 * x + 31175) * cos(0.4 * x) 
    + (2.5 * mypow(x, 5) - 333 * mypow(x, 3) + 11.25 * x * x + 12470 * x - 124.375) * sin(0.4 * x);
  
  return res;
}
