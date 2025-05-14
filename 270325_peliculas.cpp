#include <iostream>
using namespace std;

class Director{
    private:
        string nombre;
    public:
        string get_nombre() { return nombre; }
        void set_nombre(string n) { nombre=n; }
};

class Pelicula{
    private:
        string titulo;
        int anio;
        Director director;
        string trama;       
    public:
        Pelicula(string n, int a, string t) { titulo=n; anio=a, trama=t; }
        void set_director(Director d) { director=d; }
        void mostrar();
};

void Pelicula::mostrar(){
    cout << "Pelicula:\nNombre: " << titulo << '\n' <<
            "Año de filmacion: " << anio << '\n' <<
            "Director: " << director.get_nombre() << '\n' <<
            "Trama: " << trama << '\n';
}

int main(){
    Director dir1;
    dir1.set_nombre("Christopher Nolan");
    cout << dir1.get_nombre() << '\n';
    Pelicula peli1("Interestelar", 2014, "Un astronauta entra a un agujero negro y mueve libros en la biblioteca de su hija");
    peli1.set_director(dir1);
    peli1.mostrar();

    return 0;
}