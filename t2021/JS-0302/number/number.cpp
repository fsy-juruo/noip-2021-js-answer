#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read(){
	int x=0,sign=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-'){
		sign=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*sign;
}
bool vis[10000050];
int pre[10000050],nxt[10000050];
int maxn=0,a[200005];
void work(int x){
	for(int i=1;i*x<=maxn;i++){
		if(!vis[i*x]){
			vis[i*x]=1;
			nxt[pre[i*x]]=nxt[i*x];
			pre[nxt[i*x]]=pre[i*x];
		}
	}
}
void solve(){
	for(int i=1;i<=maxn;i++){
		if(vis[i]) continue;
		int itp=i;
		while(itp>0){
			if(itp%10==7){
				work(i);
				break;
			}
			itp/=10;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		maxn=max(maxn,a[i]);
	}
	maxn=min(maxn+1000003,10000010);
	for(int i=1;i<=maxn;i++){
		pre[i]=i-1;
		nxt[i]=i+1;
	}
	solve();
	for(int i=1;i<=n;i++){
		if(vis[a[i]]) printf("-1\n");
		else printf("%d\n",nxt[a[i]]);
	}
//	for(int i=10000000;;i++){
//		if(!vis[i]){
//			printf("%d %d ",i,nxt[i]);
//			break;
//		}
//	}
//	int maxx=0;
//	for(int i=1;i<=10000000;i++){
//		if(!vis[i]) maxx=max(maxx,nxt[i]-i);
//	}
//	printf("%d",maxx);
	
	
	return 0;
}
