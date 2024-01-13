#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void shellSort(int *array, int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}
int main()
{
    int n1, n2;
    cin >> n1;
    int *arr1;
    arr1 = (int *)malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        cin >> *(arr1 + i);
    }
    cin >> n2;
    int *arr2;
    arr2 = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n2; i++)
    {
        cin >> *(arr2 + i);
    }
    int breaker = 1;
    shellSort(arr1, n1);
    shellSort(arr2, n2);
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (*(arr1 + i) == *(arr2 + j))
            {
                cout << *(arr1 + i) << " ";
                breaker = 0;
            }
        }
    }
    if (breaker == 1)
    {
        cout << "-1";
    }
    return 0;
}
