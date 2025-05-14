#include <iostream>
#include <vector>
using namespace std;

void Persona:: setNombre(string n){this->nombre = n;}
string getNombre(){return this->nombre;}

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

Lote:: setearOferta()
{

    return;
}

class Subasta
{
    private:
        vector<Lote> lotes;
        int cantidadLotes;
    public:
};