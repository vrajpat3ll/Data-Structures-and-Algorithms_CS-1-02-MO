// https://www.hackerrank.com/contests/stack-queue-ug22/challenges/check-paraenthesis
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool IsComplete(string exp)
{
    stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (s.empty())
            s.push(exp[i]);
        
        else if ((s.top() == '(' && exp[i] == ')') 
               ||(s.top() == '{' && exp[i] == '}')
               ||(s.top() == '[' && exp[i] == ']'))
            s.pop();
        
        else
            s.push(exp[i]);
        
    }
    if (s.empty())
        return true;

    return false;
}

int main()
{
    string s;
    cin >> s;
    bool ans = IsComplete((s));
    if (ans)
        cout << "true" << endl;

    else
        cout << "false" << endl;

    return 0;
}