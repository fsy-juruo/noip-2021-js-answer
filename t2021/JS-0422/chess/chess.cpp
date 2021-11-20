#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int t,n,m,q,col,lv,x,y,ans,tmp;
char c;
struct Edge{
	int v,w,nxt;
	int flag;
}e[N>>4];
int head[N],ne;
void add_edge(int u,int v,int w,int flag){
	e[ne].v=v;e[ne].w=w;e[ne].flag=flag;
	e[ne].nxt=head[u];head[u]=ne++;
}
bool vis[N];
struct Node{
	int col,lv;
}a[N];
bool check(int x,int y){
	if(a[y].lv==0)return true;
	if(a[y].col!=a[tmp].col&&a[tmp].lv>=a[y].lv)return true;
	return false;
}
void dfs(int x,int r,int d){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int v=e[i].v,w=e[i].w;
		if(!check(tmp,v))continue;
		vis[v]=true;
		if(r==0&&w==1){
			ans++;
		}else if(w==2){
			if(r==0){
				ans++;dfs(v,2,e[i].flag);
			}else if(r==2&&d==e[i].flag){
				ans++;dfs(v,2,e[i].flag);
			}
		}else if(w==3){
			if(r==0||r==3){
				ans++;dfs(v,3,e[i].flag);
			}
		}
	}
}
int main(){
	//freopen("chess.in","r",stdin);
	//freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&q);
		ne=0;memset(head,-1,sizeof head);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				cin>>c;if(c=='0')continue;
				int tmp=(i-1)*m+j;
				add_edge(tmp,tmp+1,c-'0',1);
				add_edge(tmp+1,tmp,c-'0',1);
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=m;j++){
				cin>>c;if(c=='0')continue;
				int tmp=(i-1)*m+j;
				add_edge(tmp,tmp+m,c-'0',-1);
				add_edge(tmp+m,tmp,c-'0',-1);
			}
		}
		while(q--){
			scanf("%d%d%d%d",&col,&lv,&x,&y);
			tmp=(x-1)*m+y;
			a[tmp].col=col;a[tmp].lv=lv;
			memset(vis,0,sizeof vis);
			vis[tmp]=true;ans=0;dfs(tmp,0,0);
			printf("%d\n",ans);
		}
	}
	return 0;
} 
