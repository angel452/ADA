#include <iostream>
#include <fstream>
#include "Strassen.hpp"
#include "Clasicc.hpp"

using namespace std;
using std::cout;
using std::cerr;
using std::endl; 
using std::string;
using std::ifstream;

int main()
{
    int n = 8;

    int** A = initializeMatrix(n);
    int** B = initializeMatrix(n);
    int** C = initializeMatrix(n);

    //------------------ lectura de matrizA.txt -------------------------
    string filename("matrizA.txt");
    int number;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file >> number) {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] = number;
                input_file >> number;
            }
        }
    }

    input_file.close();

    //------------------ lectura de matrizB.txt -------------------------
    string filename2("matrizB.txt");
    int number2;

    ifstream input_file2(filename2);
    if (!input_file2.is_open()) {
        cerr << "Could not open the file - '"
            << filename2 << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file2 >> number2) {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                B[i][j] = number2;
                input_file2 >> number2;
            }
        }
    }

    input_file.close();

    // -------------------------------------------------------------------------
    cout << "Matrix A:" << endl;
    printMatrix(A, n);
    std::cout << "Matrix B:" << endl;
    printMatrix(B, n);

    // -------------------- CLASICO --------------------------------------------
    
    /*
    cout << "\t Multiplicacion Clasica " << endl;

    //Rellenar matriz C
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(C + i) + j) = 0;
        }
    }

    unsigned t0, t1;
    t0 = clock();

    MultiplicacionMatrizClasico(A,B,C,n);
    */

    // -------------------- STRASSEN ----------------------------------------------
    
    
    cout << "\t ----- Multiplicacion Strassen ----- " << endl;

    unsigned t0, t1;
    t0 = clock();

    C = strassenMultiply(A, B, n);

    cout << "Multipliction result:" << endl;
    printMatrix(C, n);
    

    // -----------------------------------------------------------------------------

    cout << "----------------------- Time --------------------------------" << endl;
    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Execution Time (s): " << time << endl;
    cout << "-------------------------------------------------------------" << endl;

    // --------------------- Borrado de memoria ------------------------------------
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i < n; i++)
        delete[] B[i];
    delete[] B;

    for (int i = 0; i < n; i++)
        delete[] C[i];
    delete[] C;
    // -----------------------------------------------------------------------------

    return 0;
}