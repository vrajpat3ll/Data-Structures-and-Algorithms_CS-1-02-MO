#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int VowelCount(char *str){
    int count=0;
    while(*str!='\0'){
        if(*str=='a'||*str=='A'||*str=='e'||*str=='E'||*str=='i'||*str=='I'||*str=='o'||*str=='O'||*str=='u'||*str=='U'){
            count++;
        }
        str++;
    }
    return count;
}

int main() {

    char str[1001];
    cin.getline(str,1001);
    cout<<VowelCount(str)<<endl;
    return 0;
}
