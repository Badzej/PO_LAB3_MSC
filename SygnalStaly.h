#pragma once
#include "Sygnal.h"


class SygnalStaly : public Sygnal{
    double amplituda;
    public:
      SygnalStaly(double amp);
      double symuluj() override;
};
