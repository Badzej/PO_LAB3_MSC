
#pragma once
#include <memory>
#include <string>
#include "Sygnal.h"
#include "include_ext_lib/json.hpp"

/**
 * @author Błażej Styrnol
 * @class SygnalIO
 * @brief Klasa pomocnicza do zapisu i odczytu sygnałów z plików JSON.
 */
class SygnalIO {
public:
    /**
     * @brief Zapisuje sygnał do pliku.
     * @param sciezka Ścieżka do pliku.
     * @param sygnal Sygnał do zapisania.
     */
    static void zapiszDoPliku(const std::string& sciezka, const std::unique_ptr<Sygnal>& sygnal);
    /**
     * @brief Wczytuje sygnał z pliku JSON.
     * @param sciezka Ścieżka do pliku.
     * @return Unikalny wskaźnik do wczytanego sygnału.
     */
    static std::unique_ptr<Sygnal> wczytajZPliku(const std::string& sciezka);
};