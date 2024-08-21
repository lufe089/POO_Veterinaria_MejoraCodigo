#ifndef RAZA_H
#define RAZA_H
#include <iostream>

using namespace std;

class Raza
{
private:
    string nombre;
    string paisOrigen;

public:
    Raza();
    Raza(string &nombre, string &paisOrigen);
    void setNombre(string &nombre);
    string getNombre();
    void setPaisOrigen(string &paisOrigen);
    string getPaisOrigen();
};

#endif