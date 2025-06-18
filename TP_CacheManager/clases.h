// clases.h
// Definicion de clases

#include <iostream>
#include <fstream>

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

        friend ostream& operator<<(ostream&, const CacheManager&);
};