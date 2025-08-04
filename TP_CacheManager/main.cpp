// main.cpp
// Programa principal que secuencia las acciones

#include "cache.h"
#include "cache.cpp"

#include "objeto.h"
#include "objeto.cpp"

int main(){
    CacheManager<Student> cache(3);
    cout << "Se crea la cache con tamaño 3: " << endl;
    cache.show_cache();

    cache.insert("0", Student(0,22,"Estudiante1"));
    cache.insert("1", Student(1,23,"Estudiante2"));
    cache.insert("2", Student(2,25,"Estudiante3"));
    cache.show_cache();

    cache.get("0");
    cache.show_cache();

    cache.insert("3", Student(3,29,"Estudiante4"));
    cache.show_cache();

    cache.get("4");
    cache.show_cache();

    cache.get("2");
    cache.show_cache();

    cache.insert("2", Student(22,222,"EZE"));    
    cache.show_cache();

    cache.get("1");
    cache.show_cache();

    cache.~CacheManager();
    return 0;
}