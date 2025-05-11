#pragma once
#include "Sygnal.h"
#include <memory>
#include "include_ext_lib/json.hpp"

class SygnalZNasyceniem : public Sygnal {
    std::unique_ptr<Sygnal> komponent;
    double maks_amplituda;

public:
    SygnalZNasyceniem(std::unique_ptr<Sygnal> k, double max_amp);
    SygnalZNasyceniem(const nlohmann::json& j);
    double symuluj() override;
    nlohmann::json serializuj() override;
};