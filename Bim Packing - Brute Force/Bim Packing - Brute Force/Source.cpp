#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// --------------- IMPRIMIR CONTENEDORES -------------------------------
void printMatriz(int filas, int columas, int matriz[100][100])
{
	cout << "-- CONTENEDORES: -- " << endl;
	for (int fil = 0; fil < filas; fil++)
	{
		cout << "Contenedor " << fil + 1 << ": ";
		for (int col = 0; col < columas; col++)
		{
			cout << matriz[fil][col] << " ";
		}
		cout << endl;
	}
}

void displayContainers(int weight[], int n, int c, int bin_rem[])
{
	int res = 0;
	int columna = 0;
	
	//--- Rellenando de ceros la matriz de resultados ---
	int matriz[100][100];
	for (int fil = 0; fil < 100; fil++)	{
		for (int col = 0; col < 100; col++){
			matriz[fil][col] = 0;
		}
	}
	//--------------------------------------------------

	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < res; j++)
		{
			//cout << "binRem: " << bin_rem[j] << endl;
			if (bin_rem[j] >= weight[i])
			{
				matriz[j][columna] = weight[i];
				bin_rem[j] = bin_rem[j] - weight[i];
				columna = columna + 1;

				break;
			}
		}

		if (j == res)
		{
			int aux;
			matriz[j][columna] = weight[i];
			bin_rem[res] = c - weight[i];
			res++;
			columna = columna + 1;
		}
	}

	printMatriz(5, columna, matriz);

}

// ------------------- BIN PACKING ------------------------------------
int BinPackingAux(int weight[], int n, int c, int bin_rem[])
{
    int res = 0;

    for (int i = 0; i < n; i++) 
	{
        int j;
        for (j = 0; j < res; j++) {
            if (bin_rem[j] >= weight[i]) 
			{
                bin_rem[j] = bin_rem[j] - weight[i];

                break;
            }
        }

        if (j == res) 
		{
            bin_rem[res] = c - weight[i];
            res++;
        }
    }
    return res;
}

void display(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << endl;
}

int BinPacking(int a[], int n, int c, int bin_rem[])
{
	int minBinPacking = 1000;
	int resBinPacking;

	// Sort the given array
	sort(a, a + n);

	do {
		//display(a, n);
		resBinPacking = BinPackingAux(a, n, c, bin_rem);
		//cout << "Numero de contenedores: " << resBinPacking << endl << endl;

		if (resBinPacking < minBinPacking)
		{
			minBinPacking = resBinPacking;
		}

	} while (next_permutation(a, a + n));

	return minBinPacking;
}

// ------------------- MAIN ------------------------------------
int main()
{
	cout << "Inicio ..." << endl;

	int weight[] = { 4,8,1,4,2,1 };
	//int weight[] = { 3,8,7 };
	//int weight[] = { 2, 5, 4, 7, 1, 3, 8 };

	int c = 10;
	int n = sizeof(weight) / sizeof(weight[0]);
	int bin_rem[sizeof(weight) / sizeof(weight[0])];

	cout << "---------------------------------------------------------" << endl;
	display(weight, n);

	int minBinPacking;
	minBinPacking =	BinPacking(weight, n,c,bin_rem);

	cout << "---------------------------------------------------------" << endl;
	cout << "Numero minimo de contenedores a usar: " << minBinPacking << endl;
	cout << "---------------------------------------------------------" << endl;

	int weightSolution[] = { 4,4,8,1,2,1 };
	displayContainers(weightSolution, n, c, bin_rem);

	cout << endl << "Fin del Programa" << endl;
	return 0;
}
