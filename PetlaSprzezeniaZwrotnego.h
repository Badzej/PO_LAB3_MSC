#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"

/**
 * @author Błażej Styrnol
 * @class PetlaSprzezeniaZwrotnego
 * @brief Implementacja funktora symulujacego jeden krok petli sprzezenia zwrotnego
 */
class PetlaSprzezeniaZwrotnego {
public:
    [[nodiscard]] double operator()(RegulatorPID& regulator, ModelARX& model,const double wartosc_zadana = 1.0) ;
};