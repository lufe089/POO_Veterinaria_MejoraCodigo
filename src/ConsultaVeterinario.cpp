#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include "ConsultaVeterinario.h"

using namespace std;

ConsultaVeterinario::ConsultaVeterinario()
{
}

void ConsultaVeterinario::setFecha()
{
    fecha = time(0);
}

time_t ConsultaVeterinario::getFecha()
{
    return fecha;
}

void ConsultaVeterinario::setIdConsulta(long l)
{
    idConsulta = l;
}

long ConsultaVeterinario::getIdConsulta()
{
    return idConsulta;
}

void ConsultaVeterinario::setPerroObj(Perro *p)
{
    perroObjt = p;
}

Perro *ConsultaVeterinario::getPerroObj()
{
    return perroObjt;
}

void ConsultaVeterinario::setVeterinarioObj(Veterinario *v)
{
    veterinarioObjt = v;
}

Veterinario *ConsultaVeterinario::getVeterinarioObj()
{
    return veterinarioObjt;
}

void ConsultaVeterinario::setMotivoVisita(string s)
{
    motivoVisita = s;
}

string ConsultaVeterinario::getMotivoVisita()
{
    return motivoVisita;
}