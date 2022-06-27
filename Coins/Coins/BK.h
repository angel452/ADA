#pragma once
#include <iostream>
using namespace std;

void test()
{
	cout << "hola" << endl;
}

int cambio(int valor, int INFINITO, int monedas[4], int N)
{
	if (valor < 0) //caso negativo
	{
		return INFINITO;
	}
	if (valor == 0) //esta respuesta si la sabemos
	{
		return 0;
	}

	int res = INFINITO; //para que la primera comparacion este siempre sea mayor y no lo tomemos
	for (int i = 0; i < N; i++)
	{
		res = min(res, cambio(valor - monedas[i],INFINITO,monedas,N));
	}
	return res + 1;
}