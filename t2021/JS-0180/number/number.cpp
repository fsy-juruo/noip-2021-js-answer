#include <cstdio>
const int N = 4*1e3+7, M = 1e6+3;
int clearlove[N], clearlove1[M];
int v[N];
int tot = 1, tot1 = 0;
bool ver;
int T, a;
bool vn(int op)
{
	if (op<N && v[op]) return 1;
	for (int i = 0; clearlove1[i] <= op/2 && i < tot1; ++i)
	{
		if (op%clearlove1[i] == 0)
			return 1;
	}
	return 0;
}
int main()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	scanf ("%d", &T);
	clearlove[0] = 7;
	for (int i = 17; i < N-6; ++i)
	{
		int k = i;
		ver = 0;
		while (k > 0)
		{
			if(k%10== 7) 
			{
				ver = 1;
				break;
			}
			k /= 10;
		}
		if (ver)
			clearlove[tot++] = i;
	}
	for (int j = 6; j < tot; ++j)
		for (int i = 0;  clearlove[i]*clearlove[i] <= clearlove[j]; ++i)
			if(clearlove[j]%clearlove[i]==0) 
			{	
				clearlove[j] = 0;
				break;
			}
	for (int i = 0; i < tot; ++i)
		if(clearlove[i]) 
		{
			v[clearlove[i]] = 1;
			clearlove1[tot1++] = clearlove[i];
		}
//
	for (int i = N; i < M; ++i)
	{
		int k = i;
		ver = 0;
		while (k > 0)
		{
			if(k%10== 7) 
			{
				ver = 1;
				break;
			}
			k /= 10;
		}
		if (ver) clearlove1[tot1++] = i;
	}
//
//	for (int i = 0; i < tot1; ++i)
//		printf ("%d ", clearlove1[tot1-1]);
//	printf ("%d", tot1);
	while (T--)
	{
		scanf ("%d", &a);
		if (v[a] && a<=N) printf ("-1\n");
		else if (a%7 == 0) printf ("-1\n");
		else if (vn(a)) printf ("-1\n");
		else{
			int ls = a+1;
			while (vn(ls) == 1) ls+=1;
			printf ("%d\n", ls);
		}
	}
	return 0;
}
