#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//the error is that numbers having a digit which is occuring more than once would be giving wrong answer
// int sumofdigits_totheright(int n,int digit){
//     int sum=0;
//     while((n%10)!=digit){
//         int p=n%10;
//         sum+=p;
//         n/=10;
//     }
//     return sum;
// }
bool DoesitContain(int n,int d){
    while(n){
        if(n%10==d){return true;}
        n/=10;
    }
    return false;
}

bool IsGoodNumber(int N,int digit){
    if(!DoesitContain(N,digit)){
        int sum=0,f=0;
        string Num=to_string(N);
        for(int i=Num.length()-1;i>=0;i--){
            for(int j=Num.length()-1;j>i;j--){
                sum+=Num[j]-'0';
            }
            if((Num[i]-'0')>sum){
                f=1;
            }
            if(f==0) {return false;}
        }
        if(f==1){return true;}
    }
    return false;
}


int main() {
    int L,R,D;
    cin>>L>>R>>D;
    for(int X=L+1;X<R;X++){
        if(IsGoodNumber(X,D)){
            cout<<X<<" ";
        }
    }
    return 0;
}
