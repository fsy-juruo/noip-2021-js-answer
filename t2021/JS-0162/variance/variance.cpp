#include<bits/stdc++.h>
using namespace std;
int ans=INT_MAX,n,l,sum,sum1,bo[1305][1005],a[10005],ok[10005];
void dfs(int s,int pfs)
{
	//cout<<n*pfs-s*s<<endl;
	ans=min(ans,n*pfs-s*s);
	//if(ans==59865) return;
	for(int i=1;i<=l;i++)
	{
		int flg=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]!=bo[i][j])
			{
				flg=1;
				break;
			}
		}
		if(flg==0) return;
	}
	l++;
	for(int i=1;i<=n;i++)
		bo[l][i]=a[i];
	for(int i=2;i<n;i++)
	{
		if(ok[i]&&a[i]>0&&a[i+1]+a[i-1]-a[i]!=a[i])
		{
			int t=a[i],t1=ok[i-1],t2=ok[i+1],t3=ok[i];
			a[i]=a[i+1]+a[i-1]-a[i];
			if(n*(pfs-t*t+a[i]*a[i])-(s-t+a[i])*(s-t+a[i])>ans)
			{
				a[i]=t;
				continue;
			}
			ok[i]=0;
			ok[i-1]=ok[i+1]=1;
			dfs(s-t+a[i],pfs-t*t+a[i]*a[i]);
			a[i]=t;
			ok[i-1]=t1;ok[i+1]=t2;ok[i]=t3;			
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		sum1=sum1+a[i]*a[i];
	}
	memset(ok,1,sizeof(ok));
	dfs(sum,sum1);
	cout<<ans<<endl;
	return 0;
}
/*
4
1 2 4 6
*/