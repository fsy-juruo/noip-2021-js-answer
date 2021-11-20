#include <bits/stdc++.h>
#define ll long long
//const int N=;
int read()
{   int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return x*f;
}
int n;
int a[110],v[1000000];
double ans=1000.0;
int hash()
{
	int s=0;
	for(int i=1;i<=n;i++)
	{
		s=s*3+a[i];
	}
	return s;
}
void dfs()
{
	if(v[hash()]) return;
	v[hash()]=1;
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",a[i]);
//	}puts("");
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
//	printf("dd");
	double aver=sum/n;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(a[i]-aver)*(a[i]-aver)*n;
	}
	if(sum<ans) ans=sum;
//	printf("%.2f\n",ans);
	for(int i=2;i<n;i++)
	{
		int m=a[i];
		a[i]=(a[i-1]+a[i+1]-a[i]);
		if(a[i]<a[i-1]||a[i]>a[i+1]||a[i]==m) 
		{
			a[i]=m;
			continue;
		}
		else dfs();
		a[i]=m;
	}
}
int main(){
  freopen("variance.in","r",stdin);
  freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
//		scanf("%f",a[i]);
	}
	dfs();
	printf("%.0f",ans);
	return 0;
}
//4
//1 2 4 6
