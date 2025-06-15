#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace StringKlasse {
    class String
    {
    private:
        char * zeichenkette; //Pointer für die Zeichenkette
        int laenge; //Länge der Zeichenkette

        //--------------Hilfsfunktionen--------------

        //Berechnet die Länge der Zeichenkette
        static int strLength(char const *);

        //Kopiert eine Zeichenkette in eine andere
        static void strCopy(char*, char const *);

    public:
        // ------------------------------------------------------------------------------------------------
        // Caros Testfälle

        char * get_zeichenkette() const {
            return zeichenkette;
        }

        int get_laenge() const {
            return laenge;
        }

        //--------------Konstruktoren / Dekonsturktoren--------------

        //Default Konstrukor
        String();

        //Konstruktor, wenn Char Array übergeben wird
        String(const char*);

        //Konstruktor, wenn ein Char übergeben wird
        String(char const);

        //Kopier-Konstruktor, wenn String übergeben wird
        String(String const &);

        //Dekonstruktor
        ~String();

        //--------------Zuweisungs Operatoren--------------
        String & operator=(char); // Caro
        //String & String::operator=(char const &);
        String & operator=(char* const &);
        String & operator=(String const &);

        //--------------Vergleichs Operatoren--------------
        bool operator==(String const &) const;
        bool operator!=(String const &) const;
        //bool operator<(String const &) const;
        //bool operator>(String const &) const;
        //bool operator<=(String const &) const;
        //bool operator>=(String const &) const;

        //--------------Zugriffs Operatoren--------------
        //char operator[](int) const;

        //--------------Verkettung Operatoren--------------
        String & operator+=(String const & string);
        String & operator+=(char* const &);
        String & operator+=(char);

        String operator+(String const &);
        String operator+(char* const &);
        String operator+(char);

        //--------------Allgemeine Funktionen--------------
        int getLength();
        String toUpper() const;
        String toLower() const;

        static char* umwandelnInCharArray(char); // Caro
        static char* umwandelnInCharArray(char const *); // Caro
        static String umwandleVonCharArray(char * const); // Caro
        
        //char* umwandelnInCharArray(char const);
        //char* umwandelnInCharArray(const char*);
        //String umwandleVonCharArray(char* const);

        //--------------IO-Stream--------------
        /*
        * Ein - und Ausgabe wird in der Headerdatei implementiert, da es sich um kleine Methoden handelt.
        * Dies verbessert die Performance, da ein Funktionsaufruf wegfällt.
        * Außerdem werden die Methoden als friend deklariert, damit der Zugriff auf private Member möglich ist.
        */
        friend std::ostream& operator<<(std::ostream& os, String const& str) {
            for (int i = 0; i < str.laenge; i++) {
                os << str.zeichenkette[i];
            }

            os << std::endl;
            return os;
        }

        friend std::istream& operator>>(std::istream & is, String& str) {
            for (int i = 0; i < str.laenge; i++) {
                is >> str.zeichenkette[i];
            }
            return is;
        }
    };
}

#endif // STRING_H
