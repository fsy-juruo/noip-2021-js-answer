#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int a[10010];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n=read();
	long long sum=0,sum2=0;
	for(int i=0;i<n;i++)
	{
		a[i]=read();
		sum+=a[i];
		sum2+=a[i]*a[i];
	}
	long long ans=9999999999999999;
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			long long tmp=a[j];
			a[j]=a[j+1]+a[j-1]-a[j];
			sum2-=tmp*tmp;
			sum2+=a[j]*a[j];
			sum-=tmp;
			sum+=a[j];
			int tmp2=n*sum2-sum*sum;
			ans=ans>tmp2?tmp2:ans;
		}
	}
	printf("%d",ans);
	
	return 0;
	//freopen
	//大小写
	//return
	//文件名
}

