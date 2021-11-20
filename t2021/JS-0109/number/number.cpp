#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read()
{
	ll res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=getchar();
	return res*f;
}

const int N=20000007;
const int n=10000005;

bool seven[N],ban[N];
int nxt[N];

void Init()
{
	int omi=1;
	for(int i=1;i<=7;i++)
	{
		int se=omi*7;
		for(int j=0;j<omi;j++)
		{
			int k=0;
			while(1)
			{
				int x=k*omi*10+se+j;
				if(x>n)
					break;
				seven[x]=1;
				k++;
			}
		}
		omi*=10;
	}
	for(int i=1;i<=n;i++)
	{
		if(!seven[i])
			continue;
		for(int j=i;j<=n;j+=i)
			ban[j]=1;
	}
//	cout<<ban[10000001];
	int cur=n;
	for(int i=n;i;i--)
		if(!ban[i])
			nxt[i]=cur,cur=i;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	Init();
	int t=read();
	while(t--)
	{
		int x=read();
		if(ban[x])
			puts("-1");
		else
			printf("%d\n",nxt[x]);
	}
	
	return 0;
}
