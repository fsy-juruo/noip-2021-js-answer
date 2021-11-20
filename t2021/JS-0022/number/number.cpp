#include<bits/stdc++.h>
using namespace std;

const int N=10000005,LEN=10000000;
int v[N],a[N];
int t,n;

void init()
{
//	int cnt=0;
	for(int i=1;i<=LEN;i++)
	{
//		if(v[i]) cnt++;
		if(v[i]) continue;
		int tmp=i;
		while(tmp)
		{
			if(tmp%10==7) {v[i]=1;break;}
			tmp/=10;
		}
		if(!v[i]) continue;
//		cnt++;
		for(int j=i+i;j<=LEN;j+=i) v[j]=1;
	}
//	cout<<cnt<<endl;
	a[LEN]=LEN+1;
	for(int i=LEN;i>1;i--)
	{
		if(!v[i]) a[i-1]=i; else a[i-1]=a[i];
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	init();
	while(t--)
	{
		int x;
		scanf("%d",&x);
		if(v[x]) printf("-1\n"); else printf("%d\n",a[x]);
	}
}
