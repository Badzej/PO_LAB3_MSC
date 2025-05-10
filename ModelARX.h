#pragma once
#include <vector>
#include <queue>
#include <random>
#include "ObiektSISO.h"


/**
 * @author Błażej Styrnol
 * @class ModelARX
 * @brief Implementacja dyskretnego modelu ARX
 */
class ModelARX : public ObiektSISO {
    std::vector<double> A;     ///Wielomian A (z⁻¹) — wpływ przeszłych wyjść y na bieżące wyjście
    std::vector<double> B;     ///Wielomian B (z⁻¹) — wpływ przeszłych wejść u na wyjście
    std::deque<double> y_hist; ///Historia wartości wyjściowych
    std::deque<double> u_hist; ///Historia wartości wejściowych
    unsigned int k;            ///Opóźnienie transportowe (liczba próbek)
    double sigma;              ///Odchylenie standardowe zakłócenia (szumu)

    /**
     * @brief Generuje próbkę zakłócenia (szumu) o rozkładzie normalnym.
     * @return Losowa wartość szumu.
     */
    [[nodiscard]] double generujZaklocenie() const;

    /// @brief Oblicza wartość wielomianu na podstawie historii wejść.
    /// @param wielomian Wielomian, na bazie którego ma być obliczana wartość np. wielomian A lub wielomian B
    /// @param poprzednie_wartosci Historia wartości – zgodnie z kolejnością współczynników.
    /// @return Suma iloczynów współczynników i wartości z historii.
    [[nodiscard]] double oblicz(const std::vector<double>& wielomian,const std::deque<double>& poprzednie_wartosci) const;
public:
    /**
     * @brief Konstruktor modelu ARX.
     * @param a Współczynniki wielomianu A
     * @param b Współczynniki wielomianu B
     * @param opoznienie Opóźnienie transportowe k
     * @param moc Odchylenie standardowe szumu
     */
    ModelARX(const std::vector<double>& a, const std::vector<double>& b, unsigned int opoznienie, double moc);

    /**
     * @brief Konstruktor tworzący obiekt na podstawie danych z pliku (JSON).
     * @param sciezka Ścieżka do pliku JSON
     */
    explicit ModelARX(const std::string& sciezka);

    /**
     * @brief Symuluje działanie modelu — generuje nowe wyjście na podstawie wejścia.
     * @param u Nowa wartość wejściowa
     * @return Wygenerowana wartość wyjściowa
     */
    double symuluj(double u) override;

    /**
     * @brief Zapisuje konfigurację modelu do pliku JSON.
     * @param sciezka Ścieżka do pliku wyjściowego
     */
    void serializuj(const std::string& sciezka) const;

    /**
     * @brief Wczytuje dane modelu z pliku JSON i tworzy nowy obiekt.
     * @param sciezka Ścieżka do pliku wejściowego
     * @return Obiekt ModelARX zrekonstruowany z pliku
     */
    static ModelARX deserializuj(const std::string& sciezka);

    /**
     * @brief Zwraca kolejke wartosci wyjscia y
     * @return Kolejka y_hist
     */
    double pobierzOstatnieWyjscie() const;
};
