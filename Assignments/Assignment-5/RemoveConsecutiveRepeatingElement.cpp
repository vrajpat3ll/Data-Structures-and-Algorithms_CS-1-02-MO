// https://www.hackerrank.com/contests/stack-queue-ug22/challenges/remove-consecutive-repeating-element

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string RemoveConsecutiveDuplicates(const string &s)
{
    stack<char> st;

    for (char c : s)
    {
        if (st.empty() || c != st.top())
        {
            st.push(c);
        }
    }

    string newS;
    for (; !st.empty();)
    {
        newS += st.top();
        st.pop();
    }
    return newS;
}

string reverse(string s)
{
    int n = s.length();
    for (int i = 0; i < n/2; i++)
    {
        swap(s[i],s[n-i-1]);
    }

    return s;
}

int main()
{
    string s;
    getline(cin, s);
    s = reverse(s);
    cout << RemoveConsecutiveDuplicates(s) << endl;
}