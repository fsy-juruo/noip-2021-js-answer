#include<cstdio>
#include<cctype>
const int R=10000010;
int T,n,nxt[R];
bool vis[R];
bool check(int x)
{
	while(x)
	{
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
void sieve()
{
	for(int i=1;i<R;i++)
	{
		if(vis[i]) continue;
		if(check(i)&&!vis[i])
			for(int j=1;j*i<R;j++) vis[i*j]=true;
	}
	return ;
}
void prework()
{
	for(int i=R-5;i;i--)
	{
		if(vis[i+1]) nxt[i]=nxt[i+1];
		else nxt[i]=i+1;
	}
	return ;
}
int qread()
{
	int x=0;
	char c='\0';
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-48;;
	return x;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	sieve();
	prework();
	T=qread();
	while(T--)
	{
		n=qread();
		if(vis[n]) printf("-1\n");
		else printf("%d\n",nxt[n]);
	}
	return 0;
}
