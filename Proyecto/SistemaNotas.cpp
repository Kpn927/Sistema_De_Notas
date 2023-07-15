#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

#include "sistema.h"

void llenado_vector() 
{
    alma = 0;
    DATA.open("DATA.csv", ios::in);

    getline(DATA, line); // Makes it so the header line is ignored.

    while ((getline(DATA, line)) && (!line.empty()))
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