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
Oferta::Oferta(Persona p, float m) : ofertante(p), monto(m) {}
Persona Oferta::getOfertante()
{
    return ofertante;
}
float Oferta::getMonto()
{
    return monto;
}
// Sobrecarga del cout para Oferta
ostream &operator<<(ostream &os, const Oferta &O)
{
    os << O.monto
       << " de " << O.ofertante;
    return os;
}

//-Lote------------------------
//-Constructor
Lote::Lote(int id, string n) : id(id), nombre(n), maxOferta(nullptr) {}
int Lote::getId()
{
    return id;
}
string Lote::getNombre()
{
    return nombre;
}
Oferta Lote::getMaxOferta()
{
    return *maxOferta;
}
void Lote::setOferta(Oferta nuevaOferta)
{
    cout << nuevaOferta.getOfertante()
         << " oferto " << nuevaOferta.getMonto()
         << " por \"" << nombre << "\""
         << endl;
    if (maxOferta == nullptr)
    {
        maxOferta = &nuevaOferta;
        cout << "Es la primera oferta para \"" << nombre << "\"."
             << endl;
    }
    else if (nuevaOferta.getMonto() > maxOferta->getMonto())
    {
        maxOferta = &nuevaOferta;
        cout << "La oferta reemplaza a la anterior." << endl;
    }
    else
    {
        cout << "La oferta es menor a la actual, no se registra." << endl;
    }
    cout << "Oferta actual para \"" << nombre
         << "\": " << maxOferta->getMonto()
         << " de " << maxOferta->getOfertante()
         << endl;
    return;
}
//-Sobrecarga del cout para Lote
ostream &operator<<(ostream &os, const Lote &L)
{
    if (L.maxOferta != nullptr)
    {
        os << "Puntero: " << &L
           << " -ID: " << L.id
           << " -Nombre: " << L.nombre
           << " -Oferta: " << *L.maxOferta;
    }
    else
    {
        os << "Puntero: " << &L
           << " -ID: " << L.id
           << " -Nombre: " << L.nombre
           << " -Oferta: " << "sin oferta aun";
    }
    return os;
}

// Subasta
// Constructor
Subasta::Subasta() : lotes(), cantidadLotes(0) {
    cout << "Inicia la subasta: " << *this << "." << endl;
}
void Subasta::insertLote(int id, string n)
{
    Lote lote(id, n);
    lotes.push_back(&lote);
    cantidadLotes++;
    cout << "Lote ingresado: " << lote << "." << endl;
}
void Subasta::ofertarLote(int idLote, string persona, float monto)
{
    Lote* loteBuscado;
    for (auto lote : lotes)
    {
        cout << "Puntero lote: " << lote << endl;
        if (lote->getId() == idLote)
        {
            loteBuscado = lote;
            break;
        }
    }
    if (loteBuscado != nullptr)
    {
        cout << "Lote encontrado: " << *loteBuscado << endl;
        Oferta oferta(Persona(persona),monto);
        loteBuscado->setOferta(oferta);
    } else {
        cout << "ID de lote no encontrado." << endl;
    }
}
/* vector<Lote> Subasta::getLotes()
{

    return lotes;
} */

// Sobrecarga del cout para vector de lotes
ostream &operator<<(ostream &os, const vector<Lote*> &lotes)
{
    for (auto lote : lotes)
    {
        os << *lote << endl;
    }
    return os;
}
//-Sobrecarga del cout para Subasta
ostream &operator<<(ostream &os, const Subasta &S)
{
    if (S.cantidadLotes != 0)
    {
        os << "Cantidad de lotes: " << S.cantidadLotes << endl
           << "Lotes: " << endl << S.lotes;
    }
    else
    {
        os << "sin lotes";
    }
    return os;
}