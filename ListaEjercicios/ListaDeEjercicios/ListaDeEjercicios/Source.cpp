#include <iostream>
#include "DescompositionNumber.hpp"
#include "maxSum.hpp"

using namespace std;

int main()
{
	cout << "-------------- Ejercicio 4 ------------------------------" << endl;



	cout << "-------------- Ejercicio 5 ------------------------------" << endl;
	cout << "Descomposicion recursiva de sumas: " << endl;

	descompositionNumber(3, 0, 3);

	cout << "--------------------------------------------" << endl;

	cout << "Suma maxima de un vector" << endl;

	int A[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
	cout << maxSum(A, 10) << endl;

	cout << "--------------------------------------------" << endl;

	return 0;
}