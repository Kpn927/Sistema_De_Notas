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

//FUNCION EDICION//

void edicion()
{
    unsigned int opcion, tempo;
    bool found = false;
    string nombrenuevo, apellidonuevo, nuevogmail, nuevosexo, nomb, ape;
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
    do
    {
    cout << "\nQue vamos a modificar\n(1= Dato Personal)\n(2= Notas)\n-> ";
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
        case 2:
            cout << "Ingrese el nuevo apellido: " << endl;
            cin >> apellidonuevo;
            arr[tempo].apellido = apellidonuevo;
            break;
        case 3:
            cout << "Ingrese nuevo gmail: " << endl;
            cin >> nuevogmail;
            arr[tempo].email = nuevogmail;
        case 4:
            cout << "Ingrese nuevo genero: " << endl;
            cin >> nuevosexo;
            arr[tempo].sexo = nuevosexo;
            break;
        default:
            cout << "ERROR: Escogiste un numero invalido.";
            break;
        }
    }
    else if (opcion == 2)
    {
        unsigned int matematicanuevo, fisicanuevo, artesnuevo, Efisicanuevo, biologianuevo, socialesnuevo;
        int con = 0;
        opcion = 0;
        cout << "\nQue modificamos?\n(1= Matematicas)\n(2= Sociales)\n(3= Artes)\n(4= Fisica)\n(5= Educacion Fisica)\n(6= Biologia)\n->";
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
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
            }
            else if (matematicanuevo < 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
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
            cout << "\nIngrese la nueva nota de Matematica: ";
            cin >> socialesnuevo;
            if (socialesnuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
            }
            else if (socialesnuevo < 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
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
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
            }
            else if (artesnuevo < 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
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
            cout << "\nIngrese la nueva nota de fisica: ";
            cin >> fisicanuevo;
            if (fisicanuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
            }
            else if (fisicanuevo < 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
            }
            else{
            con = 1;
            arr[tempo].fisica = artesnuevo;
            }
            } while (con == 0);
            break;
        case 5:
            do
            {
            cout << "\nIngrese la nueva nota de Educación Fisica: ";
            cin >> Efisicanuevo;
            if (Efisicanuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
            }
            else if (Efisicanuevo < 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
            }
            else{
            con = 1;
            arr[tempo].e_fisica = Efisicanuevo;
            }
            } while (con == 0);
            break;
        case 6: 
            do
            {
            cout << "\nIngrese la nueva nota de Biologia: ";
            cin >> biologianuevo;
            if (biologianuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
            }
            else if (biologianuevo < 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.";
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
    cout << "\nQuieres modificar algo más?\n(Si = 1) (No = Otra cosa.): ";
    cin >> opcion;
    cout << "\n";
} while (opcion == 1);
}

void agregar(){
    int opcion = 0;
    do
    {
    string newNombre, newApellido, newGenero, newEmail;
    unsigned int newMat, newBio, newFis, newArt, newEfis, newSoci;
    cout << "</Agregar Alumno numero " << alma+1 << " \\>";

    cout << "\nIngrese su nombre: ";
    cin >> newNombre;
    
    cout << "Ingrese su apellido: ";
    cin >> newApellido;

    cout << "Ingrese su genero: ";
    cin >> newGenero;

    cout << "Ingrese su Email: ";
    cin >> newEmail;

    cout << "Ingrese la nota de Matematica: ";
    cin >> newMat;
    
    cout << "Ingrese la nota de Biologia: ";
    cin >> newBio;

    cout << "Ingrese la nota de Fisica: ";
    cin >> newFis;

    cout << "Ingrese la nota de Artes: ";
    cin >> newArt;
    
    cout << "Ingrese la nota de Educacion fisica: ";
    cin >> newEfis;

    cout << "Ingrese la nota de Sociales: ";
    cin >> newSoci;

    alma++;
    arr[alma].nombre = newNombre;
    arr[alma].apellido = newApellido;
    arr[alma].email = newEmail;
    arr[alma].sexo = newGenero;
    arr[alma].matematica = newMat;
    arr[alma].biologia = newBio;
    arr[alma].fisica = newFis;
    arr[alma].e_fisica = newEfis;
    arr[alma].sociales = newSoci;
    arr[alma].artes = newArt;
        cout << "\nQuieres agregar a otro alumno?\n(Si = 1) (No = Otra cosa.): ";
        cin >> opcion;
        cout << "\n";
    }while (opcion == 1);
}

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
void promediofis()
{
    unsigned int temp;
    float result;
    for (int i = 0; i < alma; i++)
    {
        temp+= arr[i].fisica;
    }
    result = (float)temp / (float)alma;

    cout << "Promedio en fisica es: " << result;
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


void probando(){
    cout << arr[alma].nombre << endl;
    cout << arr[alma].apellido << endl;
    cout << arr[alma].email << endl;
    cout << arr[alma].sexo << endl;
    cout << arr[alma].matematica << endl;
    cout << arr[alma].biologia << endl;
    cout << arr[alma].fisica << endl;
    cout << arr[alma].e_fisica << endl; 
    cout << arr[alma].sociales << endl;
    cout << arr[alma].artes << endl;
    
}