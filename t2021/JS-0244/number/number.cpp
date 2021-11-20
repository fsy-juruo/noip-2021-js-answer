#include<bits/stdc++.h>
using namespace std;
#define x1 xabncasd
#define x2 xajsklddasd
#define y1 ydakldjsakdsa 
#define y2 yajslkdsadsa
#define fi first 
#define se second
#define mp make_pair
const int N=1e7+100;
int n;
int a[N];
int c[200005];
int b[N];
int d[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,T;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&c[i]);
		n=max(n,c[i]);
	}
	if(n<=200000)
	{
		n=200005;
	}
	else
	{
		n=N-50;
	}
	int tot=0;
	for(i=1;i<=n;i++)
	{
		int tmp=i;
		while(tmp)
		{
			if(tmp%10==7)
			{
				a[++tot]=i;
				b[i]=1;
				break;
			}
			tmp=tmp/10;
		}
	}
//	cout<<tot<<endl;
	for(i=1;i<=tot;i++)
	{
		for(j=2;j*a[i]<=n;j++)
		{
			b[a[i]*j]=1;
		}
	}
	int tot2=0;
	for(i=1;i<=n;i++)
	{
		if(!b[i]) 
		{
			tot2++;
			d[tot2]=i;
		}
	}
//	for(i=1;i<=tot2;i++)
//	{
//		printf("%d ",d[i]);
//	}
	for(i=1;i<=T;i++)
	{
		int pos=lower_bound(d+1,d+tot2,c[i])-d;
		if(d[pos]!=c[i]) printf("-1\n");
		else printf("%d\n",d[pos+1]);
	}
	return 0;
}
