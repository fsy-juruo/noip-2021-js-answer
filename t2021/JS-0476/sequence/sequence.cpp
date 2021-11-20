#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s;
}
int n,m,k,S;
int ss=0;
int f[105];
int cnt[105];
long long cnt2[105];
long long cnt3[105];
long long v[105];
long long ans=0ll;
int count(int x)
{
	int s=0;
	while(x!=0)
	{
		if(x&1) s++;
		x>>=1;
	}
	return s;
}
void dfs(int step)
{
//	cout<<step<<" "<<ss<<endl;
//	cout<<cnt[3]<<" "<<cnt[2]<<" "<<cnt[1]<<" "<<cnt[0]<<endl;
//	system("pause");
	if(ss==n)
	{
		long long temp=1,temp2=1;
		for(int i=0;i<=m;i++) //权值计算 
		{
//			cout<<cnt[i]<<" ";
			int num=cnt[i];
			while(num!=0)
			{
				temp=(temp*v[i])%998244353ll;
				num--;
			}
		}
		for(int i=2;i<=n;i++) //组合数计算 
		{
			cnt2[i]++;
		}
		for(int i=0;i<=m;i++)
		{
			for(int j=2;j<=cnt[i];j++)
			{
				cnt2[j]--;
			}
		}
		for(int i=2;i<=n;i++) //组合数质因数分解 
		{
			if(cnt2[i]==0) continue;
			int p=2;
			int num=i;
			while(num>1)
			{
				if(num%p==0)
				{
					num/=p;
					cnt3[p]+=cnt2[i];
				}
				else
				{
					p++;
				}
			}
		}
		for(int i=2;i<=n;i++) //质因数分解后累乘到答案里 
		{
			while(cnt3[i]!=0)
			{
				temp2=(temp2*i)%998244353ll;
				cnt3[i]--;
			}
		}
//		cout<<temp<<" "<<temp2<<endl;
		ans=(ans+temp2*temp)%998244353ll;
		return ;
	}
	if(step<1||ss>n)
	{
		return ;
	}
	if(step>m)
	{
		while(cnt[step]>0)
		{
			ss++;
			cnt[step]--;
			cnt[step-1]+=2;
		}
		dfs(step-1);
		return ;
	}
	while(cnt[step]>0)
	{
		dfs(step-1);
		ss++;
		cnt[step]--;
		cnt[step-1]+=2;
	}
	dfs(step-1);
	while(cnt[step-1]>1)
	{
		cnt[step-1]-=2;
		cnt[step]++;
		ss--;
	}
	return ;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++)
	{
		v[i]=read();
	}
	f[0]=1ll;
	for(int i=1;i<=m;i++)
	{
		f[i]=f[i-1]<<1;
	}
	int l=n,r=n*f[m];
	for(S=l;S<=r;S++)
	{
		if(count(S)>k) continue;
		memset(cnt,0,sizeof(cnt));
		int t=S,k=-1;
		ss=0;
		while(t!=0)
		{
			k++;
			if(t&1) cnt[k]++,ss++;
			t>>=1;
		}
		dfs(k);
	}
	printf("%lld",ans);
	return 0;
}
