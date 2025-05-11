#pragma once
#include "Sygnal.h"
#include <memory>

#include "SygnalKomponent.h"
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class SygnalZNasyceniem
 * @brief Dekorator ograniczający wartość sygnału do zadanej amplitudy.
 */
class SygnalZNasyceniem : public SygnalKomponent {
    double maks_amplituda;

public:
    /**
     * @brief Konstruktor dekoratora z limitem amplitudy.
     * @param k Bazowy sygnał do ograniczenia.
     * @param max_amp Maksymalna dopuszczalna amplituda (dodatnia i ujemna).
     */
    SygnalZNasyceniem(std::unique_ptr<Sygnal> k, double max_amp);

    /**
     * @brief Konstruktor deserializujący z obiektu JSON.
     * @param j Obiekt JSON z konfiguracją.
     */
    explicit SygnalZNasyceniem(const nlohmann::json& j);

    /**
     * @brief Generuje próbkę sygnału z ograniczoną amplitudą.
     * @return Wartość sygnału przycięta do zadanego zakresu.
     */
    double symuluj() override;

    /**
     * @brief Serializuje dekorowany sygnał do formatu JSON.
     * @return Obiekt JSON zawierający konfigurację.
     */
    nlohmann::json serializuj() override;
};