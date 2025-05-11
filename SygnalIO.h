
#pragma once
#include <memory>
#include <string>
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

class SygnalIO {
public:
    static void zapiszDoPliku(const std::string& sciezka, const std::unique_ptr<Sygnal>& sygnal);
    static std::unique_ptr<Sygnal> wczytajZPliku(const std::string& sciezka);
};