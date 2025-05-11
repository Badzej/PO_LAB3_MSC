// SygnalFactory.h
#pragma once
#include <memory>
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class SygnalFabryka
 * @brief Fabryka tworząca sygnały na podstawie JSON-a.
 */
class SygnalFabryka {
public:
    /**
     * @brief Tworzy sygnał na podstawie typu w JSON.
     * @param j Obiekt JSON z danymi.
     * @return Wskaźnik do nowo utworzonego obiektu Sygnal.
     */
    static std::unique_ptr<Sygnal> stworz_z_json(const nlohmann::json& j);
};