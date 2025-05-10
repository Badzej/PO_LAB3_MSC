
#include "SygnalProstokatny.h"
#include <cmath>

SygnalProstokatny::SygnalProstokatny(double amp,double czest,double wypel):
    amplituda(amp),
    czestotliwosc(czest),
    wypelnienie(wypel),
    faza(0.0)
    // sinusoida(amp,czest)
{};
double SygnalProstokatny::symuluj() {
    faza += czestotliwosc;
    if (faza >= 2 * M_PI)
        faza -= 2 * M_PI;
    double granica = 2 * M_PI * wypelnienie;
    return (faza < granica) ? amplituda : -amplituda;
};
