/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Student.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
////

int main()
{
    std::vector<Student> studentenListe;
    Student student;
    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

   /* if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
       studentenListe.push_back(student); //nicht mehr PushBack sondern push_back, vector liste
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.push_back(student);
    }*/

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Liste ruchwaerts ausgeben: "<<std::endl
				  << "(5): Datensatz loeschen: "<<std::endl
				  << "(6): Student vorne einfuegen: "<<std::endl
				  << "(7): Datenelement vorne loeschen: "<<std::endl
				  << "(8): Daten aus Datei einlesen: "<<std::endl
				  << "(9): Daten in eine Datei sichern: "<<std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for(const auto& other :studentenListe){
                    	other.ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;
            case '4':
            	if (!studentenListe.empty()) {
            	        std::cout << "Rueckwaertsausgabe der Liste:" << std::endl;
            	        for(auto it = studentenListe.rbegin(); it!= studentenListe.rend();++it){
            	        	it->ausgabe();
            	        }
            	    } else {
            	        std::cout << "Die Liste ist leer!\n\n";
            	    }
            	break;
            case '5':
            {
            	if(studentenListe.empty()){
            		std::cout<<"Liste ist leer.\n";
            		break;
            	}
            	unsigned int matNr;
            	std::cout<<"Matrikel Nummern: "; std::cin>>matNr;
            	auto it = std::find_if(studentenListe.begin(), studentenListe.end(),
            	                       [matNr](const Student& s) { return s.getMatNr() == matNr; });

            	if(it != studentenListe.end()){
            		std::cout<<"Erloeschte Student: ";
            		it->ausgabe();
            		studentenListe.erase(it);
            	}else{
            		// Si no se encontró el estudiante (pero la lista no está vacía), lo informamos
            		std::cout << "No se encontró ningún estudiante con esa matrícula.\n";
            	}
            }
            	break;
            case '6':
            {
            	unsigned int matNr = 0;
				std::string name = "";
				std::string geburtstag = "";
				std::string adresse = "";
				std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
				getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen
				std::cout << "Geburtsdatum: ";
				getline(std::cin, geburtstag);
				std::cout << "Adresse: ";
				getline(std::cin, adresse);
				std::cout << "Matrikelnummer: ";
				std::cin >> matNr;
				std::cin.ignore(10, '\n');
				student = Student(matNr, name, geburtstag, adresse);

				studentenListe.insert(studentenListe.begin(),student); //insert at the beginning
            }
            break;

            case '7':
            	if(!studentenListe.empty()){
            		Student sfront = studentenListe.front();
            		std::cout<<"Dieser Student wurde geloescht: "<<std::endl;
            		sfront.ausgabe();
            		studentenListe.erase(studentenListe.begin());
            	}else{
            		std::cout<<"Die Liste ist leer"<<std::endl;
            	}
            	break;
            case '8':
            {

            	//ask for the archivo name
            	string dateinName;
            	cout<<"Dateiname eingeben: ";
            	cin>>dateinName;
            	//empty the existed vector
            	studentenListe.clear();
            	//open the file
            	std::ifstream inFile(dateinName);
            	if(!inFile){
            		cout<<"Datei nicht geofnet"<<std::endl;
            		break;
            	}
            	//Read data
            	unsigned int matNr;
            	string name, geburstag, adresse;
            	while(inFile>>matNr){ //inFile works like cin here
            		// we do getline because >>cannot read strings with spaces
            		inFile.ignore();                 // Ignora el salto de línea después del número
					getline(inFile, name);          // Lee línea completa para el nombre
					getline(inFile, geburstag);    // Lee línea completa para la fecha
					getline(inFile, adresse);
            		//reads name, matr, etc from file not console
            		Student student(matNr, name,geburstag,adresse);
            		studentenListe.push_back(student);
            	}
            	//close file
            	 inFile.close();

            	//
            	 cout<<"Daten erforlgreich";
            	break;
            }
            case '9':
            {
            	if(studentenListe.empty()){
            		cout<<"Liste ist leer."<<endl;
            		break;
            	}
            	string datei;
            	cout<<"In welche Datei moechten sie die Datei speichern? ";
            	cin>>datei;
            	std::ofstream outFile(datei);
            	if(!outFile){
            		cout<<"Datei konnte nicht geoffnet werden"<<endl;
            		break;
            	}
            	for(const auto& student:studentenListe){
            		outFile<<student.getMatNr()<<endl;
            		outFile<<student.getName()<<endl;
            		outFile<<student.getGeburtstag()<<endl;
            		outFile<<student.getAdresse()<<endl;

            	}
            	outFile.close();
            	cout<<"Erfolgreich";
            	break;
            }
            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default:
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
