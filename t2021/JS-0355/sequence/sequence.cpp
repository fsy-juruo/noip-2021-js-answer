#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[20],a[40],anaa,ans;
vector<int> ex;
multiset<int> jl[122881];
bool jd(int x)
{
	int Q=0;
	while(x)
	{
		int w=x&-x;
		x-=w;
		Q++;
		if(Q==k&&x)
		{
			return 0;
			break;
		}
		else if(Q>k)
		{
			return 0;
			break;
		}
	}
	return 1;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	if(m>=15)
	{
		while(1)
		cout<<"I JUST CAN'T DO THAT!!!"<<endl;
	}
	else
	{
		for(int i=0;i<=m;i++)
		cin>>v[i];
		int l=n,r=1;
		int x=m;
		while(x)
		{
			r*=2;
			x--;
		}
		r*=n;
		for(int i=l;i<=r;i++)
		{
			if(jd(i))
			    ex.push_back(i);
		}
	}
	return 0;
}
