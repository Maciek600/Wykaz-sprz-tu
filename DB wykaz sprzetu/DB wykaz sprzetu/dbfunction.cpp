#include "header.h"

Equipment::Equipment(int id, string name, string department)
    : id_(id), name_(name), department_(department) {}

int Equipment::getId() const {
    return id_;
}

string Equipment::getName() const {
    return name_;
}

string Equipment::getDepartment() const {
    return department_;
}

void Equipment::setName(string name) {
    name_ = name;
}

void Equipment::setDepartment(string department) {
    department_ = department;
}



EquipmentDatabase::EquipmentDatabase() {
    //dodajemy przyk³adowe elementy
    /*equipment_.push_back(Equipment(1, "Laptop", "IT"));
    equipment_.push_back(Equipment(2, "Monitor", "IT"));
    equipment_.push_back(Equipment(3, "Telefon", "Sprzeda¿"));*/
    
}

vector<Equipment> EquipmentDatabase::getEquipmentList() const {
    return equipment_;
}

void EquipmentDatabase::addEquipment(Equipment equipment) {
    equipment_.push_back(equipment);


    // Zapisz aktualne dane do pliku wejœciowego
    ofstream outputFile("db.txt");
    if (outputFile.is_open()) {
        for (const auto& eq : equipment_) {
            outputFile << eq.getId() << " " << eq.getName() << " " << eq.getDepartment() << "\n";
        }
        outputFile.close();
    }
    else {
       cout << "Nie mo¿na otworzyæ pliku wejœciowego do zapisu.\n";
    }
}

void EquipmentDatabase::removeEquipment(int id) {
    equipment_.erase(
        remove_if(
            equipment_.begin(),
            equipment_.end(),
            [id](const Equipment& equipment) { return equipment.getId() == id; } //wyra¿enie lambda
        ),
        equipment_.end()
    );
}

void EquipmentDatabase::modifyEquipment(int id, string name, string department) {
    for (auto& equipment : equipment_) { //iteracja przez ka¿dy element equipment wektora equipment_
        if (equipment.getId() == id) {
            equipment.setName(name);
            equipment.setDepartment(department);
        }
    }
}

vector<Equipment> EquipmentDatabase::searchEquipment(string query) const {
    vector<Equipment> results;
    for (const auto& equipment : equipment_) { //const auto& poniewa¿ chcemy tylko wyszukaæ elementu a nie go modyfikowaæ
        if (equipment.getName() == query || to_string(equipment.getId()) == query) {
            results.push_back(equipment);
        }
    }
    return results;
}

vector<Equipment> EquipmentDatabase::getEquipmentByDepartment(string department) const {
    vector<Equipment> results;
    for (const auto& equipment : equipment_) { 
        if (equipment.getDepartment() == department) {
            results.push_back(equipment);
        }
    }
    return results;
}


// Funkcja wyœwietlaj¹ca pe³ny wykaz sprzêtu
void displayEquipmentList(const EquipmentDatabase& db) {
    cout << "Pelny wykaz sprzetu:\n";
    auto equipmentList = db.getEquipmentList();


    // Wyœwietlamy ka¿dy element z listy sprzêtu
    for (const auto& equipment : equipmentList) {
        cout << "ID: " << equipment.getId() << " Nazwa: " << equipment.getName() << " Dzial: " << equipment.getDepartment() << endl;
    }
   
}

// Funkcja loguj¹ca u¿ytkownika na konto Admin
bool loginAsAdmin() {
    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    return password == "Pk2ktW";
}

// Funkcja dodaj¹ca nowy sprzêt do bazy danych
void addNewEquipment(EquipmentDatabase& db) {
    int id;
    string name, department;
    cout << "Podaj ID nowego sprzetu: ";
    cin >> id;
    cout << "Podaj nazwe nowego sprzetu: ";
    cin >> name;
    cout << "Podaj dzial nowego sprzetu: ";
    cin >> department;
    db.addEquipment(Equipment(id, name, department));
    cout << "Nowy sprzet zostal dodany do bazy danych.\n";
    option(db);
}

// Funkcja usuwaj¹ca sprzêt z bazy danych na podstawie jego ID
void removeEquipment(EquipmentDatabase& db) {
    int id;
    cout << "Podaj ID sprzetu do usuniecia: ";
    cin >> id;


    // Aktualizacja zmian w pliku wejœciowym
    ofstream outputFile("db.txt");
    if (!outputFile.is_open()) {
        cout << "Nie mozna otworzyc pliku input.txt do zapisu zmian." << endl;
        return;
    }

    // Wpisuje pe³en wykaz oprócz tego którego numer ID zosta³ podany jako ten do usuniêcia
    auto equipmentList = db.getEquipmentList();
    for (const auto& equipment : equipmentList) {
        if (equipment.getId() != id) {
            outputFile << equipment.getId() << " " << equipment.getName() << " " << equipment.getDepartment() << endl;
        }
    }


    db.removeEquipment(id);
    cout << "Sprzet o ID " << id << " zostal usuniety z bazy danych.\n";
    option(db);
}

