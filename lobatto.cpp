#include "lobatto.h"

//TODO: fix calc because this algorithm has some problems

double Lobatto::calc(double eps, int* count) {
  int n = 1;
  double len = rbord - lbord;
  double integVal = (func(lbord) + func(rbord)) * len / 3.0;
  double iPrev = 0;
  double iNew = 0;
  double err = 0;

  do {
    double newLen = len / 2;
    double integValPrev = integVal;
    double tmp = lbord + newLen;

    iNew = 0;
    for (int i = 0; i < n; ++i) {
      iNew += func(tmp);
      tmp += len;
    }
    iNew *= newLen * 4.0 / 3.0;
    integVal = iNew + integValPrev / 2.0 - iPrev;

    err = (integVal - integValPrev) / 3.0;

    n = 2 * n;
    len = newLen;
    iPrev = iNew / 4.0;
    (*count)++;
    
  } while (fabs(err) >= eps);

  return integVal; // +err;
}
