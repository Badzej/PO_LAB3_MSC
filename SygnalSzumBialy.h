#pragma once
#include "Sygnal.h"
#include <random>
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class SygnalSzumBialy
 * @brief Klasa reprezentująca biały szum.
 */
class SygnalSzumBialy : public Sygnal {
private:
    std::default_random_engine generator;
    std::uniform_real_distribution<double> rozklad;
public:
    /**
     * @brief Konstruktor tworzący generator białego szumu.
     * @param sigma Maksymalne wychylenie wartości (rozrzut).
     */
    explicit SygnalSzumBialy(double sigma);

    /**
     * @brief Konstruktor deserializujący z obiektu JSON.
     * @param j Obiekt JSON z parametrami szumu.
     */
    explicit SygnalSzumBialy(const nlohmann::json &j);

    /**
     * @brief Generuje losową próbkę szumu.
     * @return Wartość próbki z rozkładu jednostajnego.
     */
    double symuluj() override;

    /**
     * @brief Serializuje parametry sygnału do formatu JSON.
     * @return Obiekt JSON zawierający konfigurację szumu.
     */
    nlohmann::json serializuj() override;
};