
#include "SygnalSzumBialy.h"
#include <random>


SygnalSzumBialy::SygnalSzumBialy(double sigma)  :
    generator(std::random_device{}()),
    rozklad(-sigma, sigma) {}

double SygnalSzumBialy::symuluj()  {
    return rozklad(generator);  // Zwraca losową próbkę szumu
}

SygnalSzumBialy::SygnalSzumBialy(const nlohmann::json &j) :
generator(std::random_device{}()),
rozklad(-j["sigma"].get<double>(), j["sigma"].get<double>()){
}


nlohmann::json SygnalSzumBialy::serializuj() {
    return {
                {"typ", "szum_bialy"},
                {"sigma", rozklad.max()},
    };
}