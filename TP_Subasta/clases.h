// clases.h
// Definicion de clases

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
        float monto;
        Persona ofertante;
    public:
        Oferta(float, Persona);
        ~Oferta();
        float getMonto();
        Persona getOfertante();
        friend ostream& operator<<(ostream&, const Oferta&);
};

class Lote {
    private:
        int id;
        string nombre;
        Oferta* maxOferta;
    public:
        Lote(int, string);
        ~Lote();
        int getId();
        string getNombre();
        Oferta* getMaxOferta();
        void setOferta(Oferta);
        friend ostream& operator<<(ostream&, const Lote&);
};

class Subasta {
    private:
        vector<Lote*> lotes;
        int cantidadLotes;
    public:
        Subasta();
        ~Subasta();
        vector<Lote*> getLotes();
        int getCantidadLotes();
        Lote* buscarLote(int);
        void insertLote(int, string);
        void ofertarLote(int, string, float);
        friend ostream& operator<<(ostream&, const Subasta&);
};

#endif