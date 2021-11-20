#include <bits/stdc++.h>
#define lint long long
using namespace std;
const int maxn=10005;
int sum1,sum2,ans=INT_MAX,n,a[maxn],b[maxn];
int g[100005][105],cn;
//map <string,bool> m;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool check()
{
	for(int i=1;i<=cn;i++)
	{
		bool flag=false;
		for(int j=1;j<=n;j++)
		{
			if(b[j]!=g[i][j])
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
		return true;
	}
	cn++;
	for(int i=1;i<=n;i++)
	{
		g[cn][i]=b[i];
	}
	return false;
}
//bool check()
//{
//	string s;
//	for(int i=2;i<n;i++)
//	{
//		s[i]=b[i];
//	}
//	if(m[s])
//	return true;
//	m[s]=true;
//	return false;
//}
void dfs(int fa,int sm1,int sm2)
{
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",b[i]);
//	}
//	puts("");
	ans=min(ans,n*sm1-sm2*sm2);
//	int p=0;
//	int smm1=0,smm2=0;
//	for(int i=1;i<=n;i++)
//	{
//		smm1+=b[i]*b[i];
//		smm2+=b[i];
//	}
//	p=smm2;
//	for(int i=1;i<=n;i++)
//	{
//		smm1+=(n*b[i]-p)*(n*b[i]-p);
//	}
//	if(smm1/n!=n*sm1-sm2*sm2)
//	printf("A");
//	if(smm1!=sm1||smm2!=sm2)
//	printf("a");
//	ans=min(ans,n*smm1-smm2*smm2);
	for(int i=2;i<n;i++)
	{
		if(i!=fa)
		{
			int y=b[i];
			b[i]=b[i+1]+b[i-1]-b[i];
			if(!check())
			{
				dfs(i,sm1-y*y+b[i]*b[i],sm2-y+b[i]);
			}
			b[i]=y;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
    {
    	a[i]=read();
    	b[i]=a[i];
    	sum1+=a[i]*a[i];
    	sum2+=a[i];
	}
	dfs(0,sum1,sum2);
	printf("%d",ans);
	return 0;
}

