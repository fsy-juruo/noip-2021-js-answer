#include<bits/stdc++.h>
using namespace std;
namespace FIFO{
//char buf[1<<23],*p1=buf,*p2=buf;
//#define gc() (p1==p2&&(p2=buf+fread(p1=buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define gc() getchar()
void read(int&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
void print(int x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
}using namespace FIFO;
int T_T,n,m,Q,tim[200100],lev[200100],col[200100],X[200100],Y[200100],ord[200100],id[200100];
char S[200100],*s[200100],T[200100],*t[200100];
int dsu[200100],sz[200100],blk[200100];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){x=find(x),y=find(y);if(x==y)return;dsu[x]=y,sz[y]+=sz[x];}
vector<int>v[200100]; 
int res[200100];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int nex(int x,int y,int d){
	if(x+dx[d]>=n||y+dy[d]>=m||x+dx[d]<0||y+dy[d]<0)return 0;
	if(d==0)return t[x][y]-'0';
	if(d==1)return s[x][y]-'0';
	if(d==2)return t[x-1][y]-'0';
	if(d==3)return s[x][y-1]-'0';
}
int ent[200100],lea[200100],tot;
void dfs(int x){ent[x]=++tot;for(auto y:v[x])dfs(y);lea[x]=tot;}
struct BIT{
	int t[200100];
	void reset(){memset(t,0,sizeof(t));}
	void ADD(int x,int y){while(x<=tot)t[x]+=y,x+=x&-x;}
	int SUM(int x){int y=0;while(x)y+=t[x],x-=x&-x;return y;} 
}bit[2];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T_T);
	while(T_T--){
		read(n),read(m),read(Q);
		s[0]=S;for(int i=0;i<n;i++)scanf("%s",s[i]),s[i+1]=s[i]+m-1;
		t[0]=T;for(int i=0;i+1<n;i++)scanf("%s",t[i]),t[i+1]=t[i]+m;
		for(int i=0;i<n*m;i++)tim[i]=Q+1;
		for(int i=1;i<=Q;i++)
			read(col[i]),read(lev[i]),read(X[i]),X[i]--,read(Y[i]),Y[i]--,ord[i]=i,tim[X[i]*m+Y[i]]=i;
		for(int i=0;i<n*m;i++)dsu[i]=i,sz[i]=1,v[i].clear();
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			if(tim[i*m+j]<=Q)continue;
			if(nex(i,j,0)==3&&tim[(i+1)*m+j]>Q)merge(i*m+j,(i+1)*m+j);
			if(nex(i,j,1)==3&&tim[i*m+(j+1)]>Q)merge(i*m+j,i*m+(j+1));
		}
		for(int i=0;i<n*m;i++)blk[i]=dsu[i];
//		for(int i=0;i<n*m;i++)printf("%d ",blk[i]);puts("");
		for(int i=Q;i;i--){
			int x=X[i],y=Y[i],p=x*m+y;
			for(int t=0;t<4;t++)if(nex(x,y,t)==3){
				int xx=x+dx[t],yy=y+dy[t];
				if(tim[xx*m+yy]<i)continue;
				int q=find(xx*m+yy);
//				printf("%d:%d,%d\n",i,p,q);
				if(p==q)continue;
				dsu[q]=p,v[p].push_back(q),sz[p]+=sz[q];
			}
			res[i]=sz[p]-1;
		}
//		for(int i=1;i<=Q;i++)printf("%d ",res[i]);puts("");
//		puts("IN");
		tot=0;for(int i=0;i<n*m;i++)if(dsu[i]==i)dfs(i);
		sort(ord+1,ord+Q+1,[](int x,int y){return lev[x]<lev[y];});
		for(int l=1,r=1;l<=Q;){
			for(;r<=Q&&lev[ord[r]]==lev[ord[l]];r++){
				int i=ord[r],x=X[i],y=Y[i],p=x*m+y;
				for(int t=0;t<4;t++)if(nex(x,y,t)==3){
					int xx=x+dx[t],yy=y+dy[t],q=xx*m+yy;
					if(tim[q]<i)continue;
					bit[col[i]].ADD(ent[blk[q]],1);
					bit[col[i]].ADD(ent[p],-1);
				}
			}
			for(;l<r;l++){
				int i=ord[l],x=X[i],y=Y[i],p=x*m+y;
				res[i]+=bit[!col[i]].SUM(lea[p])-bit[!col[i]].SUM(ent[p]-1);
			}
		}
