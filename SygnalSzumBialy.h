#pragma once
#include "Sygnal.h"
#include <random>
#include "include_ext_lib/json.hpp"

class SygnalSzumBialy : public Sygnal {
private:
    std::default_random_engine generator;
    std::uniform_real_distribution<double> rozklad;
public:
    explicit SygnalSzumBialy(double sigma);
    explicit SygnalSzumBialy(const nlohmann::json &j);
    double symuluj() override;
    nlohmann::json serializuj() override;
};