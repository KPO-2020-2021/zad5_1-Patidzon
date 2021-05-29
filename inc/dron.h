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
#include <cassert>
#include <unistd.h>
#include <iomanip>

class dron
{
private:
    prostopadloscian korpus;
    graniastoslup rotory[4];
    double katorient;
    Vector<SIZE> polozenie;
    Vector<SIZE> skalarotor;
    Vector<SIZE> skalakorpus;
    Vector<SIZE> polozenierotorow[4]={wek1,wek2,wek3,wek4};
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
  /* for (unsigned int Idx = 0; NazwyPlikowWlasciwych[Idx] != nullptr; ++Idx) 
{}*/
}

dron::~dron()
{
}
void dron::tworzdrona(){
  int i=0;
for (unsigned int Idx = 0; NazwyPlikowWlasciwychrotory[Idx] != nullptr; ++Idx) 
{rotory[Idx].przekazparametrykonstrukcji(polozenierotorow[i],skalarotor);
 rotory[Idx].przekazparametryprzesuniecia(polozenie,katorient);
 rotory[Idx].zaladujwspwzor();
 rotory[Idx].Przesunwierzcholki();
 rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[Idx]);

}

}