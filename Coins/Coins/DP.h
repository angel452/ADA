#pragma once
#include <iostream>
using namespace std;

const int N2 = 4;
int INFINITO2 = 100000;
int monedas2[N2] = { 1,3,4,5 };

int cambio2(int valor, int memoria[100001])
{
	if (valor < 0) //caso negativo
	{
		return INFINITO2;
	}
	if (valor == 0) //esta respuesta si la sabemos
	{
		return 0;
	}

	if (memoria[valor] != -1)
	{
		return memoria[valor];
	}

	int res2 = INFINITO2; //para que la primera comparacion este siempre sea mayor y no lo tomemos
	for (int i = 0; i < N2; i++)
	{
		res2 = min(res2, cambio2(valor - monedas2[i], memoria));
	}
	return memoria[valor] = res2 + 1;
}