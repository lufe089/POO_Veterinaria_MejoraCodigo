#include "GestionPerrosController.h"

using namespace std;

int main()
{
    GestionPerrosController controlador;
    bool closeRequest = false;
    int screen = 1;
    string userText;
    string userText2;
    string userText3;
    string userText4;
    string userText5;
    int userOption;
    Perro *perroAux;
    Raza *razaAux;
    Veterinario *vetAux;
    Propietario *propAux;
    bool endRegistro;
    cout << "   Bienvenido al Sistema de Gestion de la Veterinaria" << endl;
    cout << "---------------------------------------------------------" << endl;

    // FIXME paasar las diferentes opciones del menu a métodos separados del main
    //  para facilitar la lectura del código
    while (!closeRequest)
    {
        if (screen == 1)
        {
            cout << "Opciones" << endl;
            cout << "-----------" << endl;
            cout << "1.) Registrar Visita" << endl;
            cout << "2.) Agregar nuevo perro" << endl;
            cout << "3.) Agregar nuevo veterinario" << endl;
            cout << "4.) Agregar nueva raza" << endl;
            cout << "5.) Agregar nuevo propietario" << endl;
            cout << "6.) Mostrar perros" << endl;
            cout << "7.) Mostrar razas" << endl;
            cout << "8.) Mostrar propietarios" << endl;
            cout << "9.) Mostrar Visitas" << endl;
            cout << "10.) Buscar perro por nombre" << endl;
            cout << "0.) Terminar programa" << endl;
            cout << endl;
            cout << "Seleccione su opcion" << endl;
            cin >> userOption; // FIXME homogenizar userOption y screen, son dos variables que pueden servir paara lo mismo
            cout << endl;

            if (userOption == 1)
            {
                screen = 2;
            }
            else if (userOption == 2)
            {
                screen = 3;
            }
            else if (userOption == 3)
            {
                screen = 4;
            }
            else if (userOption == 4)
            {
                screen = 5;
            }
            else if (userOption == 5)
            {
                screen = 6;
            }
            else if (userOption == 6)
            {
                controlador.mostrarPerros();
                cout << "Escriba OK y luego Enter para continuar" << endl;
                cin >> userText;
                cout << endl;
            }
            else if (userOption == 7)
            {
                controlador.mostrarRazas();
                cout << "Escriba OK y luego Enter para continuar" << endl;
                cin >> userText;
                cout << endl;
            }
            else if (userOption == 8)
            {
                controlador.mostrarPropietarios();
                cout << "Escriba OK y luego Enter para continuar" << endl;
                cin >> userText;
                cout << endl;
            }
            else if (userOption == 9)
            {
                controlador.mostrarVisitas();
                cout << "Escriba OK y luego Enter para continuar" << endl;
                cin >> userText;
                cout << endl;
            }
            else if (userOption == 10)
            {
                screen = 7;
            }
            else if (userOption == 0)
            {
                closeRequest = true;
            }
        }

        // Registrar Visita//
        else if (screen == 2)
        {
            cout << "Ingrese el nombre del perro atendido:" << endl;
            cin >> userText;
            cout << endl;
            perroAux = controlador.buscarPerro(userText);
            if (perroAux == NULL)
            {
                cout << "No existe ningun perro llamado '" << userText << "'" << endl;
                cout << "Escriba OK y luego Enter para continuar" << endl;
                cin >> userText;
                cout << endl;

                screen = 1;
            }
            else
            {
                cout << "Ingrese el codigo del veterinario:" << endl;
                cin >> userText;
                cout << endl;

                cout << "Ingrese el motivo de la visita:" << endl;
                cin >> userText2;
                cout << endl;

                controlador.registrarVisita(perroAux, userText, userText2);

                cout << "Visita registrada exitosamente!" << endl;
                cout << "Escriba OK y luego Enter para continuar" << endl;
                cin >> userText;
                cout << endl;

                screen = 1;
            }
        }

        /*Agregar perro*/
        else if (screen == 3)
        {
            cout << "Ingrese el nombre del perro:" << endl;
            cin >> userText;
            cout << endl;

            cout << "Ingrese el tamano del perro:" << endl;
            cin >> userText2;
            cout << endl;

            cout << "Ingrese el color del perro:" << endl;
            cin >> userText3;
            cout << endl;

            cout << "Ingrese la edad del perro:" << endl;
            cin >> userOption;
            cout << endl;

            // FIXME, llamar a otro metodo que muestre las razas y luego el usuario elija, si no existe ninguna de opción de agregar
            cout << "Ingrese la raza del perro (Por nombre):" << endl;
            cin >> userText4;
            cout << endl;

            // FIXME, llamar a otro metodo que muestre los veterinarios y luego el usuario elija, si no existe ninguno de opción de agregar
            cout << "Ingrese el codigo del veterinario a cargo:" << endl;
            cin >> userText5;
            cout << endl;

            // FIXME arreglar constructor para que reciba un apuntador a un apuntador a un objeto raza y un objeto veterinario
            controlador.agregarPerro(userText, userText2, userText3, userOption, userText4, userText5);

            cout << "Perro registrado exitosamente!" << endl;
            cout << "Escriba OK y luego Enter para continuar" << endl;
            cin >> userText;
            cout << endl;

            screen = 1;
        }

        /*Agregar veterinario*/
        else if (screen == 4)
        {
            cout << "Ingrese el codigo del veterinario nuevo:" << endl;
            cin >> userText;
            cout << endl;

            cout << "Ingrese los detalles de contacto:" << endl;
            cin >> userText2;
            cout << endl;

            // FIXME primero valido, si veterinario no existe entonces se agrega veterinario
            //  en todo caso muestra error
            controlador.agregarVeterinario(userText, userText2);

            cout << "Veterinario registrado exitosamente!" << endl;
            cout << "Escriba OK y luego Enter para continuar" << endl;
            cin >> userText;
            cout << endl;

            screen = 1;
        }

        /*Agregar raza*/
        else if (screen == 5)
        {
            cout << "Ingrese el nombre de la raza:" << endl;
            cin >> userText;
            cout << endl;

            cout << "Ingrese el pais de origen de dicha raza:" << endl;
            cin >> userText2;
            cout << endl;

            // FIXME primero valido, si raza no existe entonces se agrega raza
            controlador.agregarRaza(userText, userText2);

            cout << "Raza registrada exitosamente!" << endl;
            cout << "Escriba OK y luego Enter para continuar" << endl;
            cin >> userText;
            cout << endl;

            screen = 1;
        }

        /*Agregar Propietario*/
        else if (screen == 6)
        {
            cout << "Ingrese el identificador del propietario:" << endl;
            cin >> userText;
            cout << endl;

            controlador.mostrarPerros();
            endRegistro = false;

            // FIXME: Mejorar el flujo-> primero busco, si no existe creo.
            controlador.agregarPropietario(userText);
            propAux = controlador.buscarPropietario(userText);
            while (!endRegistro) // FIXME userText2!= -1 así quita la variable endRegistro
            {
                cout << "Ingrese el nombre de sus perros uno por uno (Ingrese -1 para terminar):" << endl;
                cin >> userText2;
                cout << endl;
                if (userText2 == "-1")
                {
                    endRegistro = true;
                }
                else
                {
                    // FIXME separar, primero busco, si no existe muestro erro, si existo agrego
                    // y luego muestro mensaje para informar a usuario
                    propAux->agregarPerro(controlador.buscarPerro(userText2));
                }
            }

            cout << "Propietario registrado exitosamente!" << endl;
            cout << "Escriba OK y luego Enter para continuar" << endl;
            cin >> userText;
            cout << endl;

            screen = 1;
        }

        /*Buscar Perro por el nombre*/
        else if (screen == 7)
        {
            cout << "Ingrese el nombre del perro a buscar:" << endl;
            cin >> userText;
            cout << endl;

            perroAux = controlador.buscarPerro(userText);
            // FIXME potencial null pointer excepcion, agregar validacion en el caso null

            // TODO Hacer un método mostrar en la clase perro, que se encargue de escribir
            //  en consola los datos del perro, llamar a este metodo aqui en el main
            cout << "Nombre: " << (perroAux)->getNombre() << endl;
            cout << "Tamano: " << (perroAux)->getTamano() << endl;
            cout << "Color: " << (perroAux)->getColor() << endl;
            cout << "Edad: " << (perroAux)->getEdad() << endl;
            cout << "Raza: " << ((perroAux)->getRaza())->getNombre() << endl;
            cout << "Veterinario: " << ((perroAux)->getVeterinario())->getNumeroASocio() << endl;
            cout << "******************" << endl;

            cout << "Escriba OK y luego Enter para continuar" << endl;
            cin >> userText;
            cout << endl;

            screen = 1;
        }
    }
    return 0;
}