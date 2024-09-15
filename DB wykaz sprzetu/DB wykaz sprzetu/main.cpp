#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "header.h"
using namespace std;

/*! \mainpage Wykaz sprzetu w firmie
 *
 *
 * \section intro_sec Tresc zadania
 * Napisac program realizujacy zadania zwiazane z zarzadzaniem i wyswietlaniem spisu sprzetu w firmie.
 * \section test_sec Plik testowy
 * W zalaczonych plikach znajduje sie plik tekstowy zawierajacy 60 wierszy.
 * Plik ten jest reprezentacja bazy danych sprzetu w firmie.
 * Kazdy wiersz ma nastepujaca budowe:
 * <unikatowy numer id> <nazwa_sprzetu> <nazwa_dzialu>
 *
 *
 * \section instr_sec Instrukcja
 * Po uruchomieniu programu uzytkownik ma do wyboru dwie opcje:
 * 1) Wyswietlenie pelnego wykazu sprzetu - ta opcja pozwala na wyswietlenie pelnej listy sprzetu znajdujacego sie w firmie.
 * 2) Zalogowanie sie na konto Admin w celu zdobycia wiekszej ilosci uprawnieñ - ta opcja umozliwia uzytkownikowi dostep do konta administracyjnego i dodatkowych funkcjonalnosci.
 *
 * Haslo pozwalajace na przelaczenie konta z domyslnego na administracyjne to "Pk2ktW".
 * Uwaga: Wielkosc i kolejnosc liter maja znaczenie!
 *
 * Po zalogowaniu sie na konto Admin, uzytkownik moze korzystac z nastepujacych opcji:
 * a) Dodawanie - ta opcja pozwala na dodawanie nowego sprzetu do bazy danych.
 * b) Usuwanie - ta opcja pozwala na usuwanie konkretnego sprzetu/ przedmiotu z bazy danych.
 * c) Modyfikacja - ta opcja umozliwia modyfikowanie informacji o konkretnym sprzecie znajdujacym sie w bazie danych.
 * d) Opcja “find” - ta opcja pozwala na wyszukiwanie sprzetu w bazie danych za pomoca nazwy lub numeru ID.
 * e) Wyswietlenie wzgledem konkretnego dzialu w firmie - ta opcja umozliwia wyswietlenie sprzetu zwiazane z danym dzialem w firmie.
 *
 *\author Maciej Fajlhauer
 *
 */
int main() {
	
    EquipmentDatabase db;

	cout << "---------------------------" << endl;
	cout<< "Witamy w programie WykaZ"<<endl;
	cout  << "---------------------------" << endl;
	system("pause");
	system("cls");
	cout << "Aby wczytac baze sprzetu podaj nazwe pliku o rozszerzeniu .txt: " << endl;
	
	string filename;
	ifstream wykaz;
	cin >> filename;
	wykaz.open(filename);
	if (wykaz.good() == true)
	{
		system("pause");
		system("cls");
		cout << "Uzyskano dostep do pliku!" <<endl;
		int id;
        string name, department;
        while (wykaz >> id >> name >> department) {
            db.addEquipment(Equipment(id, name, department));
			
        }
        cout << "Baza danych zostala wczytana z pliku " << filename << endl;
        system("pause");
        system("cls");
        logowanie(db);
		
	}
	else cout << "Dostep do pliku zostal zabroniony!" <<endl;

	//zamkniêcie pliku
	wykaz.close();
	return 0;
}