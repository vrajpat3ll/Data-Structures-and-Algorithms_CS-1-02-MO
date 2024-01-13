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
bool DoesitContain(int n,int d){    //perfectly works
    while(n){
        if(n%10==d){return true;}
        n/=10;
    }
    return false;
}

bool IsGoodNumber(int N,int digit){
     if(!DoesitContain(N,digit)){
        int sum=0;
        bool foofaa=true;
        string Num=to_string(N);
        for(int i=Num.length()-1;i>=0;i--){
            int dig=Num[i]-'0';
            if(dig<=sum && foofaa==false){return false;}
            sum+=dig;
            foofaa=false;
        }
        return true;
    }
    return false;
}


int main() {
    int L,R,D;
    cin>>L>>R>>D;
    for(int X=L;X<=R;X++){
        if(IsGoodNumber(X,D)){
            cout<<X<<" ";
        }
    }
    return 0;
}
