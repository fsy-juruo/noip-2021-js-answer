#include<bits/stdc++.h>
#define LL long long
using namespace std;
void read(int &x)
{
	x=0;bool flg=0;char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') flg=1;else x=c^48;c=getchar();
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	if(flg) x=-x;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
void writeln(int x)
{
	write(x);
	puts("");
}
const int mx=1e7+1;
bool vis[mx+5];
int prm[mx/10],tot,v[mx+5];
int nxt[mx+5],pre;
bool check(int x)
{
	bool ret=1;
	while(x&&ret)
	{
		ret&=x%10!=7;
		x/=10;
	}
	return ret;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vis[1]=1;
	for(int i=2;i<=mx;i++)
	{
		vis[i]=1;
		if(!v[i]) prm[v[i]=++tot]=i;
		for(int j=1;j<=v[i];j++)
		{
			if(prm[j]*i>mx) break;
			v[prm[j]*i]=v[i];
		}
	}
	for(int i=1;i<=mx;i++)
	{
		if(vis[i]) vis[i]=check(i);
		if(vis[i]) continue;
		for(int j=1;j<=tot;j++)
		{
			if(prm[j]*i>mx) break;
			vis[i*prm[j]]=0;
		}
	}
	for(int i=1;i<=mx;i++)
	{
		if(!vis[i]) nxt[i]=-1;
		else nxt[pre]=i,pre=i;
	}
	int T,x;
	read(T);
	while(T--)
	{
		read(x);
		writeln(nxt[x]);
	}
	return 0;
}

