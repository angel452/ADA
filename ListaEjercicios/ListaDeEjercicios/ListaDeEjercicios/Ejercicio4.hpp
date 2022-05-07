#pragma once
void insertionSort(int arr[], int n)
{
	int a;
	int aux;
	int j;
	for (a = 1; a < n; a++)
	{
		aux = arr[a];
		j = a - 1;
		while (j >= 0 and arr[j] > aux)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = aux;
	}
}

void mergeaux2(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void mergeaux(int array[], int *left, int mid, int * right)
{
    
}

void mergeSort(int* A, int n)
{
	//base
	if (n == 1)
	{
		return;
	}
	//recurisivo
	int centro = n / 2;
	int* aux1izq = new int[centro];
	int* aux2der = new int[n - centro];

	//recorremos la primera parte
	for (int i = 0; i < centro; i++)
	{
		aux1izq[i] = A[i];
	}
	//recorremos la otra parte
	for (int i = centro; i < n; i++)
	{
		aux2der[i-centro] = A[i];
	}
	mergeSort(aux1izq, centro); //evaluacion recursivamente la primera mitad
	mergeSort(aux2der, n - centro); //evaluacion recursiva de la segunda mitad
    mergeaux(A, aux1izq, centro, aux2der); //obtenido de la tarea "Algoritmos de ordenacion"
}