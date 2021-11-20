#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=998244353;
int n,m,k,edge;
int a[200],sum=0;
int path[200];
typedef vector<int> VT;
map<VT,bool> mp;

LL column(int a,int b)//line_up a in b
{
//	cout<<"C"<<a<<' '<<b<<endl;
	LL res=1;
	for(int i=1;i<=b;++i)
		res*=a-i+1;
	for(int i=1;i<=b;++i)
		res/=i;
	return res;
}
LL mypow(int a,int b)
{
//	cout<<"P"<<a<<' '<<b<<endl;
	LL res=a;
	for(int i=2;i<=b;++i)
		res*=a;
//	cout<<res<<endl;
	return res;
}
void dfs2(int s)
{
	if(s==n)
	{
		for(int i=edge+1;i>m;--i)
			if(path[i]) return;
		VT y;
		for(int i=m;i>=0;--i)
		{
			y.push_back(path[i]);
//			cout<<path[i];
		}	
//		cout<<endl;
		
		if(mp.count(y)) return;
		mp[y]=1;
		
		LL times=1,weight=1;
		int tmp=n;
		for(int i=m;i>=0;--i)
		{
			times*=column(tmp,path[i]);
			weight*=mypow(a[i],path[i]);
			tmp-=path[i];
		}
//		cout<<times<<' '<<weight<<endl;
		sum=(sum+times*weight%MOD)%MOD;
		return;
	}
	for(int i=edge+1;i>=1;--i)
	{
		if(path[i])
		{
			path[i]-=1;
			path[i-1]+=2;
			dfs2(s+1);
			path[i]+=1;
			path[i-1]-=2;
		}
	}
}
void dfs1(int u,int s)
{
	if(s>k) return;
	if(u==edge+1)
	{
//		for(int i=edge+1;i>=0;--i)
//			cout<<path[i];
//		cout<<endl;

		dfs2(s);
		return;
	}
	path[u]=1;
	dfs1(u+1,s+1);
	path[u]=0;
	dfs1(u+1,s);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;++i)
		cin>>a[i];
	
	edge=log(n)/log(2)+m+1;

	dfs1(0,0);
	cout<<sum;
	return 0;
}
