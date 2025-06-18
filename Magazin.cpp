/*
 * Magazin.cpp
 *
 *  Created on: Jun 13, 2025
 *      Author: Karime Soriano
 */

#include "Magazin.h"
#include <iostream>
using std::cout;
using std::endl;

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

bool Magazin::ausleihen(Person person, Datum ausleihdatum){
	//to know the new output
	if(ausleihdatum-erscheinungsdatum==0){ //operator overload in Datum
		cout<<"Magazin "<<titel<<"darf nicht ausgeleihen werden"<<endl;
		return false;
	}
	return Medium::ausleihen(person, ausleihdatum);
}
