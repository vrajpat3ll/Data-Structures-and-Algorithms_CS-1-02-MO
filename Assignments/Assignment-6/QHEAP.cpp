#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> HEAPq;
    int NQueries;
    cin >> NQueries;
    int queries = NQueries;
    set<int> SET;
    int QueryType, input;
    while (queries--)
    {

        cin >> QueryType;
        switch (QueryType)
        {
        case 1:
            cin >> input;
            HEAPq.push(input);
            break;
        case 2:
            cin >> input;

            if (input == HEAPq.top())
            {
                HEAPq.pop();
            }
            else
            {
                SET.insert(input);
            }
            break;
        case 3:
            for (auto it : SET)
            {
                if (it == HEAPq.top())
                {
                    HEAPq.pop();
                }
            }
            cout << HEAPq.top() << endl;
            break;
        }
    }
}