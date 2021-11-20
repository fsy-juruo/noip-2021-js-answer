#include<bits/stdc++.h>
using namespace std;
int T;
bool h[10000005];
bool cf(int x)
{
	while(x!=0)
	{
		int y=x%10;
		if(y==7) return 1;
		x/=10;
	} 
	return 0;
}
int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	for(int i=1;i<=10000000;i++)
	{
		if(h[i]==1) continue;
		if(cf(i))
		{
			h[i]=1;
			for(int j=2;j<=10000000/i;j++)
			{
				h[i*j]=1;
			}
		}
	}
	while(T--)
	{
		int x=read();
		if(h[x]) cout<<-1<<endl;
		else
		{
			for(int i=x+1;i<=10000001;i++)
			{
				if(!h[i])
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
//	cout<<h[7]<<' '<<h[107]<<' '<<h[108]<<endl;
	return 0;
}

