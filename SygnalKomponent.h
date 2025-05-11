#pragma once
#include <memory>
#include "Sygnal.h"

class SygnalKomponent : public Sygnal {
protected:
    std::unique_ptr<Sygnal> komponent;
public:
    explicit SygnalKomponent(std::unique_ptr<Sygnal> k);
};
