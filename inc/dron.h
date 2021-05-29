#pragma once

#include <iostream>
#include <cmath>
#include <size.h>
#include "brylawzorcowa.h"
#include "vector.h"
#include "prostopadloscian.h"
#include "graniastoslup.h"
#include <cstdlib>
#include "matrix.h"
#include <fstream>
class dron
{
private:
    prostopadloscian korpus;
    graniastoslup rotory[4];
    double katorient;
    Vector<SIZE> polozenie;
public:
    dron(/* args */);
    ~dron();
  void  tworzdrona();
  void  przemiescdron(Vector<SIZE> przesuniecie);
  void  obrocdron(double kat);
  void  lotzwiadowczy();
};

dron::dron(/* args */)
{
}

dron::~dron()
{
}
