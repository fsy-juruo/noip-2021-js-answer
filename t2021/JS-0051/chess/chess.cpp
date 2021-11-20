#include<bits/stdc++.h>
#define N 200010
#define pb push_back
using namespace std;
int n,m,t,q,x[N],y[N],vis[N],used[N],col[N],lv[N],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
string s[N],l[N];
vector<int> vy,vx;

//void dfs(int xx,int yy,int c){
//	if(vis[xx*(m-1)+yy]) return ;
//	vis[xx*(m-1)+yy]=1;
//	vx.pb(xx);
//	vy.pb(yy);
////	for(int i=0;i<4;i++){
////		if(xx+dx[i]>n||yy+dy[i]>m||xx+dx[i]<1||yy+dy[i]<1) continue;
////		if(i&1){
////			if(dx[i]==-1){
////				
////			}
////		}
////	}
//}

int ch(int xx,int yy){
	return xx*(m-1)+yy;
}

int main(){
	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	cin>>t;
	while(t--){
		memset(used,0,sizeof used);
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		for(int i=1;i<n;i++){
			cin>>l[i];
		}
		for(int i=1;i<=q;i++){
			cin>>col[i]>>lv[i]>>x[i]>>y[i];
			int ans=0;
			used[x[i]*(m-1)+y[i]]=i;
			if((!used[ch(x[i]-1,y[i])]||(col[used[ch(x[i]-1,y[i])]]!=col[i]&&lv[used[ch(x[i]-1,y[i])]]<=lv[i]))&&x[i]>1&&l[x[i]-1][y[i]-1]=='1'){
				ans++;
			}
			if((!used[ch(x[i]+1,y[i])]||(col[used[ch(x[i]+1,y[i])]]!=col[i]&&lv[used[ch(x[i]+1,y[i])]]<=lv[i]))&&x[i]<n&&l[x[i]][y[i]-1]=='1'){
				ans++;
			}
			if((!used[ch(x[i],y[i]-1)]||(col[used[ch(x[i],y[i]-1)]]!=col[i]&&lv[used[ch(x[i],y[i]-1)]]<=lv[i]))&&y[i]>1&&s[x[i]][y[i]-1]=='1'){
				ans++;
			}
			if((!used[ch(x[i],y[i]+1)]||(col[used[ch(x[i],y[i]+1)]]!=col[i]&&lv[used[ch(x[i],y[i]+1)]]<=lv[i]))&&y[i]<m&&s[x[i]][y[i]]=='1'){
				ans++;
			}
			cout<<ans<<endl;
//			dfs(x[i],y[i],0);
//			for(int j=0;j<vx.size();j++){
//				vis[vx[j]*(m-1)+vy[j]]=0;
//			}
//			printf
//			vector<int>().swap(vx);
//			vector<int>().swap(vy);
		}
	}
	return 0;
}
