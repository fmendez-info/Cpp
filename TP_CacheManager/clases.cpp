// clases.cpp
// Definicion de metodos de cada clase

#include "clases.h"
#include <iostream>
#include <string>

template <class T>
CacheManager<T>::CacheManager(int cap)
{
    capacidad = cap;
}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::write_file(string key, T obj)
{
    return true;
}

template <class T>
void CacheManager<T>::insert(string key, T obj)
{
    // Si existe, actualizara al objeto tanto en cache como en el archivo.
    // De lo contrario, escribira el objeto en el sistema de archivos y la cache
    // Se actualizara el MRU del Obj para que sea el mayor.
}

template <class T>
T CacheManager<T>::get(string key)
{
    // Si el obj existe, sea en la cache o en el archivo, lo retorna y
    // actualiza el MRU.
    // Si la clave no existe tanto en el sistema principal como en el sistema
    // de archivos, el programa debe informarlo
}

template <class T>
ostream &operator<<(ostream &os, const CacheManager<T> &C)
{
    os << C.capacidad;
    return os;
}