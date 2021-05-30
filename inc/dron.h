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
#include "lacze_do_gnuplota.hh"

class dron
{
private:
    prostopadloscian korpus;
    graniastoslup rotory[4];
    double katorient=0;
    Vector<SIZE> polozenie=V1;
     Vector<SIZE> polozeniepoczatkowe;
    Vector<SIZE> skalarotor=skalarotor1;
    Vector<SIZE> skalakorpus=skalakorpus1;
    Vector<SIZE> polozenierotorow[4]={wek1,wek2,wek3,wek4};
public:
    dron(/* args */);
    ~dron();
  void  tworzdrona();
  void  przemiescdron(/*Vector<SIZE> przesuniecie*/);
 
  void  lotzwiadowczy();
  void  ustawparametry(Vector<SIZE> polozenie2, double kat);
  void ustawpolozeniepoczatkowe(Vector<SIZE> polozeniepoczatkowe1);
  void przesundron();
  void obrocdron();
  void animacjalotu(PzG::LaczeDoGNUPlota  Lacze);
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
  int j=0;
  polozeniepoczatkowe=V2; 
  ustawparametry(V1,0);
for (unsigned int Idx = 0; NazwyPlikowWlasciwychrotory[Idx] != nullptr; ++Idx) 
{
  rotory[Idx].przekazparametrykonstrukcji(polozenierotorow[j],skalarotor);
  rotory[Idx].ustawpolozeniepoczatkowe(V2);
 // std::cout<<polozenierotorow[j]<<std::endl<<skalarotor<<std::endl;
 //rotory[Idx].przekazparametryprzesuniecia(polozenie,katorient);
 //std::cout<<polozenie<<std::endl<<katorient<<std::endl;
 rotory[Idx].zaladujwspwzor();
 rotory[Idx].Przesunwierzcholki();
 rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[Idx]);

 j++;
 //rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[Idx]);
}
for (unsigned int Idx = 0; NazwyPlikowWlasciwychkorpusy[Idx] != nullptr; ++Idx) {
korpus.przekazparametrykonstrukcji(skalakorpus);
korpus.ustawpolozeniepoczatkowe(V2+V3);
 //korpus.przekazparametryprzesuniecia(polozenie,katorient);
 korpus.zaladujwspwzor();
 korpus.Przesunwierzcholki();
 //std::cout<<std::endl<<"1"<<std::endl;
korpus.zapiszwsp(NazwyPlikowWlasciwychkorpusy[Idx]);
  //std::cout<<std::endl<<"2"<<std::endl;
}

}
void dron::ustawparametry(Vector<SIZE> polozenie2, double kat){
polozenie=polozenie2;
katorient=kat;



}
void dron::ustawpolozeniepoczatkowe(Vector<SIZE> polozeniepoczatkowe1){

polozeniepoczatkowe=polozeniepoczatkowe1;
for (unsigned int Idx = 0; NazwyPlikowWlasciwychrotory[Idx] != nullptr; ++Idx) 
{
  rotory[Idx].ustawpolozeniepoczatkowe(polozeniepoczatkowe);
}
for (unsigned int Idx = 0; NazwyPlikowWlasciwychkorpusy[Idx] != nullptr; ++Idx) {
korpus.ustawpolozeniepoczatkowe(polozeniepoczatkowe);
}

}

void dron::przesundron(){
 
for (unsigned int Idx = 0; NazwyPlikowWlasciwychrotory[Idx] != nullptr; ++Idx) 
{
  

 // std::cout<<polozenierotorow[j]<<std::endl<<skalarotor<<std::endl;

 rotory[Idx].przekazparametryprzesuniecia(polozenie,katorient);
 //std::cout<<polozenie<<std::endl<<katorient<<std::endl;
 rotory[Idx].zaladujwspwzor();
 rotory[Idx].Przesunwierzcholki();
 rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[Idx]);


 //rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[Idx]);
}
for (unsigned int Idx = 0; NazwyPlikowWlasciwychkorpusy[Idx] != nullptr; ++Idx) {

 korpus.przekazparametryprzesuniecia(polozenie,katorient);
 korpus.zaladujwspwzor();
 korpus.Przesunwierzcholki();
 //std::cout<<std::endl<<"1"<<std::endl;
korpus.zapiszwsp(NazwyPlikowWlasciwychkorpusy[Idx]);
  //std::cout<<std::endl<<"2"<<std::endl;
}



}
void dron::obrocdron(){
    
for (unsigned int Idx = 0; NazwyPlikowWlasciwychrotory[Idx] != nullptr; ++Idx) 
{
  

 // std::cout<<polozenierotorow[j]<<std::endl<<skalarotor<<std::endl;
 
 rotory[Idx].przekazparametryprzesuniecia(polozenie,katorient);
 //std::cout<<polozenie<<std::endl<<katorient<<std::endl;
 rotory[Idx].zaladujwspwzor();
 rotory[Idx].Obrocwierzcholki();
 rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[Idx]);


 //rotory[Idx].zapiszwsp(NazwyPlikowWlasciwychrotory[Idx]);
}
for (unsigned int Idx = 0; NazwyPlikowWlasciwychkorpusy[Idx] != nullptr; ++Idx) {

 korpus.przekazparametryprzesuniecia(polozenie,katorient);
 korpus.zaladujwspwzor();
 korpus.Obrocwierzcholki();
 //std::cout<<std::endl<<"1"<<std::endl;
korpus.zapiszwsp(NazwyPlikowWlasciwychkorpusy[Idx]);
  //std::cout<<std::endl<<"2"<<std::endl;
}



}

void dron::animacjalotu(PzG::LaczeDoGNUPlota  Lacze){
  int kat=1,katbackup=katorient;
  double dlugosclotu;
  Vector<SIZE> V4=argumentsV10;
  std::cout<<V4<<std::endl;
  while ((kat%5)!=0)
  {
     std::cout<<"podaj kat obrotu drona(wielokrotnosc 5"<<std::endl;
  std::cin>>kat;
  }
  std::cout<<"podaj dlugosc lotu"<<std::endl;
  std::cin>>dlugosclotu;
  
    std::cout<<polozenie<<std::endl;
    std::cout<<katorient<<std::endl;
  //-------------------------------------
  // Wznoszenie ...
  //
  //std::cout << std::endl << "Wznoszenie ... " << std::endl;
  for (int i = 0; i < 100; i=i+2)
  { 
     V4=V4+V3;
    ustawparametry(V4,katbackup);
  
    obrocdron();
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();

  }
  
    // cout << "Zmiana orientacji ... " << endl;
  for (int i=0; i <= kat; i+= 5) {
    ustawparametry(V4,katbackup+i);
   obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
// ustawpolozeniepoczatkowe(V4);
  for (int i=0; i <= dlugosclotu; i+= 1) {
    V4=V4+V5;
    ustawparametry(V4,katorient);
   obrocdron();
    usleep(100000);
    Lacze.Rysuj();
  }
    for (int i = 100; i > 0; i=i-2)
  {
     V4=V4-V3;
    ustawparametry(V4,katorient);
    obrocdron();
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }
    std::cout<<polozenie<<std::endl<<polozeniepoczatkowe<<std::endl;
  ustawpolozeniepoczatkowe((polozenie+polozeniepoczatkowe));
  std::cout<<katorient<<std::endl;
  std::cout<<polozeniepoczatkowe;

}