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

ifstream DATA;
ofstream newDATA;

string line;

unsigned int alma;



