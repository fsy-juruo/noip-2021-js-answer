#include<bits/stdc++.h>
using namespace std;
inline int read();
int n;
typedef unsigned long long ULL;
const int N=1e4+7;
ULL ans=0x7f7f7f7f7f7f7f;
//bool pd[N][N];
int a[N];
//map<int *,bool>ma;
void check()
{
	int tot=0;
	for(int i=1;i<=n;++i)
	{
		tot+=a[i];
	}
	ULL res=0;
	ULL hhh=(tot*tot);
	for(int i=1;i<=n;++i)
	{
//		pd[i][a[i]]=1;
		res+=a[i]*a[i]*n-((tot*a[i])<<1);
//		cout<<a[i]<<" ";
	}
	res+=hhh;
//	cout<<res<<"\n";
	if(res<ans)ans=res;
}
void dfs(int k)
{
	if(k==n)
	{
		check();
	}
	else
	{
		for(int i=1;i<=2;++i)
		{
			if(i==1)
			{
				dfs(k+1);
			}
			if(i==2)
			{
				int temp=a[k];
				a[k]=(a[k-1]+a[k+1]-a[k]);
				dfs(k+1);
				a[k]=temp;
			}
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
	}
//	check();
	dfs(2);
	cout<<ans;
	return 0;
}




inline int read()
{
	int s=0;bool w=1;
	char c;
	while(c<'0'||c>'9'){if(c=='-')w=0;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return w?s:-s;
}
