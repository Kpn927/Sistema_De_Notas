//========================
//====== Libraries =======
//========================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//===========================
//====== Header Files =======
//===========================
#include "../Main.h"

using namespace std;

//editar//
void edicion()
{
    unsigned int opcion, tempo;
    bool found = false;
    string nombrenuevo, apellidonuevo, nuevogmail, nuevosexo, nuevosec, nomb, ape;
    do
    {
    
    cout << "\nIngresa el nombre del alumno. " << endl;
    cout << "\nNombre: ";
    cin >> nomb;
    cout << "Apellido: ";
    cin >> ape;

    int index = -1;
    for (int i = 0; i < alma; i++)
    {
        if ((arr[i].nombre == nomb) && (arr[i].apellido == ape))
        {
            found = true;
            index = i;
            break;
        }
    }

    if (found) {
        cout << "\nNombre: " << arr[index].nombre << " " << arr[index].apellido << endl;
        tempo = index;
    }
    else {
        cout << "No se ha encontrado, por favor, ingrese otro nombre. " << endl;
    }
    } while (found != true);
    do
    {
    cout << "\nQue vamos a modificar\n(1= Dato Personal)\n(2= Notas)\n-> ";
    cin >> opcion;

    if (opcion == 1)
    {
        opcion = 0;
        cout << "\nQue modificamos?\n(1= Nombre)\n(2= Apellido)\n(3= Gmail)\n(4= Genero)\n(5= Seccion)\n->";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\nIngrese el nuevo nombre: " << endl;
            cin >> nombrenuevo;
            arr[tempo].nombre = nombrenuevo;
            break;
        case 2:
            cout << "\nIngrese el nuevo apellido: " << endl;
            cin >> apellidonuevo;
            arr[tempo].apellido = apellidonuevo;
            break;
        case 3:
            cout << "\nIngrese nuevo gmail: " << endl;
            cin >> nuevogmail;
            arr[tempo].email = nuevogmail;
            break;
        case 4:
            cout << "\nIngrese nuevo genero: " << endl;
            cin >> nuevosexo;
            arr[tempo].sexo = nuevosexo;
            break;
        case 5:
            cout << "\nIngrese nueva seccion: " << endl;
            cin >> nuevosec;
            arr[tempo].seccion = nuevosec;
        default:
            cout << "\nERROR: Escogiste un numero invalido.\n";
            break;
        }
    }
    else if (opcion == 2)
    {
        unsigned int matematicanuevo, fisicanuevo, artesnuevo, Efisicanuevo, biologianuevo, socialesnuevo;
        int con = 0;
        opcion = 0;
        cout << "\nQue modificamos?\n(1= Matematicas)\n(2= Sociales)\n(3= Artes)\n(4= Educacion Fisica)\n(5= Biologia)\n->";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            do
            {
            cout << "\nIngrese la nueva nota de Matematica: ";
            cin >> matematicanuevo;
            if (matematicanuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else if (matematicanuevo <= 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else{
            con = 1;
            arr[tempo].matematica = matematicanuevo;
            }
            } while (con == 0);
            break;
        case 2:
            do
            {
            cout << "\nIngrese la nueva nota de Sociales: ";
            cin >> socialesnuevo;
            if (socialesnuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else if (socialesnuevo <= 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else{
            con = 1;
            arr[tempo].sociales = socialesnuevo;
            }
            } while (con == 0);
            break;
        case 3:
            do
            {
            cout << "\nIngrese la nueva nota de artes: ";
            cin >> artesnuevo;
            if (artesnuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else if (artesnuevo <= 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else{
            con = 1;
            arr[tempo].artes = artesnuevo;
            }
            } while (con == 0);
            break;
        case 4:
            do
            {
            cout << "\nIngrese la nueva nota de Educacion Fisica: ";
            cin >> Efisicanuevo;
            if (Efisicanuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else if (Efisicanuevo <= 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else{
            con = 1;
            arr[tempo].e_fisica = Efisicanuevo;
            }
            } while (con == 0);
            break;
        case 5: 
            do
            {
            cout << "\nIngrese la nueva nota de Biologia: ";
            cin >> biologianuevo;
            if (biologianuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else if (biologianuevo <= 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else{
            con = 1;
            arr[tempo].biologia = biologianuevo;
            }
            } while (con == 0);
            break;
        default:
            cout << "ERROR: Escogiste un numero invalido.";
            break;
        }
    }
    cout << "\nQuieres modificar algo mas? (Si = 0) (No = Otro numero.)\n->";
    cin >> opcion;
    cout << "\n";
} while (opcion == 0);
}

//agregar//
void agregar(){
    int opcion = 0, con = 0;
    do
    {
    string newNombre, newApellido, newGenero, newEmail;
    unsigned int newMat, newBio, newFis, newArt, newEfis, newSoci;
    cout << "\n</Agregar Alumno numero" << alma+1 << "\\>";

    cout << "\nIngrese su nombre: ";
    cin >> newNombre;
    
    cout << "Ingrese su apellido: ";
    cin >> newApellido;

    cout << "Ingrese su genero: ";
    cin >> newGenero;

    cout << "Ingrese su Email: ";
    cin >> newEmail;

    do
    {
        con = 0;
        cout << "Ingrese su nota de Matematica: ";
        cin >> newMat;
    if (newMat > 20)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else if (newMat <= 0)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else
    {
    con = 1;
    }
    } while (con == 0);
    
    do
    {
        con = 0;
        cout << "Ingrese su nota de Biologia: ";
        cin >> newBio;
    if (newBio > 20)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else if (newBio <= 0)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else
    {
    con = 1;
    }
    } while (con == 0);

    do
    {
        con = 0;
        cout << "Ingrese su nota de Artes: ";
        cin >> newArt;
    if (newArt > 20)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else if (newArt <= 0)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else
    {
    con = 1;
    }
    } while (con == 0);

    do
    {
        con = 0;
        cout << "Ingrese su nota de Educacion Fisica: ";
        cin >> newEfis;
    if (newEfis > 20)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else if (newEfis <= 0)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else
    {
    con = 1;
    }
    } while (con == 0);

    do
    {
        con = 0;
        cout << "Ingrese su nota de Sociales: ";
        cin >> newSoci;
    if (newSoci > 20)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else if (newSoci <= 0)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else
    {
    con = 1;
    }
    } while (con == 0);

    arr[alma].nombre = newNombre;
    arr[alma].apellido = newApellido;
    arr[alma].email = newEmail;
    arr[alma].sexo = newGenero;
    arr[alma].matematica = newMat;
    arr[alma].biologia = newBio;
    arr[alma].e_fisica = newEfis;
    arr[alma].sociales = newSoci;
    arr[alma].artes = newArt;
    cout << "\nQuieres agregar a otro alumno? (Si = 0) (No = Otro numero.)\n->";
    cin >> opcion;
    alma++;
    }while (opcion == 0);
}
void eliminar()
{
    unsigned int id, opt, opcion;
    do
    {
    
    cout << "\nPor favor Ingresa el ID del estudiante a eliminar. \n->";
    cin >> id;

    for (int i = 0; i < alma; i++)
    {
        if (arr[i].id == id)
        {
            cout << "El estudiante que quieres eliminar es: " << arr[i].nombre << " " << arr[i].apellido << endl;
        }
        else if ((id > alma) || (id < 0))
        {
            cout << "El estudiante no existe. " << endl;
            id = 0;
        }
    }

    if (id != 0)
    {
        cout << "Quieres eliminar este alumno? (Si = 0) (No = Otro numero.)\n-> ";
        cin >> opt;

        if (opt == 0)
        {
            arr.erase(arr.begin() + (id - 1));

            for (int i = 0; i < alma; i++)
            {
                arr[i].id-=1;
            }
            alma--;
        }

    }
    cout << "\nQuieres eliminar a otro alumno? (Si = 0) (No = Otro numero.)\n->";
    cin >> opcion;
    } while (opcion == 0);
}

void agregarprofesor(){
    int opcion = 0, con = 0;
    do
    {
    string newNombre, newApellido, newGenero, newEmail, newSec;

    unsigned int newIDMAT;
    
    cout << "\n</Agregar profesor numero " << alma2+1 << "\\>";

    cout << "\nIngrese su nombre: ";
    cin >> newNombre;
    
    cout << "Ingrese su apellido: ";
    cin >> newApellido;

    cout << "Ingrese su genero: ";
    cin >> newGenero;

    cout << "Ingrese su Email: ";
    cin >> newEmail;

    cout << "Ingrese su seccion (UNA SOLA LETRA): ";
    cin >> newSec;

    cout << "Ingrese su ID de materia: ";
    cin >> newIDMAT;

    arr2[alma2].idp = alma2+1;
    arr2[alma2].nombrep = newNombre;
    arr2[alma2].apellidop = newApellido;
    arr2[alma2].emailp = newEmail;
    arr2[alma2].generop = newGenero;
    arr2[alma2].seccionp = newSec;
    arr2[alma2].id_materia = newIDMAT;
    cout << "\nQuieres agregar a otro profesor? (Si = 0) (No = Otro numero.)\n->";
    cin >> opcion;
    alma2++;
    }while (opcion == 0);
}

void edicionprofes()
{
    unsigned int opcion, tempo, nuevoidmat;
    string nombrenuevo, apellidonuevo, nuevogmail, nuevosexo, nuevosecc;

    cout << "Ingrese el ID del profesor\n->";
    cin >> tempo;
    tempo--;

    cout << "Vamos a modificar al profesor " << arr2[tempo].nombrep << " " << arr2[tempo].apellidop << endl;
    do
    {
    cout << "\nQue vamos a modificar\n(1= Dato Personal)\n(2= Notas)\n-> ";
    cin >> opcion;

    if (opcion == 1)
    {
        opcion = 0;
        cout << "\nQue modificamos?\n(1= Nombre)\n(2= Apellido)\n(3= Gmail)\n(4= Genero)\n(5= Seccion) (6= ID_Materia)\n->";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\nIngrese el nuevo nombre: " << endl;
            cin >> nombrenuevo;
            arr2[tempo].nombrep = nombrenuevo;
            break;
        case 2:
            cout << "\nIngrese el nuevo apellido: " << endl;
            cin >> apellidonuevo;
            arr2[tempo].apellidop = apellidonuevo;
            break;
        case 3:
            cout << "\nIngrese nuevo gmail: " << endl;
            cin >> nuevogmail;
            arr2[tempo].emailp = nuevogmail;
            break;
        case 4:
            cout << "\nIngrese nuevo genero: " << endl;
            cin >> nuevosexo;
            arr2[tempo].generop = nuevosexo;
            break;
        case 5:
            cout << "\nIngrese nueva seccion: " << endl;
            cin >> nuevosecc;
            arr2[tempo].seccionp = nuevosecc;
            break;
        case 6:
            cout << "\nIngrese nueva ID de materia: " << endl;
            cin >> nuevoidmat;
            arr2[tempo].id_materia = nuevoidmat;
        default:
            cout << "\nERROR: Escogiste un numero invalido.\n";
            break;
        }
    }
    cout << "\nQuieres modificar algo mas? (Si = 0) (No = Otro numero.)\n->";
    cin >> opcion;
    cout << "\n";
} while (opcion == 0);
}

void eliminarprofe()
{
    unsigned int id, opt, opcion;
    do
    {
    
    cout << "\nPor favor Ingresa el ID del profesor a eliminar. \n->";
    cin >> id;

    for (int i = 0; i < alma2; i++)
    {
        if (arr2[i].idp == id)
        {
            cout << "El estudiante que quieres eliminar es: " << arr2[i].nombrep << " " << arr2[i].apellidop << endl;
        }
        else if ((id > alma2) || (id < 0))
        {
            cout << "El estudiante no existe. " << endl;
            id = 0;
        }
    }

    if (id != 0)
    {
        cout << "Quieres eliminar este profesor? (Si= 0) (No= Otro numero.)\n-> ";
        cin >> opt;

        if (opt == 0)
        {
            arr2.erase(arr2.begin() + (id - 1));

            for (int i = 0; i < alma2; i++)
            {
                arr2[i].idp-=1;
            }
            alma2--;
        }

    }
    cout << "\nQuieres eliminar a otro profesor? (Si = 0) (No = Otro numero.)\n->";
    cin >> opcion;
    } while (opcion == 0);
}