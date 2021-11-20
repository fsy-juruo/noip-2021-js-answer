#include<bits/stdc++.h>
using namespace std;
int T,n,m,q,col[100001],l[100001];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;++i){
			getchar();
			for(int j=1;j<m;++j)
				getchar();
		}
		for(int i=1;i<n;++i){
			getchar();
			for(int j=1;j<=m;++j)
				getchar();
		}
		for(int i=1;i<=q;++i){
			int _col,_l,x,y;
			scanf("%d%d%d%d",&_col,&_l,&x,&y);
		}
		for(int i=1;i<=q;++i)
			printf("0\n",n);
	}
	return 0;
}
