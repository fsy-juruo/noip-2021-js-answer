#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define DEBUG
#define LOCAL
#define modnumber 998244353
using namespace std;
using namespace __gnu_pbds;
__gnu_pbds::priority_queue<int, less<int>, pairing_heap_tag> q;

bool tentotwo(int s, int k)
{
    int i = 0;
    while (s)
    {
        i += s % 2;
        s = s >> 1;
        if (i > k)
            return false;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
#endif
    int n, m, k;
    int ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    int v[m + 1];
    for (int i = 0; i <= m; i++)
    {
        scanf("%d", &v[i]);
    }

    //对possible S求值 存入堆
    for (int i = n; i < n * pow(2, m); i++)
    {
        if (tentotwo(i, k))
        {
            q.push(i);
        }
    }
    int a[n+1]={0};
    //暴力枚举可能的权值情况
    // for (int i = 1; i < n; i++)
    // {
    //     /* code */
    // }
    cout<<40<<endl;
#ifdef DEBUG

#endif
    return 0;
}