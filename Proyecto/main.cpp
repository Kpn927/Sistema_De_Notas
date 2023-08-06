#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include "main.h"
#include "FUNCIONES_IMPT\mostrar.h"
#include "FUNCIONES_SEARCH_SORT\sort.h"
#include "FUNCIONES_IMPT\modificaciones.h"


using namespace std;

int opt, opt1, reinicio;

int main ()
{
    cout << "\nBuenas, este es el centro de comandos para el manejo de base de datos para la institucion.\n" << endl;
    llenado_vector1();
    llenado_vector2();
    do
    {
    cout << "Que datos vamos a manipular? (0= Alumnos)(1= Profesores)\n->";
    cin >> opt1;
    
    switch (opt1)
    {
    case 0:
        cout << "Escogiste Sección de Alumnos. \n(1= Buscar un alumno y su promedio)\n(2= Revisar Aprobados y Desaprobados)\n(3= Agregar Alumno)" << 
        "\n(4= Eliminar Alumno)\n(5= Editar Informacion del Alumno)\n(6= Promedio de Materias)\n(7= Top Estudiantes)\n(8= Crear Boletas)\n(9= Top 10 Estudiantes Por Seccion)\n->";
        cin >> opt;
        switch (opt)
        {
        case 1:
            opt = 0;
            do
            {
            cout << endl;
            mostrar_persona();
            cout << "\n\nQuiere ubicar a otra persona? (Si = 0)(No = Otro numero.)\n->";
            cin >> opt;
            } while (opt == 0);
            break;

        case 2:
            opt = 0;
            int opt1;
            do
            {
            cout << "\nCual materia revisamos el promedio?\n(1= Matematica)\n(2= Sociales)\n(3= Artes)\n(4= Educacion Fisica)\n(5= Biologia)\n->";
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
                EFisica();
                break;
            case 5:
                Biologia();
                break;
            default:
                cout << "\nSeleccion una de las opciones, porfavor." << endl;
                break;
            }
            cout << "\n\nQuiere ver otra materia? (Si = 0)(No = Otro numero.):";
            cin >> opt;
            } while (opt == 0);
            break;
        case 3:
            agregar();
            structToCSV();
            structToCSV2();
            break;
        case 4:
            eliminar();
            structToCSV();
            structToCSV2();
            break;
        case 5:
            edicion();
            structToCSV();
            structToCSV2();
            break;
        case 6:
            do
            {
            opt = 0;
            opt1 = 0;
            cout << "\nCual materia revisamos el promedio?\n(1= Matematica)\n(2= Sociales)\n(3= Artes)\n(4= Educacion Fisica)\n(5= Biologia)\n->";
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
                promedioefis();
                break;
            case 6:
                promediobio();
                break; 
            default:
                cout << "\nSeleccion una de las opciones, porfavor." << endl;
                break;
            }
            cout << "\n\nQuiere ver otra materia? (Si = 0)(No = Otro numero.)\n->";
            cin >> opt;
            } while (opt == 0);
            break;
        case 7:
            do
            {
            opt = 0;
            opt1 = 0;
            cout << "\nCual materia revisamos el TOP 10?\n(1= Matematica)\n(2= Sociales)\n(3= Artes)\n(4= Educacion Fisica)\n(5= Biologia)\n->";
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
                top10efissort(arr, 0, alma);
                mostrartop10efis();
                break;
            case 5:
                top10biosort(arr, 0, alma);
                mostrartop10bio();
                break;
            default:
                cout << "\nSeleccion una de las opciones, porfavor." << endl;
                break;
            }
            cout << "\n\nQuiere ver otra materia? (Si = 0)(No = Otro numero.)\n->";
            cin >> opt;
            } while (opt == 0);
            break;

        case 8:
            do
            {
            opt = 0;
            boleta();
            cout << "\n\nQuiere crear otra boleta? (Si = 0)(No = Otro numero.)\n->";
            cin >> opt;
            } while (opt == 0);
            break;

        case 9:
            int option10;
            cout << "Ingrese la seccion que se quiere visualisar el top 10 \n(1= A)\n(2= B)\n(3= C)\n(4= D)\n->";
            cin >> option10;
            switch (option10)
            {
            case 1:
                promllenado();
                promsortx(arr, 0, alma);
                sortsecx(arr, 0, alma);
                seccionA();
                break;

            case 2:
                promllenado();
                promsortx(arr, 0, alma);
                sortsecx(arr, 0, alma);
                seccionB();
                break;

            case 3:
                promllenado();
                promsortx(arr, 0, alma);
                sortsecx(arr, 0, alma);
                seccionC();
                break;

            case 4:
                promllenado();
                promsortx(arr, 0, alma);
                sortsecx(arr, 0, alma);
                seccionD();
                break;
            
            default:
                break;
            }
            break;
        case 10:
            rendimientoprofe();
            break;
        case 11:
            agregarprofesor();
            break;
        default:
            cout << "\nSeleccion una de las opciones, porfavor." << endl;
            break;
        }
        break;

    case 1:
        unsigned opt2; 
        cout << endl <<"Has elegido seccion Profesores \n(1= Rendimiento de profesor)\n(2= Agregar un profesor)\n(3= Editar Profesor)\n->";
        cin >> opt2;
            switch (opt2)
            {
            case 1:
                rendimientoprofe();
                break;

            case 2:
                agregarprofesor();
                break;
            
            case 3:
                edicionprofes();
                break;
            
            case 4: 
                eliminarprofe();
                break;
                
            default:
                cout << "\nSeleccion una de las opciones, porfavor." << endl;
                break;
            }
        break;
    }

    cout << "\nHaremos otra cosa? (Si = 0)(No = Otro numero.):\n->";
    cin >> reinicio;
    if (reinicio == 0)
    {
        system("cls");
    }
    } while (reinicio == 0);

    structToCSV();
    structToCSV2();

}