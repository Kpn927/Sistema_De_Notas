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