#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0, k = 0;
    cin >> n;
    int q[n];
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    cin >> k;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int count = k;
        int ex = 0;
        for (int j = i; j < n; j++)
        {
            if (count == 0 && q[j] == 0)
            {
                break;
            }
            if (q[j] == 1)
            {
                ex++;
            }
            else
            {
                ex++;
                count--;
            }
        }
        if (max < ex)
        {
            max = ex;
        }
    }

    cout << max;
    return 0;
}