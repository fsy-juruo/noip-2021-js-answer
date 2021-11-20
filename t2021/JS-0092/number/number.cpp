#include<bits/stdc++.h>
using namespace std;
int read()
{
	int res=1,num=0;
	char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') res=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){num=num*10+ch-'0';ch=getchar();}
	return res*num;
}
int t;
int x;
const int N=2e5+5;
int p[N+10];
int sum[N+10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	for(int i=1;i<=N;i++)
	{
		int tmp=i;
		while(tmp)
		{
			if(tmp%10==7)
			{
				p[i]=1;
				break;
			}
			tmp/=10;
		}
		if(p[i]==1) continue;
		tmp=i;
		for(int j=2;j*j<=tmp;j++)
		{
			if(tmp%j==0)
			{
				if(p[j]==1||p[tmp/j]==1)
				{
					p[i]=1;
					break;
				}
			}
		}
	}
//	for(int i=1;i<=199;i++)
//		if(p[i]==0) printf("%d ",i);
//	puts("");
	for(int i=1;i<=N;i++)
		sum[i]=sum[i-1]+((p[i]+1)%2);
	while(t--)
	{
		x=read();
		if(p[x]==1)
		{
			printf("-1\n");
			continue;
		}
		int s=sum[x];
		int l=x,r=N,mid,p1=N;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(sum[mid]>s)
			{
				p1=mid;
				r=mid-1;
			}else l=mid+1;
		}
		printf("%d\n",p1);
	}
	return 0;
}
