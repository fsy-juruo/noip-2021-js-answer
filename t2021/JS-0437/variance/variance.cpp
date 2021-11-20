#include<bits/stdc++.h>
using namespace std;
int n;
struct P12
{
	int a[5],ans=100000000;
	bool f[45][45];
	void dfs(int x1,int x2,int x3,int x4)
	{
		if(f[x2][x3])return;
		f[x2][x3]=1;
		int ave=(x1+x2+x3+x4)/4,cnt=(x1-ave)*(x1-ave)+(x2-ave)*(x2-ave)+(x3-ave)*(x3-ave)+(x4-ave)*(x4-ave);
		cnt/=4;
		ans=min(ans,cnt);
//		cout<<cnt<<endl;
		dfs(x1,x1+x3-x2,x3,x4);
		dfs(x1,x2,x2+x4-x3,x4);
	}
	void solve()
	{
		scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
		a[1]*=4;a[2]*=4;a[3]*=4;a[4]*=4;
		dfs(a[1],a[2],a[3],a[4]);
		printf("%d\n",ans);
	}
}p12;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	if(n==4)p12.solve();
	return 0;
}
