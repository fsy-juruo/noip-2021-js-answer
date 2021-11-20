#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
int t, con[N], cnt, nxt[N];
bool iscon[N];

bool ins(int x)
{
	while(x)
	{
		if(x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for(int i = 7; i < N; i++)
		if(ins(i)) con[++cnt] = i, iscon[i] = true;
	for(int i = 1; i <= cnt; i++)
		for(int j = 2; j * con[i] < N; j++)
			iscon[con[i] * j] = true;
	nxt[N - 1] = N - 1;
	for(int i = N - 1; i > 1; i--)
		if(iscon[i - 1]) nxt[i - 1] = nxt[i];
		else nxt[i - 1] = i - 1;
	for(int i = 1; i < N - 1; i++)
		nxt[i] = nxt[i + 1];
	scanf("%d", &t);
	while(t--)
	{
		int x;
		scanf("%d", &x);
		if(iscon[x]) printf("-1\n");
		else printf("%d\n", nxt[x]);
	}
	return 0;
}

