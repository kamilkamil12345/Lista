#include <iostream>

using namespace std;

class Lista {
private:
    struct Element {
        int wartosc;
        Element* nastepny;

        Element(int value) : wartosc(value), nastepny(nullptr) {}
    };

    Element* glowa;

public:
    Lista() : glowa(nullptr) {}

    void dodajElement(int value) {
        Element* nowyElement = new Element(value);

        if (!glowa) {
            glowa = nowyElement;
        } else {
            Element* temp = glowa;
            while (temp->nastepny) {
                temp = temp->nastepny;
            }
            temp->nastepny = nowyElement;
        }

        cout << "Dodano " << value << " do listy." << endl;
    }

    void usunElement(int value) {
        Element* temp = glowa;
        Element* poprzedni = nullptr;

        while (temp && temp->wartosc != value) {
            poprzedni = temp;
            temp = temp->nastepny;
        }

        if (temp) {
            if (poprzedni) {
                poprzedni->nastepny = temp->nastepny;
            } else {
                glowa = temp->nastepny;
            }
            delete temp;
            cout << "Usunieto element z listy." << endl;
        } else {
            cout << "Element o wartosci " << value << " nie istnieje w liscie." << endl;
        }
    }

    void wyswietlListe() {
        Element* temp = glowa;

        if (!temp) {
            cout << "Lista jest pusta." << endl;
        } else {
            cout << "Zawartosc listy: ";
            while (temp) {
                cout << temp->wartosc << " ";
                temp = temp->nastepny;
            }
            cout << endl;
        }
    }

    ~Lista() {
        Element* temp;
        while (glowa) {
            temp = glowa;
            glowa = glowa->nastepny;
            delete temp;
        }
    }
};

int main() {
    Lista listaSymulacja;
    char choice;

    do {
        cout << "Menu:"<< endl;
        cout << "1. Dodaj element do listy" << endl;
        cout << "2. Usun element z listy" << endl;
        cout << "3. Wyswietl liste" << endl;
        cout << "0. Zakoncz program" << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int value;
                cout << "Podaj wartosc do dodania do listy: ";
                cin >> value;
                listaSymulacja.dodajElement(value);
                break;
            }
            case '2': {
                int value;
                cout << "Podaj wartosc do usuniecia z listy: ";
                cin >> value;
                listaSymulacja.usunElement(value);
                break;
            }
            case '3':
                listaSymulacja.wyswietlListe();
                break;
            case '0':
                cout << "Koniec programu." << endl;
                break;
            default:
                cout << "Niepoprawna opcja. Sprobuj jeszcze raz." << endl;
        }
    } while (choice != '0');

    return 0;
}
