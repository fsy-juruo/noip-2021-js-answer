#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
inline void fl()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
}
int a[10005],c[10005];
int main()
{
	fl();
	int n=read(),i;
	for(i=1;i<=n;i++)
		a[i]=read();
	if(n<=10)
	{
		for(i=1;i<n;i++)
			c[i]=a[i+1]-a[i];
		sort(c+1,c+n);
		int maxv=1000000007;
		do
		{
			int ans=0,sum=0;
			for(i=2;i<=n;i++)
				a[i]=a[i-1]+c[i-1];
			for(i=1;i<=n;i++)
			{
				ans+=a[i]*a[i];
				sum+=a[i];
			}
			ans=ans*n-sum*sum;
			maxv=min(maxv,ans);
		}while(next_permutation(c+1,c+n));
		printf("%d",maxv);
	}
	else
		putchar('0');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
