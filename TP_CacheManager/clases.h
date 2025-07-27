// clases.h
// Definicion de clases

#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>

using namespace std;

template <class T>
class CacheManager {
    private:
        int capacidad;
        map <string, pair<T, int>> cache_data;
        //  <clave,<Objeto,Indice>>
        bool write_file(string,T);
    public:
        CacheManager(int); //recibe la capacidad
        ~CacheManager();
        void insert(string, T);
        T get(string);
        template <class U>
        //friend ostream& operator<<(ostream&, const CacheManager<T>&);
};

#endif