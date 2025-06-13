/*
 * Magazin.h
 *
 *  Created on: Jun 13, 2025
 *      Author: Karime Soriano
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_
#include "Medium.h"
#include "Datum.h"
#include <string>
using std::string;

class Magazin: public Medium {

public:
	Magazin(string initTitel, Datum initDatumAusgabe, string initSparte);
	virtual ~Magazin();
	virtual void ausgabe() const override;

private:
	Datum erscheinungsdatum;
	string sparte;
};

#endif /* MAGAZIN_H_ */
