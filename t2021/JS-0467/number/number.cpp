#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+1500;
int T,f[maxn+50];
void read(int &s)
{
	s=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+(c-48);
		c=getchar();
	}
	s=s*f;
}
bool check(int x)
{
	while(x)
	{
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(T);
	for(int i=2;i<=maxn;i++)
	{
		f[i]=check(i);
		if(f[i])continue;
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				int x=j,y=i/j;
				if(f[x]||f[y])
				{
					f[i]=true;
					break;
				}
			}
		}
	}
	for(int i=1;i<=T;i++)
	{
		int x;
		read(x);
		if(f[x])printf("-1\n");
		else
		{
			for(int j=x+1;1;j++)
			{
				if(!f[j])
				{
					printf("%d\n",j);
					break;
				}
			}
		}
	}
	return 0;
}
