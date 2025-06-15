#include "String.hpp"
#include "gtest/gtest.h"

using namespace StringKlasse;

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