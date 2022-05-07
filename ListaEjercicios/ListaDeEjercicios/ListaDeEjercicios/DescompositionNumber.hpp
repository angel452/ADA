#include <iostream>
#include <vector>
#include <stdio.h>
#pragma once

using namespace std;

/*
5
4 1
3 2
3 1 1
2 2 1
2 1 1 1 
1 1 1 1 1
*/

void printVector(vector <int> v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";
}

void printarr(int *A, int i)
{
	//for (int j = i; j < sizeof(A)/ sizeof(A[0]); j++)
	for (int j = i; j > 0; j--)
	//for (int j = 0; j < i; j++)
	{
		cout << A[j-1] << " ";
	}
	cout << endl;	
}

void descompositionNumber(int n, int i, int tam)
{
	static int* arr = new int[tam];
	if (n == 0)
	{ 
		printarr(arr, i);
	}

	if (n > 0)
	{
		int j;
		for (j = tam; j > 0; j--)
		{
			arr[i] = j;
			descompositionNumber(n - 1, i + 1, j);
		}
	}
}


