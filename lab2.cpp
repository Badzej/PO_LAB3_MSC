#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>

#define DEBUG

#include "SumaSygnalow.h"

#include "RegulatorPID.h"
#include "ModelARX.h"
#include "PetlaSprzezeniaZwrotnego.h"
#include "SygnalSinusoidalny.h"
#include "SygnalProstokatny.h"
#include "SygnalStaly.h"
#include "SygnalSzumBialy.h"
#include "SygnalTrojkatny.h"
#include "SygnalZNasyceniem.h"
#include "SygnalIO.h"

#ifdef DEBUG

//Funkcje pomocnicze dla testów:

void raportBleduSekwencji(std::vector<double>& spodz, std::vector<double>& fakt)
{
	constexpr size_t PREC = 3;
	std::cerr << std::fixed << std::setprecision(PREC);
	std::cerr << "  Spodziewany:\t";
	for (auto& el : spodz)
		std::cerr << el << ", ";
	std::cerr << "\n  Faktyczny:\t";
	for (auto& el : fakt)
		std::cerr << el << ", ";
	std::cerr << std::endl << std::endl;
}

bool porownanieSekwencji(std::vector<double>& spodz, std::vector<double>& fakt)
{
	constexpr double TOL = 1e-3;	// tolerancja dla porównań zmiennoprzecinkowych
	bool result = fakt.size() == spodz.size();
	for (int i = 0; result && i < fakt.size(); i++)
		result = fabs(fakt[i] - spodz[i]) < TOL;
	return result;
}

void test_RegulatorP_brakPobudzenia()
{
	//Sygnatura testu:
	std::cerr << "RegP (k = 0.5) -> test zerowego pobudzenia: ";
	try
	{
		// Przygotowanie danych:
		RegulatorPID instancjaTestowa(0.5);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja modelu:

		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_RegulatorP_skokJednostkowy()
{
	//Sygnatura testu:
	std::cerr << "RegP (k = 0.5) -> test skoku jednostkowego: ";

	try
	{
		// Przygotowanie danych:
		RegulatorPID instancjaTestowa(0.5);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy 
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_RegulatorPI_skokJednostkowy_1()
{
	//Sygnatura testu:
	std::cerr << "RegPI (k = 0.5, TI = 1.0) -> test skoku jednostkowego nr 1: ";

	try
	{
		// Przygotowanie danych:
		RegulatorPID instancjaTestowa(0.5,1.0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy 
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 19.5, 20.5, 21.5, 22.5, 23.5, 24.5, 25.5, 26.5, 27.5, 28.5, 29.5 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_RegulatorPI_skokJednostkowy_2()
{
	//Sygnatura testu:
	std::cerr << "RegPI (k = 0.5, TI = 10.0) -> test skoku jednostkowego nr 2: ";

	try
	{
		// Przygotowanie danych:
		RegulatorPID instancjaTestowa(0.5, 10.0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy 
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3, 3.1, 3.2, 3.3, 3.4 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_RegulatorPID_skokJednostkowy()
{
	//Sygnatura testu:
	std::cerr << "RegPID (k = 0.5, TI = 10.0, TD = 0.2) -> test skoku jednostkowego: ";

	try
	{
		// Przygotowanie danych:
		RegulatorPID instancjaTestowa(0.5, 10.0, 0.2);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy 
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0.8, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3, 3.1, 3.2, 3.3, 3.4 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

using namespace std;

int main() {
	// test_RegulatorP_brakPobudzenia();
	// test_RegulatorP_skokJednostkowy();
	// test_RegulatorPI_skokJednostkowy_1();
	// test_RegulatorPI_skokJednostkowy_2();
	// test_RegulatorPID_skokJednostkowy();
	//
	// RegulatorPID regulator(1.0, 0.1, 0.01);
	// ModelARX model({ -0.4 }, { 0.6 }, 1, 0);  // przykładowe współczynniki
	//
	// PetlaSprzezeniaZwrotnego krok;
	// //Tutaj wartosc zadana z wygenerowanego sygnalu
	// for (int i = 0; i < 4; i++) {
	// 	double wyjscie = krok(regulator, model);
	// 	std::cout << "Krok " << i << " -> Wyjscie: " << wyjscie << std::endl;
	// }
	double f = 1.0;               // 1 Hz
	double fs = 100.0;            // 100 próbek/sek
	double omega = M_PI * f / fs;  //radiany na próbkę


	std::unique_ptr<Sygnal> sygnal =	std::make_unique<SygnalZNasyceniem> //Maksymalne nasycenie - wszystko powyzej lub ponizej zadanej wartosci jest zamieniane na wartosc -max, max
		(std::make_unique<SumaSygnalow>	//Suma sygnalow
			( std::make_unique<SumaSygnalow>
				( std::make_unique<SumaSygnalow>
					( std::make_unique<SumaSygnalow>
						( std::make_unique<SumaSygnalow>
							( std::make_unique<SumaSygnalow>
								(std::make_unique<SygnalSinusoidalny>(2.0, omega)
									, std::make_unique<SygnalStaly>(0.2))
							, std::make_unique<SygnalTrojkatny>(1.1,omega))
						// ,std::make_unique<SygnalSzumBialy>(0.5))
						,std::make_unique<SygnalStaly>(0.01))
					,std::make_unique<SygnalProstokatny>(1.0,omega,0.25))
				// ,std::make_unique<SygnalSzumBialy>(1.0))
				,std::make_unique<SygnalStaly>(0.01))
			,std::make_unique<SygnalSinusoidalny>(1.0, omega))
		,2.0);

	SygnalIO::zapiszDoPliku("test.json",sygnal);
	std::unique_ptr<Sygnal> sygnal_z_pliku = SygnalIO::wczytajZPliku("test.json");
	std::cout<<"Orgin"<<std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << round(sygnal->symuluj()*10000)/10000.0 << std::endl;
	}
	std::cout<<"Kopia"<<std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << round(sygnal_z_pliku->symuluj()*10000)/10000.0 << std::endl;
	}

	//auto generator = std::make_unique<SumaSygnalow>(std::make_unique<SumaSygnalow>( std::make_unique<SygnalSinusoidalny>(1.0,omega), std::make_unique<SygnalStaly>(1.0) ));
	// SygnalSinusoidalny sinus(1.0,omega);
	// for (int i = 0; i < 400; i++) {
	// 	std::cout << round(sinus.symuluj()*10000)/10000.0 << std::endl;
	// }
	//
	// std::cout << "Prostokat"<< std::endl << std::endl;
	// SygnalProstokatny prostokat(1.0,omega,1.0);
	// for (int i = 0; i < 400; i++) {
	// 	std::cout << round(prostokat.symuluj()*10000)/10000.0 << std::endl;
	// }
	//
	// std::cout << "Trojkat"<< std::endl << std::endl;
	// SygnalTrojkatny trojkat(1.0,omega);
	// for (int i = 0; i < 400; i++) {
	// 	std::cout << round(trojkat.symuluj()*10000)/10000.0 << std::endl;
	// }
	//
	// std::cout << "Szum bialy"<< std::endl << std::endl;
	// SygnalSzumBialy sbialy(1.0);
	// for (int i = 0; i < 400; i++) {
	// 	std::cout << round(sbialy.symuluj()*10000)/10000.0 << std::endl;
	// }
}

#endif

#ifdef MAIN

using namespace std;

int main()
{

}
#endif

