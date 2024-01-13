#include<iostream>
#include<string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<string> subsequence(string str, vector<string> &vec)
{
    if (str.size() == 0) { return vec; } 

    string s = str.substr(1);

    vector<string> adder = subsequence(s, vec);
    for (int i = 0; i < pow(2, str.size() - 1); i++)
    {
        vec.push_back(str[0] + adder[i]);
    }

    return vec;
}

int main()
{
    string str;
    vector<string> Svec;
    cin >> str;
    Svec.push_back("");  //Empty string
    
    vector<string> solution = subsequence(str, Svec);
    
    sort(solution.begin(), solution.end());   // sorts vector lexicographically

    for (auto subseq : solution) { cout << subseq << " "; }  // pritn all elements in string vector
    return 0;
}