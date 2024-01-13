//https://www.hackerrank.com/contests/stack-queue-ug22/challenges/remove-duplicates-2-0
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> CharStack;
    for (auto c:s)
    {
        if (CharStack.empty())
        {
            CharStack.push(c);
        }
        else if (CharStack.top()==c)
        {
            CharStack.pop();
        }
        
        else if (CharStack.top()!=c)
        {
            CharStack.push(c);
        }
        
    }
    stack<char> Ans;

    for (;!CharStack.empty();CharStack.pop()){
        Ans.push(CharStack.top());
    }
    for (;!Ans.empty();Ans.pop()){
        cout<<Ans.top();
    }    
    return 0;
}