#pragma once

#include <iostream>
#include <cmath>
#include <size.h>
#include "brylawzorcowa.h"
#include "vector.h"
#include "prostopadloscian.h"
#include "graniastoslup.h"
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
};

dron::dron(/* args */)
{
}

dron::~dron()
{
}
