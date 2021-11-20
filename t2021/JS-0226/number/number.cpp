#include<bits/stdc++.h>
using namespace std;
//bool st;
const int N=2e5+100;
bool vis[1100],vis2[11000],vis3[N];
bool pri[N];
int num[N];
int a[N];
int T,n,cnt;
//bool ed;
inline int read()
{
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
	return res*f;
}
inline bool pd(int x)
{
	while(x>0)
	{
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
inline void pre()
{
	for(int i=1;i<=1000;i++)
	{
		if(pd(i)==true) vis[i]=true;
		else
		{
			for(int j=2;j<=i;j++)
			{
				if(i%j!=0) continue;
				if(vis[i/j]==true) vis[i]=true;
			}
		}
	}
	return;
}
inline void work1(int x)
{
	pre();
	while(x--)
	{
		n=read();
		if(vis[n]==true) printf("-1\n");
		else
		{
			for(int i=n+1;;i++)
			{
				if(vis[i]==false)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
}
inline void pre2()
{
	for(int i=2;i<=10100;i++)
	{
		if(pri[i]==true) continue;
		for(int j=i*2;j<=10100;j+=i)
		{
			pri[j]=true;
		}
	}
	for(int i=2;i<=10100;i++)
	{
		if(pri[i]==false) num[++cnt]=i;
	}
	vis2[1]=vis2[2]=vis2[3]=vis2[4]=vis2[5]=vis2[6]=false;vis2[7]=true;
	for(int i=1;i<=10100;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			if(i%num[j]!=0) continue;
			if(vis2[i/num[j]]==true)
			{
				vis2[i]=true;
				break;
			}
		}
		if(pd(i)==true) vis2[i]=true;
	}
	return;
}
inline void work2(int x)
{
	pre2();
	while(x--)
	{
		n=read();
		if(vis2[n]==true) printf("-1\n");
		else
		{
			for(int i=n+1;;i++)
			{
				if(vis2[i]==false)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
}
inline void pre3(int mx)
{
	for(int i=2;i<=mx;i++)
	{
		if(pri[i]==true) continue;
		for(int j=i*2;j<=mx;j+=i)
		{
			pri[j]=true;
		}
	}
	for(int i=2;i<=mx;i++)
	{
		if(pri[i]==false) num[++cnt]=i;
	}
	vis3[1]=vis3[2]=vis3[3]=vis3[4]=vis3[5]=vis3[6]=false;vis3[7]=true;
	for(int i=1;i<=mx;i++)
	{
		for(int j=1;j<=cnt;j++)
		{
			if(i%num[j]!=0) continue;
			if(vis3[i/num[j]]==true)
			{
				vis3[i]=true;
				break;
			}
		}
		if(pd(i)==true) vis3[i]=true;
	}
	return;
}
inline void work3(int x)
{
	int mx=-1;
	for(int i=1;i<=x;i++) a[i]=read(),mx=max(mx,a[i]);
	pre3(mx);
	for(int j=1;j<=x;j++)
	{
		if(vis3[a[j]]==true) printf("-1\n");
		else
		{
			for(int i=a[j]+1;;i++)
			{
				if(vis3[i]==false)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
}
inline void work4(int x)
{
	while(x--)
	{
		n=read();
		cout<<"This is not a real work4. The real one has been eaten by me because I was hungry when I was coding.иоиоио!"<<endl;
	}
}
int main()
{
//	cout<<(&ed-&st)/1024.0/1024;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	if(T<=100) work1(T);
	else if(T<=1000) work2(T);
	else if(T<=10000) work3(T);
	else work4(T);
	return 0;
}

