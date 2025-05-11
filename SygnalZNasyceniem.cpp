#include "SygnalZNasyceniem.h"

#include "SygnalFabryka.h"



SygnalZNasyceniem::SygnalZNasyceniem(std::unique_ptr<Sygnal> k, double max_amp)
    : SygnalKomponent(std::move(k)),
        maks_amplituda(max_amp) {}

SygnalZNasyceniem::SygnalZNasyceniem(const nlohmann::json &j):
SygnalKomponent(SygnalFabryka::stworz_z_json(j["sygnal_podstawowy"])),maks_amplituda(j["maks_amplituda"].get<double>()){
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
                    {"sygnal_podstawowy", komponent->serializuj()},
                    {"maks_amplituda", maks_amplituda}
    };
}
