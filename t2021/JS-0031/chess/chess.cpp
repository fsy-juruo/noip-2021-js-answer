#include<bits/stdc++.h>
#define LL long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define DF(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define mp make_pair
using namespace std;
int read(){
	char ch=getchar();int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
const int M=2e5+10,E=1e6+10;
int n,m,q;
int id(int x,int y){
	return (x-1)*m+y;
}
int to[E],nxt[E],head[M],w[E],cnt; 
void add(int x,int y,int z){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}

char s[M];
int cm[M],X[M],Y[M],col[M],lev[M],rk[M];
void CLR(){
	F(i,id(1,1),id(n,m)) head[i]=0,cm[i]=0;
	cnt=0;
}

namespace Q1{
	int ask(int o){
		int ret=0;
		int cur=id(X[o],Y[o]);
		for (int i=head[cur];i;i=nxt[i]){
			int y=to[i];
			if (w[i]!=1) continue; 
			if (!cm[y]) ret++;
			else{
				int oo=cm[y];
//				cerr<<o<<" "<<oo<<"   ?? \n";
				if (lev[oo]<=lev[o] && col[oo]^col[o]){
					ret++;
				}
			}
		}
		return ret;
	}
}
//namespace Q23{
//	int L[M*211],R[M*211],sz[M*211][2],tot;
//	#define mid (l+r>>1)
//	struct SGT{
//		int rt[M],f[M],s0[M];
//		int Fd(int x){
//			if (f[x]==x) return x;
//			return f[x]=Fd(f[x]);
//		}
//		
//		void init(){
//			F(i,1,n*m) f[i]=i;
//		}
//		void upd(int &x,int l,int r,int p,int o,int oo){
//			if (!x) x=++tot,sz[x][0]=sz[x][1]=L[x]=R[x]=0;
//			if (l==r){
//				sz[x][oo]=o;
//				return ;	
//			}
//			if (p<=mid) upd(L[x],l,mid,p,o,oo);
//			else upd(R[x],mid+1,r,p,o,oo);
//			sz[x][oo]=sz[L[x]][oo]+sz[R[x]][oo];
//		}
//		int qry(int x,int l,int r,int p,int oo){
//			if (!x || l>p || !sz[x][oo]) return 0;
//			if (r<=mid) return sz[x][oo];
//			return qry(L[x],l,mid,p,oo)+qry(R[x],mid+1,r,p,oo);
//		}
//		int merge(int x,int y,int l,int r){
//			if (!x || !y) return x|y;
//			if (l==r){
//				sz[x][0]=sz[x][0]|sz[y][0];
//				sz[x][1]=sz[x][1]|sz[y][1];
//				return x;
//			}
//			L[x]=merge(L[x],L[y],l,mid);
//			R[x]=merge(R[x],R[y],mid+1,r);
//			sz[x][0]=sz[L[x]][0]+sz[R[x]][0];
//			sz[x][1]=sz[L[x]][1]+sz[R[x]][1];
//			return x;
//		}
//		void mg(int x,int y){
//			x=Fd(x); y=Fd(y);
//			if (x==y) return ;
//			f[y]=x;
//			s0[x]+=s0[y];
//			rt[x]=merge(rt[x],rt[y],0,q);
//		}
//		void xiu(int R,int p,int o,int oo){
//			R=Fd(R);
//			upd(rt[R],0,q,p,o,oo);
//		}
//		void add0(int R){
//			R=Fd(R); s0[R]++;
//		}
//		int Q(int ii){
//			int R=id(X[ii],Y[ii]);
//			R=Fd(R);
//			return s0[Fd(R)]-1+qry(rt[R],0,q,rk[ii],col[ii]^1);
//		}
//	}A,B,C;
//	void init(){
//		A.init(); B.init(); C.init();
//		F(ii,1,n){
//			F(jj,1,m){
//				int x=id(ii,jj);
//				if (!cm[x]){
//					A.s0[x]++; B.s0[x]++; C.s0[x]++;
//					continue;
//				}
//				for (int i=head[x];i;i=nxt[i]){
//					int y=to[i];
//					if (w[i]==2){
//						if (abs(x-y)==1) A.xiu(y,rk[cm[x]],1,col[cm[x]]);
//						else B.xiu(y,rk[cm[x]],1,col[cm[x]]);
//					}
//					if (w[i]==3){
//						C.xiu(y,rk[cm[x]],1,col[cm[x]]); 
//					}
//				}
//			}
//		}
//		F(ii,1,n){
//			F(jj,1,m){
//				int x=id(ii,jj);
//				for (int i=head[x];i;i=nxt[i]){
//					int y=to[i];
//					if (cm[x] || cm[y]) continue;
//					if (w[i]==2){
//						if (abs(x-y)==1) A.mg(x,y);
//						else B.mg(x,y);
//					}
//					if (w[i]==3){
//						C.mg(x,y);
//					}
//				}
//			}
//		}
//	}
//	int ask(int x){
//		return 0;
//	}
//}
void del(int ii){
//	int x=id(X[ii],Y[ii]);
	cm[id(X[ii],Y[ii])]=0;		
//	bool fA=0,fB=0,fC=0;
//	for (int i=head[x];i;i=nxt[i]){
//		int y=to[i];
//		if (!cm[y]){
//			if (w[i]==2){
//				if (abs(x-y)==1){
//					fA=1;
//					Q23::A.mg(x,y);
//				}
//				else{
//					fB=1;
//					Q23::B.mg(x,y);
//				}
//			}
//			if (w[i]==3){
//				fC=1;
//				Q23::C.mg(x,y);
//			}
//			
//		}
//	}
//	if (fA){
//		Q23::A.xiu(x,rk[ii],0,col[ii]);
//	}
//	if (fB){
//		Q23::B.xiu(x,rk[ii],0,col[ii]);
//	}
//	if (fC){
//		Q23::C.xiu(x,rk[ii],0,col[ii]);
//	}
//	Q23::A.add0(x);
//	Q23::B.add0(x);
//	Q23::C.add0(x);
}




bool cmp(int x,int y){
	return lev[x]<lev[y];
}
int ans[M],p[M],lb[M];
namespace BF{
	int q[M];
	bool vis[M],pl[M];
	int dis[M];
	void bfs(int S,int o){
		int l=1,r=1; q[1]=S;
		F(i,1,n*m) pl[i]=0;
		while (l<=r){
			int x=q[l++];
			for (int i=head[x];i;i=nxt[i]){
				int y=to[i];
				if (w[i]!=1) continue; 
				if (!cm[y]){
					pl[y]=1; 
				}
				else{
					int oo=cm[y];
					if (lev[oo]<=lev[o] && col[oo]^col[o]){
						pl[y]=1;
					}
				}
			}
		}
		l=1,r=1; q[1]=S;
		F(i,1,n*m) vis[i]=0,dis[i]=0; vis[S]=1; dis[S]=3;
		
		while (l<=r){
			int x=q[l++];
			
			for (int i=head[x];i;i=nxt[i]){
				int y=to[i];
				if (w[i]!=2 || vis[y]) continue;
//				if (o==2){
//					cerr<<x<<" "<<y<<" "<<dis[x]<<" "<<cm[y]<<"   fuck \n";
//				}
				int ty=(abs(x-y)==1 ? 1 : 2);
				if (!(dis[x]&ty)) continue;
				if (!cm[y]){
					pl[y]=1;
					dis[y]=ty;
					q[++r]=y;
					vis[y]=1;
				}
				else{
					int oo=cm[y];
//					if (o==2){
//						cerr<<o<<" "<<oo<<"    omg \n";
//					}
					if (lev[oo]<=lev[o] && col[oo]^col[o]){
						pl[y]=1;
					}
				}
			}
		}
		
		l=1,r=1; q[1]=S;
		F(i,1,n*m) vis[i]=0; vis[S]=1;
		while (l<=r){
			int x=q[l++];
			for (int i=head[x];i;i=nxt[i]){
				int y=to[i];
				if (w[i]!=3 || vis[y]) continue;
				if (!cm[y]){
					pl[y]=1;
					q[++r]=y;
					vis[y]=1;
				}
				else{
					int oo=cm[y];
					if (lev[oo]<=lev[o] && col[oo]^col[o]){
						pl[y]=1;
					}
				}
			}
		}
	}
	void solve(int hh){
		DF(i,hh,1){
			cm[id(X[i],Y[i])]=0;
			bfs(id(X[i],Y[i]),i);
//			cerr<<X[i]<<" "<<Y[i]<<" !! \n";
//			F(x,1,n){
//				F(y,1,m){
//					if (pl[id(x,y)]){
//						cout<<x<<" "<<y<<"  reachable\n";
//					}
//				}
//			}
			F(j,1,n*m) if (j^id(X[i],Y[i]) && pl[j]) ans[i]++;
		}
		F(i,1,hh){
			cout<<ans[i]<<"\n";
		}
	}
}

void work(){
	n=read(); m=read(); q=read();
	CLR();
//	cerr<<n*m<<" "<<q<<"   size \n";
	F(i,1,q) ans[i]=0;
	bool no23=1;
	F(i,1,n){
		scanf("%s",s+1);
		F(j,1,m-1){
			int o=s[j]-'0';
			no23&=(o<=1);
			add(id(i,j),id(i,j+1),o);
			add(id(i,j+1),id(i,j),o);
		}
	}
	F(i,1,n-1){
		scanf("%s",s+1);
		F(j,1,m){
			int o=s[j]-'0';
			no23&=(o<=1);
			add(id(i,j),id(i+1,j),o);
			add(id(i+1,j),id(i,j),o);
		}
	}
	F(i,1,q){
		col[i]=read();
		lev[i]=read(); 
		X[i]=read();
		Y[i]=read();
		cm[id(X[i],Y[i])]=i;
	}
	
	if (!no23 && q<=2000){
		BF::solve(q);
		return ;
	}
	
	
	
	lev[q+1]=q;
	F(i,1,q+1) p[i]=i;
	sort(p+1,p+q+2,cmp);
	F(i,1,q+1) rk[p[i]]=i;
	
	F(i,0,q){
		F(j,lev[p[i]],lev[p[i+1]]-1) lb[j]=i;
	}
	
//	Q23::init();
	
	//[0,q]
	
	DF(i,q,1){
		del(i);
		if (no23) ans[i]=Q1::ask(i);
		else{
			
		}
		//+Q23::ask(i);
	}
	F(i,1,q){
		cout<<ans[i]<<"\n";
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while (T--) work();  
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
0 4 2 2

*/

