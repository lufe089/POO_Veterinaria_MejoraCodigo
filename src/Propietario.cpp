#include "Propietario.h"

Propietario::Propietario() : numeroIdentificacion(""), perrosACargo(vector<Perro *>()) {}

Propietario::~Propietario()
{
    perrosACargo.clear();
}

Propietario::Propietario(string &numeroIdentificacion, vector<Perro *> &perro)
    : numeroIdentificacion(numeroIdentificacion), perrosACargo(perro) {};

void Propietario::setNumeroIdentificacion(string &numeroIdentificacionNuevo)
{
    numeroIdentificacion = numeroIdentificacionNuevo;
}

string Propietario::getNumeroIdentificacion()
{
    return numeroIdentificacion;
}

void Propietario::agregarPerro(Perro *perro)
{
    // FIXME agregar condición en caso de que el perro sea NULL
    perrosACargo.push_back(perro);
}

vector<Perro *> Propietario::getPerrosACargo()
{
    return perrosACargo;
}