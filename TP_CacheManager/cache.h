// cache.h
// Definicion de la clase

#ifndef CACHE_H
#define CACHE_H

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
        size_t capacidad;
        int indice;
        map <string, pair<T, int>> cache_data;
        //  <clave,<Objeto,Indice>>
        bool write_file(string, T);
        map <string, T> read_file();
        void show_file();
    public:
        CacheManager(int); //recibe la capacidad
        ~CacheManager();
        void insert(string, T);
        T get(string);
        void show_cache();
};

#endif