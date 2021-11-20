#include <bits/stdc++.h>
using namespace std;
int x[111],k,ans,v[111],f,n,m;
int cl(int h)
{
	int s=0;
	while (h!=0)
	{
		s+=h%2;
		h=h/2;
	}
	return s;
}
int pw(int b)
{
	int bb=2,as=1;
	while (b)
	{
		if (b&1)
			as=(as*bb);
		bb=(bb*bb);
		b=b>>1;
	}
	return as;
}
void dfs(int a,int h,int si)
{
	x[a]=si;
	if (a==n)
	{
		if (cl(h)<=k)
		{
			f=1;
			for (int i=1;i<=n;i++)
				f=f*v[x[i]];
			ans=(ans+f)%998244353;
		}
		return;
	}
	for (int i=0;i<=m;i++)
		dfs(a+1,h+pw(i),i);
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin >>n>>m>>k;
	for (int i=0;i<=m;i++)
		cin >>v[i];
	dfs(0,0,0);
	cout <<ans<<endl;
	return 0;
}

