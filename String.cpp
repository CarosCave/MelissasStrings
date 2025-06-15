#include "string.hpp"
#include <iostream>
using namespace std;

namespace StringKlasse {

    //----------//Hilfsfunktionen----------------

    int String::strLength(char const * input) {
        int laenge = 0;
        // '\0' markiert das Ende einer Zeichenkette und hat den ASCII-Wert 0
        //Array wird also so lang, bis Markierung eingetroffen ist
        while (input[laenge] != '\0') {
            laenge++;
        }

        return laenge;
    }

    void String::strCopy(char* ziel, char const * quelle) {
        int i = 0;
        while ((ziel[i] = quelle[i]) != '\0') {
            ++i;
        }
    }

    //----------//Konstruktoren / Dekonsturktoren----------------

    String::String() : zeichenkette(nullptr), laenge(0) {}

    String::String(const char* input) {

        laenge = strLength(input);
        zeichenkette = umwandelnInCharArray(input);
    };

    String::String(char const input) {

        laenge = 1;
        zeichenkette = umwandelnInCharArray(input);
    }

    String::String(String const & input) : laenge(input.laenge), zeichenkette(input.zeichenkette){};

    String::~String() {
        //delete[] zeichenkette;
    };

    //----------Zuweisungs Operatoren------------------------------

    String & String::operator=(char const & input) {
        //Aktuelle Zeichenkette wird gelöscht, damit sie überschrieben werden kann
        delete[] zeichenkette;
        //Neue Länge der Zeichenkette
        laenge = strLength(&input);
        //Neue Zeichenkette
        zeichenkette = new char[laenge + 1];
        strCopy(zeichenkette, &input);
        return *this;
    }

    String & String::operator=(char* const & input) {
        //Aktuelle Zeichenkette wird gelöscht, damit sie überschrieben werden kann
        delete[] zeichenkette;
        //Neue Länge der Zeichenkette
        laenge = strLength(input);
        //Neue Zeichenkette
        zeichenkette = new char[laenge + 1];
        strCopy(zeichenkette, input);
        return *this;
    }

    String & String::operator=(String const & input) {
        if (this != &input) {
            //Aktuelle Zeichenkette wird gelöscht, damit sie überschrieben werden kann
            delete[] zeichenkette;
            //Neue Länge der Zeichenkette
            laenge = input.laenge;
            //Neue Zeichenkette
            zeichenkette = new char[laenge + 1];
            strCopy(zeichenkette, input.zeichenkette);
        }
        return *this;
    }

    //----------Vergleichs Operatoren-----------------------------

    bool String::operator==(String const & input) const {

        //Zeichenkette durchlaufen, um zu gucken, ob alle Zeichen gleich sind
        for (int i = 0; i < laenge; i++) {
            if (this->zeichenkette[i] != input.zeichenkette[i]) {
                return false;
            }
        }

        //Wenn alle Zeichen gleich sind
        if (laenge == input.laenge) {
            return true;
        }
        else {
            return false;
        }
    };

    bool String::operator!=(String const & input) const {
        //Zeichenkette durchlaufen, um zu gucken, ob alle Zeichen gleich sind
        for (int i = 0; i < laenge; i++) {
            if (this->zeichenkette[i] != input.zeichenkette[i]) {
                return true;
            }
        }

        //Wenn alle Zeichen gleich sind
        if (laenge == input.laenge) {
            return false;
        }
        else {
            return true;
        }
    };

    // bool String::operator<(String const & input) const {
    //
    //     //Erstmal alle Zeichen in Kleinbuchstaben ändern, um den Zahlenwert dahinter vergleichen zu können
    //     String this_string = toLower();
    //     String str = input.toLower();
    //
    //     //Kürzeres Wort herausfinden, um damit anzufangen
    //     int kuerzeresWort = this->laenge < input.laenge ? this->laenge : input.laenge;
    //     for (int i = 0; i < kuerzeresWort; i++) {
    //         int buchstabe1 = this->zeichenkette[i];
    //         int buchstabe2 = input.zeichenkette[i];
    //
    //         if (buchstabe1 > buchstabe2) {
    //             return false;
    //         }
    //         else if (buchstabe1 < buchstabe2) {
    //             return true;
    //         }
    //         else if (buchstabe1 == buchstabe2) {
    //             continue;
    //         }
    //     }
    // };

    // bool String::operator>(String const & string) const {
    //
    //     //Erstmal alle Zeichen in Kleinbuchstaben ändern, um den Zahlenwert dahinter vergleichen zu können
    //     String this_string = toLower();
    //     String str = string.toLower();
    //
    //     //Kürzeres Wort herausfinden, um damit anzufangen
    //     int kuerzeresWort = this->laenge < string.laenge ? this->laenge : string.laenge;
    //     for (int i = 0; i < kuerzeresWort; i++) {
    //         int buchstabe1 = this->zeichenkette[i];
    //         int buchstabe2 = string.zeichenkette[i];
    //
    //         if (buchstabe1 < buchstabe2) {
    //             return false;
    //         }
    //         else if (buchstabe1 > buchstabe2) {
    //             return true;
    //         }
    //         else if (buchstabe1 == buchstabe2) {
    //             continue;
    //         }
    //     }
    // };

