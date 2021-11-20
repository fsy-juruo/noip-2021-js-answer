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
void write(LL x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
void writeln(LL x)
{
	write(x);
	puts("");
}
set<vector<int> > mp;
vector<int> a;
LL ans=1<<15;
int n;
void dfs(LL sum1,LL sum2)
{
	mp.insert(a);
	ans=min(ans,sum2*n-sum1*sum1);
	for(int i=1;i<n-1;i++)
	{
		if(a[i]==a[i-1]+a[i+1]) continue;
		int t1=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		int t2=a[i];
		if(mp.count(a)) continue;
		dfs(sum1-t1+t2,sum2-t1*t1+t2*t2);
		a[i]=a[i-1]+a[i+1]-a[i];
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	LL sum1=0,sum2=0;
	for(int i=1,x;i<=n;i++)
	{
		read(x);
		a.push_back(x);
		sum1+=x,sum2+=x*x;
	}
	dfs(sum1,sum2);
	writeln(ans);
	return 0;
}

