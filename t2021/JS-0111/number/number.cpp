#include<bits/stdc++.h>
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;++i)
#define Rep(i,x,y) for(re int i=x;i>=y;--i)
#define _rep(i,x,y) for(re int i=x;i<y;++i)
#define _Rep(i,x,y) for(re int i=x;i>y;--i)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double db;
template<typename T>inline void read(T&x)
{
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
	x=(f?(-x):x);
}
template<typename T>inline T chkmax(T&x,const T&y){return x=(x>y?x:y);}
template<typename T>inline T chkmin(T&x,const T&y){return x=(x<y?x:y);}
const int N=1e7+10000;
bool chk[105];
bool f[N],g[N],h[N];
int nex[N];
void init()
{
	bool ff=0;int t=0;
	int n=1e7+10;
	rep(i,0,n)
	{
		if(t==0)
		{
			ff=0;
			int x=i;
			x/=100;
			while(x)
			{
				if(x%10==7)
				ff=1;
				x/=10;
			}
		}
		if(!ff&&!chk[t])
		f[i]=0;else f[i]=1;
		g[i]=f[i];
		++t;t=(t==100?0:t);
	}
	int las=0;
	memset(f,0,sizeof(f));
	rep(i,0,n)
	if(!f[i]&&g[i])
	{
		f[i]=1;
		for(int j=(i<<1);j<=n;j+=i)
		f[j]=1;
	}
	rep(i,0,n)
	if(!f[i])
	nex[las]=i,las=i;
//	rep(i,0,100)
//	printf("%d %d\n",i,f[i]);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	rep(i,0,99)
	if(i%10==7||i/10==7)
	chk[i]=1;else chk[i]=0;
	init();
	int T,x;
	read(T);
	while(T--)
	{
		read(x);
		printf("%d\n",(f[x]?-1:nex[x]));
	}
	return 0;
}

