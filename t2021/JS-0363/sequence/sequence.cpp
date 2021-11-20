#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int i,n,f[110],a[1100],m,k,q[110],p[110];
long long ans,A[50];
long long sqr(int x,int y)
{
  long long p=1;
  for(;x<=y;x++)
    p=p*x%mod;
  return p;
}
long long pos()
{
  long long X,Y,Z; 
  if(n<=12)
  {
  	X=A[n];
  	for(int i=0;i<=m;i++)
  	  X/=A[q[i]];
//  	for(int i=0;i<=m;i++)
//  	  printf("%d ",q[i]);
//  	printf("\n");
  	return X%mod;
  }
  if(n<=22)
  {
  	X=A[12];
  	Y=A[n];
  	for(int i=0;i<=m;i++)
  	{
  	  if(Y%A[q[i]]==0)Y/=A[q[i]];
  	  else X/=A[q[i]];
  	  return X%mod*(Y%mod)%mod;
	}
  }
  X=A[12];
  Y=A[22];
  Z=A[n];
  for(i=0;i<=m;i++)
  {
  	if(Z%A[q[i]]==0)Z/=A[q[i]];
  	else if(Y%A[q[i]]==0)Y/=A[q[i]];
  	else X/=A[q[i]];
  	return (X%mod)*(Y%mod)%mod*(Z%mod)%mod;
  }
}
bool check()
{
  int sum=0;
  memset(f,0,sizeof(f));
  for(int i=1;i<=n;i++)
  {
  	f[p[i]+1]++;
  }
  for(int i=1;i<=m+10;i++)
  {
  	f[i+1]+=f[i]/2;
  	if(f[i]%2==1)sum++;
  }
  if(sum>k)return false;
  else
  {
//  	for(int i=1;i<=n;i++)
//	  printf("%d ",p[i]);
//	printf("\n");
	return true;
  }
}
long long val()
{
  long long k=1;
  for(int i=1;i<=n;i++)
  {
  	k=(k*a[p[i]])%mod; 
  }
//  printf("%d\n",k);
  return k;
}
void calc()
{
  memset(q,0,sizeof(q));
  for(int i=1;i<=n;i++)
    q[p[i]]++;
}
void dfs(int dep,int num)
{
  if(dep>n)
  {
  	calc();
  	if(check())ans=(ans+1ll*val()*pos()%mod)%mod;
  	return;
  }
  if(num==m)
  {
  	calc();
  	for(int i=dep;i<=n;i++)p[i]=m; 
  	if(check())
	  {
	  	ans=(ans+1ll*val()*pos()%mod)%mod;
	  }
    return;
  }
  
  dfs(dep,num+1);
  for(int i=1;i<=n-dep+1;i++)
  {
  	p[i+dep-1]=num;
  	dfs(dep+i,num+1);
  }
}
int main()
{
  freopen("sequence.in","r",stdin);
  freopen("sequence.out","w",stdout);
  scanf("%d%d%d",&n,&m,&k);
  A[1]=1;
  A[0]=1;
  for(i=2;i<=12;i++)A[i]=A[i-1]*i;
  A[13]=1;
  for(i=14;i<=22;i++)A[i]=A[i-1]*i;
  A[23]=1;
  for(i=24;i<=30;i++)A[i]=A[i-1]*i;
  for(i=0;i<=m;i++)
  {
    scanf("%d",&a[i]);
  }
  if(k==n)
  {
    for(i=1;i<=n;i++)
    {
      long long x=1;
      for(int j=1;j<=m;j++)
        x=(x*n)%mod;
      ans=(ans+(x*n)/m%mod)%mod;
	}
	printf("%d\n",ans);
  	return 0;
  }
  dfs(1,0);
  printf("%d\n",ans);
  return 0;
}
