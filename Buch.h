/*
 * Buch.h
 *
 *  Created on: Jun 13, 2025
 *      Author: Karime Soriano
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"
#include <string>
using std::string;
class Buch : public Medium { //so ist ererbung
public:

	//Constructor
	Buch(string initTitel, string initAutor);

	//Destructor
	virtual ~Buch();

	virtual void ausgabe()const override;
private:
	string autor;
};

#endif /* BUCH_H_ */
