// clases.cpp
// Definicion de metodos de cada clase

#include "objeto.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student() : id(0), valor(0), nombre("") {}

Student::Student(int k, int v, string d) : id(k), valor(v), nombre(d) {}

Student::~Student() {}

ostream &operator<<(ostream &os, const Student &S)
{
    os << S.id << " " << S.valor << " "  << S.nombre;
    return os;
}

istream &operator>>(istream &is, Student &S)
{
    is >> S.id >> S.valor >> S.nombre;
    return is;
}

const string Student :: class_name = " StudentClass ";