#include<bits/stdc++.h>
using namespace std;

long long n,m,k;
long long v[105];
long long smin,smax;
long long maybe[2000005];
long long change[110];
long long two[105];
//int realchange[110];
long long num1=0;
long long ans123m[2505][1005];
long long anslength[2505];
long long numbertype[2505][115];
long long quanzhi[2505];

inline long long read()
{
	int res=0,t=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') 
	{
		if(ch='-') t=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*t;
}

inline void zhuanhua(int kk)
{
	num1=0;
//	memset(realchange,-1,sizeof(realchange));
	memset(change,-1,sizeof(change));
	num1=1;
	while(kk)
	{
		num1++;
		change[num1]=kk%2;
		kk/=2;
	}
//	for(int i=num1;i>=1;i--)
//	{
//		int j=i-num1+1;
//		realchange[i-num1+1]=change[i];
//	}
}

inline long long check(int mm)
{
	while(mm)
	{
		if(mm%2!=0) num1++;
		mm>>1; 
	}
	return num1;
}

int main()
{
	freopen("sequence.in","r",stdin);	
	freopen("sequence.out","w",stdout);
memset(ans123m,-1,sizeof(ans123m));
memset(anslength,-1,sizeof(anslength));
memset(quanzhi,1,sizeof(quanzhi));
	n=read();
	m=read();
	k=read();
	for(long long i=1;i<=m+1;i++)
	{
		v[i]=read();
	}
	smin=n;
	long long cnt=1;
	two[0]=1;
	for(long long i=1;i<=m;i++)
	{
		cnt*=2;
		two[i]=cnt;
	}
	smax=n*cnt;
	long long numk=0;
	long long num=0;
	for(long long i=smin;i<=smax;i++)
	{
		num1=0;
		zhuanhua(i);
		for(long long i=1;i<=num1;i++)
		{
			if(change[i]==1) numk++;
		}
		if(numk<=k) maybe[++num]=i;
	}
	long long nn=0;
	long long numclone=num;
	for(long long i=num;i>=1;i--)
	{
		for(long long j=m;j>=0;j--)
		{
			if(maybe[i]>=two[j]&&maybe[i]-two[i]>=num-1) 
			{
				maybe[i]-=two[j];
				ans123m[i][++nn]=j;
				anslength[i]++;
				num--;
			}
			else continue;
		}
		if(nn!=n)
		{
			for(long long j=1;j<=nn;j++)
			{
				ans123m[i][j]=-1;
			}
			anslength[i]=-1;
			continue;
		}
	}
	long long xulieshu[2005];
	memset(xulieshu,1,sizeof(xulieshu));
	for(long long i=1;i<=numclone;i++)
	{
		if(anslength[i]==-1) continue;
		else
		{
			for(long long j=1;j<=anslength[i];j++)
			{
				numbertype[i][ans123m[i][j]]++;
				quanzhi[i]*=two[ans123m[i][j]];
			}
			for(long long j=1;j<=numbertype[i][0];j++)
			{
				xulieshu[i]*=(n-j+1);
				xulieshu[i]/=j;
			}
		}
	}
	long long sum=0;
	for(long long i=1;i<=numclone;i++)
	{
		if(anslength[i]==-1) continue;
		else
		{
			sum+=quanzhi[i]*xulieshu[i];
			sum%=998244353;
		}
	}
	printf("%lld\n",sum);
	
	
	return 0;
}
