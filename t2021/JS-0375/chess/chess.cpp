#include <bits/stdc++.h>
#define N 1005 
using namespace std;
int mp[N][N][4],n,mx,q;
int m[N][N][2],cnt,vis[N][N];
int dirx[4]={0,1,0,-1},diry[4]={1,0,-1,0};

void def(int x,int y,int pre,int dir)
{
	if(pre<0)
		for(int i=0;i<4;++i)
			def(x+dirx[i],y+diry[i],mp[x][y][i],i);
	if(pre==0)
		return;
	if(pre==3){
		for(int i=0;i<4;++i){
			if(mp[x][y][i]==3){
				if(vis[x][y]) continue;
				if(!vis[x][y]) vis[x][y]=1,cnt++;
				def(x+dirx[i],y+diry[i],pre,i);
			}
		}
	}
	if(pre==1){
		if(!vis[x][y]) vis[x][y]=1,cnt++;
		return;
	}
	if(pre==2){
		if(!vis[x][y]) vis[x][y]=1,cnt++;
		def(x+dirx[dir],y+diry[dir],pre,dir);
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(mp,0,sizeof(mp)),memset(m,0,sizeof(m));
		int col,lv,x,y;
		scanf("%d%d%d",&n,&mx,&q);
		string s;
		for(int i=1;i<=n;++i){
			cin>>s;
			for(int j=0;j<s.size();++j)
				mp[i][j+1][0]=mp[i][j+2][2]=s[j]-'0';
		}
		for(int i=1;i<n;++i){
			cin>>s;
			for(int j=0;j<s.size();++j)
				mp[i][j+1][1]=mp[i+1][j+1][3]=s[j]-'0';
		}
		for(int i=1;i<=q;++i){
			cnt=0;
			scanf("%d%d%d%d",&col,&lv,&x,&y);
			m[x][y][0]=col,m[x][y][1]=lv;
			def(x,y,-1,-1);
		}
	}
}
