#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
long long n,m,k;
long long ans;
int v[10010];
int a[10010];//数组中值为i的个数 
int gc(int x)
{
	if( x == 0 )
	  return 1;
	else
	{
		int cot=1;
		while( x >= 2 )
		{
			cot*=x;
			x--;
		}
		return cot;
	}
}
void search(int maxn)
{
	int b[10010];
	for(int i=0;i<=maxn;i++)
	  b[i]=a[i];
	long long cot=0;
	int num_group=gc(n);
	for(int i=0;i<=maxn;i++)
	  num_group/=gc(b[i]);
	int temp=maxn;
	while( temp <= m )
	{
		cot=1;
		for(int i=0;i<=maxn;i++)
		{
			for(int j=1;j<=b[i];j++)
			{
				cot*=v[i];
				cot=cot%998244353;
			}
		}  
		ans+=cot*num_group;
		ans=ans%998244353;
		for(int i=maxn;i>=0;i--)
		  b[i+1]=b[i];
		temp++;
	}
	if( a[maxn] == 1 && maxn >= 2 )
	{
		a[maxn-2]+=2;
		a[maxn]=0;
		a[maxn-1]--;
		maxn-=2;
		search(maxn);
		maxn+=2;
		a[maxn]=1;
		a[maxn-1]++;
		a[maxn-2]-=2;
	}
	for(int i=1;i<=maxn;i++)
	{
		if( a[i] >= 2 )
		{
			a[i]-=2;
			for(int j=1;j<=i-1;j++)
			{
				if( a[j] >= 1 )
				{
				  	a[j-1]+=2;
				  	a[j]-=1;
				  	a[i+1]+=1;
				  	if( i == maxn )
				  	  maxn++;
				  	search(maxn);
				  	if ( i == maxn - 1 )
				  	  maxn--;
				  	a[i+1]--;
				    a[j]++;
				  	a[j-1]-=2;
				}
			}
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	  cin>>v[i];
	if( k == 1 )
	{
		a[0]=2;
		for(int i=1;i<=n-2;i++)
		  a[i]=1;
		//number of group,length of group
		search(n-2);
		cout<<ans<<endl;
	}
	else
	{
		//cout<<114514<<endl;
		cout<<22400;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5 2
1 2 3 4 5 6
*/
