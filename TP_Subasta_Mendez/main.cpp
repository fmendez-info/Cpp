// main.cpp
// Programa principal que secuencia las acciones

#include "clases.h"
#include "clases.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
/* 
    // Testeo de las clases----------------------------------------------------
        // Persona
        Persona p1("Francisco");
        Persona p2("Juan");
        Persona p3("Pablo");
        cout << p1 << endl;
        cout << p2 << endl;
        cout << p3 << endl;
        // Oferta
        Oferta o1(12000, p1);
        Oferta o2(11000, p2);
        Oferta o3(15000, p3);
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
/* 
    // Funcionamiento secuenciado----------------------------------------------
    // Se crea la subasta
    Subasta subasta;
    cout << endl << "Se ingresan los lotes a subastar:" << endl;
    subasta.insertLote(1, "Auto secuestrado");
    subasta.insertLote(2, "Camiseta firmada por Messi");
    subasta.insertLote(3, "Escultura hecha por Leo Gomez");
    cout << "_____________________________________________________________"
         << endl << "Inicia la subasta: "
         << endl << subasta;
    
    subasta.ofertarLote(1, "Alberto", 2000000);
    subasta.ofertarLote(1, "Juan", 1500000);
    subasta.ofertarLote(1, "Pablo", 3000000);
    subasta.ofertarLote(2, "Maria", 100000);
    subasta.ofertarLote(2, "Pedro", 200000);
    subasta.ofertarLote(2, "Martin", 300000);
    subasta.ofertarLote(3, "Lucas", 200000);
    subasta.ofertarLote(3, "Sofia", 300000);
    subasta.ofertarLote(3, "Ana", 400000);

    cout << "_____________________________________________________________"
         << endl << "Se da por terminada la subasta: "
         << endl << subasta;
*/
    // Funcionamiento interactivo----------------------------------------------
    // Se crea la subasta
    Subasta subasta;
    int opcion;
    do{
        cout << "1-Ingresar un lote" << endl
             << "2-Ofertar por un lote" << endl
             << "3-Mostrar estado de la subasta" << endl
             << "0-Concluir la subasta" << endl;
        cin >> opcion;
        cin.ignore();

        int id;
        string nombreLote;
        string nombreOfertante;
        float monto;
        switch(opcion){
            case 1:
                cout << "Ingrese numero del lote: ";
                cin >> id;
                cout << "Ingrese nombre del lote: ";
                cin >> nombreLote;
                subasta.insertLote(id, nombreLote);
                cout << endl;
                break;
            case 2:
                cout << "Ingrese numero del lote: ";
                cin >> id;
                cout << "Ingrese nombre del ofertante: ";
                cin >> nombreOfertante;
                cout << "Ingrese monto de la oferta: ";
                cin >> monto;
                subasta.ofertarLote(id, nombreOfertante, monto);
                cout << endl;
                break;
            case 3:
                cout << "Subasta: " << endl << subasta;
                break;
            case 0:
                break;
            default:
                cout << "Opcion incorrecta." << endl << endl;
                break;
        }
    }while (opcion > 0);

    cout << "_____________________________________________________________"
         << endl << "Se da por terminada la subasta: "
         << endl << subasta;


    return 0;
}