//		for(int i=1;i<=Q;i++)printf("%d ",res[i]);puts("");
		for(int i=1;i<=Q;i++){
			int x=X[i],y=Y[i],p=x*m+y;
			for(int t=0;t<4;t++)if(nex(x,y,t)==1){
				int xx=x+dx[t],yy=y+dy[t],q=xx*m+yy;
				if(ent[p]<=ent[blk[q]]&&lea[blk[q]]<=lea[p])continue;
				if(tim[q]>i){res[i]++;continue;}
				if(lev[tim[q]]>i||col[tim[q]]==col[i])continue;
				bool ok=true;
				for(auto r:v[q])if(ent[p]<=ent[r]&&lea[r]<=lea[p]){ok=false;break;}
				res[i]+=ok;
			}
		}
		for(int i=1;i<=Q;i++)print(res[i]),putchar('\n');
		for(int t=0;t<2;t++)bit[t].reset();
	}
	return 0;
} 
/*#include<bits/stdc++.h>
using namespace std;
namespace FIFO{
//char buf[1<<23],*p1=buf,*p2=buf;
//#define gc() (p1==p2&&(p2=buf+fread(p1=buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define gc() getchar()
void read(int&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
void print(int x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
}using namespace FIFO;
int T_T,n,m,Q,tim[200100],lev[200100],col[200100],X[200100],Y[200100],ord[200100],id[200100];
char S[200100],*s[200100],T[200100],*t[200100];
int dsu[200100],sz[200100],blk[200100];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){x=find(x),y=find(y);if(x==y)return;dsu[x]=y,sz[y]+=sz[x];}
vector<int>v[200100],u[200100]; 
int res[200100];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int nex(int x,int y,int d){
	if(x+dx[d]>=n||y+dy[d]>=m||x+dx[d]<0||y+dy[d]<0)return 0;
	if(d==0)return t[x][y]-'0';
	if(d==1)return s[x][y]-'0';
	if(d==2)return t[x-1][y]-'0';
	if(d==3)return s[x][y-1]-'0';
}
int ent[200100],lea[200100],tot;
void dfs(int x){ent[x]=++tot;for(auto y:v[x])dfs(y);lea[x]=tot;}
struct BIT{
	int t[200100],len;
	void reset(){for(int i=1;i<=len;i++)t[i]=0;len=0;}
	void ADD(int x,int y){while(x<=len)t[x]+=y,x+=x&-x;}
	int SUM(int x){int y=0;while(x)y+=t[x],x-=x&-x;return y;} 
}bit[2],tib;
int stk[200100],tp;
bool reach(int p,int q){
	if(ent[p]<=ent[blk[q]]&&lea[blk[q]]<=lea[p])return false;
	if(tim[q]>tim[p])return true;
	if(lev[tim[q]]>lev[tim[p]]||col[tim[q]]==col[tim[p]])return false;
	for(auto r:v[q])if(ent[p]<=ent[r]&&lea[r]<=lea[p])return false;
	return true;
}
int LAS[200100];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T_T);
	while(T_T--){
		read(n),read(m),read(Q);
		s[0]=S;for(int i=0;i<n;i++)scanf("%s",s[i]),s[i+1]=s[i]+m-1;
		t[0]=T;for(int i=0;i+1<n;i++)scanf("%s",t[i]),t[i+1]=t[i]+m;
		for(int i=0;i<n*m;i++)tim[i]=Q+1;
		for(int i=1;i<=Q;i++)
			read(col[i]),read(lev[i]),read(X[i]),X[i]--,read(Y[i]),Y[i]--,ord[i]=i,tim[X[i]*m+Y[i]]=i;
		for(int i=0;i<n*m;i++)dsu[i]=i,sz[i]=1,v[i].clear();
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			if(tim[i*m+j]<=Q)continue;
			if(nex(i,j,0)==3&&tim[(i+1)*m+j]>Q)merge(i*m+j,(i+1)*m+j);
			if(nex(i,j,1)==3&&tim[i*m+(j+1)]>Q)merge(i*m+j,i*m+(j+1));
		}
		for(int i=0;i<n*m;i++)blk[i]=dsu[i];
//		for(int i=0;i<n*m;i++)printf("%d ",blk[i]);puts("");
		for(int i=Q;i;i--){
			int x=X[i],y=Y[i],p=x*m+y;
			for(int t=0;t<4;t++)if(nex(x,y,t)==3){
				int xx=x+dx[t],yy=y+dy[t];
				if(tim[xx*m+yy]<i)continue;
				int q=find(xx*m+yy);
//				printf("%d:%d,%d\n",i,p,q);
				if(p==q)continue;
				dsu[q]=p,v[p].push_back(q),sz[p]+=sz[q];
			}
			res[i]=sz[p]-1;
		}
//		for(int i=1;i<=Q;i++)printf("%d ",res[i]);puts("");
//		puts("IN");
		tot=0;for(int i=0;i<n*m;i++)if(dsu[i]==i)dfs(i);
		bit[0].len=bit[1].len=tot;
		sort(ord+1,ord+Q+1,[](int x,int y){return lev[x]<lev[y];});
		for(int l=1,r=1;l<=Q;){
			for(;r<=Q&&lev[ord[r]]==lev[ord[l]];r++){
				int i=ord[r],x=X[i],y=Y[i],p=x*m+y;
				for(int t=0;t<4;t++)if(nex(x,y,t)==3){
					int xx=x+dx[t],yy=y+dy[t],q=xx*m+yy;
					if(tim[q]<i)continue;
					bit[col[i]].ADD(ent[blk[q]],1);
					bit[col[i]].ADD(ent[p],-1);
				}
			}
			for(;l<r;l++){
				int i=ord[l],x=X[i],y=Y[i],p=x*m+y;
				res[i]+=bit[!col[i]].SUM(lea[p])-bit[!col[i]].SUM(ent[p]-1);
			}
		}
//		for(int i=1;i<=Q;i++)printf("%d ",res[i]);puts("");
		for(int i=1;i<=Q;i++){
			int x=X[i],y=Y[i],p=x*m+y;
			for(int t=0;t<4;t++)if(nex(x,y,t)==1){
				int xx=x+dx[t],yy=y+dy[t],q=xx*m+yy;
				res[i]+=reach(p,q);
			}
		}
		tib.len=tot;
		for(int i=0;i<n;i++){
			stk[tp=0]=-1;
			for(int j=0;j<m;j++){
				if(tim[i*m+j]>Q)continue;
				while(tp&&tim[i*m+stk[tp]]>tim[i*m+j])tp--;
				LAS[j]=stk[tp],res[i*m+j]+=j-LAS[j]-1;
				if(LAS[j]!=-1)u[LAS[j]].push_back(i*m+j);
				if(stk[tp]!=-1)res[tim[i*m+j]]+=reach(i*m+j,i*m+stk[tp]);
				stk[++tp]=j;
			}
			for(int j=0;j<m;j++){
				if(tim[i*m+j]<=Q)res[tim[i*m+j]]-=tib.SUM(lea[i*m+j])-tib.SUM(ent[i*m+j]-1);
				tib.ADD(blk[i*m+j],1);
				for(auto x:u[j])res[tim[x]]+=tib.SUM(lea[x])-tib.SUM(ent[x]-1);
				u[j].clear();
			}
			for(int j=0;j<m;j++)tib.ADD(blk[i*m+j],-1);
		}
		for(int i=0;i<n;i++){
			stk[tp=0]=m;
			for(int j=m-1;j>=0;j--){
				if(tim[i*m+j]>Q)continue;
				while(tp&&tim[i*m+stk[tp]]>tim[i*m+j])tp--;
				LAS[j]=stk[tp],res[i*m+j]+=j-LAS[j]-1;
				if(LAS[j]!=m)u[LAS[j]].push_back(i*m+j);
				if(stk[tp]!=m)res[tim[i*m+j]]+=reach(i*m+j,i*m+stk[tp]);
				stk[++tp]=j;
			}
			for(int j=m-1;j>=0;j--){
				if(tim[i*m+j]<=Q)res[tim[i*m+j]]-=tib.SUM(lea[i*m+j])-tib.SUM(ent[i*m+j]-1);
				tib.ADD(blk[i*m+j],1);
				for(auto x:u[j])res[tim[x]]+=tib.SUM(lea[x])-tib.SUM(ent[x]-1);
				u[j].clear();
			}
			for(int j=0;j<m;j++)tib.ADD(blk[i*m+j],-1);
		}
		for(int j=0;j<m;j++){
			stk[tp=0]=-1;
			for(int i=0;i<n;i++){
				if(tim[i*m+j]>Q)continue;
				while(tp&&tim[stk[tp]*m+j]>tim[i*m+j])tp--;
				LAS[i]=stk[tp],res[i*m+j]+=j-LAS[i]-1;
				if(LAS[i]!=-1)u[LAS[i]].push_back(i*m+j);
				if(stk[tp]!=-1)res[tim[i*m+j]]+=reach(i*m+j,stk[tp]*m+j);
				stk[++tp]=j;
			}
			for(int j=0;j<m;j++){
				if(tim[i*m+j]<=Q)res[tim[i*m+j]]-=tib.SUM(lea[i*m+j])-tib.SUM(ent[i*m+j]-1);
				tib.ADD(blk[i*m+j],1);
				for(auto x:u[j])res[tim[x]]+=tib.SUM(lea[x])-tib.SUM(ent[x]-1);
				u[j].clear();
			}
			for(int j=0;j<m;j++)tib.ADD(blk[i*m+j],-1);
		}
		for(int i=0;i<n;i++){
			stk[tp=0]=-1;
			for(int j=0;j<m;j++){
				if(tim[i*m+j]>Q)continue;
				while(tp&&tim[i*m+stk[tp]]>tim[i*m+j])tp--;
				LAS[j]=stk[tp],res[i*m+j]+=j-LAS[j]-1;
				if(LAS[j]!=-1)u[LAS[j]].push_back(i*m+j);
				if(stk[tp]!=-1)res[tim[j]]+=reach(i*m+j,i*m+stk[tp]);
				stk[++tp]=j;
			}
			for(int j=0;j<m;j++){
				if(tim[i*m+j]<=Q)res[tim[i*m+j]]-=tib.SUM(lea[i*m+j])-tib.SUM(ent[i*m+j]-1);
				tib.ADD(blk[i*m+j],1);
				for(auto x:u[j])res[tim[x]]+=tib.SUM(lea[x])-tib.SUM(ent[x]-1);
				u[j].clear();
			}
			for(int j=0;j<m;j++)tib.ADD(blk[i*m+j],-1);
		}
		for(int i=1;i<=Q;i++)print(res[i]),putchar('\n');
		for(int t=0;t<2;t++)bit[t].reset();tib.reset();
	}
	return 0;
} */
