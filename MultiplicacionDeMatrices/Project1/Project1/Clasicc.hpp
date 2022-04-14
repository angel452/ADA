#include <iostream>
#include "GeneralFunctions.hpp"
#pragma once
using namespace std;

void MultiplicacionMatrizClasico(int** A, int** B, int** C, int n)
{
    //Multiplicacion
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            for (int inner = 0; inner < n; inner++)
            {
                C[row][col] += A[row][inner] * B[inner][col];
            }
        }
    }

    cout << "Resultado:" << endl;
    printMatrix(C, n);

}


