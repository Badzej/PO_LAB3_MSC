#pragma once
#include "include_ext_lib/json.hpp"

class Sygnal {
public:
    virtual ~Sygnal() = default;
    virtual double symuluj() = 0;
    virtual nlohmann::json serializuj() = 0;
};



