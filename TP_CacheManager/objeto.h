// clases.h
// Definicion de clases

#ifndef OBJETO_H
#define OBJETO_H

#include <string>

using namespace std;

class Student {
    private:
        int id;
        int value;
        string data;
    public:
        static const string class_name;
        Student(int k, int v, string d);
        ~Student();
        void print();
        friend ostream& operator<<(ostream&, const Student&);
};

#endif