// Funkcja modyfikuj¹ca dane o sprzêcie na podstawie jego ID
void modifyEquipment(EquipmentDatabase& db) {
    int id;
    string name, department;
    cout << "Podaj ID sprzetu do modyfikacji: ";
    cin >> id;
    cout << "Podaj nowa nazwe sprzetu: ";
    cin >> name;
    cout << "Podaj nowy dzial sprzetu: ";
    cin >> department;


    // Aktualizacja zmian w pliku wejœciowym
    ofstream outputFile("db.txt");
    if (!outputFile.is_open()) {
        cout << "Nie mozna otworzyc pliku input.txt do zapisu zmian." << endl;
        return;
    }

    // Wpisywanie spr¿etu ze wszystkimi dokonanymi modyfikacjami
    auto equipmentList = db.getEquipmentList();
    for (const auto& equipment : equipmentList) {
        if (equipment.getId() == id) {
            outputFile << id << " " << name << " " << department << endl;
        }
        else {
            outputFile << equipment.getId() << " " << equipment.getName() << " " << equipment.getDepartment() << endl;
        }
    }


    db.modifyEquipment(id, name, department);
    cout << "Dane o sprzecie o ID " << id << " zostaly zaktualizowane.\n";
    option(db);
}

// Funkcja wyszukuj¹ca sprzêt po nazwie lub ID
void searchEquipment(EquipmentDatabase& db) {
    string query;
    cout << "Podaj nazwe lub ID sprzetu do wyszukania: ";
    cin >> query;
    auto results = db.searchEquipment(query);
    if (results.empty()) {
        cout << "Nie znaleziono sprzetu pasujacego do zapytania.\n";
        option(db);
    }
    cout << "Znalezione sprzety:\n";
    for (const auto& equipment : results) {
        cout << "ID: " << equipment.getId() << " Nazwa: " << equipment.getName() << " Dzial: " << equipment.getDepartment() << endl;
    }
    option(db);
}

// Funkcja wyœwietlaj¹ca sprzêt zwi¹zany z danym dzia³em w firmie
void displayEquipmentByDepartment(EquipmentDatabase& db) {
    string department;
    cout << "Podaj nazwê dzialu: ";
    cin >> department;
    auto results = db.getEquipmentByDepartment(department);
    if (results.empty()) {
        cout << "Nie znaleziono sprzetu powiazanego z podanym dzialem.\n";
        option(db);
    }
    cout << "Sprzet powiazany z dzia³em " << department << ":\n";
    for (const auto& equipment : results) {
        cout << "ID: " << equipment.getId() << " Nazwa: " << equipment.getName() << endl;
    }
    option(db);
}

//Funkcja obs³uguj¹ca logowanie sie do systemu
void logowanie(EquipmentDatabase& db)
{
    bool isAdmin = false;
    while (true) {
        cout << "\nWybierz opcje:\n";
        cout << "1. Wyswietl pelny wykaz sprzetu\n";
        cout << "2. Zaloguj sie na konto Admin\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            displayEquipmentList(db);
        }
        else if (choice == 2) {
            isAdmin = loginAsAdmin();
            if (!isAdmin) {
                cout << "Nieprawidlowe haslo.\n";
            }
        }
        else {
            cout << "Nieprawidlowy wybor.\n";
        }

        // Jeœli u¿ytkownik zalogowa³ siê jako Admin, udostêpniamy mu dodatkowe opcje
        if (isAdmin) {
            option(db);
        }
    }

}

void option(EquipmentDatabase& db) {
    int number;
    system("pause");
    system("cls");
    cout << "\nWybierz opcje:\n";
    cout << "1. Dodaj nowy sprzet\n";
    cout << "2. Usun sprzet\n";
    cout << "3. Zmodyfikuj dane o sprzecie\n";
    cout << "4. Wyszukaj sprzet po nazwie lub ID\n";
    cout << "5. Wyswietl sprzet zwiazany z danym dzialem w firmie\n";
    cout << "6.Koniec.";
    cin >> number;

    switch (number) {
    case 1:
        addNewEquipment(db);
        system("pause");
        system("cls");
        break;
    case 2:
        removeEquipment(db);
        system("pause");
        system("cls");
        break;
    case 3:
        modifyEquipment(db);
        system("pause");
        system("cls");
        break;
    case 4:
        searchEquipment(db);
        system("pause");
        system("cls");
        break;
    case 5:
        displayEquipmentByDepartment(db);
        system("pause");
        system("cls");
        break;
    case 6:
        system("pause");
        system("cls");


        cout << "DZIEKUJE ZA PRACE.\n" << "Zamknij program albo zacznij od nowa" << endl;
        logowanie(db);
    default:
        cout << "Nieprawidlowy wybor. \n";
        break;
    }
}

