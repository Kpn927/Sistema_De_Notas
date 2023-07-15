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
unsigned int counterA, counterB, counterC;

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
        cout << "\nQue modificamos?\n(1= Nombre)\n(2= Apellido)\n(3= Gmail)\n(4= Genero)\n->";
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
        case 4:
            cout << "\nIngrese nuevo genero: " << endl;
            cin >> nuevosexo;
            arr[tempo].sexo = nuevosexo;
            break;
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
            cout << "\nIngrese la nueva nota de fisica: ";
            cin >> fisicanuevo;
            if (fisicanuevo > 20)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
            }
            else if (fisicanuevo <= 0)
            {
                cout << "ERROR: El rango tiene que estar entre 01 y 20.\n";
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
        case 6: 
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
    cout << "\nQuieres modificar algo mas? (Si = 0) (No = Otra cosa.)\n->";
    cin >> opcion;
    cout << "\n";
} while (opcion == 0);
}

void agregar(){
    int opcion = 0, con = 0;
    do
    {
    string newNombre, newApellido, newGenero, newEmail;
    unsigned int newMat, newBio, newFis, newArt, newEfis, newSoci;
    cout << "</Agregar Alumno numero" << alma+1 << "\\>";

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
        cout << "Ingrese su nota de Fisica: ";
        cin >> newFis;
    if (newFis > 20)
    {
        cout << "\nERROR: El rango tiene que estar entre 01 y 20.\n";
    }
    else if (newFis <= 0)
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
    arr[alma].fisica = newFis;
    arr[alma].e_fisica = newEfis;
    arr[alma].sociales = newSoci;
    arr[alma].artes = newArt;
    cout << "\nQuieres agregar a otro alumno? (Si = 0) (No = Otra cosa.)\n->";
    cin >> opcion;
    cout << "\n";
    alma++;
    }while (opcion == 0);
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
////////////////////////////////
//////////////TOP10/////////////
////////////////////////////////

///////////////MATEMATICA////////////////
int top10mat(vector<Notas> &arr, int low, int high)
{
    int pivote = arr[high].matematica;
    int i = low - 1;
    int j = low;

    for (j; j <= high - 1; j++)
    {
        if (arr[j].matematica <= pivote)
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }

    swap (arr[i+1], arr[j]);

    return (i+1);
}

void top10matsort(vector<Notas> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = top10mat(arr, low, high);

        top10matsort(arr, low, pi - 1);
        top10matsort(arr, pi + 1, high);
    }
}

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

///////////////Fisica////////////////
int top10fis(vector<Notas> &arr, int low, int high)
{
    int pivote = arr[high].fisica;
    int i = low - 1;
    int j = low;

    for (j; j <= high - 1; j++)
    {
        if (arr[j].fisica <= pivote)
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }

    swap (arr[i+1], arr[j]);

    return (i+1);
}

void top10fissort(vector<Notas> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = top10fis(arr, low, high);

        top10fissort(arr, low, pi - 1);
        top10fissort(arr, pi + 1, high);
    }
}

void mostrartop10fis(){
    counterC++;
    cout << "</TOP 10 en Fisica\\>\n";
    for (int i = alma; alma-10 < i; i--)
    {
        cout << "\nTOP: " << counterC++;
        cout << "\nNombre: "<< arr[i].nombre << endl;
        cout << "Apellido: " << arr[i].apellido << endl;
        cout << "Email: " <<arr[i].email << endl;
        cout << "Genero: " <<arr[i].sexo << endl;
        cout << "Nota: " << arr[i].fisica << endl;
    }
    counterC = 0;
}

///////////////Educacion Fisica////////////////
int top10efis(vector<Notas> &arr, int low, int high)
{
    int pivote = arr[high].e_fisica;
    int i = low - 1;
    int j = low;

    for (j; j <= high - 1; j++)
    {
        if (arr[j].e_fisica <= pivote)
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }

    swap (arr[i+1], arr[j]);

    return (i+1);
}

void top10efissort(vector<Notas> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = top10efis(arr, low, high);

        top10efissort(arr, low, pi - 1);
        top10efissort(arr, pi + 1, high);
    }
}

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

///////////////Artes////////////////
int top10art(vector<Notas> &arr, int low, int high)
{
    int pivote = arr[high].artes;
    int i = low - 1;
    int j = low;

    for (j; j <= high - 1; j++)
    {
        if (arr[j].artes <= pivote)
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }

    swap (arr[i+1], arr[j]);

    return (i+1);
}

void top10artsort(vector<Notas> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = top10art(arr, low, high);

        top10artsort(arr, low, pi - 1);
        top10artsort(arr, pi + 1, high);
    }
}

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

///////////////sociales////////////////
int top10soci(vector<Notas> &arr, int low, int high)
{
    int pivote = arr[high].sociales;
    int i = low - 1;
    int j = low;

    for (j; j <= high - 1; j++)
    {
        if (arr[j].sociales <= pivote)
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }

    swap (arr[i+1], arr[j]);

    return (i+1);
}

void top10socisort(vector<Notas> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = top10soci(arr, low, high);

        top10socisort(arr, low, pi - 1);
        top10socisort(arr, pi + 1, high);
    }
}

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

///////////////Biologia////////////////
int top10bio(vector<Notas> &arr, int low, int high)
{
    int pivote = arr[high].biologia;
    int i = low - 1;
    int j = low;

    for (j; j <= high - 1; j++)
    {
        if (arr[j].biologia <= pivote)
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }

    swap (arr[i+1], arr[j]);

    return (i+1);
}

void top10biosort(vector<Notas> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = top10bio(arr, low, high);

        top10biosort(arr, low, pi - 1);
        top10biosort(arr, pi + 1, high);
    }
}

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
//////////
//BOLETA//
//////////
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
        sumatoria = (arr[index].sociales+arr[index].matematica+arr[index].artes+arr[index].biologia+arr[index].fisica+arr[index].e_fisica);
        prom = (float)sumatoria/6;
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
    cout << "Fisica: " << arr[temp].fisica << endl;
    cout << "Educacion Fisica: " << arr[temp].e_fisica << endl;
    cout << "Biologia: " << arr[temp].biologia << endl;
    cout << "Artes: " << arr[temp].artes << endl;
    cout << "---------------------------" << endl;
    cout << "Promedio Total: " << temp1 << endl;
}

void structToCSV() 
{
    newDATA.open("DATA1.csv");

    newDATA << "nombre,apellido,email,gender,matematicas,sociales,biologia,fisica,educacion_fisica,artes" << endl;

    for (int i = 0; i <= (alma-1); i++)
    {
        newDATA << arr[i].nombre << ",";
        newDATA << arr[i].apellido << ",";
        newDATA << arr[i].email << ",";
        newDATA << arr[i].sexo << ",";
        newDATA << arr[i].matematica << ",";
        newDATA << arr[i].sociales << ",";
        newDATA << arr[i].biologia << ",";
        newDATA << arr[i].fisica << ",";
        newDATA << arr[i].e_fisica << ",";
        newDATA << arr[i].artes << endl;
    }

    newDATA.close();
}
// Code Reutilizado pero modificado para mi conveniencia de proyecto anterior junto a GABO1423 para facilitar las cosas. //