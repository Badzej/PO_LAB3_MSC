#include "SygnalZNasyceniem.h"

#include "SygnalFabryka.h"



SygnalZNasyceniem::SygnalZNasyceniem(std::unique_ptr<Sygnal> k, double max_amp)
    : komponent(std::move(k)), maks_amplituda(max_amp) {}

SygnalZNasyceniem::SygnalZNasyceniem(const nlohmann::json &j):
komponent(SygnalFabryka::stworz_z_json(j["sygnal"])),maks_amplituda(j["maks_amplituda"].get<double>()){
}


double SygnalZNasyceniem::symuluj() {
    double wynik = komponent->symuluj();
    if (wynik > maks_amplituda) return maks_amplituda;
    if (wynik < -maks_amplituda) return -maks_amplituda;
    return wynik;
}

nlohmann::json SygnalZNasyceniem::serializuj() {
    return {
                    {"typ", "nasycenie"},
                    {"sygnal", komponent->serializuj()},
                    {"maks_amplituda", maks_amplituda}
    };
}
