#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define REP(x,y) for(int x=0;x<y;++x)
#define REPA(x,y) for(int x=1;x<=y;++x)
#define vi vector<int>
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define mp make_pair
using namespace std;
const ll MOD=1e9+7;
//const ll MOD=998244353;
const int INF=0x3f3f3f3f;
//const ll INF=0x3f3f3f3f3f3f3f3f;
inline ll quick_power(ll A,ll B){
	A%=MOD;ll ret=1;
	while(B){
		if(B&1)ret=ret*A%MOD;
		B>>=1;
		A=A*A%MOD;
	}
	return ret;
}
inline int lowbit(int x){return x&-x;}
#define si set<int>::iterator 
int N,M,Q;
struct SET{
	set<int>s;
}rw[100100],cl[100100];
inline void solve(){
	scanf("%d%d%d",&N,&M,&Q);
	pii G[N+3][M+3];bool vis[N+3][M+3];
	REP(i,N)REP(j,M)G[i][j]=mp(0,0);
	int rg[N+3][M+3],dwn[N+3][M+3];
	char c[max(N,M)+10];
	bool flag=0,flag2=1;
	REP(i,N){
		scanf("%s",c);
		REP(j,M-1){
			rg[i][j]=c[j]-'0';
			if(c[j]=='3')flag=1;
			if(c[j]!='1'||c[j]!=0)flag2=0;
		}
	}
	REP(i,N-1){
		scanf("%s",c);
		REP(j,M){
			dwn[i][j]=c[j]-'0';
			if(c[j]=='3')flag=1;
			if(c[j]!='1'||c[j]!=0)flag2=0;
		}
	}
	if(flag2){
		while(Q--){
			int col,lv,x,y;
			scanf("%d%d%d%d",&col,&lv,&x,&y);
			--x,--y;
			G[x][y]=mp(col,lv);
			int ans=0;
			if(y<M-1){
				if(rg[x][y]==1){
					if(G[x][y+1].se==0)++ans;
					else if(G[x][y].fi!=G[x][y+1].fi&&G[x][y].se>=G[x][y+1].se)++ans;
				}
			}
			if(y>0){
				if(rg[x][y-1]==1){
					if(G[x][y-1].se==0)++ans;
					else if(G[x][y].fi!=G[x][y-1].fi&&G[x][y].se>=G[x][y-1].se)++ans;
				}
			}
			if(x<N-1){
				if(dwn[x][y]==1){
					if(G[x+1][y].se==0)++ans;
					else if(G[x][y].fi!=G[x+1][y].fi&&G[x][y].se>=G[x+1][y].se)++ans;
				}
			}
			if(x>0){
				if(dwn[x-1][y]==1){
					if(G[x-1][y].se==0)++ans;
					else if(G[x][y].fi!=G[x-1][y].fi&&G[x][y].se>=G[x-1][y].se)++ans;
				}
			}
			printf("%d\n",ans);
		}
	}
	else if(flag){
		set<pii>S;
		while(Q--){
			S.clear();
			int col,lv,x,y;
			scanf("%d%d%d%d",&col,&lv,&x,&y);
			--x,--y;
			G[x][y]=mp(col,lv);
			queue<int>Q;
			
		}
	}
	else{
		REP(i,N)rw[i].s.clear(),rw[i].s.insert(-1),rw[i].s.insert(INF);
		REP(i,M)cl[i].s.clear(),cl[i].s.insert(-1),cl[i].s.insert(INF);
		while(Q--){
			int col,lv,x,y;
			scanf("%d%d%d%d",&col,&lv,&x,&y);
			--x,--y;
			G[x][y]=mp(col,lv);
			int ans=0;
			if(y<M-1){
				if(rg[x][y]==0){
					
				}
				else if(rg[x][y]==1){
					if(G[x][y+1].se==0)++ans;
					else if(G[x][y].fi!=G[x][y+1].fi&&G[x][y].se>=G[x][y+1].se)++ans;
				}
				else{
					si it=rw[x].s.lower_bound(y);
				//	if((*it)==INF)
				}
			}
		}
	}
	
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}
/*
think twice, code once;
think once, debug forever.
*/
/*
sto QL orz
sto HJ orz
sto H2 orz
sto ET orz
sto I9 orz
sto FG orz
haoba, yyds!
*/

