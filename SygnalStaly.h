#pragma once
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class SygnalStaly
 * @brief Klasa reprezentująca sygnał o stałej wartości.
 */
class SygnalStaly : public Sygnal{
    double amplituda;
public:
    /**
     * @brief Konstruktor sygnału stałego.
     * @param amp Amplituda (stała wartość) sygnału.
     */
    explicit SygnalStaly(double amp);

    /**
     * @brief Konstruktor deserializujący z obiektu JSON.
     * @param j Obiekt JSON z parametrami sygnału.
     */
    explicit SygnalStaly(const nlohmann::json &j);

    /**
     * @brief Zwraca stałą wartość sygnału.
     * @return Amplituda sygnału.
     */
    double symuluj() override;

    /**
     * @brief Serializuje parametry sygnału do formatu JSON.
     * @return Obiekt JSON zawierający konfigurację sygnału.
     */
    nlohmann::json serializuj() override;
};
