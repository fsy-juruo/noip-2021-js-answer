
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000000+2;
bool is7[maxn];
bool vis[maxn];
inline bool check(int m)
{
	int tmp=0;
	int om=m;
	while(m>0)
	{
		tmp=m%10;
		m/=10;
		if(tmp==7)
		{
			return vis[om]=is7[om]=true;
		}
	}
	vis[om]=true;
	return false;
}
int sishewuru(double m)
{
	if((int)m==(int)(m-0.5)) return m+1;
	else return m;
}
bool qfac(int a)
{
	/*if(a==577)
	{
		int debug=1;
	}*/
	int tmp=2;
	int alt=2;
	int aq=sishewuru(sqrt(a));
	if(not vis[a])
	{
	 if(check(a)) return true;
	}
	else if(is7[a]) return true;
	while(tmp<=aq)
	{
		if((a%tmp)!=0) tmp++;
		else
		{
			alt=a/tmp; 
			if(!vis[tmp]) 
			{
				if(check(tmp))
				{
					return true;
				}
			}
			else if(is7[tmp]) return true;
			if(!vis[alt])
			{
				if(check(alt))
				{
					return true;
				}
			}		
			else if(is7[alt]) return true;
			tmp++;
		}
	}
	return false;
}
int T,x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&x);
		if(qfac(x)) printf("-1\n");
		else
		{
			int m=x+1;
			while(qfac(m))
			{
				m++;
			}
			printf("%d\n",m);
		}
	}
	return 0;
}
