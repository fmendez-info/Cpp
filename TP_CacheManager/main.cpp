// main.cpp
// Programa principal que secuencia las acciones

#include "clases.h"
#include "clases.cpp"

#include "objeto.h"
#include "objeto.cpp"

int main(){
    CacheManager<Student> cache(3);

    cout << cache << endl;

    cache.insert("0", Student(0,22,"Estudiante1"));
    cache.insert("1", Student(1,23,"Estudiante2"));
    cache.insert("2", Student(2,25,"Estudiante3"));
    cache.insert("3", Student(3,29,"Estudiante4"));

    cout << cache << endl;

    cache.insert("2", Student(22,222,"EZE"));
    
    cout << cache << endl;

    return 0;
}