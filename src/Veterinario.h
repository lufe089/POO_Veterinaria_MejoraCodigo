#ifndef VETERINARIO_H
#define VETERINARIO_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Veterinario
{
private:
    string numeroAsocio;
    string detallesContacto;

public:
    Veterinario();
    void setNumeroASocio(string &);
    string getNumeroASocio();
    void setDetallesContacto(string &);
    string getDetallesContacto();
};

#endif