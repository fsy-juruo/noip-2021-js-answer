#include <bits/stdc++.h>
using namespace std;
long long a,c[1005],l,x,b[1005],ans,sum,rans,now;
vector<long long>v[5];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	rans=10000000000000;
	cin>>a;
	cin>>c[0],l=c[0];
	for(int i=1;i<a;i++)
	{
		cin>>x;
		b[i]=x-l;l=x;
	}
	sort(b+1,b+a);
	for(int i=0;i<(1<<(a-1));i++)
	{
		v[0].clear();
		v[1].clear();
		x=i;
		now=1;
		while(now<a)
		{
			v[x%2].push_back(b[now]);
			x/=2;
			now++;
		}
		ans=0;sum=0;
		now=1;
		for(int i=v[0].size()-1;i>=0;i--)
		c[now]=c[now-1]+v[0][i],now++;
		for(int i=0;i<v[1].size();i++)
		c[now]=c[now-1]+v[1][i],now++;
		for(int i=0;i<a;i++)
		ans+=a*c[i]*c[i],sum+=c[i];
		if(ans-sum*sum<rans)
		{
//			for(int i=0;i<a;i++)
//			cout<<c[i]<<" ";
//			cout<<endl;
			rans=ans-sum*sum;
		}
	}
			cout<<rans<<endl;
}
