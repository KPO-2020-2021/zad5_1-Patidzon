#pragma once
#include "vector.h"
constexpr int SIZE = 3;
constexpr int SIZE1 = 28;
constexpr int SIZE2 = 20;
constexpr double MINDIF =0.0000000001;

#define PLIK_WLASCIWY__DRON1_KORPUS  "../dat/PlikWlasciwy_Dron1_Korpus.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR1  "../dat/PlikWlasciwy_Dron1_Rotor1.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR2  "../dat/PlikWlasciwy_Dron1_Rotor2.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR3  "../dat/PlikWlasciwy_Dron1_Rotor3.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR4  "../dat/PlikWlasciwy_Dron1_Rotor4.dat"
#define PLIK_WLASCIWY__DRON2_KORPUS  "../dat/PlikWlasciwy_Dron2_Korpus.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR1  "../dat/PlikWlasciwy_Dron2_Rotor1.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR2  "../dat/PlikWlasciwy_Dron2_Rotor2.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR3  "../dat/PlikWlasciwy_Dron2_Rotor3.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR4  "../dat/PlikWlasciwy_Dron2_Rotor4.dat"
#define PLIK_TRASY_PRZELOTU "../dat/trasa_przelotu.dat"
/*
#define TRANSLACJA_ROTOR_LEWY_PRZEDNI   5,4,5
#define TRANSLACJA_ROTOR_PRAWY_PRZEDNI  5,-4,5
#define TRANSLACJA_ROTOR_LEWY_TYLNY    -5,4,5
#define TRANSLACJA_ROTOR_PRAWY_TYLNY   -5,-4,5  
*/
int liczbawektorow=0;
int calkowitaliczbawektorow=0;

    double argumentsV1[] = {5,4,5};
    double argumentsV2[] = {5,-4,5};
    double argumentsV3[] = {-5,4,5};
    double argumentsV4[] = {-5,-4,5};
      double argumentsV5[] = {10,8,4};
    double argumentsV6[] = {8,8,2};
        double argumentsV7[] = {20,20,0};
         double argumentsV8[] = {0,0,0};
          double argumentsV9[] = {0,0,2};
          double argumentsV10[] = {0,0,0};
            double argumentsV11[] = {1,0,0};
    Vector<SIZE> wek1=argumentsV1;
    Vector<SIZE> wek2=argumentsV2;
    Vector<SIZE> wek3=argumentsV3;
    Vector<SIZE> wek4=argumentsV4;
    
       Vector<SIZE> skalakorpus1=argumentsV5;
    Vector<SIZE> skalarotor1=argumentsV6;
    Vector<SIZE> V2=argumentsV7;
     Vector<SIZE> V1=argumentsV8;
     Vector<SIZE> V3=argumentsV9;
     
     Vector<SIZE> V5=argumentsV11;
     const char *NazwyPlikowWlasciwychrotory[][5]= {{  PLIK_WLASCIWY__DRON1_ROTOR1,
					 PLIK_WLASCIWY__DRON1_ROTOR2, PLIK_WLASCIWY__DRON1_ROTOR3,
					 PLIK_WLASCIWY__DRON1_ROTOR4, nullptr
                                        },{
                                          PLIK_WLASCIWY__DRON2_ROTOR1,
					 PLIK_WLASCIWY__DRON2_ROTOR2, PLIK_WLASCIWY__DRON2_ROTOR3,
					 PLIK_WLASCIWY__DRON2_ROTOR4, nullptr
                                        }};
      const char *NazwyPlikowWlasciwychkorpusy[][2]= {{ PLIK_WLASCIWY__DRON1_KORPUS  , nullptr
                                        },{PLIK_WLASCIWY__DRON2_KORPUS  , nullptr}};                                  