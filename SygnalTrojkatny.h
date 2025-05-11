#pragma once
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class SygnalTrojkatny
 * @brief Klasa reprezentująca sygnał trójkatny.
 */
class SygnalTrojkatny: public Sygnal{
    double amplituda;
    double czestotliwosc;
    double faza;
public:
    /**
     * @brief Konstruktor sygnału trójkątnego.
     * @param amp Amplituda.
     * @param czest Częstotliwość.
     */
    SygnalTrojkatny(double amp,double czest);

    /**
     * @brief Konstruktor deserializujący z JSON-a.
     * @param j Obiekt JSON z parametrami sygnału.
     */
    explicit SygnalTrojkatny(const nlohmann::json &j);

    /**
     * @brief Generuje kolejną próbkę sygnału trójkątnego.
     * @return Wartość próbki.
     */
    double symuluj() override;

    /**
     * @brief Serializuje sygnał do formatu JSON.
     * @return Obiekt JSON z parametrami.
     */
    nlohmann::json serializuj() override;
};
