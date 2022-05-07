#include <iostream>
#pragma once

using namespace std;

int maxSum(int A[], int n)
{
	int aux1 = 0;																		 //C
	int aux2 = 0;																		 //C

	int sum1 = 0;																		 //C
	int result = 0; // para la respuesta final											 //C
		
	for (int i = 0; i < n; i++) //maxima suma entre todos los numeros					 //N
	{
		sum1 = sum1 + A[i];																 //N
	}

	int aux3 = sum1;																	 //C
	int sum2 = sum1;																	 //C

	for (int i = 0; i < n; i++) // COMPROBACION DE IZQUIERDA A DERECHA					 //N
	{
		aux3 = aux3 - A[i]; //vamos restando a la suma total los elementos del vector	 //N
		if (aux3 > sum1)																 //N
		{
			sum1 = aux3; //reemplazamos sum1 porque encontramos un numero mayor          //N
			aux1 = i; // marcamos donde encontramos un mayor							 //N
		}
	}

	int aux4 = sum2;																	 //C
	for (int i = n - 1; i >= 0; i--) // COMPROBACION DE DERECHA A IZQUIERDA				 //N
	{
		aux4 = aux4 - A[i];																 //N
		if (aux4 > sum2)																 //N
		{
			sum2 = aux4;																 //N
			aux2 = i; // marcamos donde encontramos un mayor							 //N
		}
	}

	for (int i = aux1 + 1; i <= aux2 - 1; i++)											 //N
	{
		result = result + A[i];															 //N
	}

	return result;

}
/*
O( 7 O(C) + 14 O(N) )
O( O(C) + O(N) )
O( O(N) )
complejidad de O(N) 
*/