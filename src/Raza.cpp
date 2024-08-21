#include "Raza.h"

Raza::Raza()
{
    nombre = "";
    paisOrigen = "";
}

Raza::Raza(string &nombre, string &paisOrigen) : nombre(nombre), paisOrigen(paisOrigen) {}

void Raza::setNombre(string &nombre)
{
    nombre = nombre;
}

string Raza::getNombre()
{
    return nombre;
}

void Raza::setPaisOrigen(string &paisOrigen)
{
    paisOrigen = paisOrigen;
}

string Raza::getPaisOrigen()
{
    return paisOrigen;
}