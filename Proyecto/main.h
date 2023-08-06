#pragma once

//Librerías a usar.

#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Notas
{
    unsigned int id;
    string nombre;
    string apellido;
    string email;
    string sexo;
    string seccion;
    unsigned int matematica;
    unsigned int sociales;
    unsigned int biologia;
    unsigned int e_fisica;
    unsigned int artes;
    float prom;
} Users;

struct profesores
{
    unsigned int idp;
    string nombrep; 
    string apellidop;
    string generop;
    string emailp;
    string seccionp;
    unsigned int id_materia;
    //Mate = 1001
    //Sociales = 1002
    //Biologia = 1003
    //Educacion Fisica = 1004
    //Arte = 1005
}Profes;

vector <Notas> arr;
vector <profesores> arr2; 

unsigned int counterA, counterB, counterC, alma, alma2;

ifstream DATA1, DATA2;
ofstream newDATA, newDATA2;

string line, line2;

void llenado_vector1() 
{
    DATA1.open("ARCHIVOS_CSV/DATAE.csv", ios::in);
    getline(DATA1, line); // Makes it so the header line is ignored.

    while ((getline(DATA1, line)) && (!line.empty()))
    {
        stringstream stream_check(line); // Helps us deal with the int and float varaibles of the struct.

        string temp;

        getline(stream_check, temp, ',');
        Users.id = stoi(temp);

        getline(stream_check, Users.nombre, ',');

        getline(stream_check, Users.apellido, ',');

        getline(stream_check, Users.sexo, ',');

        getline(stream_check, Users.email, ',');

        getline(stream_check, Users.seccion, ',');

        getline(stream_check, temp, ',');
        Users.matematica = stoi(temp);

        getline(stream_check, temp, ',');
        Users.sociales = stoi(temp);

        getline(stream_check, temp, ',');
        Users.biologia = stoi(temp);

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
    DATA1.close();
}

void llenado_vector2() 
{
    DATA2.open("ARCHIVOS_CSV/DATAP.csv", ios::in);
    getline(DATA2, line); // Makes it so the header line is ignored.

    while ((getline(DATA2, line2)) && (!line2.empty()))
    {
        stringstream stream_check(line2); // Helps us deal with the int and float varaibles of the struct.

        string temp2;

        getline(stream_check, temp2, ',');
        Profes.idp = stoi(temp2);

        getline(stream_check, Profes.nombrep, ',');

        getline(stream_check, Profes.apellidop, ',');

        getline(stream_check, Profes.generop, ',');

        getline(stream_check, Profes.emailp, ',');

        getline(stream_check, Profes.seccionp, ',');

        getline(stream_check, temp2, ',');
        Profes.id_materia = stoi(temp2);

        if (!stream_check) // Error Check in case something goes wrong with reading the CSV's lines.
        {
            cout << "ERROR: El archivo ha fallado al ser leído. " << endl;
            break;
        }

        arr2.push_back(Profes); // Pushes the CSV's data into the Vector.
        alma2++; // Needed to see the total of products we have.
    }
    DATA2.close();
}

void structToCSV() 
{
    newDATA.open("ARCHIVOS_CSV/DATAE.csv");

    newDATA << "id,nombre,apellido,email,genero,seccion,matematicas,sociales,biologia,educacion_fisica,artes" << endl;

    for (int i = 1; i <= (alma-1); i++)
    {
        newDATA << arr[i].id << ",";
        newDATA << arr[i].nombre << ",";
        newDATA << arr[i].apellido << ",";
        newDATA << arr[i].sexo << ",";
        newDATA << arr[i].email << ",";
        newDATA << arr[i].seccion << ",";
        newDATA << arr[i].matematica << ",";
        newDATA << arr[i].sociales << ",";
        newDATA << arr[i].biologia << ",";
        newDATA << arr[i].e_fisica << ",";
        newDATA << arr[i].artes << endl;
    }

    newDATA.close();
}
// Code Reutilizado pero modificado para mi conveniencia de proyecto anterior junto a GABO1423 para facilitar las cosas. //

void structToCSV2() 
{
    newDATA2.open("ARCHIVOS_CSV/DATAP.csv");

    newDATA2 << "id,nombre,apellido,genero,email,seccion,id_materia" << endl;

    for (int i = 0; i <= (alma2-1); i++)
    {
        newDATA2 << arr2[i].idp << ",";
        newDATA2 << arr2[i].nombrep << ",";
        newDATA2 << arr2[i].apellidop << ",";
        newDATA2 << arr2[i].generop << ",";
        newDATA2 << arr2[i].emailp << ",";
        newDATA2 << arr2[i].seccionp << ",";
        newDATA2 << arr2[i].id_materia << endl;
    }

    newDATA2.close();
}