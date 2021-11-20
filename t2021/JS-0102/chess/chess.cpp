#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,q;
int G[maxn][20],nod[maxn][20];
void re(){
	for(int i=1;i<=n*m;i++){
		for(int j=0;j<=10;j++){
			G[i][j]=0;nod[i][j]=-1;
		}
	}
}
int f[maxn];
int dfs(int c,int l,int x,int y){
	int num=(x-1)*n+y,ans=0;
	for(int i=1;i<=4;i++){
		int ne=G[num][i+4];
		if(G[num][i]==1||G[num][i]==0||G[num][i]==2||f[i]==1) continue;
		if(nod[ne][1]==-1||(nod[ne][1]!=c&&l>nod[ne][2])){
			f[ne]=1;
			ans+=dfs(c,l,ne/n+1,ne%n);
		}
	}
	return ans;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		re();
		for(int i=1;i<=n;i++){
			char s[100000];
			scanf("%s",s);
			for(int j=1;j<m;j++){
				G[(i-1)*n+j][2]=s[j]-'0';G[(i-1)*n+j][6]=(i-1)*n+j+1;
				G[(i-1)*n+j+1][4]=s[j]-'0';G[(i-1)*n+j+1][8]=(i-1)*n+j;
			}
		}
		for(int i=1;i<n;i++){
			char s[100000];
			scanf("%s",s);
			for(int j=1;j<=m;j++){
				G[(i-1)*n+j][3]=s[j]-'0';G[(i-1)*n+j][7]=i*n+j;
				G[i*n+j][1]=s[j]-'0';G[i*n+j][5]=(i-1)*n+j;
			}
		}
		while(q--){
			int c,l,x,y;
			scanf("%d%d%d%d",&c,&l,&x,&y);
			int num=(x-1)*n+y,ans=0;
			for(int i=1;i<=4;i++){
				int ne=G[num][i+4];
				if(G[num][i]==0) continue;
				if(G[num][i]==1){
					if(nod[ne][1]==-1||(nod[ne][1]!=c&&l>nod[ne][2])) ans++;
				}else if(G[num][i]==2){
					while(true){
						if(nod[ne][1]==-1||(nod[ne][1]!=c&&l>nod[ne][2])){
							ans++;
							ne=G[ne][i+4];
						}else break;
					}
				}else{
					for(int i=1;i<=n*m;i++) f[i]=0;
					ans+=dfs(c,l,x,y);
				}
			}
			printf("%d\n",ans);
		}
	}

	return 0;
}

