#include <bits/stdc++.h>
using namespace std;
int h[10000005],t[10000005];
bool v[10000005];
int x[200005];
int read1()
{
	char cc=getchar();
	while(!(cc>=48&&cc<=57))
	{
		if(cc=='-')
		{
			break;
		}
		cc=getchar();
	}
	bool f=false;
	int s=0;
	if(cc=='-')
	{
		f=true;
	}
	else
	{
		s=cc-48;
	}
	while(1)
	{
		cc=getchar();
		if(cc>=48&&cc<=57)
		{
			s=s*10+cc-48;
		}
		else
		{
			break;
		}
	}
	if(f==true)
	{
		s=-s;
	}
	return s;
}
bool pd(int n)
{
	while(n>0)
	{
		if((n%10)==7)
		{
			return true;
		}
		n/=10;
	}
	return false;
}
void pre(int n)
{
	for(int i=1;i<=n;i++)
	{
		h[i]=i-1;
		t[i]=i+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==false)
		{
			if(pd(i)==true)
			{
				for(int j=i;j<=n;j+=i)
				{
					if(v[j]==false)
					{
						v[j]=true;
						t[h[j]]=t[j];
						h[t[j]]=h[j];
					}
				}
			}
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	cin>>T;
	int maxn=0;
	for(int i=1;i<=T;i++)
	{
		x[i]=read1();
		maxn=max(maxn,x[i]);
	}
	if(maxn<=200000)
	{
		pre(200005);
	}
	else
	{
		pre(10000000);
	}
	for(int i=1;i<=T;i++)
	{
		if(v[x[i]]==true)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n",t[x[i]]);
		}
	}
	return 0;
}
//70 points
