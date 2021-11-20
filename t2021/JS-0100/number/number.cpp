#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*y;
}
int n,t,a[10000005],s[10000005],cnt,p=1,b[1000005],num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	for(int i=1;i<=10000000;i++)
	{
		int tmp=i;
		while(tmp)
		{
			if(tmp%10==7)
			{
				a[tmp]=1;
				s[++cnt]=i;
				break;
			}
			tmp/=10;
		}
	}
	for(int i=1;i<=sqrt(10000000);i++)
	{
		if(s[p]!=i&&a[i]==1) continue;
		if(s[p]!=i)
			for(int j=p;j<=cnt;j++)
				if(s[j]*i>10000000) break;
				else a[s[j]*i]=1;			
		if(s[p]==i)
		{
			for(int j=i;j<=10000000;j++)
				if(i*j>10000000) break;
				else a[j*i]=1;
			p++;
		}
	}
	for(int i=1;i<=10000000;i++)
		if(a[i]==0)
		{
			b[++num]=i;
//			printf("%d\n",i);
		}
	b[++num]=10000001;
	while(t--)
	{
		n=read();
		if(a[n]) puts("-1");
		else printf("%d\n",b[upper_bound(b+1,b+num+1,n)-b]);
	}
}
