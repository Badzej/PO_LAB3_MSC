#include "PetlaSprzezeniaZwrotnego.h"
    double PetlaSprzezeniaZwrotnego::operator()(RegulatorPID& regulator, ModelARX& model,const double wartosc_zadana) {

        double poprzednie_wyjscie = model.pobierzOstatnieWyjscie();

        double uchyb = wartosc_zadana - poprzednie_wyjscie;

        double sterowanie = regulator.symuluj(uchyb);

        double wyjscie = model.symuluj(sterowanie);
        
        return wyjscie;
    }