#include "clases.h"
#include "clases.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    // crear una persona
    Persona p1("Francisco");
    Persona p2("Mateo");
    Persona p3("Emi");

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    Oferta o1(p1, 12000);
    Oferta o2(p2, 11000);
    Oferta o3(p3, 15000);

    cout << "Oferta: " << o1 << "." << endl;
    cout << "Oferta: " << o2 << "." << endl;
    cout << "Oferta: " << o3 << "." << endl;

    Lote l1(1, "Cuadro de Van Gogh");

    cout << "Lote: " << l1 << "." << endl;

    l1.setOferta(o1);
    l1.setOferta(o2);
    l1.setOferta(o3);


    cout << "Lote: " << l1 << "." << endl;

     


    return 0;
}