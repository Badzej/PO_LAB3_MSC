// SygnalIO.cpp
#include "SygnalIO.h"
#include "SygnalFabryka.h"
#include <fstream>

void SygnalIO::zapiszDoPliku(const std::string& sciezka, const std::unique_ptr<Sygnal>& sygnal) {
    nlohmann::json j = sygnal->serializuj();
    std::ofstream plik(sciezka);
    plik << j.dump(4); // zapis z ładnym formatowaniem
}

std::unique_ptr<Sygnal> SygnalIO::wczytajZPliku(const std::string& sciezka) {
    std::ifstream plik(sciezka);
    nlohmann::json j;
    plik >> j;
    return SygnalFabryka::stworz_z_json(j);
}