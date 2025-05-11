#pragma once
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"
class SygnalTrojkatny: public Sygnal{
    double amplituda;
    double czestotliwosc;
    double faza;
public:
    SygnalTrojkatny(double amp,double czest);
    SygnalTrojkatny(const nlohmann::json &j);
    double symuluj() override;
    nlohmann::json serializuj() override;
};
