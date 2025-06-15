#include "String.hpp"
#include "gtest/gtest.h"

using namespace StringKlasse;

// ------------------------------------------------------------------------------------------------
// Test der Konstuktoren
TEST(Konstruktoren, Standard) {
    String a;
    EXPECT_EQ(a.get_zeichenkette(), nullptr);
    EXPECT_EQ(a.get_laenge(), 0);
}

TEST(Konstruktoren, Char_Array) {
    String a("Hallo");
    EXPECT_EQ(a, "Hallo");
    EXPECT_EQ(a.getLength(), 5);
}

TEST(Konstruktoren, Char) {
    String a('a');
    EXPECT_EQ(a, "a");
    EXPECT_EQ(a.getLength(), 1);
}

TEST(Konstruktoren, Copy_String) {
    String a("Hallo");
    String b(a);
    EXPECT_EQ(a, b);
    EXPECT_EQ(a.get_laenge(), b.get_laenge());
}

// ------------------------------------------------------------------------------------------------
// Test der allgemeinen Funktionen
TEST(Allgemeine_Funktionen, toUpper)
{
    String a{"hallo"};
    String b{"HALLO"};
    EXPECT_EQ(a.toUpper(), b);
}

TEST(Allgemeine_Funktionen, toLower)
{
    String a{"HALLO"};
    EXPECT_EQ(a.toLower(), "hallo");
}

TEST(Allgemeine_Funktionen, umwandelnInCharArray_Char)
{
    char a[] = "a";
    EXPECT_STREQ(a, String::umwandelnInCharArray('a'));
}

TEST(Allgemeine_Funktionen, umwandelnInCharArray_CharArray)
{
    char a[] = "Hallo";
    EXPECT_STREQ(a, String::umwandelnInCharArray("Hallo"));
}

TEST(Allgemeine_Funktionen, umwandleVonCharArray)
{
    String a{"Hallo"};
    EXPECT_EQ(a, String::umwandleVonCharArray("Hallo"));
}

// ------------------------------------------------------------------------------------------------
// Test der Zuweisungsoperatoren
TEST(Zuweisungs_Operator, Char) {
    String a;
    a = 'a';
    EXPECT_EQ(a, "a");
    EXPECT_EQ(a.get_laenge(), 1);
}

TEST(Zuweisungs_Operator, Char_Array) {
    String a;
    a = "Hallo";
    EXPECT_EQ(a, "Hallo");
    EXPECT_EQ(a.get_laenge(), 5);
}

TEST(Zuweisungs_Operator, String) {
    String a("Hallo");
    String b;
    b = a;
    EXPECT_EQ(b, a);
    EXPECT_EQ(b.get_laenge(), b.get_laenge());
}

// ------------------------------------------------------------------------------------------------
// Test der Vergleichenden Operatoren
TEST(Vergleicher, Gleich)
{
    String a{"Hallo"};
    String b{"Hallo"};
    String c{"Test"};
    EXPECT_EQ(a == b, true);
    EXPECT_EQ(a == c, false);
}

TEST(Vergleicher, Ungleich)
{
    String a{"Hallo"};
    String b{"Halloechen"};
    String c{"Hallo"};
    EXPECT_EQ(a != b, true);
    EXPECT_EQ(a != c, false);
}