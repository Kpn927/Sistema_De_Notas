#pragma once

//Librerías a usar.

#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Notas
{
    string nombre;
    string apellido;
    string email;
    string sexo;
    unsigned int matematica;
    unsigned int sociales;
    unsigned int biologia;
    unsigned int fisica;
    unsigned int e_fisica;
    unsigned int artes;
} Users;

vector <Notas> arr;

ifstream DATA1;
ofstream newDATA;

string line;

unsigned int alma;

// Funciones //
unsigned int counterA, counterB;

void llenado_vector() 
{
    alma = 0;
    DATA1.open("DATA1.csv", ios::in);

    getline(DATA1, line); // Makes it so the header line is ignored.

    while ((getline(DATA1, line)) && (!line.empty()))
    {
        stringstream stream_check(line); // Helps us deal with the int and float varaibles of the struct.

        string temp;

        getline(stream_check, Users.nombre, ',');

        getline(stream_check, Users.apellido, ',');

        getline(stream_check, Users.email, ',');

        getline(stream_check, Users.sexo, ',');

        getline(stream_check, temp, ',');
        Users.matematica = stoi(temp);

        getline(stream_check, temp, ',');
        Users.sociales = stoi(temp);

        getline(stream_check, temp, ',');
        Users.biologia = stoi(temp);

        getline(stream_check, temp, ',');
        Users.fisica = stoi(temp);

        getline(stream_check, temp, ',');
        Users.e_fisica = stoi(temp);

        getline(stream_check, temp, ',');
        Users.artes = stoi(temp);

        if (!stream_check) // Error Check in case something goes wrong with reading the CSV's lines.
        {
            cout << "ERROR: El archivo ha fallado al ser leído. " << endl;
            break;
        }

        arr.push_back(Users); // Pushes the CSV's data into the Vector.
        alma++; // Needed to see the total of products we have.
    }
}
// Código reusado de mi anterior proyecto con GABO1423. // 

void clear(){

    system("CLS");
    cout << endl;
}

void mostrar_persona(){
    string nomb;
    string ape;
    cout << "Ingresa el nombre del alumno. " << endl;
    cout << "\nNombre: ";
    cin >> nomb;
    cout << "Apellido: ";
    cin >> ape;

    bool found = false;
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
        float prom;
        int sumatoria;
        sumatoria = (arr[index].sociales+arr[index].matematica+arr[index].artes+arr[index].biologia+arr[index].fisica+arr[index].e_fisica);
        prom = (float)sumatoria/6;
        cout << "\nNombre: " << arr[index].nombre << " " << arr[index].apellido << endl;
        cout << "Su promedio es: " << prom; 
    }
    else {
        cout << "No se ha encontrado, por favor, ingrese otro nombre. " << endl;
    }
}

//////////////////////////////////////////
///// Materias aprovadas y reprobadas/////
//////////////////////////////////////////

void sociales()
{
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].sociales >= 10)
        {
            counterA++;
        }
        if (arr[i].sociales < 10)
        {
            counterB++;
        }
    }
    cout << "Estudiantes Aprobados y Reprobados en Sociales: " << endl;
    cout << "\nPasaron: " << counterA << endl;
    cout << "Reprobaron: " << counterB << endl;
    counterA = 0; counterB = 0;
    
}

void Matematica()
{
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].matematica >= 10)
        {
            counterA++;
        }
        if (arr[i].matematica < 10)
        {
            counterB++;
        }
    }
    cout << "Estudiantes Aprobados y Reprobados en Matematica: " << endl;
    cout << "\nPasaron: " << counterA << endl;
    cout << "Reprobaron: " << counterB << endl;
    counterA = 0; counterB = 0;
}

void Fisica()
{
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].fisica >= 10)
        {
            counterA++;
        }
        if (arr[i].fisica < 10)
        {
            counterB++;
        }
    }
    cout << "Estudiantes Aprobados y Reprobados en Fisica: " << endl;
    cout << "\nPasaron: " << counterA << endl;
    cout << "Reprobaron: " << counterB << endl;
    counterA = 0; counterB = 0;
}

void EFisica()
{
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].e_fisica >= 10)
        {
            counterA++;
        }
        if (arr[i].e_fisica < 10)
        {
            counterB++;
        }
    }
    cout << "Estudiantes Aprobados y Reprobados en Educación Fisica: " << endl;
    cout << "\nPasaron: " << counterA << endl;
    cout << "Reprobaron: " << counterB << endl;
    counterA = 0; counterB = 0;
}
void Biologia()
{
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].biologia >= 10)
        {
            counterA++;
        }
        if (arr[i].biologia < 10)
        {
            counterB++;
        }
    }
    cout << "Estudiantes Aprobados y Reprobados en Biologia: " << endl;
    cout << "\nPasaron: " << counterA << endl;
    cout << "Reprobaron: " << counterB << endl;
    counterA = 0; counterB = 0;
}
void Artes()
{
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].artes >= 10)
        {
            counterA++;
        }
        if (arr[i].artes < 10)
        {
            counterB++;
        }
    }
    cout << "Estudiantes Aprobados y Reprobados en Artes: " << endl;
    cout << "\nPasaron: " << counterA << endl;
    cout << "Reprobaron: " << counterB << endl;
    counterA = 0; counterB = 0;
}

void edicion()
{
    bool found = false;
    string nombrenuevo, apellidonuevo, nuevogmail, nuevosexo, nomb, ape;
    unsigned int matematicanuevo, fisicanuevo, artesnuevo, Efisicanuevo, biologianuevo, socialesnuevo, opcion, tempo;
    do
    {
    
    cout << "Ingresa el nombre del alumno. " << endl;
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

    cout << "Que vamos a modificar\n(1= Dato Personal)\n(2= Notas)\n-> ";
    cin >> opcion;

    if (opcion == 1)
    {
        opcion = 0;
        cout << "\nQue modificamos?\n(1= Nombre)\n(2= Apellido)\n(3= Gmail)\n(4= Genero)\n->";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el nuevo nombre: " << endl;
            cin >> nombrenuevo;
            arr[tempo].nombre = nombrenuevo;
            break;
        
        default:
            break;
        }
    }
    else if (opcion == 2)
    {
        /* code */
    }
}

