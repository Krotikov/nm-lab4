#ifndef LOBATTO_H
#define LOBATTO_H

#include "func.h"


struct Lobatto {
  Lobatto(double lbord, double rbord, double (*func)(double))
  : lbord(lbord), rbord(rbord), func(func) {}

  double calc(double eps, int* count);

  double calc(double eps);


  ~Lobatto() {}
  
  double lbord;
  double rbord; 
  double (*func)(double);
};

#endif /*LOBATTO_H*/