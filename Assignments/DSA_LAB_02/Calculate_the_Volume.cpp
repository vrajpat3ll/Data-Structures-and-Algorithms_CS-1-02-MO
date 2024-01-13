#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Cuboid{
    public:
    int l,b,h;
    
    void display(){
        cout<<l<<" "<<b<<" "<<h<<endl;
    }
};

class CuboidVol:public Cuboid{
    public:
    CuboidVol(int a,int v,int c){
        l=a;
        b=v;
        h=c;
    }
    void readInput(int len,int bd,int ht){
        l=len;
        b=bd;
        h=ht;
    }
    int Display(int l,int b,int h){
        return l*b*h;
    }
};

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        
        int a,b,c;
        cin>>a>>b>>c;
        CuboidVol obj(a,b,c);
        obj.readInput(a,b,c);
        obj.display();
        cout<<obj.Display(a,b,c)<<endl;
    }
    return 0;
}
