#pragma once
#include "Sygnal.h"
class SygnalTrojkatny: public Sygnal{
    double amplituda;
    double czestotliwosc;
    double faza;
public:
    SygnalTrojkatny(double amp,double czest);
    double symuluj() override;
};
