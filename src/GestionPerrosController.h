/*Librerias*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <cstring>
#include "ConsultaVeterinario.h"
#include "Propietario.h"

using namespace std;

class GestionPerrosController
{
private:
    vector<Perro *> perros;
    unordered_map<string, Propietario *> propietarios;
    unordered_map<string, Raza *> razas;
    unordered_map<string, Veterinario *> veterinarios;
    vector<ConsultaVeterinario *> consultasVeterinario;
    long int numeroVisitaActual;

public:
    GestionPerrosController();
    ~GestionPerrosController();
    void registrarVisita(Perro *, string &, string &);
    void agregarPerro(string &, string &, string &, int, string &, string &);
    void agregarVeterinario(string &, string &);
    void agregarRaza(string &, string &);
    void mostrarPerros();
    void mostrarPropietarios();
    void mostrarRazas();
    void mostrarVisitas();
    void agregarPropietario(string &);
    Propietario *buscarPropietario(string &);
    Perro *buscarPerro(string &);
};