#include<bits/stdc++.h>
#define ALL(v) v.begin(),v.end()
#define srt(v) sort(ALL(v))
#define rALL(v) v.rbegin(),v.rend()
#define rsrt(v) sort(rALL(v))
#define rev(v) reverse(ALL(v))
#define sz(v) (int)(v.size())
#define inf 0x3f3f3f3f
#define eps 1e-9
#define pii pair<int,int>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
inline int sqr(int x)
{
	return x*x;
}
int C(int a,int b,int c,int d)
{
	int sum=a+b+c+d;
	return (sqr(a*4-sum)+sqr(b*4-sum)+sqr(c*4-sum)+sqr(d*4-sum))/4;
}
int C(vector<int> v)
{
	int sum=0;
	for(int i=0;i<sz(v);i++)
		sum+=v[i];
	int var=0;
	for(int i=0;i<sz(v);i++)
		var+=sqr(sum-v[i]*sz(v));
	return var/sz(v);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==4)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int ans=C(a,b,c,d);
		ans=min(ans,min(C(a,a+c-b,c,d),C(a,b,b+d-c,d)));
		ans=min(ans,min(C(a,a+c-b,a+d-b,d),C(a,a+d-c,b+d-c,d)));
		ans=min(ans,C(a,a+d-c,a+d-b,d));
		printf("%d\n",ans);
	}
	else
	{
		vector<int> v(n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		printf("%d\n",C(v));
	}
	return 0;
}
