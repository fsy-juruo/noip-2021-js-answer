#include <bits/stdc++.h>
using namespace std;
bool a[10000005];
int b[10000005];
int T,n;
int x=-1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	a[10000000]=false;
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				for(int l=0;l<=9;l++)
					for(int o=0;o<=9;o++)
						for(int p=0;p<=9;p++)
							for(int q=0;q<=9;q++)
							{
								x++;
								if(a[x]==true) continue;
								if(i==7||j==7||k==7||l==7||o==7||p==7||q==7)
								{
									int d=1;
									while(x*d<=9999999)
										a[x*d]=true,d++;
									continue;
								}
							}
	b[10000001]=10000001;
	int w=10000001;
	for(int i=10000000;i>=0;i--)
	{
		if(a[i]==true)
			b[i]=w;
		else
		{
			w=i;
			b[i]=w;
		}
	}
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		if(a[n]==true) printf("%d\n",-1);
		else printf("%d\n",b[n+1]);
	}
	return 0;
} 
