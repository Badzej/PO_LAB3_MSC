#pragma once
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class Sygnal
 * @brief Abstrakcyjna klasa bazowa dla wszystkich typów sygnałów.
 */
class Sygnal {
public:
    virtual ~Sygnal() = default;

    /**
     * @brief Symuluje jedną próbkę sygnału.
     * @return Wartość próbki.
     */
    virtual double symuluj() = 0;

    /**
     * @brief Serializuje sygnał do obiektu JSON.
     * @return Obiekt JSON reprezentujący stan sygnału.
     */
    virtual nlohmann::json serializuj() = 0;
};



