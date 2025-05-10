#pragma once
#include "Sygnal.h"
class SygnalProstokatny: public Sygnal{
    double amplituda;
    double czestotliwosc;
    double wypelnienie;
    double faza;
public:
    SygnalProstokatny(double amp,double czest,double wypel);
    double symuluj() override;
};
