#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include "sistema.h"

using namespace std;

unsigned int opt, reinicio; 

int main ()
{
    llenado_vector();
    do
    {
    cout << "\nBuenas, este es el centro de comandos para el manejo de base de datos para la institucion.\n" << endl;
    cout << "Que queremos hacer hoy?\n(1= Buscar el promedio de un Alumno)\n(2= Revisar Aprobados y Desaprobados)\n(3= Agregar Alumno)\n(4= Editar Informacion del Alumno)\n(5= Promedio de Materias)\n(6= Top Estudiantes)\n(7= Crear Boletas)\n->";
    cin >> opt;
    switch (opt)
    {
    case 1:
        opt = 0;
        do
        {
        cout << endl;
        mostrar_persona();
        cout << "\n\nQuiere ubicar a otra persona? (Si = 0)(No = Otra cosa.)\n->";
        cin >> opt;
        } while (opt == 0);
        break;

    case 2:
        opt = 0;
        int opt1;
        do
        {
        cout << "\nCual materia revisamos el promedio?\n(1= Matematica)\n(2= Sociales)\n(3= Artes)\n(4= Fisica)\n(5= Educacion Fisica)\n(6= Biologia)\n->";
        cin >> opt1;
        cout << endl;
        switch (opt1)
        {
        case 1:
            Matematica();
            break;
        case 2:
            sociales();
            break;
        case 3:
            Artes();
            break;
        case 4:
            Fisica();
            break;
        case 5:
            EFisica();
            break;
        case 6:
            Biologia();
            break;
        default:
            cout << "\nSeleccion una de las opciones, porfavor." << endl;
            break;
        }
        cout << "\n\nQuiere ver otra materia? (Si = 0)(No = Otra cosa.):";
        cin >> opt;
        } while (opt == 0);
        break;
    case 3:
        agregar();
        structToCSV();
        break;
    case 4:
        edicion();
        structToCSV();
        break;
    case 5:
        do
        {
        opt = 0;
        opt1 = 0;
        cout << "\nCual materia revisamos el promedio?\n(1= Matematica)\n(2= Sociales)\n(3= Artes)\n(4= Fisica)\n(5= Educacion Fisica)\n(6= Biologia)\n->";
        cin >> opt1;
        cout << endl;
        switch (opt1)
        {
        case 1:
            promediomat();
            break;
        case 2:
            promediosoci();
            break;
        case 3:
            promedioarte();
            break;
        case 4:
            promediofis();
            break;
        case 5:
            promedioefis();
            break;
        case 6:
            promediobio();
            break; 
        default:
            cout << "\nSeleccion una de las opciones, porfavor." << endl;
            break;
        }
        cout << "\n\nQuiere ver otra materia? (Si = 0)(No = Otra cosa.)\n->";
        cin >> opt;
        } while (opt == 0);
        break;
    case 6:
        do
        {
        opt = 0;
        opt1 = 0;
        cout << "\nCual materia revisamos el TOP 10?\n(1= Matematica)\n(2= Sociales)\n(3= Artes)\n(4= Fisica)\n(5= Educacion Fisica)\n(6= Biologia)\n->";
        cin >> opt1;
        cout << endl;
        switch (opt1)
        {
        case 1:
            top10matsort(arr, 0, alma);
            mostrartop10mat();
            break;
        case 2:
            top10socisort(arr, 0, alma);
            mostrartop10soci();
            break;
        case 3:
            top10artsort(arr, 0, alma);
            mostrartop10art();
            break;
        case 4:
            top10fissort(arr, 0, alma);
            mostrartop10fis();
            break;
        case 5:
            top10efissort(arr, 0, alma);
            mostrartop10efis();
            break;
        case 6:
            top10biosort(arr, 0, alma);
            mostrartop10bio();
            break;
        default:
            cout << "\nSeleccion una de las opciones, porfavor." << endl;
            break;
        }
        cout << "\n\nQuiere ver otra materia? (Si = 0)(No = Otra cosa.)\n->";
        cin >> opt;
        } while (opt == 0);
        break;

    case 7:
        do
        {
        opt = 0;
        boleta();
        cout << "\n\nQuiere crear otra boleta? (Si = 0)(No = Otra cosa.)\n->";
        cin >> opt;
        } while (opt == 0);
        break;

    default:
        cout << "\nSeleccion una de las opciones, porfavor." << endl;
        break;
    }

    structToCSV();
    cout << "\nHaremos otra cosa? (Si = 0)(No = Otra cosa.):\n->";
    cin >> reinicio;
    if (reinicio == 0)
    {
        system("cls");
    }
    } while (reinicio == 0);
}