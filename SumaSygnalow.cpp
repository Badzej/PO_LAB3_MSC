
#include "SumaSygnalow.h"
#include "SygnalFabryka.h"
SumaSygnalow::SumaSygnalow(std::unique_ptr<Sygnal> k, std::unique_ptr<Sygnal> dodawany_sygnal):
    SygnalKomponent(std::move(k)),
        nowy_sygnal(std::move(dodawany_sygnal)) {}

double SumaSygnalow::symuluj(){
    return komponent->symuluj() + nowy_sygnal->symuluj();
}

SumaSygnalow::SumaSygnalow(const nlohmann::json& j):
SygnalKomponent(SygnalFabryka::stworz_z_json(j["sygnal_podstawowy"])),
nowy_sygnal(SygnalFabryka::stworz_z_json(j["dodawany_sygnal"]))
{}

nlohmann::json SumaSygnalow::serializuj() {
    return {
                        {"typ", "suma_sygnalow"},
                        {"sygnal_podstawowy", komponent->serializuj()},
                        {"dodawany_sygnal", nowy_sygnal->serializuj()}
    };
}