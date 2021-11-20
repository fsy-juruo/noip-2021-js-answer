#include<bits/stdc++.h>
using namespace std;
inline int read();
bool check(int);
const int M=1e7+10;
const int N=1e7+5;
bool pd[M];
int p[M],lp=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//
	int n=read(),x;
	for(int i=1;i<=N;++i)
	{
		if(pd[i]==1)
		{
			if(check(i))
			{
				for(int j=i;j<=N;j+=i)
				{
					pd[j]=1;
				}
			}
		}
		else
		{
			if(check(i))
			{
				for(int j=i;j<=N;j+=i)
				{
					pd[j]=1;
				}
			}
			else
			{
				p[++lp]=i;
			}
		}
	}
//	cout<<"#\n";
//	for(int i=1;i<=lp;++i)cout<<p[i]<<" ";
	for(int i=1;i<=n;++i)
	{
		x=read();
		if(pd[x])
		{
			cout<<"-1\n";
		}
		else
		{
			int l=1,r=lp,mind;
			while(l<r)
			{
				mind=((l+r)>>1);
				if(p[mind]>x)
				{
					r=mind;
				}
				else
				{
					l=mind+1;
				}
			}
			cout<<p[r]<<"\n";
		}
	}
	return 0;
}



bool check(int i)
{
	while(i)
	{
		if(i%10==7)return 1;
		i=i/10;
	}
	return 0;
}


inline int read()
{
	int s=0;bool w=1;
	char c;
	while(c<'0'||c>'9'){if(c=='-')w=0;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return w?s:-s;
}
