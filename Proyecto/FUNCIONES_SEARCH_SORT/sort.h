#include "../main.h"
#include <iostream>
#include <vector> 

using namespace std;

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

int sortsec(vector<Notas> &arr, int low, int high)
{
    string pivote = arr[high].seccion;
    int i = low - 1;
    int j = low;

    for (j; j <= high - 1; j++)
    {
        if ((arr[j].seccion <= pivote))
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }

    swap (arr[i+1], arr[j]);

    return (i+1);
}

void sortsecx(vector<Notas> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = sortsec(arr, low, high);

        sortsecx(arr, low, pi - 1);
        sortsecx(arr, pi + 1, high);
    }
}

int promsort(vector<Notas> &arr, int low, int high)
{
    float pivote = arr[high].prom;
    int i = low - 1;
    int j = low;

    for (j; j <= high - 1; j++)
    {
        if ((arr[j].prom <= pivote))
        {
            i++;
            swap (arr[i], arr[j]);
        }
    }

    swap (arr[i+1], arr[j]);

    return (i+1);
}

void promsortx(vector<Notas> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = promsort(arr, low, high);

        promsortx(arr, low, pi - 1);
        promsortx(arr, pi + 1, high);
    }
}

void promllenado()
{
    for (int i = 0; i < alma; i++)
    {
        arr[i].prom = (float)(arr[i].sociales+arr[i].matematica+arr[i].artes+arr[i].biologia+arr[i].e_fisica)/5;
    }
}

unsigned int countersecA, countersecB, countersecC, countersecD;

void contasecA(){
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].seccion == "A")
        {
            countersecA++;
        }
        
    }
}

void contasecB(){
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].seccion == "B")
        {
            countersecB++;
        }
        
    }
}

void contasecC(){
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].seccion == "C")
        {
            countersecC++;
        }
        
    }   
}

void contasecD(){
    for (int i = 0; i < alma; i++)
    {
        if (arr[i].seccion == "D")
        {
            countersecD++;
        }
        
    }
}

void seccionA()
{
    unsigned int temp;
    temp = countersecA;
    temp-=10;
    int x = 10;
    for (int i = temp; i < countersecA; i++)
    {
        cout << x << " ";
        cout << arr[i].nombre << " " <<arr[i].apellido << ": "<<arr[i].prom << endl;
        x--;
    }
    
}

void seccionB()
{
    unsigned int temp;
    temp = countersecB;
    temp-=10;
    int x = 10;
    for (int i = temp; i < countersecB; i++)
    {
        cout << x << " ";
        cout << arr[i].nombre << " " <<arr[i].apellido << ": "<<arr[i].prom << endl;
        x--;
    }
    
}

void seccionC()
{
    unsigned int temp;
    temp = countersecC;
    temp-=10;
    int x = 10;
    for (int i = temp; i < countersecC; i++)
    {
        cout << x << " ";
        cout << arr[i].nombre << " " <<arr[i].apellido << ": "<<arr[i].prom << endl;
        x--;
    }
    
}

void seccionD()
{
    unsigned int temp;
    temp = countersecD;
    temp-=10;
    int x = 10;
    for (int i = temp; i < countersecD; i++)
    {
        cout << x << " ";
        cout << arr[i].nombre << " " <<arr[i].apellido << ": "<<arr[i].prom << endl;
        x--;
    }
    
}

