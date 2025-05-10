#include "RegulatorPID.h"
#include <iostream>

RegulatorPID::RegulatorPID(double p, double i, double d) {
  if (czyDodatnia(p) && czyDodatnia(i) && czyDodatnia(d)) {
    k = p;
    ti = i;
    td = d;
  } else {
    std::cerr << "Blad: Wszystkie nastawy musza byc dodatnie!" << std::endl;
  }
}

RegulatorPID::RegulatorPID(double p, double i) {
  if (czyDodatnia(p) && czyDodatnia(i)) {
    k = p;
    ti = i;
  } else {
    std::cerr << "Blad: Wszystkie nastawy musza byc dodatnie!" << std::endl;
  }
}

RegulatorPID::RegulatorPID(double p) {
  if (czyDodatnia(p)) {
    k = p;
  } else {
    std::cerr << "Blad: Wszystkie nastawy musza byc dodatnie!" << std::endl;
  }
}

bool RegulatorPID::czyDodatnia(double wartosc_spr) { return wartosc_spr >= 0; }

double RegulatorPID::obliczWyjscieP(double e) const{
  return  e*k;
}

double RegulatorPID::obliczWyjscieI(double e) {
   if (ti == 0) return 0; // Chronimy się przed dzieleniem przez 0
   double u = 1.0/ti*(suma_uchybow);
   if(czyDodatnia(u))
      return u;
   return 0;
}

double RegulatorPID::obliczWyjscieD(double e){
  double u = td*(e-poprzedni_uchyb);
  if(czyDodatnia(u))
    return u;
  return 0;
}

void RegulatorPID::ustawP(double p){
  if(czyDodatnia(p))
    k=p;
  else
    std::cerr << "Nastawa czesci proporcjonalnej nie moze byc ujemna: p=" << p << std::endl;
}

void RegulatorPID::ustawPI(double p, double i){
  if(czyDodatnia(p) && czyDodatnia(i)) {
    k=p; ti=i;
  }
  else
    std::cerr << "Nastawy czesci proporcjonalnej i całkującej nie moga byc ujemne: p=" << p << " i=" << i << std::endl;
}

void RegulatorPID::ustawPID(double p, double i, double d){
  if(czyDodatnia(p) && czyDodatnia(i) && czyDodatnia(d)) {
    k=p; ti=i; td=d;
  }
  else
   std::cerr << "Nastawy czesci proporcjonalnej, całkującej i rozniczkujacej nie moga byc ujemne: p=" << p << " i=" << i << " d=" << d << std::endl;
}

double RegulatorPID::symuluj(double e){
  double u = obliczWyjscieP(e);
  suma_uchybow += e;
  if (ti > 0)
    u += obliczWyjscieI(e);
  if (td > 0)
    u += obliczWyjscieD(e);
  poprzedni_uchyb = e;
  return u;
}