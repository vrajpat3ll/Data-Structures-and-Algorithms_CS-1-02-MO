#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void revstr(char *s)
{
    int l = 0;
    while (*s != '\0')
    {
        l++;
        s++;
    }
    char *begin = s;
    char *end = s + l - 1;
    while (begin < end)
    {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}

int main()
{
    char str[101];
    cin.getline(str, 101);
    revstr(str);
    int l = 0, i = 0;
    while (*(str + i) != '\0')
    {
        l++;
        i++;
    }
    for (int i = l - 1; i != -1; i--)
    {
        cout << *(str + i);
    }
    cout << endl;
    return 0;
}