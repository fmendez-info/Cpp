#include "clases.h"
#include "clases.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    /* 
    // Testeo de las clases
        // Persona
        Persona p1("Francisco");
        Persona p2("Juan");
        Persona p3("Pablo");
        cout << p1 << endl;
        cout << p2 << endl;
        cout << p3 << endl;
        // Oferta
        Oferta o1(p1, 12000);
        Oferta o2(p2, 11000);
        Oferta o3(p3, 15000);
        cout << "Oferta: " << o1 << "." << endl;
        cout << "Oferta: " << o2 << "." << endl;
        cout << "Oferta: " << o3 << "." << endl;
        // Lote
        Lote l1(1, "Cuadro de Van Gogh");
        cout << "Lote: " << l1 << "." << endl;
        // Ofertas al lote
        l1.setOferta(o1);
        l1.setOferta(o2);
        l1.setOferta(o3);
        cout << "Lote: " << l1 << "." << endl;
     */
    // Subasta
    Subasta subasta;
    subasta.insertLote(1, "Auto secuestrado");
    subasta.insertLote(2, "Camiseta firmada por Messi");
    subasta.insertLote(3, "Escultura hecha por Leo Gomez");
    cout << "Lotes: " << endl << subasta.getLotes();
    subasta.ofertarLote(1, "Alberto", 200000);
    subasta.ofertarLote(1, "Juan", 150000);
    subasta.ofertarLote(1, "Pablo", 300000);
    subasta.ofertarLote(2, "Maria", 100000);
    subasta.ofertarLote(2, "Pedro", 200000);
    subasta.ofertarLote(2, "Martin", 300000);
    subasta.ofertarLote(3, "Lucas", 200000);
    subasta.ofertarLote(3, "Sofia", 300000);
    subasta.ofertarLote(3, "Ana", 400000);

    cout << "Resultado de la subasta: " << endl << subasta;

    return 0;
}