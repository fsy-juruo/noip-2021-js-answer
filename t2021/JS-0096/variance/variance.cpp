#include <bits/stdc++.h>
#define re register
#define SIZE 10005
#define INF 0x3f3f3f3f
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f;char c;
	x=0;f=0;c=getchar();
	while(c<'0' || '9'<c)	f|=(c=='-'),c=getchar();
	while('0'<=c && c<='9')	x=(x<<3)+(x<<1)+c-48,c=getchar();
	x=f?-x:x;
}
int n;
int a[SIZE],s[SIZE];
int ans=INF;
inline void Debug()
{
	for(re int i=1;i<=n;++i)
		cout<<s[i]<<" ";
	cout<<endl;
}
map<vector<int>,int> vis;
vector<int> now;
inline void dfs(int d,int sum,int Sa)
{
	ans=min(ans,sum);
	if(vis[now])
		return;
	vis[now]=1;
	for(re int i=2;i<n;++i)
	{
		int x=2*s[i]-s[i-1]-s[i+1];
		int y=(n-1)*(s[i-1]+s[i+1])+2*s[i]-2*Sa;
		if(x*y)
		{
			int t=s[i];
			s[i]=s[i-1]+s[i+1]-s[i];
			now[i-1]=s[i];
			dfs(d+1,sum-x*y,Sa-t+s[i]);
			s[i]=t;
			now[i-1]=t;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(re int i=1;i<=n;++i)
		read(a[i]),s[i]=a[i],now.push_back(s[i]);
	int S=0,tot=0;//LL?
	for(re int i=1;i<=n;++i)
	{
		S+=s[i];
		tot+=s[i]*s[i];
	}
	tot=n*tot-S*S;
	dfs(1,tot,S);
	printf("%d\n",ans);
	return 0;
}
/*
9
6 19 25 31 2 14 6 32 1

*/
