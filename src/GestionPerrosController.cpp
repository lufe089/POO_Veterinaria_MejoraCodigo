#include "GestionPerrosController.h"

using namespace std;

GestionPerrosController::GestionPerrosController()
{
    numeroVisitaActual = 1;
}

void GestionPerrosController::registrarVisita(Perro *perrito, string &nombreVeterinario, string &motivo)
{
    ConsultaVeterinario *nuevaVisita = new ConsultaVeterinario();
    nuevaVisita->setPerroObj(perrito);
    nuevaVisita->setVeterinarioObj(veterinarios.at(nombreVeterinario));
    nuevaVisita->setMotivoVisita(motivo);
    /*Fecha en segundos desde Enero 1, 1970*/
    nuevaVisita->setFecha();
    nuevaVisita->setIdConsulta(numeroVisitaActual);
    numeroVisitaActual++;
    consultasVeterinario.push_back(nuevaVisita);
}

// FIXME  Arreglar gestión, recibe un apuntador a veterinario y a perro, no solo cadenas
void GestionPerrosController::agregarPerro(string &nombreNuevo, string &tamanoNuevo, string &colorNuevo, int edadNueva, string &nombreRaza, string &codVeterinario)
{
    Perro *nuevoPerro = new Perro(nombreNuevo, tamanoNuevo, colorNuevo, edadNueva, razas.at(nombreRaza), veterinarios.at(codVeterinario));
    perros.push_back(nuevoPerro);
}

void GestionPerrosController::agregarVeterinario(string &numeroAsociado, string &detallesDeContacto)
{
    Veterinario *nuevoVeterinario = new Veterinario();
    nuevoVeterinario->setNumeroASocio(numeroAsociado);
    nuevoVeterinario->setDetallesContacto(detallesDeContacto);
    veterinarios[numeroAsociado] = nuevoVeterinario;
}

void GestionPerrosController::agregarRaza(string &nombreNuevo, string &paisNuevo)
{
    Raza *nuevaRaza = new Raza(nombreNuevo, paisNuevo);
    razas[nombreNuevo] = nuevaRaza;
}

void GestionPerrosController::mostrarPerros()
{
    cout << "Perros" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < perros.size(); i++)
    {
        cout << "Perro #" << (i + 1) << ":" << endl;
        cout << "Nombre: " << (perros[i])->getNombre() << endl;
        cout << "Tamano: " << (perros[i])->getTamano() << endl;
        cout << "Color: " << (perros[i])->getColor() << endl;
        cout << "Edad: " << (perros[i])->getEdad() << endl;
        cout << "Raza: " << ((perros[i])->getRaza())->getNombre() << endl;
        cout << "Veterinario: " << ((perros[i])->getVeterinario())->getNumeroASocio() << endl;
        cout << "******************" << endl;
    }
}

void GestionPerrosController::mostrarPropietarios()
{
    vector<Perro *> perrosEncargados;
    cout << "Propietarios" << endl;
    cout << "---------------------------" << endl;
    int i;
    for (unordered_map<string, Propietario *>::iterator it = propietarios.begin(); it != propietarios.end(); it++)
    {
        cout << "Identificacion: " << (it->second)->getNumeroIdentificacion() << endl;
        cout << "Perros a Cargo: (Nombre, Raza)" << endl;
        perrosEncargados = (it->second)->getPerrosACargo();
        for (i = 0; i < perrosEncargados.size(); i++)
        {
            cout << "   " << (perrosEncargados[i])->getNombre() << ", " << ((perrosEncargados[i])->getRaza())->getNombre() << endl;
        }
        cout << "******************" << endl;
    }
}

void GestionPerrosController::mostrarRazas()
{
    cout << "Razas" << endl;
    cout << "---------------------------" << endl;
    for (unordered_map<string, Raza *>::iterator it = razas.begin(); it != razas.end(); it++)
    {
        cout << "Nombre: " << (it->second)->getNombre() << endl;
        cout << "Pais de origen: " << (it->second)->getPaisOrigen() << endl;
        cout << "******************" << endl;
    }
}

void GestionPerrosController::mostrarVisitas()
{
    cout << "Visitas Veterinario" << endl;
    cout << "---------------------------" << endl;
    tm *fechaConsulta;
    time_t fechaS;
    char *fechaStr;
    for (int i = 0; i < consultasVeterinario.size(); i++)
    {
        fechaS = (consultasVeterinario[i])->getFecha();
        fechaConsulta = localtime(&fechaS);
        fechaStr = asctime(fechaConsulta);
        cout << "Fecha: " << fechaStr << endl;
        cout << "ID: " << (consultasVeterinario[i])->getIdConsulta() << endl;
        cout << "Perro Atendido: (Nombre, Raza)" << endl;
        cout << "   " << ((consultasVeterinario[i])->getPerroObj())->getNombre() << ", " << (((consultasVeterinario[i])->getPerroObj())->getRaza())->getNombre() << endl;
        cout << "Veterinario A Cargo: (Codigo)" << endl;
        cout << "   " << ((consultasVeterinario[i])->getVeterinarioObj())->getNumeroASocio() << endl;
        cout << "Motivo de Visita:" << endl;
        cout << (consultasVeterinario[i])->getMotivoVisita() << endl;
        cout << "******************" << endl;
    }
}

Perro *GestionPerrosController::buscarPerro(string &nombrePerro)
{
    Perro *resultado = NULL;
    int i = 0;
    bool flag = false;
    while ((i < perros.size()) && (!flag))
    {
        if ((perros[i])->getNombre() == nombrePerro)
        {
            resultado = perros[i];
            flag = true;
        }
        i++;
    }
    return resultado;
}

void GestionPerrosController::agregarPropietario(string &id)
{
    Propietario *nuevoPropietario = new Propietario();
    nuevoPropietario->setNumeroIdentificacion(id);
    propietarios[id] = nuevoPropietario;
}

Propietario *GestionPerrosController::buscarPropietario(string &idPropietario)
{
    Propietario *resultado = NULL;
    resultado = propietarios.at(idPropietario);
    return resultado;
}

GestionPerrosController::~GestionPerrosController()
{
    /*Liberar Perros*/
    int i;
    for (i = 0; i < perros.size(); i++)
    {
        delete perros[i];
    }
    perros.clear();

    /*Liberar propietarios*/
    unordered_map<string, Propietario *>::iterator it1;
    for (it1 = propietarios.begin(); it1 != propietarios.end(); it1++)
    {
        (it1->second)->~Propietario();
        delete (it1->second);
    }
    propietarios.clear();

    /*Liberar razas*/
    unordered_map<string, Raza *>::iterator it2;
    for (it2 = razas.begin(); it2 != razas.end(); it2++)
    {
        delete (it2->second);
    }
    razas.clear();

    /*Liberar veterinarios*/
    unordered_map<string, Veterinario *>::iterator it3;
    for (it3 = veterinarios.begin(); it3 != veterinarios.end(); it3++)
    {
        delete (it3->second);
    }
    veterinarios.clear();

    /*Liberar Consultas*/
    int j;
    for (j = 0; j < consultasVeterinario.size(); j++)
    {
        delete consultasVeterinario[j];
    }
    consultasVeterinario.clear();
}