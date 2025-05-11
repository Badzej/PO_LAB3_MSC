#include "SygnalTrojkatny.h"
#include "cmath"
SygnalTrojkatny::SygnalTrojkatny(double amp, double czest)
    : amplituda(amp), czestotliwosc(czest), faza(0.0) {}
double SygnalTrojkatny::symuluj() {
    faza += czestotliwosc;
    if (faza > 2 * M_PI) faza -= 2 * M_PI;
    return (2 * amplituda / M_PI) * asin(sin(faza));
}

SygnalTrojkatny::SygnalTrojkatny(const nlohmann::json &j) :
amplituda(j["amplituda"].get<double>()),
czestotliwosc(j["czestotliwosc"].get<double>()), faza(j["faza"].get<double>()){}


nlohmann::json SygnalTrojkatny::serializuj() {
    return {
                {"typ", "trojkatny"},
                {"amplituda", amplituda},
                {"czestotliwosc", czestotliwosc},
                {"faza", faza}
    };
}
