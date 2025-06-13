/*
 * Magazin.cpp
 *
 *  Created on: Jun 13, 2025
 *      Author: Karime Soriano
 */

#include "Magazin.h"
#include <iostream>

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
    : Medium(initTitel), erscheinungsdatum(initDatumAusgabe), sparte(initSparte)
{
}

Magazin::~Magazin() {
	// TODO Auto-generated destructor stub
}

void Magazin::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Erscheinungsdatum: " << erscheinungsdatum << std::endl;
    std::cout << "Sparte: " << sparte << std::endl;
}
