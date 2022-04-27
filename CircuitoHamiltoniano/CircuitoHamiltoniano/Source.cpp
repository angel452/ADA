#include <iostream>
#include <fstream>

#include <time.h>
#include <stdlib.h>

#include "GeneralFunctions.hpp"

using namespace std;

int main()
{
    bool** A = initializeMatrix();

    //------------------ lectura de matrizA.txt -------------------------
    string filename("matrizA.txt");
    bool number;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file >> number) {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                A[i][j] = number;
                input_file >> number;
            }
        }
    }

    input_file.close();
    //-------------------------------------------------------------------

    // Pasamos la informacion a otra matriz B[V][V]
    bool B[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            B[i][j] = A[i][j];
        }
    }

    cout << "Matrix B:" << endl;
    printMatrix2(B, V);

    // --------------------- CIRCUITO HAMILTONIANO ------------------------
    /*
    EJEMPLO DE MATRIZ
          a(1)   b(2)   c(3)   d(5)   e(6)   f(7)   g(8)
    a(1)   0      1       1      0      1      0     0
    b(2)   1                     1             1     1
    c(3)   1      1                     1            1
    d(5)          1                                  1
    e(6)   1              1                    1
    f(7)          1                     1
    g(8)                  1      1
    */
    
    hamilton(B);
    cout << "Fin del programa" << endl;
//-------------------------------------------------------------
}