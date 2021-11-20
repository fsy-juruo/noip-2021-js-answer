#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0x3f3f3f3f;
typedef vector<int> VT;
map<VT,bool> mp;
int calc(VT x)
{
	double s=0;
	double res=0;
	for(int i=0;i<x.size();++i)
		s+=x[i];
	for(int i=0;i<x.size();++i)
		res+=(x[i]-s/n)*(x[i]-s/n);
	return res*n;
}
void dfs(VT x)
{
//	for(int i=0;i<x.size();++i)
//		cout<<x[i]<<' ';
//	cout<<calc(x)<<endl;

	ans=min(ans,calc(x));
	for(int i=1;i<x.size()-1;++i)
	{
		VT y=x;
		y[i]=y[i-1]+y[i+1]-y[i];
		if(mp.count(y)) continue;
		if(calc(y)>calc(x)+1000) continue;
		mp[y]=1;
		dfs(y);
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	VT v;
	for(int i=1;i<=n;++i)
	{
		int t;
		cin>>t;
		v.push_back(t);
	}
	dfs(v);
	cout<<ans;
	
	return 0;
}
