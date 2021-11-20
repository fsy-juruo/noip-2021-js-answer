#include<bits/stdc++.h>
using namespace std;
int T;
const int NM=5010;
struct qizi{
	bool exist;
	int lv;
	int cl;
}c[NM];
int n,m,q;
int code(int x,int y){
	return (x-1)*m+y;
}
struct EDGE{
	int nxt;
	int to;
	int tp;
}edge[4*NM];
int cnt,head[NM];
bool vis[NM];
void add(int u,int v,int tp){
	edge[cnt].to=v;
	edge[cnt].tp=tp;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
}
void init(){
	for(int i=1;i<=n*m;i++) c[i].exist=false;
	for(int i=1;i<=n*m;i++) head[i]=-1;
	for(int i=1;i<=n*m;i++) vis[i]=false;
	cnt=0;
}
int cl,lv,x,y;
char s[5010];
struct inq{
	int first;
	int second;
	bool way;
};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		init();
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m-1;j++){
				int type;
				type=s[j]-'0';
				add(code(i,j),code(i,j+1),type);
				add(code(i,j+1),code(i,j),type);
			}
		}
		for(int i=1;i<=n-1;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++){
				int type;
				type=s[j]-'0';
				add(code(i,j),code(i+1,j),type);
				add(code(i+1,j),code(i,j),type);
			}
		}
		for(int i=1;i<=q;i++){
			memset(vis,false,sizeof(vis));
			scanf("%d%d%d%d",&cl,&lv,&x,&y);
			vis[code(x,y)]=true;
			queue<inq> q;
			for(int i=head[code(x,y)];i!=-1;i=edge[i].nxt){
				int to=edge[i].to;
				int type=edge[i].tp;
				if(!type) continue;
				if(c[to].exist){
					if(cl!=c[to].cl&&lv>=c[to].lv){
						vis[to]=true;
					}
					continue;
				}
				vis[to]=true;
				q.push((inq){to,type,(abs(to-code(x,y))==1)});
			}
			while(!q.empty()){
				inq u=q.front();
				q.pop();
				for(int i=head[u.first];i!=-1;i=edge[i].nxt){
					int to=edge[i].to;
					int type=edge[i].tp;
					if(vis[to]) continue;
					if(!type) continue;
					if(type!=u.second) continue;
					if(type==1) continue;
					if(type==2){
						if((abs(u.first-to)==1)==u.way){
							if(c[to].exist){
					if(cl!=c[to].cl&&lv>=c[to].lv){
						vis[to]=true;
					}
					continue;
				}
							vis[to]=true;
							q.push((inq){to,type,u.way});
						}
					}
					if(type==3){
						if(c[to].exist){
					if(cl!=c[to].cl&&lv>=c[to].lv){
						vis[to]=true;
					}
					continue;
				}
						vis[to]=true;
						q.push((inq){to,type,u.way});
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n*m;i++) ans+=vis[i];
			ans--;
			printf("%d\n",ans);
			c[code(x,y)].exist=true;
			c[code(x,y)].cl=cl;
			c[code(x,y)].lv=lv;
		}
	}
	return 0;
}

