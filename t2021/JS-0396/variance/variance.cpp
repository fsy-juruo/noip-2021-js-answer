#include<bits/stdc++.h>
using namespace std;
int a[100005],n,cnt=0,t=100;
int fc=0,minn=99999999,spj=0,dpj=0;
int pf(int a)
{
	return a*a;
}
/*void dfs(int b[],int spj)
{
	for(int i=2;i<n;i++)
		if(b[i-1]+b[i+1]!=2*b[i]) flag=1;
	if(!flag) return;
	else
	{
		flag=0;
		for(int i=2;i<n;i++)
		{
			b[i]=b[i-1]+b[i+1]-b[i];
			dpj=spj+(b[i-1]+b[i+1]-b[i])/n;
			for(int j=1;j<=n;j++) fc+=pf(b[j]-dpj);
			minn=min(minn,fc);
			printf("%d\n",minn);
			dfs(b,dpj);
			b[i]=a[i];	
		}
	}
	return;
}*/
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=4;i++)
	{
		scanf("%d",&a[i]);
		spj+=a[i];
		a[i]*=4;
	}
	while(t--)
	{
		cnt+=4;
		a[1+(cnt-3)*4]=a[1];
		a[2+(cnt-3)*4]=a[1]+a[3+(cnt-4)*4]-a[2+(cnt-4)*4];
		a[3+(cnt-3)*4]=a[3+(cnt-4)*4];
		a[4+(cnt-3)*4]=a[4];
		dpj=(a[1+(cnt-3)*4]+a[2+(cnt-3)*4]+a[3+(cnt-3)*4]+a[4+(cnt-3)*4])/4;
		fc=pf(a[1+(cnt-3)*4]-dpj)+pf(a[2+(cnt-3)*4]-dpj)+pf(a[3+(cnt-3)*4]-dpj)+pf(a[4+(cnt-3)*4]-dpj);
		minn=min(minn,fc);
		
		a[1+(cnt-2)*4]=a[1];
		a[2+(cnt-2)*4]=a[2+(cnt-4)*4];
		a[3+(cnt-2)*4]=a[2+(cnt-4)*4]+a[4]-a[3+(cnt-4)*4];
		a[4+(cnt-2)*4]=a[4];
		dpj=(a[1+(cnt-2)*4]+a[2+(cnt-2)*4]+a[3+(cnt-2)*4]+a[4+(cnt-2)*4])/4;
		fc=pf(a[1+(cnt-2)*4]-dpj)+pf(a[2+(cnt-2)*4]-dpj)+pf(a[3+(cnt-2)*4]-dpj)+pf(a[4+(cnt-2)*4]-dpj);
		minn=min(minn,fc);
		
		a[1+(cnt-1)*4]=a[1];
		a[2+(cnt-1)*4]=a[2+(cnt-4)*4];
		a[3+(cnt-1)*4]=a[2+(cnt-4)*4]+a[4]-a[3+(cnt-4)*4];
		a[4+(cnt-1)*4]=a[4];
		dpj=(a[1+(cnt-1)*4]+a[2+(cnt-1)*4]+a[3+(cnt-1)*4]+a[4+(cnt-1)*4])/4;
		fc=pf(a[1+(cnt-1)*4]-dpj)+pf(a[2+(cnt-1)*4]-dpj)+pf(a[3+(cnt-1)*4]-dpj)+pf(a[4+(cnt-1)*4]-dpj);
		minn=min(minn,fc);
		
		a[1+cnt*4]=a[1];
		a[2+cnt*4]=a[1]+a[3+(cnt-4)*4]-a[2+(cnt-4)*4];
		a[3+cnt*4]=a[3+(cnt-4)*4];
		a[4+cnt*4]=a[4];
		dpj=(a[1+cnt*4]+a[2+cnt*4]+a[3+cnt*4]+a[4+cnt*4])/4;
		fc=pf(a[1+cnt*4]-dpj)+pf(a[2+cnt*4]-dpj)+pf(a[3+cnt*4]-dpj)+pf(a[4+cnt*4]-dpj);
		minn=min(minn,fc);
	}
	printf("%d",minn/n);
	return 0;
}
