#include<bits/stdc++.h>
using namespace std;
int i,n,m,j,k,a[1000100],p[20000100],tot;
bool check(int x)
{
  while(x>0)
  {
  	if(x%10==7)return true;
  	x/=10;
  }
  return false;
} 
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  	scanf("%d",&a[i]);
  	m=max(m,a[i]);
  }
  m=m+10;
  for(i=1;i<=m;i++)
  {
  	if(p[i]==-1)continue;
    if(check(i))
	{
	  p[i]=-1;
	  for(j=i;j<=m;j+=i)
	    if(j<=m)p[j]=-1;
	}
	else p[i]=i;
  }
  bool f=1;
  for(i=1;i<=m;i++)
  {
  	if(p[i]==-1&&f)
  	{
  	  f=0;
  	  k=i;
	}
	if(!f&&p[i]==i)
	{
	  for(;k<=i;k++)
	    p[k]=i;
	}
  }
//  for(i=m-199990;i<=m;i++)if(p[i]!=-1){printf("%d\n",i);break;}
  for(i=1;i<=n;i++)
  {
  	if(p[a[i]]==a[i])printf("%d\n",p[a[i]+1]);
  	else printf("-1\n");
  }
  return 0;
}
