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
  double katorient=0;
 Vector<SIZE> polozenie=V1;
 Vector<SIZE> polozeniepoczatkowe;
  Vector<SIZE> przesunieciewzgkorpusu;
 Vector<SIZE> skala;

public:
   // graniastoslup();
 
    void  zaladujwspwzor();
    void Przesunwierzcholki();
    void Obrocwierzcholki();
    void zapiszwsp (const char* nazwaplikuzapisu);
    void ustawpolozeniepoczatkowe(Vector<SIZE> polozeniepoczatkowe1);
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
       //std::cout<<wierzcholkiwzor[i];
       
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
       //std::cout<<wierzcholkiwzor[i]<<std::endl<<skala<<std::endl<<przesunieciewzgkorpusu<<std::endl<<polozenie<<std::endl<<polozeniepoczatkowe<<std::endl;
       wierzcholki[i]=wierzcholkiwzor[i]*skala+przesunieciewzgkorpusu+polozenie+polozeniepoczatkowe;
      // std::cout<<wierzcholki[i]<<std::endl;
       
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
       //std::cout<<wierzcholkiwzor[i]<<std::endl<<skala<<std::endl<<przesunieciewzgkorpusu<<std::endl<<polozenie<<std::endl<<polozeniepoczatkowe<<std::endl<<katorient<<std::endl;
       wierzcholki[i]=macierz*(wierzcholkiwzor[i]*skala+przesunieciewzgkorpusu)+polozenie+polozeniepoczatkowe;
       
       
     }



}

void graniastoslup::przekazparametrykonstrukcji(Vector<SIZE> przesunieciewzgkorpusu1, Vector<SIZE> skala1){
przesunieciewzgkorpusu=przesunieciewzgkorpusu1;
skala=skala1;



}
void graniastoslup::przekazparametryprzesuniecia(Vector<SIZE> polozenie1, double kat ){
polozenie=polozenie1;
katorient=kat;


}

void graniastoslup::ustawpolozeniepoczatkowe(Vector<SIZE> polozeniepoczatkowe1){

polozeniepoczatkowe=polozeniepoczatkowe1;


}