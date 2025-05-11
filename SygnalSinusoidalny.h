#pragma once
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class SygnalSinusoidalny
 * @brief Klasa generująca przebieg sinusoidalny.
 */
class SygnalSinusoidalny: public Sygnal{
    double amplituda;
    double czestotliwosc;
    double xn_1;
    double xn_2=0;
    int stan_symulacji=0;
public:
    /**
     * @brief Konstruktor sygnału sinusoidalnego.
     * @param amp Amplituda sygnału.
     * @param czest Częstotliwość sygnału.
     */
    SygnalSinusoidalny(double amp,double czest);

    /**
     * @brief Konstruktor deserializujący z obiektu JSON.
     * @param j Obiekt JSON z parametrami sygnału.
     */
    explicit SygnalSinusoidalny(const nlohmann::json& j);

    /**
     * @brief Generuje kolejną wartość próbki sygnału.
     * @return Wartość sygnału w danym kroku.
     */
      double symuluj() override;

    /**
     * @brief Serializuje parametry sygnału do formatu JSON.
     * @return Obiekt JSON zawierający konfigurację sygnału.
     */
    nlohmann::json serializuj() override;
};
