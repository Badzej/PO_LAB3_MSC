#include "SygnalSinusoidalny.h"
#include <cmath>
SygnalSinusoidalny::SygnalSinusoidalny(double amp,double czest): amplituda(amp), czestotliwosc(czest){
  xn_1=amplituda*sin(czestotliwosc);
}

double SygnalSinusoidalny::symuluj(){
  if (stan_symulacji > 1) {
    double wyjscie = 2*cos(czestotliwosc)*xn_1 - xn_2;
    xn_2 = xn_1;
    xn_1 = wyjscie;
    return wyjscie;
  }
  else if (stan_symulacji > 0 ) {
    stan_symulacji++;
    return xn_1;
  }
  stan_symulacji++;
  return xn_2;
}