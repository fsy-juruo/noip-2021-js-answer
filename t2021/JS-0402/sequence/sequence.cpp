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
const ll mod=998244353;
const int maxn=35;
const int maxk=35;
const int maxm=105;
const int maxmask=35;
int sppcnt[maxmask];
ll a[maxm],binom[maxn][maxn],sum[maxm][maxn][maxk][maxmask];
void add(ll &x,ll y) {x+=y; x-=(x>=mod)*mod; return;}
void fl()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}
int main()
{
//	printf("%.24lf\n",(sizeof(sum))/1024.0/1024.0);
	fl();
	int n=readint(),m=readint(),K=readint();
	m++; for(int i=1;i<=m;i++) a[i]=readll();
	binom[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		binom[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			binom[i][j]=binom[i-1][j-1];
			add(binom[i][j],binom[i-1][j]);
		}
	}
	sum[0][0][0][0]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=K;k++)
				for(int mask=0;mask<32;mask++)
				{
					int nxt=mask; ll cur=1;
					for(int p=0;j+p<=n;p++)
					{
						add(sum[i+1][j+p][k+(nxt&1)][nxt>>1],sum[i][j][k][mask]*binom[n-j][p]%mod*cur%mod);
						nxt++;
						cur=cur*a[i+1]%mod;
					}
				}
	for(int i=1;i<32;i++) sppcnt[i]=sppcnt[i>>1]+(i&1); 
	ll ret=0;
	for(int i=0;i<=K;i++)
		for(int mask=0;mask<32;mask++)
			if(i+sppcnt[mask]<=K)
				add(ret,sum[m][n][i][mask]);
	Writell(ret,'\n');
	return 0;
}
/*
n 较小，第i位不容易对（i+5）及更后的位置造成影响
dp(i,j,k,mask) for the first i elements already used j out of n positions i+1 through i+5 is mask have k 1's: the sum
*/

