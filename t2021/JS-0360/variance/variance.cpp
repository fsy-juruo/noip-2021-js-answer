#include<bits/stdc++.h>
#define LL long long
#define IL inline
#define RE register int
using namespace std;

const int N=10000;
const int INF=2147483647;

int n,sum,ave,mind,nowd,ans;
int a[N+5],d[N+5];
bool vis[N];

IL void read(RE &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f?-x:x;
}

IL int abs(int x,int y){return x<=y?y-x:x-y;}

IL void dfs(int x)
{
	if(x>=n) return;
	if(vis[x-1]) return;
	
	RE k=a[x-1]+a[x+1]-a[x];
	if(k>=a[x-1]&&k<=a[x+1]){
		vis[x]=1;
		ave+=(k-a[x])/n;a[x]=k;
		RE tot=0;
		for(RE i=1;i<=n;i++){
			RE t=abs(a[i]-ave);cout<<t*t<<" ";
			tot+=t*t;
		}cout<<endl;
		ans=min(ans,tot/n);
		dfs(x+1);
		a[x]=a[x-1]+a[x+1]-k;
		ave+=(k-a[x])/n;
		vis[x]=0;
	}
	
	dfs(x+1);
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(RE i=1,x;i<=n;i++){
		read(x);a[i]=x*n;
		sum+=a[i];
	}
	ave=sum/n;
	for(RE i=1;i<=n;i++){
		d[i]=abs(a[i]-ave);
		mind+=d[i];
		ans+=d[i]*d[i];
	}
	dfs(2);
	printf("%d\n",ans);
	return 0;
}
