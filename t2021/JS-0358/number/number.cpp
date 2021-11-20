#include <bits/stdc++.h>
using namespace std;
bool isseven(int n)
{
    while (n)
    {
        if (n % 10 == 7)
            return true;
        else
            n /= 10;
    }
}


bool compplus(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            if (isseven(i) || isseven(n / i))
                return true;
    }
    return false;
}

void doit(int n)
{
    if (compplus(n))
    {
        printf("-1");
        return;
    }
    else
        for (int i = n+1;; i++)
        {
            if (!compplus(i))
            {
                printf("%d", i);
                return;
            }
        }
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        doit(tmp);
        printf("\n");
    }
    return 0;
}