/*
 * DVD.h
 *
 *  Created on: Jun 13, 2025
 *      Author: Karime Soriano
 */

#ifndef DVD_H_
#define DVD_H_
#include "Medium.h"
#include <string>
using std::string;

class DVD : public Medium{
public:
	DVD(string initTitel, int initAltersfreigabe, string initGenre);
	virtual ~DVD();
	virtual void ausgabe() const override;
	virtual bool ausleihen(Person person, Datum ausleihdatum) override;


private:
	int altersfreigabe;
	string genre;
};

#endif /* DVD_H_ */
