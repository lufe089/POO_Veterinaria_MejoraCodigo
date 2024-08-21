#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include <iostream>
#include "Perro.h"
#include <vector>

class Propietario
{
private:
    string numeroIdentificacion;
    vector<Perro *> perrosACargo;

public:
    Propietario();
    ~Propietario();
    Propietario(string &numeroIdentificacion, vector<Perro *> &perro);
    void setNumeroIdentificacion(string &numeroIdentificacion);
    string getNumeroIdentificacion();
    void agregarPerro(Perro *perro);
    vector<Perro *> getPerrosACargo();
};

#endif