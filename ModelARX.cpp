#include "ModelARX.h"
#include <numeric>
#include "include_ext_lib/json.hpp"
#include <fstream>

double ModelARX::generujZaklocenie() const {
    if (sigma == 0.0) return 0.0;
    std::normal_distribution<double> dist(0.0, sigma);
    static std::default_random_engine gen;
    return dist(gen);
}

double ModelARX::oblicz(const std::vector<double>& wielomian,const std::deque<double>& poprzednie_wartosci) const {
    size_t n = std::min(wielomian.size(), poprzednie_wartosci.size());
    return std::inner_product(wielomian.begin(), wielomian.begin() + n, poprzednie_wartosci.begin(), 0.0);  ///iloczyn skalarny n wspolczynnikow wielomianu i poprzednich wartosci
}

ModelARX::ModelARX(const std::vector<double>& a, const std::vector<double>& b, unsigned int opoznienie, double moc) : A(a), B(b), k(opoznienie), sigma(moc) {
  u_hist.resize(b.size() + k, 0.0);
  y_hist.resize(a.size(), 0.0);
}

ModelARX::ModelARX(const std::string& sciezka) : ModelARX(deserializuj(sciezka)) {}

double ModelARX::symuluj(double u) {
    u_hist.push_front(u);
    std::deque<double> u_opoznione(u_hist.begin() + k, u_hist.end());
    double wyjscie = ModelARX::oblicz(B,u_opoznione) - ModelARX::oblicz(A,y_hist) + generujZaklocenie();
    y_hist.push_front(wyjscie);
    return wyjscie;
}

void ModelARX::serializuj(const std::string& sciezka) const {
    nlohmann::json json_obj;
    json_obj["A"] = A;
    json_obj["B"] = B;
    json_obj["k"] = k;
    json_obj["sigma"] = sigma;

    std::ofstream plik(sciezka);
    plik << json_obj.dump(4); //. 4 oznacza formatowanie z 4 spacjami
    plik.close();
}

ModelARX ModelARX::deserializuj(const std::string& sciezka) {
    std::ifstream plik(sciezka);
    if (!plik.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku do zapisu: " + sciezka);
    }
    nlohmann::json json_obj;
    plik >> json_obj;
    plik.close();

    std::vector<double> a = json_obj["A"].get<std::vector<double>>();
    std::vector<double> b = json_obj["B"].get<std::vector<double>>();
    unsigned int k = json_obj["k"].get<unsigned int>();
    double sigma = json_obj["sigma"].get<double>();

    return ModelARX(a, b, k, sigma);
}

double ModelARX::pobierzOstatnieWyjscie() const {
    return y_hist.back();
}