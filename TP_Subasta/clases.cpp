// clases.cpp
// Definicion de metodos de cada clase

#include "clases.h"
#include <iostream>
#include <string>
using namespace std;

//-Persona---------------------
//-Constructor
Persona::Persona(string n) : nombre(n) {}

string Persona::getNombre()
{
    return nombre;
}
//-Sobrecarga del cout para Persona
ostream &operator<<(ostream &os, const Persona &P)
{
    os << P.nombre;
    return os;
}

//-Oferta----------------------
//-Constructor
Oferta::Oferta(float m, Persona p) : monto(m), ofertante(p) {}
float Oferta::getMonto()
{
    return monto;
}
Persona Oferta::getOfertante()
{
    return ofertante;
}
Oferta::~Oferta() {}
// Sobrecarga del cout para Oferta
ostream &operator<<(ostream &os, const Oferta &O)
{
    os << "$";
    // imprimo monto como entero si es mayor a 100000
    O.monto >= 100000 ? os << (int)O.monto : os << O.monto;
    os << " de " << O.ofertante;
    return os;
}

//-Lote------------------------
//-Constructor
Lote::Lote(int id, string n) : id(id), nombre(n), maxOferta(nullptr) {}
Lote::~Lote()
{
    delete maxOferta;
}
int Lote::getId()
{
    return id;
}
string Lote::getNombre()
{
    return nombre;
}
Oferta* Lote::getMaxOferta()
{
    return maxOferta;
}
void Lote::setOferta(Oferta nuevaOferta)
{
    /* cout << nuevaOferta->getOfertante()
         << " oferto " << nuevaOferta->getMonto()
         << " por \"" << nombre << "\""
         << endl; */
    if (maxOferta == nullptr)
    {
        delete maxOferta;
        maxOferta = new Oferta(nuevaOferta);
        cout << "Es la primera oferta para \"" << nombre << "\"."
             << endl;
    }
    else if (nuevaOferta.getMonto() > maxOferta->getMonto())
    {
        delete maxOferta;
        maxOferta = new Oferta(nuevaOferta);
        cout << "La oferta reemplaza a la anterior." << endl;
    }
    else
    {
        cout << "La oferta es menor a la actual, no se registra." << endl;
    }
    cout << "Oferta actual para \"" << nombre
         << "\": " << *maxOferta
         << "." << endl;
    return;
}
//-Sobrecarga del cout para Lote
ostream &operator<<(ostream &os, const Lote &L)
{
    if (L.maxOferta != nullptr)
    {
        os //<< "Puntero: " << &L << ", "
           << "ID: " << L.id << ", "
           << "Nombre: " << L.nombre << ", "
           << "Oferta: " << *L.maxOferta;
    }
    else
    {
        os //<< "Puntero: " << &L << ", "
           << "ID: " << L.id << ", "
           << "Nombre: " << L.nombre << ", "
           << "Oferta: " << "sin oferta aun";
    }
    return os;
}

// Subasta
// Constructor
Subasta::Subasta() : lotes(), cantidadLotes(0) {
    cout << "Se crea la subasta: " << *this << endl;
}
Subasta::~Subasta()
{
    for (auto lote : lotes){
        delete lote;
    }
}
vector<Lote*> Subasta::getLotes()
{
    return lotes;
}
int Subasta::getCantidadLotes()
{
    return cantidadLotes;
}
void Subasta::insertLote(int id, string n)
{
    if (buscarLote(id)!=nullptr)
    {
        cout << "Numero de lote " << id << " ya existe." << endl;
        return;
    }
    Lote* lote = new Lote(id, n);
    lotes.push_back(lote);
    cantidadLotes++;
    cout << "  -Lote ingresado: " << *lote << "." << endl;
    return;
}
Lote* Subasta::buscarLote(int idLote)
{
    for (auto lote : lotes)
    {
        //cout << "Puntero lote: " << lote << endl; // testing punteros
        if (lote->getId() == idLote)
        {
            return lote;
        }
    }
    return nullptr;
}
void Subasta::ofertarLote(int idLote, string persona, float monto)
{
    cout << endl
         << "Oferta en lote " << idLote << ": "
         << persona << " oferta $";
    monto >= 100000 ? cout << (int)monto : cout << monto;
    cout << "." << endl;
    
    Lote* loteEncontrado = buscarLote(idLote);
    if (loteEncontrado==nullptr)
    {
        cout << endl << "ID de lote no encontrado." << endl;
        return;
    }
    cout << "Lote encontrado: " << *loteEncontrado
         << "." << endl;
    Persona ofertante(persona);
    Oferta oferta (monto,ofertante);
    loteEncontrado->setOferta(oferta);
    return;
}
//-Sobrecarga del cout para vector de lotes----------------
ostream &operator<<(ostream &os, const vector<Lote*> &lotes)
{
    for (auto lote : lotes)
    {
        os << "  -" << *lote
           << "." << endl;
    }
    return os;
}
//-Sobrecarga del cout para Subasta------------------------
ostream &operator<<(ostream &os, const Subasta &S)
{
    if (S.cantidadLotes != 0)
    {
        os << "Cantidad de lotes: " << S.cantidadLotes << endl
           << "Lotes: " << endl << S.lotes
           << endl;
    }
    else
    {
        os << "sin lotes." << endl;
    }
    return os;
}