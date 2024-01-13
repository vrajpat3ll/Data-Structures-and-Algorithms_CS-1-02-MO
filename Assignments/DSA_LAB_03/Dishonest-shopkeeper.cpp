#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class product
{
public:
    float original_price, discount_percentage;
    float faultyfinal_price(void)
    {
        float fp = original_price * ((100 - discount_percentage) / 100);
        if (fp > 100)
        {
            return fp + 10;
        }
        return fp;
    }
    float ogfinal_price(void)
    {
        float fp = original_price * ((100 - discount_percentage) / 100);
        return fp;
    }
};

int main()
{
    int t;
    cin >> t;
    product list[t];
    for (int i = 0; i < t; i++)
    {
        cin >> list[i].original_price >> list[i].discount_percentage;
    }

    float sum_og = 0, sum_faulty = 0;
    for (int i = 0; i < t; i++)
    {
        sum_faulty += list[i].faultyfinal_price();
        sum_og += list[i].ogfinal_price();
    }

    cout << sum_faulty - sum_og << endl;
    return 0;
}
