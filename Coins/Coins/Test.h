#pragma once
#include <iostream>
using namespace std;

const int N = 4;
const int INFINITO = 100000;

int monedas[N] = { 1,3,4,5 };

int cambio(int valor)
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
		res = min(res, cambio(valor - monedas[i]));
	}
	return res + 1;
}