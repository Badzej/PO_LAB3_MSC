#pragma once
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class SygnalProstokatny
 * @brief Klasa reprezentująca sygnał prostokątny.
 */
class SygnalProstokatny: public Sygnal{
    double amplituda;
    double czestotliwosc;
    double wypelnienie;
    double faza = 0.0;
public:
    /**
     * @brief Konstruktor sygnału prostokątnego.
     * @param amp Amplituda sygnału.
     * @param czest Częstotliwość sygnału.
     * @param wypel Wypełnienie (długość impulsu względem okresu).
     */
    SygnalProstokatny(double amp,double czest,double wypel);
    /**
     * @brief Konstruktor deserializujący z obiektu JSON.
     * @param j Obiekt JSON z parametrami sygnału.
     */
    explicit SygnalProstokatny(const nlohmann::json& j); //Konstruktor deserializujacy
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
