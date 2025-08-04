// clases.h
// Definicion de clases

#ifndef OBJETO_H
#define OBJETO_H

#include <string>

using namespace std;

class Student {
    private:
        int id;
        int valor;
        string nombre;
    public:
        static const string class_name;
        Student();
        Student(int k, int v, string d);
        ~Student();
        friend ostream& operator<<(ostream&, const Student&);
        friend istream& operator>>(istream&, Student&);
};

#endif