#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool p[400014];
bool pos[10];
ll T, x;

void dl(ll cur, ll curn, ll o, bool jud)
{
	if(cur == 6)
	{
		if(jud == 1)
		{
			p[curn] = 1;
			p[curn + 100000] = 1;
			ll x = curn * 2;
			while(x <= 300014)
			{
				p[x] = 1;
				x += curn;
			}
		}
	}
	else
	{
		for(ll i = 0; i <= 9; i ++)
		{
			if(i == 7)
				continue;
			
			if(pos[cur] == 0)
			{
				dl(cur + 1, curn + i * o, o * 10, jud);
			}
			else
			{
				dl(cur + 1, curn + 7 * o, o * 10, jud);
				jud = 1;
			}
		}
	}
}

void f(int cur)
{
	if(cur == 6)
	{
		dl(1, 0, 1, 0);
	}
	else
	{
		pos[cur] = 0;
		f(cur + 1);
		pos[cur] = 1;
		f(cur + 1);
	}
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	f(1);
	
	scanf("%lld", &T);
	for(int i = 1; i <= T; i ++)
	{
		scanf("%lld", &x);
		if(p[x] == 1)
			printf("-1\n");
		else
		{
			ll j = x + 1;
			while(1)
			{
				if(p[j] == 0)
				{
					printf("%lld\n", j);
					break;
				}
				j ++;
			}
		}
	}
	
	return 0;
}
