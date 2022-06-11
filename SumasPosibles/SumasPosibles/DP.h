#pragma once
#include <iostream>
#include <vector>
using namespace std;


class PossibleSumsDP
{
private:
    vector<int> possibleNumbers;
    vector<int> results;

    //----------------- Logica DP ---------------------
    vector<vector<int>> dp;
    /*
    1. guardar en dp las sumas posibles de ese numero. Ejemplo:
        [[4, 1, 1, 1] //Guardamos las sumas posibles de 4
        [4, 3, 1] // Guardamos las sumas posibles de 4
        [...]]
    2. Antes de hacer el condicional de la linea 73, analizamos si ya existe una solucion para ese numero 
            Si existe... hacemos push_back a results 
                    if{ existe solucion )
                    {
                        push_back(solucion)
                    }
            Si NO existe... llama recursivamente como estuvo originalmente
                    if{ no existe solucion )
                    {
                        if (n - possibleNumbers[i] >= 0)
                        {
                            results.push_back(aux2);
                            //cout << n << " - " << possibleNumbers[i] << " = " << aux << endl;
                        }
                        SumasPosiblesRec(possibleNumbers, aux);
                    }
    */
    //------------------------------------------------
    int n;

public:
    PossibleSumsDP(vector<int> _possibleNumbers, int _n)
    {
        possibleNumbers = _possibleNumbers;
        n = _n;
    }

    void printVector(vector<int> vectorA)
    {
        for (int i = 0; i < vectorA.size(); i++)
        {
            cout << vectorA[i] << ' ';
        }
    }

    //  [1,3,4]

    int SumasPosiblesRec(vector<int> possibleNumbers, int n)
    {
        //caso base
        if (n <= 0)
        {
            if (n < 0)
            {
                //cout << "negativo!" << endl;
                return 0;
            }
            else if (n == 0)
            {
                //cout << "solucion!!!" << endl;

                printVector(results);
                cout << endl;

                results.pop_back();

                return 0;
            }
        }

        //recursividad
        int i = 0;
        for (i; i < possibleNumbers.size(); i++)
        {
            int aux2 = possibleNumbers[i]; // 1
            int aux = n - possibleNumbers[i]; // 4
            cout << n << " - " << possibleNumbers[i] << " = " << aux << endl;

            vector<int> dp_aux;

            if (n - possibleNumbers[i] >= 0)
            {
                results.push_back(aux2);
                //cout << n << " - " << possibleNumbers[i] << " = " << aux << endl;

                dp_aux.push_back(aux);
                dp.push_back(dp_aux);
            }

            SumasPosiblesRec(possibleNumbers, aux);
        }

        if (results.size() > 0)
        {
            results.pop_back();
        }
    }

    void SumasPosibles()
    {
        SumasPosiblesRec(possibleNumbers, n);
    }
};