#include <bits/stdc++.h>
using namespace std;
template<typename TT>void read(TT &x){
	x=0;int f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	x*=f;
}
const int maxn=1.1e7+100,maxm=2e5+100;
int a[maxm],nxt[maxn];
bool vis[maxn];
int n,t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(t);
	for(int i=1;i<=t;i++){
		read(a[i]);
		n=max(n,a[i]);
	}
	int p,flag;
	for(int i=1;i<=n+1e6;i++)if(!vis[i]){
		p=i,flag=0;
		while(p){
			if(p%10==7){
				flag=1;
				break;
			}
			p/=10;
		}
		if(flag)for(int j=1;i*j<=n+1e6;j++)vis[i*j]=1;
	}
//	for(int i=1;i<=100;i++)cout<<i<<' '<<vis[i]<<"   ";
	p=0;
	for(int i=n+1e6;i>=1;i--){
		nxt[i]=p;
		if(!vis[i])p=i;
	}
	for(int i=1;i<=t;i++)printf("%d\n",vis[a[i]]?-1:nxt[a[i]]);
	return 0;
}
