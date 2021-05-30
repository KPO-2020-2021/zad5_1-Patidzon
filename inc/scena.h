#pragma once

#include <iostream>
#include <cmath>
#include <size.h>
#include "brylawzorcowa.h"
#include "vector.h"
#include "prostopadloscian.h"
#include "graniastoslup.h"
#include "dron.h"

class scena
{
private:
    dron drony[2];
public:
void wybierzdrona(int nrdrona);
    scena(/* args */);
    ~scena();
};

scena::scena(/* args */)
{
}

scena::~scena()
{
}
