#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 10;
int val[MAXN];
bool check(int pos)
{
    int x = pos;
    while(x)
    {
        int tmp = x % 10;
        if (tmp == 7)
        {
            return true;
        }
        x = x / 10;
    }
    return false;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    memset(val, 0, sizeof(val));
    int last = 0;
    for (int i = 1; i < MAXN; i++)
    {
        if (val[i])
        {
            continue;
        }
        if (check(i))
        {
            for (int j = 1; j * i < MAXN; j++)
            {
                val[j * i] = -1;
            }
        }
        else
        {
            val[last] = i;
            last = i;
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << val[n] << endl;
    }
    return 0;
}