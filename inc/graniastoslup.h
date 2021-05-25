#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <size.h>
#include "brylawzorcowa.h"
#include "vector.h"
#include <fstream>
class graniastoslup: public brylawzorcowa
{
private:
  Vector<SIZE> bokiwzor[SIZE1];
  Vector<SIZE> boki[SIZE1];
  double katorient;
 Vector<SIZE> polozenie;
  Vector<SIZE> przesunieciewzgkorpusu;


public:
   // graniastoslup();
 
    void  zaladujwspwzor();
    void Obliczwierzcholki();
    void zapiszwierzcholki();
};

/*graniastoslup::graniastoslup()
{
}
*/

/*!
*****************************************************************************
 | \brief Metoda klasy graniastoslup.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartosciami z pliku .                                       |
 */
 void graniastoslup::zaladujwspwzor (){
   int i;
std::fstream plik;
plik.open(nazwaplikugraniastoslup,std::ios::in);
if (plik.good()==true)
{
for ( i = 0; i < SIZE1; i++)
     {
       
       plik>>bokiwzor[i];
       
       
     }
  
}
else {
  std::cout<<"nie mozna odczytac pliku"<<std::endl;
  exit(0);}
plik.close();
}
