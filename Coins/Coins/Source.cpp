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

const int N2 = 4;
const int INFINITO2 = 100000;

int monedas2[N2] = { 1,3,4,5 };
int memoria[100001];

int cambio2(int valor)
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
		res2 = min(res2, cambio2(valor - monedas2[i]));
	}
	return memoria[valor] = res2 + 1;
}

int main()
{
	// --------------------- Bk ----------------------------------
///*
	int valor = 7;
	cout << "Valor: " << valor << endl;

	cout << "Se necesitan " << cambio(valor) << " monedas" << endl;
//*/
	// --------------------- DP ----------------------------------

/*
	memset(memoria, -1, sizeof memoria);

	int valor = 7;
	cout << "Valor: " << valor << endl;;
	
	cout << endl << "Memoria almacenada:" << endl;
	for (int i = 0; i <= valor; i++)
	{
		cout << "valor: " << i << "->" << cambio2(i) << endl;
	}
*/

	return 0;
}