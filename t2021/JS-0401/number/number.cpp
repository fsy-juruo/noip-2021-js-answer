#include <bits/stdc++.h>
#define ll int
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 10000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		ret=(ret*10+(c-48));
		c=getchar();
	}
	return ret;
}
void rout(ll x){
	if(x<10) putchar(48+x);
	else rout(x/10),putchar(48+(x%10));
	return;
}
bool isok[N],vis[N];
ll ans[N];
bool chk7(ll x)
{
	while(x>0)
	{
		if(x%10==7)
		{
			return false;
		}
		x/=10;
	}
	return true;
}
void prework()
{
	ll i,j;
	for(i=0;i<N;++i)
	{
		vis[i]=isok[i]=chk7(i);
	}
	for(i=7;i<N;++i)
	{
		if(!isok[i])
		{
			for(j=i+i;j<N;j+=i)
			{
				vis[j]=false;
			}
		}
	}
	ans[N-1]=N-1;
	for(i=N-1;i>0;--i)
	{
		ans[i-1]=ans[i];
		if(vis[i])
		{
			ans[i-1]=i;
		}
	}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	prework();
	ll T=rint();
	while(T--)
	{
		ll x=rint();
		if(vis[x])
		{
			rout(ans[x]),putchar('\n');
		}
		else
		{
			putchar('-'),putchar('1'),putchar('\n');
		}
	}
	return 0;
}
