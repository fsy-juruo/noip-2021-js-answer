// hyh ak ioi
#include <bits/stdc++.h>
using namespace std;

#define N 20000007
#define F(i,l,r) for(int i=l;i<=r;++i)
#define D(i,r,l) for(int i=r;i>=l;--i)
#define MEM(x,a) memset(x,a,sizeof(x))
#define FK(x) MEM(x,0)
int I()
{
	int x=0; char c=getchar(); bool f=0;
	while(!isdigit(c)) c=getchar(),f=(c=='-');
	while(isdigit(c)) x=(x*10+c-'0'),c=getchar();
	return f?-x:x;
}

bool notp[N]; int pr[N/10];
bool __c[10005];
bool cxk[N]; int nx[N];
void init()
{
//	clock_t t1=clock();
	int n=10000005;
	notp[1]=1; int&c=pr[0];
	F(i,2,n)
	{
		if (!notp[i])
		{
			pr[++c]=i;
		}
		for(int j=1;j<=c and i*pr[j]<=n;++j)
		{
			int u=pr[j];
			notp[i*u]=1;
			if (i%u==0)
			{
				break;
			}
		}
	}	
	F(i,1,9999)
	{
		int x=i; __c[i]=0;
		while(x) __c[i]|=(x%10==7),x/=10;
	}
	F(i,1,n)
	{
		int x=i; cxk[i]=0;
		while(x) cxk[i]|=(__c[x%10000]),x/=10000; // O(1)
	}
	F(i,1,pr[0])
	{
		int u=pr[i];
		F(j,1,n/u)
		{
			cxk[j*u]|=cxk[j];
		}
	}
	nx[n+1]=n+1;
	D(i,n,1)
	{
		nx[i]=nx[i+1];
		if (!cxk[i+1]) nx[i]=i+1;
	}
	
//	puts("init done");
//	clock_t t2=clock();
//	printf("%d\n",t2-t1);
	
}


void flandre()
{
	int t=I();
	while(t--)
	{
		int x=I();
		if (cxk[x])
		{
			puts("-1");
		}
		else
		{
			printf("%d\n",nx[x]);
		}	
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	flandre();
	return 0;
}

