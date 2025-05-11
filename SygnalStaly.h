#pragma once
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

class SygnalStaly : public Sygnal{
    double amplituda;
public:
  SygnalStaly(double amp);
    SygnalStaly(const nlohmann::json &j);
  double symuluj() override;
  nlohmann::json serializuj() override;
};
