#ifndef CONSULTAVETERINARIO_H
#define CONSULTAVETERINARIO_H
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include "Perro.h"
#include "Veterinario.h"

using namespace std;

class ConsultaVeterinario
{
private:
    time_t fecha;
    long idConsulta;
    Perro *perroObjt;
    Veterinario *veterinarioObjt;
    string motivoVisita;

public:
    ConsultaVeterinario();
    void setFecha();
    time_t getFecha();
    void setIdConsulta(long);
    long getIdConsulta();
    void setPerroObj(Perro *);
    Perro *getPerroObj();
    void setVeterinarioObj(Veterinario *);
    Veterinario *getVeterinarioObj();
    void setMotivoVisita(string);
    string getMotivoVisita();
};

#endif