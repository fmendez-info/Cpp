#include <iostream>
#include <vector>
using namespace std;

class Persona
{
    private:
        string nombre;
    public:
        void setNombre(string n){this->nombre = n;}
        string getNombre(){return this->nombre;}
};

class Oferta
{
    private:
        Persona ofertante;
        float monto;
    public:
        void setOferta(Persona persona, float monto);
        Persona getOfertante();
        float getMonto();
};

class Lote
{
    private:
        int id;
        string nombre;
        Oferta maxOferta;
    public:
        void setearOferta();
};

class Subasta
{
    private:
        vector<Lote> lotes;
        int cantidadLotes;
    public:
};