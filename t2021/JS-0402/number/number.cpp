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
const int maxn=1e7+10;
const int maxall=8e5+5;
bool ok[maxn];
int all[maxall];
void fl()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
int main()
{
	fl();
	int maxx=1e7+5,tot=0;
	for(int i=1;i<=maxx;i++)
	{
		if(ok[i]) continue;
		int x=i;
		while(x)
		{
			if(x%10==7)
			{
				ok[i]=true;
				break;
			}
			x/=10;
		}
		if(ok[i])
		{
			for(int j=i+i;j<=maxx;j+=i)
				ok[j]=true;
		}
		if(!ok[i]) all[++tot]=i;
	}
	int n=readint();
	while(n--)
	{
		int x=readint();
		if(ok[x]) {Writeint(-1,'\n'); continue;}
		int y=all[(int)(upper_bound(all+1,all+tot+1,x)-all)];
		Writeint(y,'\n');
	}
	return 0;
}


