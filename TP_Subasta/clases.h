#ifndef CLASES_H
#define CLASES_H

#include <string>
#include <vector>
using namespace std;

class Persona {
    private:
        string nombre;
    public:
        Persona(string);
        string getNombre();
        friend ostream& operator<<(ostream&, const Persona&);
};

class Oferta {
    private:
        Persona ofertante;
        float monto;
    public:
        Oferta(Persona, float);
        Persona getOfertante();
        float getMonto();
        friend ostream& operator<<(ostream&, const Oferta&);
};

class Lote {
    private:
        int id;
        string nombre;
        Oferta* maxOferta;
    public:
        Lote(int, string);
        int getId();
        string getNombre();
        Oferta getMaxOferta();
        void setOferta(Oferta);
        friend ostream& operator<<(ostream&, const Lote&);
};

class Subasta {
    private:
        vector<Lote> lotes;
        int cantidadLotes;
    public:
        Subasta();
        void insertLote(int, string);
        void ofertarLote(int, string, float);
};

#endif