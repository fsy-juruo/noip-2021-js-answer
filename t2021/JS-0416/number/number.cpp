#include<bits/stdc++.h>
using namespace std;
const int mxn=10000005;
int a[mxn+5],nxt[mxn+5];
int h(int x)
{
	while(x)
		if(x%10==7)
			return 1;
		else
			x/=10;
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=mxn;++i)
		if(!a[i]&&h(i))
			for(int j=i;j<=mxn;j+=i)
				a[j]=1;
	for(int i=mxn;i>=1;--i)
		if(!a[i+1])
			nxt[i]=i+1;
		else
			nxt[i]=nxt[i+1];
	for(int i=1;i<=t;++i)
	{
		int x;
		scanf("%d",&x);
		if(a[x])
			puts("-1");
		else
			printf("%d\n",nxt[x]);
	}
	return 0;
}

