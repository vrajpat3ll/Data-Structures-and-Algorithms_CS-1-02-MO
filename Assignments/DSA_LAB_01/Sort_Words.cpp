#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char **sr;
    sr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        sr[i] = (char *)malloc(50 * sizeof(char));
    }
    for (int j = 0; j < n; j++)
    {
        cin>>sr[j];
    }
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (strcmp(sr[min], sr[j]) > 0)
            {
                min = j;
            }
        }
        char t[50];
        strcpy(t, sr[i]);
        strcpy(sr[i], sr[min]);
        strcpy(sr[min], t);
    }
    for (int i = 0; i < n; i++)
    {
        cout << sr[i] << endl;
    }
    return 0;
}
