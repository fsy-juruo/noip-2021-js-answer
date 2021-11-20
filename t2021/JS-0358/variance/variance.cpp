#include <bits/stdc++.h>
#define DEBUG
#define LOCAL
using namespace std;
bool endflag = 0;
int n, a[10010],lastfc, fc;
double pjz;
void qpjz()
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
    }
    pjz = sum / n;
}
void qfc()
{
    qpjz();
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (pjz - a[i]) * (pjz - a[i]);
    }
    lastfc = fc;
    fc = n * sum;
}
int main()
{
#ifdef LOCAL
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    qfc();
    while (!endflag)
    {
        int maxnum, maxc = 0, tmp;
        for (int i = 2; i < n; i++)
        {
            if (maxc < abs(a[i] - pjz))
            {
                maxc = abs(a[i] - pjz);
                maxnum = i;
                tmp = a[i];
            }
        }
        a[maxnum] = a[maxnum - 1] + a[maxnum + 1] - a[maxnum];
        qfc();
        if (fc >= lastfc)
        {
            endflag = 1;
            a[maxnum] = tmp;
            qfc();
        }
    }
    printf("%d\n",fc);
#ifdef DEBUG

#endif
    return 0;
}