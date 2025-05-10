#pragma once
#include "Sygnal.h"
class SygnalSinusoidalny: public Sygnal{
    double amplituda;
    double czestotliwosc;
    double xn_1;
    double xn_2=0;
    int stan_symulacji=0;
    public:
      SygnalSinusoidalny(double amp,double czest);
      double symuluj() override;
};
