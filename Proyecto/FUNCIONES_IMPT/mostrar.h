#include "../main.h"
#include <iostream>
#include <vector> 

using namespace std;

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
        cout << "\nNombre: " << arr[index].nombre << " " << arr[index].apellido;
        cout << "\nEmail: " << arr[index].email;
        cout << "\nSexo: " << arr[index].sexo;
        cout << "\nSeccion: " << arr[index].seccion;
        cout << "\nMatematica: " << arr[index].matematica;
        cout << "\nArtes: " << arr[index].artes;
        cout << "\nBiologia: " << arr[index].biologia;
        cout << "\nEducacion Fisica: " << arr[index].e_fisica;
        cout << "\nSociales: " << arr[index].sociales << endl << endl;
        sumatoria = (arr[index].sociales+arr[index].matematica+arr[index].artes+arr[index].biologia+arr[index].e_fisica);
        prom = (float)sumatoria/5;
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

// PROMEDIO MATERIAS // 

void promediomat()
{
    unsigned int temp;
    float result;
    for (int i = 0; i < alma; i++)
    {
        temp+= arr[i].matematica;
    }
    result = (float)temp / (float)alma;

    cout << "Promedio en matematica es: " << result;
}
void promediosoci()
{
    unsigned int temp;
    float result;
    for (int i = 0; i < alma; i++)
    {
        temp+= arr[i].sociales;
    }
    result = (float)temp / (float)alma;

    cout << "Promedio en sociales es: " << result;
}

void promedioefis()
{
    unsigned int temp;
    float result;
    for (int i = 0; i < alma; i++)
    {
        temp+= arr[i].e_fisica;
    }
    result = (float)temp / (float)alma;

    cout << "Promedio en Educacion fisica es: " << result;
}
void promedioarte()
{
    unsigned int temp;
    float result;
    for (int i = 0; i < alma; i++)
    {
        temp+= arr[i].artes;
    }
    result = (float)temp / (float)alma;

    cout << "Promedio en Artes es: " << result;
}
void promediobio()
{
    unsigned int temp;
    float result;
    for (int i = 0; i < alma; i++)
    {
        temp+= arr[i].biologia;
    }
    result = (float)temp / (float)alma;

    cout << "Promedio en biologia es: " << result;
}
/////////////////////////////////////
///////////// TOP 10 ////////////////
/////////////////////////////////////
// Matematica //

void mostrartop10mat(){
    counterC++;
    cout << "</TOP 10 en Matematica\\>\n";
    for (int i = alma; alma-10 < i; i--)
    {
        cout << "\nTOP: " << counterC++;
        cout << "\nNombre: "<< arr[i].nombre << endl;
        cout << "Apellido: " << arr[i].apellido << endl;
        cout << "Email: " <<arr[i].email << endl;
        cout << "Genero: " <<arr[i].sexo << endl;
        cout << "Nota: " << arr[i].matematica << endl;
    }
    counterC = 0;
}

// Educacion fisica //

void mostrartop10efis(){
    counterC++;
    cout << "</TOP 10 en Educacion Fisica\\>\n";
    for (int i = alma; alma-10 < i; i--)
    {
        cout << "\nTOP: " << counterC++;
        cout << "\nNombre: "<< arr[i].nombre << endl;
        cout << "Apellido: " << arr[i].apellido << endl;
        cout << "Email: " <<arr[i].email << endl;
        cout << "Genero: " <<arr[i].sexo << endl;
        cout << "Nota: " << arr[i].e_fisica << endl;
    }
    counterC = 0;
}

// arte //

void mostrartop10art(){
    counterC++;
    cout << "</TOP 10 en Artes\\>\n";
    for (int i = alma; alma-10 < i; i--)
    {
        cout << "\nTOP: " << counterC++;
        cout << "\nNombre: "<< arr[i].nombre << endl;
        cout << "Apellido: " << arr[i].apellido << endl;
        cout << "Email: " <<arr[i].email << endl;
        cout << "Genero: " <<arr[i].sexo << endl;
        cout << "Nota: " << arr[i].artes << endl;
    }
    counterC = 0;
}

// Sociales //

void mostrartop10soci(){
    counterC++;    
    cout << "</TOP 10 en Sociales\\>\n";
    for (int i = alma; alma-10 < i; i--)
    {
        cout << "\nTOP: " << counterC++;
        cout << "\nNombre: "<< arr[i].nombre << endl;
        cout << "Apellido: " << arr[i].apellido << endl;
        cout << "Email: " <<arr[i].email << endl;
        cout << "Genero: " <<arr[i].sexo << endl;
        cout << "Nota: " << arr[i].sociales << endl;
    }
    counterC = 0;
}

// Biologia //

void mostrartop10bio(){
    counterC++;
    cout << "</TOP 10 en Biologia\\>\n";
    for (int i = alma; alma-10 < i; i--)
    {
        cout << "\nTOP: " << counterC++;
        cout << "\nNombre: "<< arr[i].nombre << endl;
        cout << "Apellido: " << arr[i].apellido << endl;
        cout << "Email: " <<arr[i].email << endl;
        cout << "Genero: " <<arr[i].sexo << endl;
        cout << "Nota: " << arr[i].biologia << endl;
    }
    counterC = 0;
}

void boleta()
{
    int temp, con = 0;
    float temp1;
    do
    {
    string nomb;
    string ape;
    cout << "\nIngresa el nombre del alumno. " << endl;
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
        sumatoria = (arr[index].sociales+arr[index].matematica+arr[index].artes+arr[index].biologia+arr[index].e_fisica);
        prom = (float)sumatoria/5;
        temp1 = prom;
        con = 1;
    }
    else {
        cout << "No se ha encontrado, por favor, ingrese otro nombre. " << endl;
    }
    temp = index;
    } while (con == 0);

    cout << "\nBoleta para: " << arr[temp].nombre << " " << arr[temp].apellido << endl;
    cout << "---------------------------" << endl;
    cout << "Matematica: " << arr[temp].matematica << endl;
    cout << "Sociales: " << arr[temp].sociales << endl;
    cout << "Educacion Fisica: " << arr[temp].e_fisica << endl;
    cout << "Biologia: " << arr[temp].biologia << endl;
    cout << "Artes: " << arr[temp].artes << endl;
    cout << "---------------------------" << endl;
    cout << "Promedio Total: " << temp1 << endl;
}