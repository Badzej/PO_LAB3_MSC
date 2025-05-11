// SygnalFactory.cpp
#include "SygnalFabryka.h"
#include "SygnalSinusoidalny.h"
#include "SygnalStaly.h"
#include "SygnalSzumBialy.h"
#include "SygnalProstokatny.h"
#include "SygnalTrojkatny.h"
#include "SumaSygnalow.h"
#include "SygnalZNasyceniem.h"

std::unique_ptr<Sygnal> SygnalFabryka::stworz_z_json(const nlohmann::json& j) {
    std::string typ = j["typ"];
    if (typ == "sinusoidalny") {
        return std::make_unique<SygnalSinusoidalny>(j);
    } else if (typ == "prostokatny") {
        return std::make_unique<SygnalProstokatny>(j);
    } else if (typ == "szum_bialy") {
        return std::make_unique<SygnalSzumBialy>(j);
    } else if (typ == "trojkatny") {
        return std::make_unique<SygnalTrojkatny>(j);
    } else if (typ == "staly") {
        return std::make_unique<SygnalStaly>(j);
    } else if (typ == "nasycenie") {
        return std::make_unique<SygnalZNasyceniem>(j);
    } else if (typ == "suma_sygnalow") {
        return std::make_unique<SumaSygnalow>(j);
    } else {
        throw std::runtime_error("Nieznany typ sygnału: " + typ);
    }
}