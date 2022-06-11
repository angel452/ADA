#pragma once
#include <iostream>
#include <vector>
using namespace std;


class PossibleSums
{
private:
    vector<int> possibleNumbers;
    vector<int> results;
    int n;

public:
    PossibleSums(vector<int> _possibleNumbers, int _n)
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
            int aux = n - possibleNumbers[i]; // 1
            //cout << n << " - " << possibleNumbers[i] << " = " << aux << endl;

            if (n - possibleNumbers[i] >= 0)
            {
                results.push_back(aux2);
                //cout << n << " - " << possibleNumbers[i] << " = " << aux << endl;
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