// clases.cpp
// Definicion de metodos de cada clase

#include "objeto.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student(int k, int v, string d) : id(k), value(v), data(d) {}

const string Student :: class_name = " StudentClass ";