#include<bits/stdc++.h>
using namespace std;

int a[405],t[405],n;

inline int read()
{
	int s = 0,w = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-')
			w = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		s = (s << 1) + (s << 3) + (ch ^ 48);
		ch = getchar();
	}
	return s * w;
}

void write(int x)
{
	if(x > 9)	write(x / 10);
	putchar((x % 10) + '0');
}

int ans = INT_MAX;

int work()
{
	int res1 = 0,res2 = 0;
	for(int i = 1;i <= n;i++)
		res1 += a[i] * a[i];
	res1 *= n;
	for(int i = 1;i <= n;i++)
		res2 += a[i];
	res2 = res2 * res2;
	return res1 - res2;
}

void dfs(int last,int num)
{
	ans = min(ans,num);
	for(int i = 2;i < n;i++)
	{
		if(i != last)
		{
			int T = a[i];
			a[i] = a[i - 1] + a[i + 1] - a[i];
			int cp = work();
			if(cp <= num)
				dfs(i,cp);
			a[i] = T;
		}
	}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++)
		a[i] = read(),t[i] = a[i];
	if(n == 4)
	{
		int wq = 114524;
		while(wq--)
		{
			for(int i = 2;i < n;i++)
			{
				a[i] = a[i - 1] + a[i + 1] - a[i];
				ans = min(ans,work());
			}
		}
		for(int i = 2;i < n;i++)
		{
			a[i] = t[i];
		}
		wq = 114514;
		while(wq--)
		{
			a[3] = a[2] + a[4] - a[3];
			ans = min(ans,work());
			a[2] = a[1] + a[3] - a[2];
			ans = min(ans,work());
		}
		write(ans);	
		return 0;
	}
	dfs(0,work());
	write(ans);
	return 0;	
} 
