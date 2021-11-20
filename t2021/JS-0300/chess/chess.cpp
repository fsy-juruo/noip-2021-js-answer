#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=400005;
int h[N],ne[M],e[M],idx;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int lv[N],col[N];
bool st[N];
int T;
int n,m,q;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(h,-1,sizeof h);
		memset(st,false,sizeof st);
		idx=0;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				char x;
				scanf(" %c",&x);
				if(x=='1'){
					add(m*(i-1)+j,m*(i-1)+j+1);
					add(m*(i-1)+j+1,m*(i-1)+j);
				} 
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=m;j++){
				char x;
				scanf(" %c",&x);
				if(x=='1'){
					add(m*(i-1)+j,m*(i-1)+j+m);
					add(m*(i-1)+j+m,m*(i-1)+j);
				}
			}
		}
		while(q--){
			int c,lev,x,y;
			scanf("%d%d%d%d",&c,&lev,&x,&y);
			int id=m*(x-1)+y;
			st[id]=true;
			col[id]=c;
			lv[id]=lev;
			int ans=0;
			for(int i=h[id];~i;i=ne[i]){
				int j=e[i];
				if(!st[j]) ans++;
				else{
					if(col[j]!=c&&lv[j]<=lev) ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
