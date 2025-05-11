#pragma once
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

class SygnalProstokatny: public Sygnal{
    double amplituda;
    double czestotliwosc;
    double wypelnienie;
    double faza;
public:
    SygnalProstokatny(double amp,double czest,double wypel);
    explicit SygnalProstokatny(const nlohmann::json& j); //Konstruktor deserializujacy
    double symuluj() override;
    nlohmann::json serializuj() override;
};
