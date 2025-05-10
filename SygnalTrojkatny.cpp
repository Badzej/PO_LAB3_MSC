#include "SygnalTrojkatny.h"
#include "cmath"
SygnalTrojkatny::SygnalTrojkatny(double amp, double czest)
    : amplituda(amp), czestotliwosc(czest), faza(0.0) {}
double SygnalTrojkatny::symuluj() {
    faza += czestotliwosc;
    if (faza > 2 * M_PI) faza -= 2 * M_PI;
    return (2 * amplituda / M_PI) * asin(sin(faza));
}