#include <iostream>
#include <ctime>
using namespace std;

//bouble
void booble()
{
    int temp;
    int a[10] = { 20,54,14,2,4,7,8,32,85,1 };

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++)
        {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "lista ordenada" << endl;

    for (int i = 0; i < 10; i++) {
        cout << a[i] << "\t";
    }
}

//bouble random 
void boobler()
{
    srand(time(NULL));
    int temp;
    
    int a[2000];
    int n = 2000;

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (100 - 1 + 1) + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "lista ordenada (r)" << endl;

    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}

//insert
void insert()
{
    int a[10] = { 20,54,14,2,4,7,8,32,85,1 };

    for (int i = 1; i < 10; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && temp <= a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
    cout << "lista ordenada" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << "\t";
    }
}

//insert random
void insertr()
{
    srand(time(NULL));

    int a[2000];
    int n = 2000;

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (100 - 1 + 1) + 1;
    }

    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && temp <= a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
    cout << "lista ordenada" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
}

//select
void selection()
{
    int a[10] = { 20,54,14,2,4,7,8,32,85,1 };
    int i, j, n, loc, temp, min;

    n = 10;

    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        loc = i;

        for (j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                loc = j;
            }
        }

        temp = a[i];
        a[i] = a[loc];
        a[loc] = temp;
    }

    cout << "lista ordenada" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << "\t";
    }
}

//select random
void selectionr()
{
    srand(time(NULL));
    int a[2000];
    int n = 2000;
    
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (100 - 1 + 1) + 1;
    }

    int i, j, loc, temp, min;
    
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        loc = i;

        for (j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                loc = j;
            }
        }

        temp = a[i];
        a[i] = a[loc];
        a[loc] = temp;
    }

    cout << "lista ordenada" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
}

//cocktail sort
void cocktail()
{
    int a[] = { 5,1,4,8,2,1,6,5,7 };
    int n = sizeof(a) / sizeof(a[0]);

    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void cocktailr()
{
    srand(time(NULL));

    int a[2000];
    int n = 2000;

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % (100 - 1 + 1) + 1;
    }

    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    unsigned t0, t1;

    t0 = clock();

    //boobler();
    //insertr();
    //selectionr();
    cocktailr();

    t1 = clock();

    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << endl << "Execution Time (s): " << time << endl;
 
    return 0;
}