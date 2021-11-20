#include<bits/stdc++.h>
using namespace std;
int n,p[10000001],a[1000001],c[1000001],k,t,x,b[10000001];
void read(int &x)
{
	int f=1;char ch;
	while(ch=getchar(),!isdigit(ch))if(ch=='-')f=-1;x=ch-'0';
	while(ch=getchar(),isdigit(ch))x=(x<<3)+(x<<1)+ch-'0';x*=f;
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
void writeln(int x)
{
	write(x);
	putchar('\n');
}
int check(int n)
{
	int gw=0;
	while(n)
	{
		gw=n%10;
		if(gw==7)return 1;
		n/=10;
	}
	return 0;
}
void init()
{
	for(int i=7;i<=n;i++)
	{
		if(p[i]==1)continue;
		if(check(i))
		{
			for(int j=1;j*i<=n;j++)
			{
				p[j*i]=1;
			}
		}
	}
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
//	int m=clock();
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		read(a[i]);
		n=max(n,a[i]);
	}
	n=min(n*2,10000002);
	init();
	for(int i=7;i<=n;i++)
	{
		if(p[i]==1)k++,c[k]=i;
	}
	x=n;
	for(int i=n;i>=1;i--)
	{
		if(p[i]==0)
		{
			
			b[i]=x;
			x=i;
		}
		else
		{
			b[i]=x;
		}
	}

	for(int i=1;i<=t;i++)
	{
		if(p[a[i]]==1)
		{
			writeln(-1);
			continue;
		}
		/*int l=1,r=k,mid=1,ans=1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(c[mid]>=a[i])
			{
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		cout<<c[ans]<<' '<<b[c[ans]]<<endl;*/
		else
		{
			writeln(b[a[i]]);
		}
	
	}
//	cout<<n<<' '<<clock()-m<<endl; 
	return 0;
}

