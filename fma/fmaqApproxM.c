#include <math.h>
#include "fmaqApprox.h"

__float128 fmaqApprox(__float128 x, __float128 y, __float128 z) {
  return fmal(x, y, z);
}

double fmadApprox(double x, double y, double z) {
  long double x128 = (long double) x;
  long double y128 = (long double) y;
  long double z128 = (long double) z;

  long double res =  fmal(x128, y128, z128);
  return (double)res;
}

float fmafApprox(float x, float y, float z) {
  long double x128 = (long double) x;
  long double y128 = (long double) y;
  long double z128 = (long double) z;

  long double res =  (long double)fmal (x128, y128, z128);
  return (float)res;
}
