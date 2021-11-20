#include <bits/stdc++.h>
using namespace std;
int n;
long long total;
struct ccf{
	long long p[405];
	long long total;
}a[10005];
long long minn(long long o,long long p)
{
	if(o>p) return p;
	return o;
}
int b[405];
int head,tail=1;
bool check(int k,long long d)
{
	for(int i=0;i<=tail-1;i++)
	{
		bool flag=true;
		for(int j=1;j<=n;j++)
			if(j!=k)
			{
				if(a[head].p[j]!=a[i].p[j])
				{
					flag=false;
					break;
				}
			}
			else
			{
				if(a[i].p[j]!=d)
				{
					flag=false;
					break;
				}
			}
		if(flag) return false;
	}
	return true;
}
bool check2(int k,long long d)
{
	if((a[head].p[k]==a[head].p[k-1]||a[head].p[k]==a[head].p[k+1])&&(!(a[head].p[k]==a[head].p[k-1]&&a[head].p[k]==a[head].p[k+1])))
		return true;
	long long vau1=0,vau2=0;
	long long total2=a[head].total+(d-a[head].p[k])/n;
	for(int i=1;i<=n;i++)
	{
		vau1+=abs(a[head].p[i]-a[head].total)*abs(a[head].p[i]-a[head].total);
		if(k==i)
			vau2+=abs(d-total2)*abs(d-total2);
		else
			vau2+=abs(a[head].p[i]-total2)*abs(a[head].p[i]-total2);
	}
	if(vau1>vau2) return true;
	return false;
}
void rd(int i,long long k)
{
	for(int j=1;j<=n;j++)
		if(j!=i)
		{
			a[tail].p[j]=a[head].p[j];
		}
		else
		{
			a[tail].p[j]=k;
		}
	a[tail].total=a[head].total+(k-a[head].p[i])/n;
	tail++;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		total+=b[i];
		b[i]*=n;
	}
	for(int i=1;i<=n;i++)
	{
		a[0].p[i]=b[i];
	}
	a[0].total=total;
	while(head<tail)
	{
		for(int i=2;i<=n-1;i++)
		{
			long long c=a[head].p[i-1]+a[head].p[i+1]-a[head].p[i];
			if(check(i,c)&&check2(i,c))
			{
				rd(i,c);
			}
		}
		head++;
	}
	long long ans=1000000000000;
	for(int i=0;i<=tail-1;i++)
	{
		long long anss=0;
		for(int j=1;j<=n;j++)
			anss+=abs(a[i].p[j]-a[i].total)*abs(a[i].p[j]-a[i].total);
		ans=minn(ans,anss);
	}
	cout<<ans/n<<endl;
	return 0;
}
