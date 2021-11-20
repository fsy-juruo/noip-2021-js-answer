#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,q;
vector<int> v1[200005];
vector<int> v2[200005];
struct node{
	int cl,lv;
};
int cmp(node a,node b){
	if(a.cl!=b.cl&&a.lv>=b.lv) return 1;
	return 0;
}
vector<node>vis[200005];
void solve1(){
	for(int i=1;i<=q;++i){
		int cl,lv,x,y;
		scanf("%d%d%d%d",&cl,&lv,&x,&y);
		node kk=(node){cl,lv};
		int ans=0;
		if(x>1&&v2[x-1][y]){
			ans+=cmp(kk,vis[x-1][y]);
		}
		if(x<n&&v2[x][y]){
			ans+=cmp(kk,vis[x+1][y]);
		}
		if(y>1&&v1[x][y-1]){
			ans+=cmp(kk,vis[x][y-1]);
		}
		if(y<m&&v1[x][y]){
			ans+=cmp(kk,vis[x][y+1]);
		}
		printf("%d\n",ans);
		vis[x][y]=kk;
	}
}
//int viss[5005][5005],vis2[5005][5005];
//void bfs(){
//	
//}
//void solve2(){
//	for(int i=1;i<=q;++i){
//		int cl,lv,x,y;
//		for(int i=1;i<=n;++i)
//			for(int j=1;j<=m;++j)
//				viss[i][j]=0;
//		scanf("%d%d%d%d",&cl,&lv,&x,&y);
//		if(x>1&&v2[x-1][y]==1){
//			viss[x-1][y]+=cmp(kk,vis[x-1][y]);
//		}
//		if(x<n&&v2[x][y]==1){
//			viss[x+1][y]+=cmp(kk,vis[x+1][y]);
//		}
//		if(y>1&&v1[x][y-1]==1){
//			viss[x][y-1]+=cmp(kk,vis[x][y-1]);
//		}
//		if(y<m&&v1[x][y]==1){
//			viss[x][y+1]+=cmp(kk,vis[x][y+1]);
//		}
//		for(int i=x-1;i>=1;--i){
//			if(v2[i][y]==2){
//				if(cmp(kk,vis[i][y])){
//					viss[i][y]=1;
//					if(vis[i][y].cl!=-1) break;
//				}
//			}else
//				break;
//		}
//		for(int i=x+1;i<=n;++i){
//			if(v2[i-1][y]==2){
//				if(cmp(kk,vis[i][y])){
//					viss[i][y]=1;
//					if(vis[i][y].cl!=-1) break;
//				}
//			}else
//				break;
//		}
//		for(int i=y-1;i>=1;--i){
//			if(v1[x][i]==2){
//				if(cmp(kk,vis[x][i])){
//					viss[x][i]=1;
//					if(vis[x][i].cl!=-1) break;
//				}
//			}else
//				break;
//		}
//		for(int i=y+1;i<=m;++i){
//			if(v1[x][i-1]==2){
//				if(cmp(kk,vis[x][i])){
//					viss[x][i]=1;
//					if(vis[x][i].cl!=-1) break;
//				}
//			}else
//				break;
//		}
//		q.push(make_pair(x,y));
//		
//	}
//}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		bool f=1;
		for(int i=1;i<=n;++i) v1[i].resize(m+1);
		for(int i=1;i<=n;++i) v2[i].resize(m+1);
		for(int i=1;i<=n;++i){
			vis[i].resize(m+1);
			for(int j=1;j<=m;++j) vis[i][j]=(node){-1,-1};
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m-1;++j){
				char ch=getchar();
				while(ch<'0'||ch>'3') ch=getchar();
				v1[i][j]=ch-'0';
				if(ch>'1') f=0;
			}
		}
		for(int i=1;i<=n-1;++i)
			for(int j=1;j<=m;++j){
				char ch=getchar();
				while(ch<'0'||ch>'3') ch=getchar();
				v2[i][j]=ch-'0';
				if(ch>'1') f=0;
			}
//		if(f){
//			solve1();
//		}else{
//			//solve2();
//			
//		}
		solve1();
	}
	return 0;
}
/*
1
3 3 3
01
11
00
111
111
2 1 1 3 
1 2 2 3
1 3 2 2
*/ 

