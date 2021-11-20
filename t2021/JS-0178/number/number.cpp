#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
int qr()
{
	int f=1,r=0;
	char ch;
	do
		ch=getchar();
	while (!isdigit(ch)&&ch!='-');
	if (ch=='-')
		f=-1;
	else
		r=ch-48;
	ch=getchar();
	while (isdigit(ch))
	{
		r=r*10+ch-48;
		ch=getchar();
	}
	return f*r;
}
bool b[10000005];
int a[200005],sum[10000005],useful[10000005];
void getse(int bnd)
{
	int i,j,tmp;
	for (i=1;i<=bnd;i++)
	{
		if (b[i])
			continue;
		tmp=i;
		while (tmp>0)
		{
			if (tmp%10==7)
			{
				b[i]=1;
				break;
			}
			tmp/=10;
		}
		if (b[i])
			for (j=i;j<=bnd;j+=i)
				b[j]=1;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,i,maxn=-2021,tot=0;
	const int BIG=10000001;
	T=qr();
	for (i=1;i<=T;i++)
	{
		a[i]=qr();
		maxn=max(maxn,a[i]);
	}
	getse(min(maxn*2,BIG));
	for (i=1;i<=min(maxn*2,BIG);i++)
		if (!b[i])
			useful[++tot]=i;
	sum[1]=2;
	for (i=2;i<=min(maxn*2,BIG);i++)
		sum[i]=sum[i-1]+(!b[i]);
	for (i=1;i<=T;i++)
	{
		if (b[a[i]])
			printf("-1\n");
		else
			printf("%d\n",useful[sum[a[i]]]);
	}
	return 0;
}
