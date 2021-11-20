#include<bits/stdc++.h>
using namespace std;
int n,a[10005],d[10005],f[500005],pre[10005],u[10005];
long long ans=3452345234643ll;
bool cmp(int a,int b)
{
	return a>b;
}
int r=time(0);
int ran()
{
	r=(r<<13)+(r<<4)+109;
	return r;
}
void rs()
{
	for(int i=2;i<=n;++i)
		if(ran()&1)
			swap(d[i],d[1]);
}
void solve(int dd)
{
	memset(f,0,sizeof(f));
	--n;
	if(dd==1)
		sort(d+1,d+n+1);
	else
		if(dd==2)
			sort(d+1,d+n+1,cmp);
		else
			rs();
	f[0]=1;
	for(int i=1;i<=n;++i)
		for(int j=a[n+1]-a[1];j>=d[i];--j)
			if(!f[j]&&f[j-d[i]])
				f[j]=i;
	int x=(a[n+1]-a[1])/2,cnt=0;
	while(!f[x])
		--x;
	while(x)
		u[f[x]]=1,pre[++cnt]=d[f[x]],x-=d[f[x]];
	sort(pre+1,pre+cnt+1,cmp);
	int tmp=cnt;
	for(int i=1;i<=n;++i)
		if(!u[i])
			pre[++cnt]=d[i];
	sort(pre+tmp+1,pre+cnt+1);
	++n;
	for(int i=2;i<=n;++i)
		a[i]=a[i-1]+pre[i-1];
	/*for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
	for(int i=1;i<=n;++i)
		printf("%d ",d[i]);*/
	long long xx=0,y=0;
	for(int i=1;i<=n;++i)
		xx+=a[i],y+=(long long)n*a[i]*a[i];
	ans=min(ans,y-xx*xx);
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<n;++i)
		d[i]=a[i+1]-a[i];
	for(int i=1;i<=10000/n;++i)
		solve(i);
	printf("%lld\n",ans);
}