    // bool String::operator<=(String const & input) const {
    //     //Hier können die bereits implementierten Operator-Methoden genutzt werden
    //     if (*this == input || *this < input) {
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // };
    //
    // bool String::operator>=(String const & input) const {
    //     //Hier können die bereits implementierten Operator-Methoden genutzt werden
    //     if (*this == input || *this > input) {
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // };

    //----------Zugriffs Operatoren----------------------------------------------------

    // char String::operator[](int index) const {
    //     if (index >= 0 && index <= laenge - 1) {
    //         return zeichenkette[index];
    //     }
    //     else {
    //         std::cout << "Index out of range." << std::endl;
    //     }
    // };

    //----------Verkettung Operatoren----------------------------------------------------

    String & String::operator+=(String const & input) {
        *this = *this + input;
        return *this;
    };

    String & String::operator+=(char* const & input) {
        String string(input);
        *this = *this + string;
        return *this;
    };

    String & String::operator+=(char input) {
        *this = *this + input;
        return *this;
    };

    String String::operator+(String const & input) {
        String string;
        int neueLaenge = laenge + input.laenge;
        string.zeichenkette = new char[neueLaenge];
        string.laenge = neueLaenge;

        for (int i = 0; i < laenge; i++) {
            string.zeichenkette[i] = zeichenkette[i];
        }

        for (int i = 0; i < input.laenge; i++) {
            string.zeichenkette[laenge + i] = input.zeichenkette[i];
        }

        //Das Ende des Char Arrays definieren
        string.zeichenkette[neueLaenge] = '\0';
        return string;
    };

    String String::operator+(char* const & input) {
        String string(input);
        String newString = *this + string;
        return newString;
    };

    /*
    * Erst hatte ich überlegt, selbst ein Leerzeichen zwischen den Wörtern hinzuzufügen, aber in der normalen Verwendung von Strings,
    * müssen wir auch selbst die Leerzeichen einfügen, das macht nicht automatisch die Methode.
    */

    String String::operator+(char input) {
        String string;
        int neueLaenge = laenge + 1;
        string.zeichenkette = new char[neueLaenge];
        string.laenge = neueLaenge;

        for (int i = 0; i < laenge; i++) {
            string.zeichenkette[i] = this->zeichenkette[i];
        }

        string.zeichenkette[laenge] = input;

        //Das Ende des Char Arrays definieren
        string.zeichenkette[neueLaenge] = '\0';
        return string;
    };

    //----------Allgemeine Operatoren----------------------------------------------------

    int String::getLength() {
        int laenge = 0;
        // '\0' markiert das Ende einer Zeichenkette und hat den ASCII-Wert 0
        //Array wird also so lang, bis Markierung eingetroffen ist
        while (this->zeichenkette[laenge] != '\0') {
            laenge++;
        }

        return laenge;
    }

    String String::toUpper() const {
        String string(*this);
        for (int i = 0; this->zeichenkette[i] != '\0'; i++) {
            if (this->zeichenkette[i] >= 'A' && this->zeichenkette[i] <= 'Z') {
                this->zeichenkette[i] = this->zeichenkette[i] - 32;
            }
        }

        return string;
    };

    String String::toLower() const {
        String string(*this);
        for (int i = 0; this->zeichenkette[i] != '\0'; i++) {
            if (this->zeichenkette[i] >= 'A' && this->zeichenkette[i] <= 'Z') {
                this->zeichenkette[i] = this->zeichenkette[i] + 32;
            }
        }

        return string;
    };

    char* String::umwandelnInCharArray(char const input) {

        //Neues Array mit der herausgefundenen Länge anlegen
        char* arr = new char[2];

        //Einzelnes Char in Array speichern
        arr[0] = input;

        //Das Ende des Char Arrays definieren
        arr[1] = '\0';

        return arr;
    };

    char* String::umwandelnInCharArray(const char* input) {

        int newLaenge = strLength(input);

        //Neues Array mit der herausgefundenen Länge anlegen
        char* arr = new char[laenge + 1];

        //Den Input, der übergeben wurde, in das neu angelegte Array hinzufügen
        for (int i = 0; i < laenge; i++) {
            arr[i] = input[i];
        }

        //Das Ende des Char Arrays definieren
        arr[laenge] = '\0';

        return arr;
    };

    String String::umwandeVonCharArray(char* const input){
        String newString(input);
        return newString;
    };
}








