#include "Perro.h"

Perro::Perro()
{
    nombre = "";
    tamano = "";
    color = "";
    edad = 0;
    razaObj = NULL;
    veterinarioObj = NULL;
};

Perro::Perro(string &nombre, string &tamano, string &color, int &edad, Raza *razaObj, Veterinario *veterinarioObj)
    : nombre(nombre), tamano(tamano), color(color), edad(edad), razaObj(razaObj), veterinarioObj(veterinarioObj) {};

void Perro::setNombre(string &nombre)
{
    nombre = nombre;
}

string Perro::getNombre()
{
    return nombre;
}

void Perro::setTamano(string &tamano)
{
    tamano = tamano;
}

string Perro::getTamano()
{
    return tamano;
}

void Perro::setColor(string &color)
{
    color = color;
}

string Perro::getColor()
{
    return color;
}

void Perro::setEdad(int &edad)
{
    edad = edad;
}

int Perro::getEdad()
{
    return edad;
}

void Perro::setRaza(Raza *razaObj)
{
    this->razaObj = razaObj;
}

Raza *Perro::getRaza()
{
    return razaObj;
}

void Perro::setVeterinario(Veterinario *veterinarioObj)
{
    veterinarioObj = veterinarioObj;
}

Veterinario *Perro::getVeterinario()
{
    return veterinarioObj;
}

void Perro::ladrar()
{
    cout << "Guau Guau" << endl;
}

void Perro::saludar()
{
    cout << "Guau" << endl;
}