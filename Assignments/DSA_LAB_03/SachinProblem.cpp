/*22 April,2023*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int SachinSeSafe(int NPeople, int index_tobe_killed)
{
    if (NPeople == 1)
    {
        return 1;
    }

    int ans=SachinSeSafe(NPeople-1,index_tobe_killed);
    ans=(ans+index_tobe_killed-1)%NPeople+1;
    return ans;
}

int main()
{
    int n, k;      // n==number of people in circular formation
    cin >> n >> k; // k==index of the person to be killed in each of the rounds

    cout<<SachinSeSafe(n, k);

    return 0;
}