#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int t,cnt2=0,cnt=0,fnum7[N+10],num7[N+10],b[N+10];
void dfs(int num,bool k)
{
	if(num>N) return;
	if(k==1) num7[++cnt]=num,b[num]=1;
	for(int i=0;i<=9;i++)
	{
		if(num==0&&i==0) continue;
		if(k==1) dfs(num*10+i,1);
		else if(i==7) dfs(num*10+i,1);
		else dfs(num*10+i,0);
	}
}
int find(int x)
{
	int l=1,r=cnt2,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(fnum7[mid]>x) r=mid-1,ans=mid;
		else l=mid+1;
	}
	return fnum7[ans];
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	dfs(0,0);
	sort(num7+1,num7+cnt+1);
	int p=cnt;
	for(int i=1;i<=p;i++)
	{
		for(int j=1;num7[i]*j<=N;j++) 
		  if(!b[num7[i]*j])
		   num7[++cnt]=num7[i]*j,b[num7[i]*j]=1;
	}
	sort(num7+1,num7+cnt+1);
	for(int i=1;i<=N;i++)
	{
		if(!b[i]) fnum7[++cnt2]=i;
	}
	scanf("%d",&t);
	while(t--)
	{
		int x;
		scanf("%d",&x);
		if(b[x]) printf("-1");
		else printf("%d",find(x));
		printf("\n");
	}
	return 0;
	
} 
