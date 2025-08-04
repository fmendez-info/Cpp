// cache.cpp
// Definicion de metodos de la clase

#include "cache.h"
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>

using namespace std;

template <class T>
CacheManager<T>::CacheManager(int cap)
{
    capacidad = cap;
    indice = 0;
    ofstream archivo("MemoriaPrincipal.dat", ios::out); // creo el archivo
    archivo.close();
}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::write_file(string key, T obj)
{
    map <string, T> data = read_file();

    auto iterador = data.find(key); // busca el elemento en el archivo
    if (iterador != data.end()){
        iterador->second = obj; // si lo encuentra lo actualiza
    } else {
        data.insert({key, obj}); // sino lo inserta
    }

    ofstream archivo("MemoriaPrincipal.dat", ios::out);
    if (!archivo.is_open()){
        return false;
    }

    for (const auto& x : data){ // por cada elemento
        // lo inserto y voy a la linea siguiente
        archivo << x.first << " " << x.second << endl;
    }

    archivo.close();
    return true;
}

template <class T>
map <string, T> CacheManager<T>::read_file()
{
    string key;
    T obj;
    map <string, T> data;

    ifstream archivo("MemoriaPrincipal.dat", ios::in);
    if (!archivo.is_open()){
        cerr << "Error al abrir el archivo" << endl;
        return data;
    }
    while (archivo >> key >> obj){
        data.insert({key, obj});
    }
    archivo.close();
    return data;
}

template <class T>
void CacheManager<T>::show_file()
{
    map <string, T> data = read_file();

    cout << "Archivo: ______________________________________" << endl;
    for (const auto& x : data){
        cout << "Clave: " << x.first <<" - Objeto: " << x.second << endl;
    }
    if (data.size() == 0) {
        cout << "Vacio." << endl;
    }
}

template <class T>
void CacheManager<T>::insert(string key, T obj)
{
    // Si existe, actualizara al objeto tanto en cache como en el archivo.
    // De lo contrario, escribira el objeto en el sistema de archivos y la cache
    // Se actualizara el MRU del Obj para que sea el mayor.
    cout << "Se inserta/actualiza en cache el elemento: " << key << " - " << obj << endl;
    indice++;
    //cache_data[key] = {obj,indice};

    // Se inserta en cache
    auto iterador = cache_data.find(key);
    if (iterador != cache_data.end()){
        // Se encontro la clave
        cout << "Elemento " << key << " existe en cache. Se actualiza." << endl;
        iterador->second = {obj,indice}; // El indice cambia al actual
    } else {
        // No se encontro la clave
        if (cache_data.size()<capacidad){ // Si todavia hay lugar
            cache_data.insert({key,{obj,indice}}); // Inserto normalmente
        } else { // Si ya no hay lugar
            auto menor_indice = cache_data.begin(); // Inicialmente tomo el primero como el menor
            for (const auto& x : cache_data){ // Recorro los elementos para buscar el de menor indice
                if (x.second.second < menor_indice->second.second) {
                    menor_indice = cache_data.find(x.first);
                }
            }

            /* 
            menor_indice->first = key; // la key no se puede modificar
            menor_indice->second = {obj, indice}; // el dato se puede modificar sin problema
            */
            
            cache_data.erase(menor_indice); // Elimino el de menor indice
            cache_data.insert({key, {obj, indice}}); // Inserto el nuevo elemento
        }
    }

    // Se inserta en archivo
    write_file(key, obj);

    cout << endl;
}

template <class T>
T CacheManager<T>::get(string key)
{
    // Si el obj existe, sea en la cache o en el archivo, lo retorna
    // y actualiza el MRU.
    // Si la clave no existe tanto en el sistema principal como en el sistema
    // de archivos, el programa debe informarlo

    cout << "Se busca el elemento " << key << endl;

    // se busca en cache
    auto iterador_cache = cache_data.find(key);
    if(iterador_cache != cache_data.end()){
        // el objeto existe
        cout << "Se encontro en cache:" << endl;
        cout << "Clave: " << iterador_cache->first <<" - Objeto: " << iterador_cache->second.first << " - Indice: " << iterador_cache->second.second << endl;
        T obj = iterador_cache->second.first;
        insert(key,obj);
        return obj;
    }

    // se busca en archivo
    map <string, T> archivo = read_file();
    auto iterador_archivo = archivo.find(key);
    if(iterador_archivo != archivo.end()){
        // el objeto existe
        cout << "Se encontro en archivo:" << endl;
        cout << "Clave: " << iterador_archivo->first <<" - Objeto: " << iterador_archivo->second << endl;
        T obj = iterador_archivo->second;
        insert(key,obj);
        return obj;
    }

    // no se encontro    
    cout << "Elemento " << key << " no encontrado." << endl << endl;
    return T(0,0,"");
}

template <class T>
void CacheManager<T>::show_cache()
{
    cout << "Cache:_________________________________________" << endl;
    for (const auto& x : cache_data){
        cout << "Clave: " << x.first <<" - Objeto: " << x.second.first << " - Indice: " << x.second.second << endl;
    }
    if (cache_data.size() == 0) {
        cout << "Vacia." << endl;
    }
    show_file();
    cout << endl;
}
