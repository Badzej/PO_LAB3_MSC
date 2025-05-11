// SygnalFactory.h
#pragma once
#include <memory>
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

class SygnalFabryka {
public:
    static std::unique_ptr<Sygnal> stworz_z_json(const nlohmann::json& j);
};