#pragma once
#include "Sygnal.h"
#include "SygnalKomponent.h"
#include "include_ext_lib/json.hpp"

class SumaSygnalow : public SygnalKomponent{
    std::unique_ptr<Sygnal> nowy_sygnal;
public:
    explicit SumaSygnalow(std::unique_ptr<Sygnal> k, std::unique_ptr<Sygnal> dodawany_sygnal);
    SumaSygnalow(const nlohmann::json& j);
    double symuluj() override;
    nlohmann::json serializuj() override;
};

