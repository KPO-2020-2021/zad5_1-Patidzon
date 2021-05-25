#pragma once

#include <iostream>
#include <cmath>
#include <size.h>
#include "brylawzorcowa.h"
#include "vector.h"
class granistoslup: public brylawzorcowa
{
private:
  Vector<SIZE> bokiwzor[SIZE1];
  Vector<SIZE> boki[SIZE1];
  double katorient;
  Vector<SIZE> przesuniecie;
  Vector<SIZE> przesunieciewzgkorpusu;


public:
    granistoslup(/* args */);
    ~granistoslup();
};

granistoslup::granistoslup(/* args */)
{
}

granistoslup::~granistoslup()
{
}
