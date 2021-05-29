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

#define TRANSLACJA_ROTOR_LEWY_PRZEDNI   5,4,5
#define TRANSLACJA_ROTOR_PRAWY_PRZEDNI  5,-4,5
#define TRANSLACJA_ROTOR_LEWY_TYLNY    -5,4,5
#define TRANSLACJA_ROTOR_PRAWY_TYLNY   -5,-4,5  

    double argumentsV1[] = {5,4,5};
    double argumentsV2[] = {5,-4,5};
    double argumentsV3[] = {-5,4,5};
    double argumentsV4[] = {-5,-4,5};
    Vector<SIZE> wek1=argumentsV1;
    Vector<SIZE> wek2=argumentsV2;
    Vector<SIZE> wek3=argumentsV3;
    Vector<SIZE> wek4=argumentsV4;
     const char *NazwyPlikowWlasciwychrotory[]= {  PLIK_WLASCIWY__DRON1_ROTOR1,
					 PLIK_WLASCIWY__DRON1_ROTOR2, PLIK_WLASCIWY__DRON1_ROTOR3,
					 PLIK_WLASCIWY__DRON1_ROTOR4, nullptr
                                        };
      const char *NazwyPlikowWlasciwychkorpusy[]= { PLIK_WLASCIWY__DRON1_KORPUS  , nullptr
                                        };                                  