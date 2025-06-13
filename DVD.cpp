/*
 * DVD.cpp
 *
 *  Created on: Jun 13, 2025
 *      Author: Karime Soriano
 */

#include "DVD.h"
#include <iostream>
using std::cout;
using std::endl;

DVD::DVD(string initTitel, int initAltersfreigabe, string initGenre): Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre) {}

DVD::~DVD() {
	// TODO Auto-generated destructor stub
}

void DVD::ausgabe() const{
	Medium::ausgabe();
	cout<<"Altersfreigabe: " << altersfreigabe << endl;
    cout << "Genre: " << genre << endl;
}
