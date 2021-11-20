#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define inf 1000000007
using namespace std;
const int mxn=10000005;
typedef long long ll;
typedef pair<int,int> pi;
inline int read()
{
	char c=getchar();
	int f=1;
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	int x=0;
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int pr[1000006],t=0;
int is[mxn];
int nx[mxn];
int T,q[200005];
inline bool hve(int x)
{
	while(x!=0)
	{
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	int mx=0;
	for(int i=0;i<T;i++)
	{
		q[i]=read();
		mx=max(mx,q[i]);
	}
	mx=min(mx+100000,mxn);
	for(int i=2;i<mx;i++)
		is[i]=i;
	for(int i=2;i<mx;i++)
	{
		if(is[i]==i)
			pr[t++]=i;
		for(int j=0;j<t && pr[j]<=is[i] && i*pr[j]<mx;j++)
			is[i*pr[j]]=pr[j];
	}
	//cout<<t<<endl;
	for(int i=1;i<mx;i++)
		is[i]=i;
	for(int i=1;i<mx;i++)
	{
		if(is[i]==i && hve(i))
		{
			is[i]=1;
			for(int j=0;j<t && i*pr[j]<mx;j++)
				is[i*pr[j]]=pr[j];
		}
		else if(is[i]!=i)
		{
			for(int j=0;j<t && pr[j]<=is[i] && i*pr[j]<mx;j++)
				is[i*pr[j]]=pr[j];
		}
	}
	int ed=mx-1;
	while(is[ed]!=ed) ed--;
	int ls=ed;
	for(int i=ed-1;i>=1;i--)
		if(is[i]!=i) nx[i]=-1;
		else 
		{
			nx[i]=ls;
			ls=i;
		}
	for(int i=0;i<T;i++)
		cout<<nx[q[i]]<<endl;
	return 0;
}


