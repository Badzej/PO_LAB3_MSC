
#include "SygnalKomponent.h"

SygnalKomponent::SygnalKomponent(std::unique_ptr<Sygnal> k) : komponent(std::move(k)) {}