//纵使三度迎来落日，太阳依旧照常升起！
//退役快乐！大学继续！ 
#include<bits/stdc++.h>
using namespace std;

int i,j,n,m,k;
unsigned long long v[104];
unsigned long long ans=0;
bitset <33> h={0}; 
bitset <33> a[33]={0};

int chg(int x)
{   int ans=0;
	int q=1;
	for (i=0;i<=9;i++) 
	{   ans+=a[x][i]*q;
		q*=2;
	}
	return ans;                       //998244353
}

void dfs(int x)
{   unsigned long long tmp=1;
	if (x==k+1) 
	{  for (i=1;i<=n;i++) tmp=(tmp%998244353)*(v[chg(i)]%998244353)%998244353;
	   ans=tmp%998244353;
	   return ;
	}
	
	
	
	return ;
	
}

int main()
{   freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	//for (i=1;i<=m+1;i++) scanf("%d",v[i]);
	dfs(1);
	cout<<ans;
	
	return 0;
}
