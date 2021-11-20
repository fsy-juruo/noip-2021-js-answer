#include<stdio.h>
#define N 10000001
typedef long long ll;
using namespace std;
template<typename qwq> void read(qwq &a)
{
	a=0;char c=getchar();int x=1;
	for	(;c<'0'||c>'9';c=getchar())	x=c=='-'?-x:x;
	for	(;c>='0'&&c<='9';a=(a<<1)+(a<<3)+(c^48),c=getchar());
	a*=x;
}
template<typename qwq> void write(qwq a)
{
	if	(a>9)	write(a/10);
	putchar(a%10+48);
}
template<typename qwq> void twrite(qwq a)
{
	if	(a<0)	putchar('-'),write(-a);
		else	write(a);
}
template<typename qwq> void writeln(qwq a)
{
	twrite(a),puts("");
}
bool inp[N+5],is7[N+5],no[N+5];
int pr[N+5],ptot,s7[N+5],tot7,ans[N+5];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	inp[1]=true;
	for	(int i=1;i<=N;i++)
		{
			is7[i]=(is7[i/10])||(i%10==7);
			if	(no[i]||!is7[i])	continue;
			no[i]=is7[i];
			int sx=N/i;
			for	(int j=2;j<=sx;j++)	no[i*j]=true;
		}
	int aa=-1;
	for	(int i=N;i>=1;i--)
		{
			ans[i]=no[i]?-1:aa;
			aa=no[i]?aa:i;
		}
	int T;read(T);
	for	(int i=1;i<=T;i++)
		{
			int x;read(x);
			writeln(ans[x]);
		}
	return 0;
}

