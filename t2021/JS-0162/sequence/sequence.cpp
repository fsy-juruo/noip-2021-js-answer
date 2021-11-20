#include<bits/stdc++.h>
using namespace std;
long long n,ans,C[1005][1005],val[1005][1005];
int m,K,cnt[1005];
const long long mo=998244353;
bool check(long long x)
{
	int p=0;
	//cout<<x<<' ';
	while(x>0)
	{
		if(x%2==1) p++;
		x/=2;
	}
	//cout<<p<<endl;
	return (p<=K);
}
void zh()
{
	C[0][1]=C[1][1]=C[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		C[i][i]=C[i][0]=1;
		for(int j=1;j<i;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
			//cout<<i<<' '<<j<<' '<<C[i][j]<<endl;
		}
	}
}
void calc()
{
	int lef=n;long long sum1=1,sum2=1;
	for(int i=0;i<=m;i++)
	{
		if(cnt[i]==0) continue;
		sum1=(sum1*C[lef][cnt[i]])%mo;
		lef-=cnt[i];
		sum2=(sum2*val[i][cnt[i]])%mo;
		//sol[len].push_back(b[i]);
	}
	ans=(ans+(sum1*sum2)%mo)%mo;
}
void fj(int dep,long long num,int lst,long long lstv)
{
	if(num<0) return;
	if(dep==n+1)
	{
		if(num==0)
		{
			//cout<<1;
			calc();
		} 
		return;
	}
	int i=lst;long long t=lstv;
	while(t<=num&&i<=m)
	{
		cnt[i]++;
		fj(dep+1,num-t,i,t);
		cnt[i]--;
		i++;
		t*=2;
	}
}
void fw()
{
	long long T=1;
	for(int i=1;i<=m;i++)
		T*=2;
	for(long long i=n;i<=n*T;i++)
	{
		if(check(i))
		{
			//cout<<i<<endl;
			fj(1,i,0,1);
		}	
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>K;
	zh();
	for(int i=0;i<=m;i++)
	{
		cin>>val[i][1];
		val[i][1]%=mo;
		for(int j=2;j<=n;j++)
		{
			val[i][j]=(val[i][j-1]*val[i][1])%mo;
			//cout<<i<<' '<<j<<' '<<val[i][j]<<endl;
		}
	}
	fw();
	cout<<ans<<endl;
	return 0;
}
/*
5 1 1
2 1*/