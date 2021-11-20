#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,q;
bool vis1[200010],vis2[200010],vis3[200010];
bool vis[200010];
int t1[200010],t2[200010];
vector<pair<int,int> >g[200010];
int col[100010],lv[100010],px[100010],py[100010];
void init(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<200010;i++)g[i].clear();
}
inline int get_id(int x,int y){return x*m+y;}
namespace sub1{
	void get_vis1(int sx,int sy){
		for(int i=0;i<n*m;i++)vis1[i]=false;
		vis1[get_id(sx,sy)]=true;
		for(int i=0;i<(int)g[get_id(sx,sy)].size();i++){
			int to=g[get_id(sx,sy)][i].first,type=g[get_id(sx,sy)][i].second;
			if(type==1)vis1[to]=true;
		}
	}
	void get_vis2(int sx,int sy){
		for(int i=0;i<n*m;i++)vis2[i]=false;
		vis2[get_id(sx,sy)]=true;
		for(int i=sy;i+1<m;i++){
			if(t1[get_id(sx,i)]==2)vis2[get_id(sx,i+1)]=true;
			else break;
			if(vis[get_id(sx,i+1)])break;
		}
		for(int i=sy-1;i>=0;i--){
			if(t1[get_id(sx,i)]==2)vis2[get_id(sx,i)]=true;
			else break;
			if(vis[get_id(sx,i)])break;
		} 
		for(int i=sx;i+1<n;i++){
			if(t2[get_id(i,sy)]==2)vis2[get_id(i+1,sy)]=true;
			else break;
			if(vis[get_id(i+1,sy)])break;
		}
		for(int i=sx-1;i>=0;i--){
			if(t2[get_id(i,sy)]==2)vis2[get_id(i,sy)]=true;
			else break;
			if(vis[get_id(i,sy)])break;
		}
	}
	int st=0,ed=0;
	int que[200010];
	void get_vis3(int sx,int sy){
		for(int i=0;i<n*m;i++)vis3[i]=false;
		st=0,ed=0;
		vis3[get_id(sx,sy)]=true;
		que[ed++]=get_id(sx,sy);
		while(st<ed){
			int id=que[st++];
			if(vis[id])continue;
			for(int i=0;i<(int)g[id].size();i++){
				int to=g[id][i].first,t=g[id][i].second;
				if(t==3&&!vis3[to]){
					vis3[to]=true;
					que[ed++]=to;
				}
			}
		}
	}
	void work(){
		for(int i=0;i<q;i++){
			cin>>col[i]>>lv[i]>>px[i]>>py[i];
			px[i]--;py[i]--;
			get_vis1(px[i],py[i]);
			get_vis2(px[i],py[i]);
			get_vis3(px[i],py[i]);
			int ans=0;
			for(int j=0;j<i;j++){
				bool ok=false;
				int id=get_id(px[j],py[j]); 
				if(vis1[id]||vis2[id]||vis3[id]){
					if(col[j]!=col[i]&&lv[j]<=lv[i])ok=true;
				}
				if(!ok)vis1[id]=vis2[id]=vis3[id]=false;
			}
			for(int id=0;id<n*m;id++)
				ans+=vis1[id]|vis2[id]|vis3[id];
			cout<<ans-1<<endl;
			vis[get_id(px[i],py[i])]=true;
		} 
	}
}
void solve(){
	init();
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)for(int j=0;j+1<m;j++){
		char t;cin>>t;
		t1[get_id(i,j)]=t-'0';
		g[get_id(i,j)].push_back(make_pair(get_id(i,j+1),t-'0'));
		g[get_id(i,j+1)].push_back(make_pair(get_id(i,j),t-'0'));
	}
	for(int i=0;i+1<n;i++)for(int j=0;j<m;j++){
		char t;cin>>t;
		t2[get_id(i,j)]=t-'0';
		g[get_id(i,j)].push_back(make_pair(get_id(i+1,j),t-'0'));
		g[get_id(i+1,j)].push_back(make_pair(get_id(i,j),t-'0'));
	}
	sub1::work();
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0; 
}
