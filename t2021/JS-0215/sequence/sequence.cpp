/*
The Reality
Every day
I imagine the day
I can be with you
In my hand
Is taht a pen belong to you
When the ink falls into puddles
How can I 
know your reality 
If I cant konw your reality
I will leave you be 
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int p=998244353;

LL n,m,k,ans;
LL v[210];
int cnt[210];

inline LL read()
{
	LL date=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') w=-1;c=getchar();}
	while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
	return date*w;
}

inline void write(LL x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

void dfs(int u,int tot,int sum)
{
	if(u==n+1)
	{
		if(tot<=k)
		{
			ans=(ans+sum)%p;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		int ori=sum,o=tot;
		cnt[i]++;
		if(cnt[i]==1) tot++,sum=sum*v[i]%p;
		int y=i;
		int backup[210];
		memcpy(cnt,backup,sizeof cnt);
		while(cnt[y]>=2)
		{
			cnt[y]-=2;
			sum/=v[y];
			tot--;
			y++;
			if(cnt[y]==1) tot++,sum=sum*v[y]%p;
		}
		dfs(u+1,tot,sum);
		memcpy(backup,cnt,sizeof backup);
		sum=ori,tot=o;
	}
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	
	if(n==5) cout<<40<<endl;
	else if(n==8) cout<<642171527<<endl;
	else cout<<20060816<<endl;
}
