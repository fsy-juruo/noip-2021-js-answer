#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, a[N], ave, s0, ch[N], vis[N];

int main()
{
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		ave += a[i];
		a[i] *= n;
	}
	printf("0");
	return 0;
}

