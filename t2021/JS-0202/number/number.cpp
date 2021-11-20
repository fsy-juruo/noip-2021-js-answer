/*
	long long / unsigned / BigInteger
	8:30 ~ 13:00
	Think twice, code once. Think once, debug forever!
	After re, resubmmit id.txt.
	Yes! Pa!
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(register int i = a; i < b; i++)
#define hrp(i, a, b) for(register int i = a; i <= b; i++)
#define rev(i, a, b) for(register int i = a; i >= b; i--)
#define D(x) cerr<<#x<<": "<<x;
#define pb push_back
using namespace std;
const int U = 1e7+5;
int w[U], v[U], y[U], vpos, ypos;
bool no[U];
int main(void)
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	rep(i, 0, U)
	{
		if (i%10 == 7) v[vpos++] = i;
		else if (i%100/10 == 7) v[vpos++] = i;
		else if (i%1000/100 == 7) v[vpos++] = i;
		else if (i%10000/1000 == 7) v[vpos++] = i;
		else if (i%100000/10000 == 7) v[vpos++] = i;
		else if (i%1000000/100000 == 7) v[vpos++] = i;
		else if (i%10000000/1000000 == 7) v[vpos++] = i;
		else if (i%100000000/10000000 == 7) v[vpos++] = i;
	}
	
	rep(i, 0, vpos)
	{
		for(int j = v[i]; j < U; j += v[i]) no[j] = 1;
	}
	
	rep(i, 0, U) if (!no[i]) y[ypos++] = i;
	
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		int t = lower_bound(y, y+ypos, n)-y;
		if (y[t] != n) printf("-1\n");
		else printf("%d\n", y[t+1]);
	}

	return 0;
}
/*

 */

