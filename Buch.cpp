/*
 * Buch.cpp
 *
 *  Created on: Jun 13, 2025
 *      Author: Karime Soriano
 */

#include "Buch.h"
using std::cout;
using std::endl;

//constructor
Buch::Buch(string initTitel, string initAutor): Medium(initTitel), autor(initAutor) {}

//destructor
Buch::~Buch() {}

//ausgabe
void Buch::ausgabe() const{
	Medium::ausgabe(); //ausgabe from medium file which is ID + title + status
	cout<<"Autor: "<<autor<<endl;

}

