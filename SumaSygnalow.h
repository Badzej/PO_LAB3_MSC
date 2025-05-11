#pragma once
#include "Sygnal.h"
#include "SygnalKomponent.h"
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class SumaSygnalow
 * @brief Dekorator sumujący sygnał bazowy k z nowym sygnałem, utworzony sygnał jest interpretowany jako jeden.
 */
class SumaSygnalow : public SygnalKomponent{
    std::unique_ptr<Sygnal> nowy_sygnal;
public:
    /**
     * @brief Konstruktor dekoratora sumujący dwa sygnały.
     * @param k Główny sygnał bazowy.
     * @param dodawany_sygnal Drugi sygnał do dodania.
     */
    explicit SumaSygnalow(std::unique_ptr<Sygnal> k, std::unique_ptr<Sygnal> dodawany_sygnal);
    /**
     * @brief Konstruktor deserializujący z obiektu JSON.
     * @param j Obiekt JSON z konfiguracją.
     */
    explicit SumaSygnalow(const nlohmann::json& j);

    /**
     * @brief Generuje próbkę sumy sygnałów.
     * @return Wartość sygnału, suma dwóch sygnałów.
     */
    double symuluj() override;

    /**
     * @brief Serializuje dekorowany sygnał do formatu JSON.
     * @return Obiekt JSON zawierający konfigurację.
     */
    nlohmann::json serializuj() override;
};

