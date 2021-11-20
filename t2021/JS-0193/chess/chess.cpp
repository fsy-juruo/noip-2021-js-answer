#include<bits/stdc++.h>
using namespace std;
#define N 200050
int T,n,m,q;
struct edge{
	int next,to;
	int opt;
}e[N<<1];
int head[N],cnt;
void add(int u,int v,int opt){
	e[++cnt].to=v;
	e[cnt].opt=opt;
	e[cnt].next=head[u];
	head[u]=cnt;
}
map<pair<int,int>,pair<int,int>> mp;//x,y,col,lv
bool vis[N],occupied[N];
int reach[N];
int ans;
void solve(int x,int y,int dir,int type){
	int u=n*(y-1)+x;
	for(int i=head[u];i;i=e[i].next){
		int j=e[i].to;
		if(e[i].opt!=type&&type!=0){
			continue;
		}
		if(vis[j]){
//			if(reach[j]!=type)
//				ans--;
//			else
				continue;
		}
		vis[j]=true;
		int px=j%n,py=j/n+1;
		if(px==0){
			px=n;
			py--;
		}
		if(occupied[j]){
//			cout<<mp[make_pair(x,y)].second<<" "<<mp[make_pair(px,py)].second<<'\n';
			if(mp[make_pair(px,py)].first==mp[make_pair(x,y)].first)
				continue;
			else if(mp[make_pair(px,py)].second>mp[make_pair(x,y)].second)
				continue;
			else{
				ans++;
				reach[j]=type;
//				cout<<"("<<px<<","<<py<<")";
				continue;
			}
		}
		if(e[i].opt==1){
			ans++;
			reach[j]=1;
//			cout<<"("<<px<<","<<py<<")";
			continue;
		}
		if(e[i].opt==2){
//		cout<<"#"<<dir<<"#";
			if(dir==0){
				ans++;
				reach[j]=2;
//				cout<<"("<<px<<","<<py<<")";
				if(px==x)
					solve(px,py,1,2);
				if(py==y)
					solve(px,py,2,2);
			}
			if(dir==1){
				
				if(px==x){
					ans++;
					reach[j]=2;
//					cout<<"("<<px<<","<<py<<")";
					solve(px,py,1,2);
				}
				else
					continue;
			}
			if(dir==2){
				if(py==y){
					ans++;
					reach[j]=2;
//					cout<<"("<<px<<","<<py<<")";
					solve(px,py,2,2);
				}
				else
					continue;
			}
		}
		if(e[i].opt==3){
			ans++;
			reach[j]=3;
//			cout<<"("<<px<<","<<py<<")";
			solve(px,py,dir,3);
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		memset(e,0,sizeof(e));
		memset(head,0,sizeof(head));
		memset(occupied,0,sizeof(occupied));
		cnt=0;
		mp.clear();
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			int len=s.size();
			for(int j=0;j<len;j++){
				int opt=s[j]-'0';
				if(!opt)
					continue;
				add(n*j+i,n*(j+1)+i,opt);
				add(n*(j+1)+i,n*j+i,opt);
			}
		}
		for(int i=1;i<=n-1;i++){
			string s;
			cin>>s;
			int len=s.size();
			for(int j=0;j<len;j++){
				int opt=s[j]-'0';
				if(!opt)
					continue;
				add(n*j+i,n*j+i+1,opt);
				add(n*j+i+1,n*j+i,opt);
			}
		}
		for(int i=1;i<=q;i++){
			int col,lv,x,y;
			cin>>col>>lv>>x>>y;
			mp[make_pair(x,y)]=make_pair(col,lv);
			memset(vis,false,sizeof(vis));
			memset(reach,false,sizeof(reach));
			occupied[n*(y-1)+x]=true;
			ans=0;
			solve(x,y,0,0);
			cout<<ans<<'\n';
		}
		
	}
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
1 3 2 2
*/
