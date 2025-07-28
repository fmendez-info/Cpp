// clases.cpp
// Definicion de metodos de cada clase

#include "objeto.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student(int k, int v, string d) : id(k), value(v), data(d) {}

Student::~Student() {}

ostream &operator<<(ostream &os, const Student &S)
{
    os << S.id << " " << S.value << " " << S.data << endl;
    return os;
}

const string Student :: class_name = " StudentClass ";