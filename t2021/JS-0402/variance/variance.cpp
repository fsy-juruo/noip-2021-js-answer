#include<bits/stdc++.h>
using namespace std;
#define ll long long
int readint()
{
	char c=getchar(); int neg=1,ret=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) ret=(ret<<3)+(ret<<1)+(c&15);
	return neg*ret;
}
ll readll()
{
	char c=getchar(); ll neg=1,ret=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) ret=(ret<<3)+(ret<<1)+(c&15);
	return neg*ret;
}
void writeint(int x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[15]; int top=0;
	while(x) {int nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void writell(ll x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[25]; int top=0;
	while(x) {ll nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void Writeint(int x,char c) {writeint(x); putchar(c); return;}
void Writell(ll x,char c) {writell(x); putchar(c); return;}
const int maxn=1e4+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int a[maxn],b[maxn];
deque<int> que;
void fl()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
}
int main()
{
	fl();
	int n=readint();
	for(int i=1;i<=n;i++)
		a[i]=readint();
	n--;
	for(int i=1;i<=n;i++)
		b[i]=a[i+1]-a[i];
	sort(b+1,b+n+1); ll ret=INF;
	for(int mask=0;mask<(1<<(n-2));mask++)
	{
		que.clear();
		que.push_back(b[1]);
		que.push_back(b[2]);
		for(int i=3;i<=n;i++)
		{
			if(mask&(1<<(i-3)))
				que.push_front(b[i]);
			else que.push_back(b[i]);
		}
		que.push_front(a[1]);
		ll u=0,v=0;
		for(int i=1;i<=n+1;i++)
		{
			a[i]=a[i-1]+que[i-1];
			u+=a[i];
			v+=1ll*a[i]*a[i];
		}
		ret=min(ret,1ll*(n+1)*v-u*u);
	}
	Writell(ret,'\n');
	return 0;
}


