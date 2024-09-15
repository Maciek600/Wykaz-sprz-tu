#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

/**
 *  @class Equipment 
 *  @brief Klasa Equipment reprezentuje sprzet. 
 * Ma prywatne pola id_, name_ i department_, ktore sa dostepne za pomoca publicznych metod getId(),
* getName() i getDepartment(). Klasa Equipment ma rowniez publiczne metody setName() i setDepartment(), które
* pozwalaja na modyfikowanie nazwy i dzialu sprzetu.
 * 
 */
class Equipment {
public:
    /**
    * Konstruktor klasy Equipment
    * @param id unikatowy numer id sprzetu
    * @param name nazwa sprzetu
    * @param department nazwa dzialu do ktorego przynalezy sprzet
    */
    Equipment(int id, string name, string department);

    /**
     * @brief Zwraca identyfikator sprzetu.
     * @return Identyfikator sprzetu.
     */
    int getId() const;

    /**
     * @brief Zwraca nazwe sprzetu.
     * @return Nazwa sprzetu.
     */
    string getName() const;

    /**
     * @brief Zwraca nazwe dzialu, do ktorego przynalezy sprzet.
     * @return Nazwa dzialu sprzetu.
     */
    string getDepartment() const;

    /**
     * @brief Metoda publiczna umozliwiajaca ustawienie nazwy sprzetu.
     * @param name Nowa nazwa sprzetu.
     */
    void setName(string name);

    /**
     * @brief Metoda publiczna umozliwiajaca ustawienie nazwy dzialu, do ktorego przynalezy sprzet.
     * @param department Nowa nazwa dzialu sprzetu.
     */
    void setDepartment(string department);
private:
    int id_; /**< Unikatowy numer identyfikacyjny sprzetu. */
    string name_; /**< Nazwa sprzetu. */
    string department_; /**< Nazwa dzia³u, do ktorego przynalezy sprzet. */
};

/**
 * @class EquipmentDatabase
 * @brief Zarzadza baza danych sprzetu.
 *
 * Klasa EquipmentDatabase sluzy do zarzadzania baza danych sprzetu.
 * Klasa EquipmentDatabase ma prywatne pole equipment, ktore jest wektorem przechowujacym obiekty klasy Equipment.
* Klasa ta ma rowniez publiczne metody getEquipmentList(), addEquipment(), removeEquipment(),
*modifyEquipment(), searchEquipment() i getEquipmentByDepartment(), ktore pozwalaja na wyswietlanie,
*dodawanie, usuwanie, modyfikowanie, wyszukiwanie i wyswietlanie sprzetu wedlug dzialu.

 */
class EquipmentDatabase {
public:
    /**
     * @brief Konstruktor klasy EquipmentDatabase.
     */
    EquipmentDatabase();

    /**
     * @brief Zwraca liste sprzetu w bazie danych.
     
     */
    vector<Equipment> getEquipmentList() const;

    /**
     * @brief Dodaje sprzet do bazy danych.
     
     */
    void addEquipment(Equipment equipment);

    /**
     * @brief Usuwa sprzet z bazy danych na podstawie identyfikatora.
     * 
     */
    void removeEquipment(int id);

    /**
     * @brief Modyfikuje dane sprzetu w bazie danych na podstawie identyfikatora.
     * @param id Identyfikator sprzetu do modyfikacji.
     * @param name Nowa nazwa sprzetu.
     * @param department Nowa nazwa dzialu sprzetu.
     */
    void modifyEquipment(int id, string name, string department);

    /**
     * @brief Wyszukuje sprzet w bazie danych na podstawie nazwy lub ID.
     * @param query Zapytanie wyszukiwania sprzetu.
     * @return Lista sprzetu pasujacego do zapytania.
     */
    vector<Equipment> searchEquipment(string query) const;

    /**
     * @brief Zwraca sprzet z danej kategorii dzialu.
     * @param department Nazwa dzialu, dla ktorego ma zostac zwrocony sprzet.
     * @return Lista sprzetu z danego dzialu.
     */
    vector<Equipment> getEquipmentByDepartment(string department) const;
private:
    vector<Equipment> equipment_; /**< Lista sprzetu w bazie danych. */
};


/**
 * @brief Wyswietla pelny wykaz sprzetu.
 *
 * Funkcja `displayEquipmentList` wyswietla pelny wykaz sprzetu z bazy danych `db`.
 */
void displayEquipmentList(const EquipmentDatabase& db);

/**
 * @brief 
 * Funkcja `loginAsAdmin` loguje uzytkownika na konto Administratora.
 *
 * @return Wartoœæ `true`, jesli logowanie powiodlo sie; wartoœæ `false`, jesli logowanie nie powiodlo sie.
 */
bool loginAsAdmin();

/**
 * @brief 
 *
 * Funkcja `addNewEquipment` dodaje nowy sprzet do bazy danych `db`.
 *
 
 */
void addNewEquipment(EquipmentDatabase& db);

/**
 * @brief
 * Funkcja `removeEquipment` usuwa sprzet z bazy danych `db` na podstawie jego ID.
 */
void removeEquipment(EquipmentDatabase& db);

/**
 * @brief Funkcja `modifyEquipment` modyfikuje dane o sprzecie w bazie danych `db` na podstawie jego ID.
 *
 */
void modifyEquipment(EquipmentDatabase & db);

/**
 * @brief Funkcja `searchEquipment` wyszukuje sprzet w bazie danych `db` na podstawie podanego zapytania.
 */
void searchEquipment(EquipmentDatabase& db);

/**
 * @brief Funkcja `displayEquipmentByDepartment` wyswietla sprzet zwiazany z danym dzialem w firmie na podstawie bazy danych `db`.
 */
void displayEquipmentByDepartment(EquipmentDatabase& db);


/**
 * @brief Funkcja `logowanie` obsluguje proces logowania do systemu, wykorzystujac baze danych `db`.
 * 
 */
void logowanie(EquipmentDatabase& db);


/**
 * @brief 
 * Funkcja `option` wywietla opcje do wyboru dla u¿ytkownika na podstawie bazy danych `db`.
 */
void option(EquipmentDatabase& db);