#pragma once

#include <iostream>
#include <cmath>
#include <size.h>
#include "brylawzorcowa.h"
#include "vector.h"

class prostopadloscian: public brylawzorcowa

{
private:
     Vector<SIZE> bokiwzor[SIZE2];
  Vector<SIZE> boki[SIZE2];
  double katorient;
   Vector<SIZE> polozenie;
  Vector<SIZE> przesunieciewzgkorpusu;

public:
    prostopadloscian(/* args */);
    ~prostopadloscian();
};

prostopadloscian::prostopadloscian(/* args */)
{
}

prostopadloscian::~prostopadloscian()
{
}
