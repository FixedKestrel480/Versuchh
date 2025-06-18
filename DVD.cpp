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

bool DVD::ausleihen(Person person, Datum ausleihdatum){
	 int alter = (ausleihdatum - person.getGeburtsdatum()) / 12; //age of the person

	    if (alter < altersfreigabe)
	    {
	    	//message restricting some ages
	        cout << "Die DVD " << titel << " darf nur an Personen ab "
	                  << altersfreigabe << " Jahren verliehen werden. "
	                  << person.getName() << " ist aber nur " << alter << " Jahre alt." << endl;
	        return false;
	    }

	    // Wenn das Alter passt, normale Ausleihe über Medium
	    return Medium::ausleihen(person, ausleihdatum);
}
