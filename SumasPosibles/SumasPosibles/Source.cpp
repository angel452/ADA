#include <iostream>
#include <vector>
#include "Backtracking.h"
#include "DP.h"
using namespace std;

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(3); 
    a.push_back(4); 

    int n = 5;

    cout << "--------------------- Datos: ---------------------" << endl;
    cout << "Numeros que podemos usar: " << endl;
    cout << "[ ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ' ';
    }
    cout << "] " << endl;
    cout << "Resultado de la suma: " << n << endl;
    cout << "----------------- Backtracking -------------------" << endl;
    PossibleSums b(a,n);
    b.SumasPosibles();

    cout << "------------------------  DP ---------------------" << endl;
    PossibleSumsDP c(a, n);
    c.SumasPosibles();

    cout << "--------------------------------------------------" << endl;
    cout << "Fin del programa" << endl;

    return 0;
}