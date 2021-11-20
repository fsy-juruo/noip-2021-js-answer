#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> cant(1e7 + 200), can;
    for (int i = 1; i <= 1e7 + 199; i++)
    {
        if (cant[i])
            continue;
        int j = i;
        bool c = 1;
        while (j)
        {
            if (j % 10 == 7)
            {
                c = 0;
                break;
            }
            j /= 10;
        }
        if (c)
            can.emplace_back(i);
        else
            for (int k = i; k <= 1e7; k += i)
                cant[k] = 1;
    }
    int t;
    cin >> t;
    for (int x; t--;)
    {
        cin >> x;
        if (cant[x])
            cout << "-1\n";
        else
            cout << *upper_bound(can.begin(), can.end(), x) << '\n';
    }
    return 0;
}
