#include<bits/stdc++.h>
using namespace std;
int n,tot;
int q[1000][16],l,r;
int ans=2e9,a[16];
vector<int>hs[16];
void insert(int p)
{
	for(int i=1;i<=n;i++)
	{
		if(i!=p)q[r][i]=q[l][i];
		else q[r][i]=q[l][i-1]+q[l][i+1]-q[l][i];
		hs[i].push_back(q[r][i]);
	}
	r++;
}
bool check(int p)
{
	int x=q[l][p];
	q[l][p]=q[l][p-1]+q[l][p+1]-x;
	for(int i=0;i<hs[1].size();i++)
	{
		bool flag=0;
		for(int j=1;j<=n;j++)
			if(hs[j][i]!=q[l][j])
				{flag=1;break;}
		if(!flag){q[l][p]=x;return 0;}
	}
	q[l][p]=x;return 1;
}
int fangcha()
{
	int sum=0,fz=0;
	for(int i=1;i<=n;i++)
		a[i]=q[l][i],fz+=a[i];
	for(int i=1;i<=n;i++)
		sum+=(a[i]*n-fz)*(a[i]*n-fz);
	return sum/n;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>10){cout<<0<<endl;return 0;}
	l=r=1;
	for(int i=1;i<=n;i++)
	{
		hs[i].push_back(a[i]);
		q[r][i]=a[i];
	}
	r++;
	while(l<r)
	{
		ans=min(ans,fangcha());
		for(int i=2;i<n;i++)
			if(check(i))insert(i),tot++;
		l++;
	}
	cout<<ans<<endl;
	return 0;
}
