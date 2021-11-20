#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
#define debug printf
#else
#define debug(...)
#endif
int read()
{
	int s = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = 0;
		}
		c = getchar();	
	} 
	while(isdigit(c))
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return f ? s : -s;
}
ll readll()
{
	ll s = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = 0;
		}
		c = getchar();	
	} 
	while(isdigit(c))
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return f ? s : -s;
}
const int maxn = 2e7 + 5;
char fg[maxn],fg2[maxn];
int c[4000005],cnt;
inline int check(int x)
{
	while(x)
	{
		if(x % 10 == 7)
		{
			return 0;
		}
		x /= 10;
	}
	return 1;
}
int mx;
void init()
{
	if(mx <= 200000)
	{
		for(int i = 1;; ++i)
		{
			int x = i;
			if(!check(x) || (x % 7 == 0) || fg[x])
			{
				for(int j = x;j <= 200002; j += x)
				{
					fg[j] = 1;
				}
			}
			else
			{
				c[++cnt] = i;
				if(x > mx)
				{
					break;
				}
			}
		}
		return;
	}
	for(int i = 1;; ++i)
	{
		int x = i;
		if(!check(x) || (x % 7 == 0) || fg[x])
		{
			for(int j = x;j <= 10000001; j += x)
			{
				fg[j] = 1;
			}
		}
		else
		{
			c[++cnt] = i;
			if(x > mx)
			{
				break;
			}
		}
	}
}
pair<int,int> in[200005];
int ans[200005];
char ss[10],u;
void output(int x)
{
	u = 0;
	while(x)
	{
		ss[++u] = x % 10;
		x /= 10;
	}
	for(int i = u;i >= 1; --i)
	{
		putchar(ss[i] + '0');
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	printf("%d\n%d\n",1024*1024,5978786);
	int T = read();
	mx = 0;
	for(int i = 1;i <= T; ++i)
	{
		in[i].first = read();
		in[i].second = i;
		mx = max(mx,in[i].first);
	}
	sort(in + 1,in + T + 1);
	init();
	int k = 1;
	for(int i = 1;i <= T; ++i)
	{
		while(c[k] < in[i].first)
		{
			++k;
		}
		if(c[k] != in[i].first)
		{
			ans[in[i].second] = -1;
		}
		else
		{
			ans[in[i].second] = c[k + 1];
		}
	}
	for(int i = 1;i <= T; ++i)
	{
		if(ans[i] == -1)
		{
			putchar('-'),putchar('1');
		}
		else
		{
			output(ans[i]);
		}
		putchar('\n');
	}
	return 0;
}
