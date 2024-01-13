// https://www.hackerrank.com/contests/stack-queue-ug22/challenges/tours-1-1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int ANS(int *petrol,int *distance,int n){
    int Tpetrol=0,Tdistance=0;
    for (int i = 0; i < n; i++)
    {
        Tpetrol+=petrol[i];
        Tdistance+=distance[i];
    }
    if (Tdistance>Tpetrol)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        if(petrol[i]-distance[i]>0){
            return i;
        } 
    }
    
    
}

int main()
{
    int n; cin >> n;
    int petrol[n], distance[n];
   
    for (int i = 0; i < n; i++)
    {
        cin >> petrol[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> distance[i];
    }
    int ans=ANS(petrol,distance,n);
    cout<<ans<<endl;
    return 0;
}