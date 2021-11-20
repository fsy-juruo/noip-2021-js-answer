#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
#define MP make_pair
using namespace std;
typedef long long ll;

inline void read(int &x) {
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}
const int N=2e5+10,M=4e5+10;
int T,n,m,q,preused[N],used[N],ans,cnt,precnt,rep;
int col,lv,x,y;
int chcol[N],chlv[N];
int head[N],ne;
bool vis[N],previs[N];
char s[N];
struct Edge {
	int v,w,dir,nxt;
}e[M<<1];
inline void init() {
	memset(head,-1,sizeof(head));
	ne=0;
}
inline void add_edge(int u,int v,int w,int dir) {
	e[ne].v=v;
	e[ne].w=w;
	e[ne].dir=dir;
	e[ne].nxt=head[u];
	head[u]=ne++;
}
inline void ins_edge(int u,int v,int w,int dir) {
	add_edge(u,v,w,dir);
	add_edge(v,u,w,dir);
}
inline int get(int x,int y) {
	return m*(x-1)+y;
}
inline bool check(int pos) {
	return !chlv[pos]||lv>=chlv[pos]&&col!=chcol[pos];
}
void dfs2(int id,int predir) {
	//cout<<"***"<<id<<endl;
	vis[id]=true;
	used[++cnt]=id;
	if(previs[id]) {
		rep++;
	}
	else {
		previs[id]=true;
		preused[++precnt]=id;
	}
	if(chlv[id]) return;
	for(int i=head[id];~i;i=e[i].nxt) {
		if(e[i].w!=2||predir!=-1&&e[i].dir!=predir) continue;
		int v=e[i].v;
		if(!vis[v]&&check(v)) {
			dfs2(v,e[i].dir);
		}
	}
}
void dfs3(int id) {
	//cout<<"***"<<id<<endl;
	vis[id]=true;
	used[++cnt]=id;
	if(previs[id]) {
		rep++;
	}
	else {
		previs[id]=true;
		preused[++precnt]=id;
	}
	if(chlv[id]) return;
	for(int i=head[id];~i;i=e[i].nxt) {
		if(e[i].w!=3) continue;
		int v=e[i].v;
		if(!vis[v]&&check(v)) {
			dfs3(v);
		}
	}
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while(T--) {
		read(n);read(m);read(q);
		init();
		memset(chlv,0,sizeof(chlv));
		for(int i=1;i<=n;i++) {
			scanf("%s",s+1);
			for(int j=1;j<m;j++) {
				if(s[j]!='0') ins_edge(get(i,j),get(i,j+1),s[j]-48,0);
			}
		}
		for(int i=1;i<n;i++) {
			scanf("%s",s+1);
			for(int j=1;j<=m;j++) {
				if(s[j]!='0') ins_edge(get(i,j),get(i+1,j),s[j]-48,1);
			}
		}
		while(q--) {
			read(col);read(lv);read(x);read(y);
			ans=0;
			precnt=0;
			int id=get(x,y);
			
			for(int i=head[id];~i;i=e[i].nxt) {
				if(e[i].w==1&&check(e[i].v)) {
					ans++;
					previs[e[i].v]=true;
					preused[++precnt]=e[i].v;
				}
			}
			
			cnt=0;
			rep=0;
			dfs2(id,-1);
			for(int i=1;i<=cnt;i++) vis[used[i]]=false;
			ans+=cnt-1-rep;
			
			cnt=0;
			rep=0;
			dfs3(id);
			for(int i=1;i<=cnt;i++) vis[used[i]]=false;
			ans+=cnt-rep;
			
			for(int i=1;i<=precnt;i++) previs[preused[i]]=0;
			chcol[id]=col;
			chlv[id]=lv;
			printf("%d\n",ans);
		}
	}
//	cout<<endl<<endl;
//	for(int i=0;i<ne;i++) {
//		printf("%d %d %d %d\n",e[i].u,e[i].v,e[i].w,e[i].dir);
//	}
	return 0;
}

