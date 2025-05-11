#pragma once
#include <memory>
#include "Sygnal.h"

/**
 * @author Błażej Styrnol
 * @class SygnalKomponent
 * @brief Bazowa klasa dla dekoratorów sygnału.
 */
class SygnalKomponent : public Sygnal {
protected:
    std::unique_ptr<Sygnal> komponent;
public:
    /**
     * @brief Konstruktor z komponentem sygnałowym.
     * @param k Wskaźnik do sygnału bazowego.
     */
    explicit SygnalKomponent(std::unique_ptr<Sygnal> k);
};
