#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,q;
vector<int> a[100007],b[1000007];
map<pair<int,int>,pair<int,int> > che;
map<pair<int,int>,int> pla;
map<pair<int,int>,int> vis;
set<pair<int,int> > ans;
int col,lv;
void dfs(int x,int y,int rod,int sta);
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		pla.clear();
		che.clear();
		cin>>n>>m>>q;
		for(int i=1;i<=n;++i){
			a[i].clear();
			a[i].push_back(0);
			string s;cin>>s;
			for(int j=0;j<s.size();++j){
				a[i].push_back(s[j]-'0');
//				cout<<a[j+1];
			}
//			cout<<"\n";
		}
		for(int i=1;i<n;++i){
			b[i].clear();
			b[i].push_back(0);
			string s;cin>>s;
			for(int j=0;j<s.size();++j){
				b[i].push_back(s[j]-'0');
//				cout<<b[j+1];
			}
//			cout<<"\n";
		}
		for(int i=1;i<=q;++i){
			int x,y;
			cin>>col>>lv>>x>>y;
			ans.clear();vis.clear();
			vis[make_pair(x,y)]=1;
			pla[make_pair(x,y)]=1;
			che[make_pair(x,y)]=make_pair(col,lv);
//			cout<<"\n";
			dfs(x,y,-1,-1);
			cout<<ans.size()<<"\n";
//			cout<<"\n";
		}
	}
	return 0;
}
void dfs(int x,int y,int rod,int sta){
	for(int i=0;i<4;++i){
		if(i==0){
			int nx=x-1,ny=y;
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(vis[make_pair(nx,ny)])continue;
			if(rod!=-1&&rod!=b[nx][ny])continue;
			if(b[nx][ny]==0)continue;
			if(b[nx][ny]==1){
				if(pla[make_pair(nx,ny)]){
					if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
					}
					else continue;
				}
				else {
//					cout<<nx<<" "<<ny<<"\n";
					ans.insert(make_pair(nx,ny));
				}
			}
			if(b[nx][ny]==2){
				if(rod!=-1&&sta!=2)continue;
				else {
					if(pla[make_pair(nx,ny)]){
						if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//							cout<<nx<<" "<<ny<<"\n";
							ans.insert(make_pair(nx,ny));
						}
						else continue;
					}
					else {
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
						vis[make_pair(nx,ny)]=1;
						dfs(nx,ny,2,2);
						vis[make_pair(nx,ny)]=0;
					}
				}
			}
			if(b[nx][ny]==3){
				if(pla[make_pair(nx,ny)]){
					if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
					}
					else continue;
				}
				else {
//					cout<<nx<<" "<<ny<<"\n";
					ans.insert(make_pair(nx,ny));
					vis[make_pair(nx,ny)]=1;
					dfs(nx,ny,3,-1);
					vis[make_pair(nx,ny)]=0;
				}
			}
		}
		if(i==1){
			int nx=x+1,ny=y;
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(vis[make_pair(nx,ny)])continue;
			if(rod!=-1&&rod!=b[x][ny])continue;
			if(b[x][ny]==0)continue;
			if(b[x][ny]==1){
				if(pla[make_pair(nx,ny)]){
					if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
					}
					else continue;
				}
				else {
//					cout<<nx<<" "<<ny<<"\n";
					ans.insert(make_pair(nx,ny));
				}
			}
			if(b[x][ny]==2){
				if(rod!=-1&&sta!=2){
						continue;
					}
				else {
					if(pla[make_pair(nx,ny)]){
						if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//							cout<<nx<<" "<<ny<<"\n";
							ans.insert(make_pair(nx,ny));
						}
						else continue;
					}
					else {
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
						vis[make_pair(nx,ny)]=1;
						dfs(nx,ny,2,2);
						vis[make_pair(nx,ny)]=0;
					}
				}
			}
			if(b[x][ny]==3){
				if(pla[make_pair(nx,ny)]){
					if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
					}
					else continue;
				}
				else {
//					cout<<nx<<" "<<ny<<"\n";
					ans.insert(make_pair(nx,ny));
					vis[make_pair(nx,ny)]=1;
					dfs(nx,ny,3,-1);
					vis[make_pair(nx,ny)]=0;
				}
			}
		}
		if(i==2){
			int nx=x,ny=y-1;
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(vis[make_pair(nx,ny)])continue;
			if(rod!=-1&&rod!=a[nx][ny])continue;
			if(a[nx][ny]==0)continue;
			if(a[nx][ny]==1){
				if(pla[make_pair(nx,ny)]){
					if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
					}
					else continue;
				}
				else {
//					cout<<nx<<" "<<ny<<"\n";
					ans.insert(make_pair(nx,ny));
				}
			}
			if(a[nx][ny]==2){
				if(rod!=-1&&sta!=1)continue;
				else {
					if(pla[make_pair(nx,ny)]){
						if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//							cout<<nx<<" "<<ny<<"\n";
							ans.insert(make_pair(nx,ny));
						}
						else continue;
					}
					else {
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
						vis[make_pair(nx,ny)]=1;
						dfs(nx,ny,2,1);	
						vis[make_pair(nx,ny)]=0;
					}
				}
			}
			if(a[nx][ny]==3){
				if(pla[make_pair(nx,ny)]){
					if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
					}
					else continue;
				}
				else {
//					cout<<nx<<" "<<ny<<"\n";
					ans.insert(make_pair(nx,ny));
					vis[make_pair(nx,ny)]=1;
					dfs(nx,ny,3,-1);
					vis[make_pair(nx,ny)]=0;
				}
			}
		}
		if(i==3){
			int nx=x,ny=y+1;
			if(nx<1||nx>n||ny<1||ny>m)continue;
			if(vis[make_pair(nx,ny)])continue;
			if(rod!=-1&&rod!=a[nx][y])continue;
			if(a[nx][y]==0)continue;
			if(a[nx][y]==1){
				if(pla[make_pair(nx,ny)]){
					if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
					}
					else continue;
				}
				else {
//					cout<<nx<<" "<<ny<<"\n";
					ans.insert(make_pair(nx,ny));
				}
			}
			if(a[nx][y]==2){
				if(rod!=-1&&sta!=1)continue;
				else {
					if(pla[make_pair(nx,ny)]){
						if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//							cout<<nx<<" "<<ny<<"\n";
							ans.insert(make_pair(nx,ny));
						}
						else continue;
					}
					else {
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
						vis[make_pair(nx,ny)]=1;
						dfs(nx,ny,2,1);	
						vis[make_pair(nx,ny)]=0;
					}
				}
			}
			if(a[nx][y]==3){
				if(pla[make_pair(nx,ny)]){
					if( col!=che[make_pair(nx,ny)].first&&lv>=che[make_pair(nx,ny)].second){
//						cout<<nx<<" "<<ny<<"\n";
						ans.insert(make_pair(nx,ny));
					}
					else continue;
				}
				else {
//					cout<<nx<<" "<<ny<<"\n";
					ans.insert(make_pair(nx,ny));
					vis[make_pair(nx,ny)]=1;
					dfs(nx,ny,3,-1);
					vis[make_pair(nx,ny)]=0;
				}
			}
		}
	}
}
