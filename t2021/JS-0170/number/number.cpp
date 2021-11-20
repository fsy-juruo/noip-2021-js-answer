#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=1e7;

int T;
int p[N];
bool st[N];

int read()
{
	int f=1,x=0;
	char c=getchar();
	
	while(c<'0'||c>'9')
	{
		f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

bool check(int x)
{
	while(x)
	{
		int t=x%10;
		if(t==7) return true;
		x/=10;
	}
	return false;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int cnt=0;
	for(int i=1;i<=N;i++)
	{
		if(!st[i]&&check(i))
		{
			for(int j=1;j*i<=N;j++)
				st[j*i]=1;
		}
		if(!st[i]) p[cnt++]=i;
	}
	
	T=read();
	while(T--)
	{
		int x=read();
		int l=0,r=cnt-1;
		while(l<r)
		{
			int mid=l+r>>1;
			if(x<=p[mid]) r=mid;
			else l=mid+1;
		}
		if(p[l]!=x) printf("-1\n");
		else printf("%d\n",p[l+1]);
	}
	
	return 0;	
}
