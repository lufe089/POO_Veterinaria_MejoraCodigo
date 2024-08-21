#include <vector>
#include <string>
#include <iostream>
#include "Veterinario.h"

using namespace std;

Veterinario::Veterinario()
{
}

void Veterinario::setNumeroASocio(string &s)
{
    numeroAsocio = s;
}

string Veterinario::getNumeroASocio()
{
    return numeroAsocio;
}

void Veterinario::setDetallesContacto(string &s)
{
    detallesContacto = s;
}

string Veterinario::getDetallesContacto()
{
    return detallesContacto;
}