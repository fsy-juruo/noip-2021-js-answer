#include<bits/stdc++.h>
using namespace std;
inline void openfiles()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
}
const int N=100005;
inline int rd()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*y;
}
int n,a[N],sum,ans;
inline int min(const int &a,const int &b){return a<b?a:b;}
inline int points()
{
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=(a[i]*n-sum)*(a[i]*n-sum);
	return cnt/n; 
}
inline void check()
{
	puts("--");
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n%d\n",points());
	puts("--\n");
}
inline unsigned long long Hash()
{
	unsigned long long cnt=0;
	for(int i=1;i<=n;i++)cnt=cnt+1ll*(a[i]*a[i-1]-a[i+2]+a[i+1]*a[i-1]);
	return cnt;
}
set<unsigned long long>s;
inline void dfs(int pos)
{
	int aft=a[pos-1]+a[pos+1]-a[pos];
	sum=sum-a[pos]+aft;
	a[pos]=aft;
	unsigned long long res=Hash();
	if(s.count(res)==0)
	{
		ans=min(ans,points());
		s.insert(res);
		for(int i=2;i<n;++i)if(i!=pos)dfs(i);
	}
	a[pos]=a[pos-1]+a[pos+1]-aft;
	sum=sum-aft+a[pos];
	return;
}
int main()
{
	openfiles();
	s.clear();
	n=rd();
	for(int i=1;i<=n;++i)
	{
		a[i]=rd();
		sum+=a[i];
	}
	s.insert(Hash());
	ans=points();
	for(int i=2;i<n;++i)dfs(i);
	printf("%d\n",ans);
	return 0;
}
/*

*/

