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
#include "Student.h"

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
       studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.push_back(student);
    }

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

				studentenListe.insert(studentenListe.begin(),student);
            }
            break;

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
