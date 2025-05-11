#pragma once
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

class SygnalSinusoidalny: public Sygnal{
    double amplituda;
    double czestotliwosc;
    double xn_1;
    double xn_2=0;
    int stan_symulacji=0;
    public:
      SygnalSinusoidalny(double amp,double czest);
    explicit SygnalSinusoidalny(const nlohmann::json& j);
      double symuluj() override;
    nlohmann::json serializuj() override;
};
