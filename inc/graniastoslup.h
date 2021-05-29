#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <size.h>
#include "brylawzorcowa.h"
#include "vector.h"
#include "matrix.h"
#include <fstream>
class graniastoslup: public brylawzorcowa
{
private:
  Vector<SIZE> wierzcholkiwzor[SIZE1];
  Vector<SIZE> wierzcholki[SIZE1];
  double katorient;
 Vector<SIZE> polozenie;
  Vector<SIZE> przesunieciewzgkorpusu;
 Vector<SIZE> skala;

public:
   // graniastoslup();
 
    void  zaladujwspwzor();
    void Przesunwierzcholki();
    void Obrocwierzcholki();
    void zapiszwsp (const char* nazwaplikuzapisu);
    void przekazparametryprzesuniecia(Vector<SIZE> polozenie1, double kat );
    void przekazparametrykonstrukcji( Vector<SIZE> przesunieciewzgkorpusu1, Vector<SIZE> skala1);
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
       
       plik>>wierzcholkiwzor[i];
       
       
     }
  
}
else {
  std::cout<<"nie mozna odczytac pliku"<<std::endl;
  exit(0);}
plik.close();
}
/*!
*****************************************************************************
 | \brief Metoda klasy graniastoslup.                                                 |
 |  Argumenty:                                                                |
 |     nazwaplikuzapisu-nazwa pliku do ktorej zostana zapisane wspolrzedne graniastoslupa                                                      |
 |      zapisuje do pliku wartosci z macierzy .                                       |
 */
void graniastoslup::zapiszwsp (const char* nazwaplikuzapisu){

int i;
std::ofstream plik;
plik.open(nazwaplikuzapisu,std::ios::out);
if (plik.good()==true)
{
for ( i = 0; i <SIZE1; i++)
     {
       
       plik<<wierzcholki[i]<<std::endl;
      i++;
      plik<<wierzcholki[i]<<std::endl;
      i++;
      plik<<wierzcholki[i]<<std::endl;
      i++;
       plik<<wierzcholki[i]<<std::endl<<std::endl;
       
     }
  
}
else {
  std::cout<<"nie mozna odczytac pliku"<<std::endl;
  exit(0);}
plik.close();
  }

/*!
*****************************************************************************
 | \brief Metoda klasy graniastoslup.                                                 |
 |  Argumenty:    brak                                                            |                                                |
 |      oblicza wspolrzedne wierzcholkow graniastoslupa                                     |
 */
void graniastoslup::Przesunwierzcholki(){
for ( int i = 0; i < SIZE1; i++)
     {
       
       wierzcholki[i]=wierzcholkiwzor[i]*skala+przesunieciewzgkorpusu+polozenie;
       
       
     }


}

/*!
*****************************************************************************
 | \brief Metoda klasy graniastoslup.                                                 |
 |  Argumenty:    brak                                                            |                                                |
 |      oblicza wspolrzedne wierzcholkow graniastoslupa z uwzglednieniem obroty                                    |
 */
void graniastoslup::Obrocwierzcholki(){

Matrix<SIZE> macierz=Matrix<SIZE>('z',katorient);

for ( int i = 0; i < SIZE1; i++)
     {
       
       wierzcholki[i]=macierz*(wierzcholkiwzor[i]*skala)+przesunieciewzgkorpusu+polozenie;
       
       
     }



}

