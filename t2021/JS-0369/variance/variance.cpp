#include<bits/stdc++.h>
using namespace std;

int n,a[10005],b[10005],c[10005],v[10005],cnt=0;
int s;
vector<int> ver[10005],pos;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
	for(int i=2;i<=n;i++)
	{
		b[i-1]=a[i]-a[i-1];
		c[i-1]=a[i]-a[i-1];
	}
	sort(b+1,b+n);
	for(int i=1;i<n;i++)
	{
		if(i%2==0) b[i]=-b[i];
	}
	sort(b+1,b+n);
	for(int i=1;i<n;i++) if(b[i]<0) b[i]=-b[i];
	//for(int i=1;i<n;i++) cout<<b[i]<<" ";
	//cout<<endl;

	for(int i=1;i<n;i++)
	{
		cnt++;
		v[b[i]]++;
		ver[b[i]].push_back(cnt);
	}
	memset(v,0,sizeof(v));
	for(int i=1;i<n;i++)
	{
		v[c[i]]++;
		c[i]=ver[c[i]][v[c[i]]-1];
	}
	for(int i=1;i<n-1;i++)
	{
		//for(int i=1;i<n;i++) cout<<c[i]<<" ";
		//cout<<endl;
		if(c[i]>c[i+1])
		{
			pos.push_back(i);
			swap(c[i],c[i+1]);
			i=1;
		}
	}
	for(int i=0;i<pos.size();i++)
	{
		int t=pos[i];
		int ts=a[t+1];
		a[t+1]=a[t]+a[t+2]-ts;
		s=s+(a[t+1]-ts);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=(n*a[i]-s)*(n*a[i]-s)/n;
	}
	cout<<ans<<endl;
	return 0;
}
