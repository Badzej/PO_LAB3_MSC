
#include "SygnalProstokatny.h"
#include <cmath>

SygnalProstokatny::SygnalProstokatny(double amp,double czest,double wypel):
    amplituda(amp),
    czestotliwosc(czest),
    wypelnienie(wypel),
    faza(0.0)
{};

SygnalProstokatny::SygnalProstokatny(const nlohmann::json &j) :
    amplituda(j["amplituda"].get<double>()),
    czestotliwosc(j["czestotliwosc"].get<double>()),
    wypelnienie(j["wypelnienie"].get<double>()),
    faza(j["faza"].get<double>()){
}

double SygnalProstokatny::symuluj() {
    faza += czestotliwosc;
    if (faza >= 2 * M_PI)
        faza -= 2 * M_PI;
    double granica = 2 * M_PI * wypelnienie;
    return (faza < granica) ? amplituda : -amplituda;
};

nlohmann::json SygnalProstokatny::serializuj() {
    return {
            {"typ", "prostokatny"},
            {"amplituda", amplituda},
            {"czestotliwosc", czestotliwosc},
            {"wypelnienie", wypelnienie},
            {"faza", faza}
    };
}

