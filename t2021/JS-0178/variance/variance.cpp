#include<cstdio>
#include<cctype>
#include<cmath>
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
int a[10005];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int i,n,cnt;
	double mid,aver=0,sum=0;
	n=qr();
	for (i=1;i<=n;i++)
		a[i]=qr();
	mid=(a[1]+a[n])/2.0;
	do
	{
		cnt=0;
		for (i=2;i<n;i++)
			if (fabs(mid-a[i-1]-a[i+1]+a[i])
			<fabs(mid-a[i]))
			{
				cnt++;
				a[i]=a[i-1]+a[i+1]-a[i];
			}
	}
	while (cnt);
	for (i=1;i<=n;i++)
		aver+=a[i];
	aver/=n;
	for (i=1;i<=n;i++)
		sum+=(aver-a[i])*(aver-a[i]);
	sum*=n;
	printf("%d\n",(int)sum);
	return 0;
}
