#include "SygnalStaly.h"

SygnalStaly::SygnalStaly(double amp): amplituda(amp){};

double SygnalStaly::symuluj(){
  return amplituda;
}

SygnalStaly::SygnalStaly(const nlohmann::json &j) :
  amplituda(j["amplituda"]) {}

nlohmann::json SygnalStaly::serializuj() {
  return {
              {"typ", "staly"},
              {"amplituda", amplituda}
  };
}