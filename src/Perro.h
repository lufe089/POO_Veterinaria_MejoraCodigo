#ifndef PERRO_H
#define PERRO_H
#include <iostream>
#include "Raza.h"
#include "Veterinario.h"

using namespace std;

class Perro
{
private:
    string nombre;
    string tamano;
    string color;
    int edad;
    Raza *razaObj;
    Veterinario *veterinarioObj;

public:
    Perro();
    Perro(string &nombre, string &tamano, string &color, int &edad, Raza *razaObj, Veterinario *veterinarioObj);
    void setNombre(string &nombre);
    string getNombre();
    void setTamano(string &tamano);
    string getTamano();
    void setColor(string &color);
    string getColor();
    void setEdad(int &edad);
    int getEdad();
    void setRaza(Raza *razaObj);
    Raza *getRaza();
    void setVeterinario(Veterinario *veterinarioObj);
    Veterinario *getVeterinario();
    void ladrar();
    void saludar();
};

#endif