
#include <bits/stdc++.h>

using namespace std;

int sup_arr[1000001];

int main()
{
    int N,t;
    cin>>t;
    while (t--)
    {
        cin>>N;
        if(N == 0)
        {
            cout<<0<<endl;
            continue;
        }
        queue<int> Q;
        Q.push(N);
        sup_arr[N] = 1;
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            if(sup_arr[now-1] == 0)
            {
                sup_arr[now-1] = sup_arr[now]+1;
                if(now -1 == 0)
                    break;
                Q.push(now-1);
            }
            for(int i = 2; i <= sqrt(now); i++)
            {
                if(now%i == 0)
                {
                    int phi = max(i, now/i);
                    if(sup_arr[phi] == 0)
                    {
                        sup_arr[phi] = sup_arr[now]+1;
                        Q.push(phi);
                    }
                }
            }
        }
        cout<<sup_arr[0]-1<<endl;
        memset(sup_arr,0,sizeof(sup_arr));
    }
    return 0;
}