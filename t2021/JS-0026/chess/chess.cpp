#include<bits/stdc++.h>
using namespace std;
int n,m,q,T,tot;
vector<vector<int> >R,C,dfn,ch,lev;
queue<int>qu,qv;
char s[200003];
void sol(){
	scanf("%d%d%d",&n,&m,&q);
	R.resize(n+2),C.resize(n+2),ch.resize(n+2),lev.resize(n+2),dfn.resize(n+2);
	for(int i=0;i<=n+1;i++)R[i].resize(m+2),C[i].resize(m+2),ch[i].resize(m+2),lev[i].resize(m+2),dfn[i].resize(m+2);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<m;j++)R[i][j]=s[j]-'0';
	}
	for(int i=1;i<n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)C[i][j]=s[j]-'0';
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ch[i][j]=-1,dfn[i][j]=0;
	for(int i=1;i<=q;i++){
		int col,lv,x,y,ans=0;scanf("%d%d%d%d",&col,&lv,&x,&y);
		++tot;
		qu.push(x),qv.push(y),dfn[x][y]=tot;
		while(!qu.empty()){
			int u=qu.front(),v=qv.front(),uu,vv;qu.pop(),qv.pop();
			if(ch[u][v]!=-1&&ch[u][v]==col)continue;
			if(ch[u][v]!=-1&&lev[u][v]>lv)continue;
			ans++;
			if(ch[u][v]!=-1)continue;
			if(u>0){
				uu=u-1,vv=v;
				if(C[uu][vv]==3&&dfn[uu][vv]!=tot){
					dfn[uu][vv]=tot;
					qu.push(uu),qv.push(vv);
				}
			}
			if(u<n){
				uu=u+1,vv=v;
				if(C[u][v]==3&&dfn[uu][vv]!=tot){
					dfn[uu][vv]=tot;
					qu.push(uu),qv.push(vv);
				}
			}
			if(v>1){
				uu=u,vv=v-1;
				if(R[uu][vv]==3&&dfn[uu][vv]!=tot){
					dfn[uu][vv]=tot;
					qu.push(uu),qv.push(vv);
				}
			}
			if(v<m){
				uu=u,vv=v+1;
				if(R[u][v]==3&&dfn[uu][vv]!=tot){
					dfn[uu][vv]=tot;
					qu.push(uu),qv.push(vv);
				}
			}
		}
		int u=x,v=y,uu,vv;
		if(u>0){
			uu=u-1,vv=v;
			if(C[uu][vv]==1&&dfn[uu][vv]!=tot){
				dfn[uu][vv]=tot;
				if(ch[uu][vv]!=-1){
					if(ch[uu][vv]==col);
					else if(lev[uu][vv]<=lv)ans++;
				}else ans++;
			}
		}
		if(u<n){
			uu=u+1,vv=v;
			if(C[u][v]==1&&dfn[uu][vv]!=tot){
				dfn[uu][vv]=tot;
				if(ch[uu][vv]!=-1){
					if(ch[uu][vv]==col);
					else if(lev[uu][vv]<=lv)ans++;
				}else ans++;
			}
		}
		if(v>1){
			uu=u,vv=v-1;
			if(R[uu][vv]==1&&dfn[uu][vv]!=tot){
				dfn[uu][vv]=tot;
				if(ch[uu][vv]!=-1){
					if(ch[uu][vv]==col);
					else if(lev[uu][vv]<=lv)ans++;
				}else ans++;
			}
		}
		if(v<m){
			uu=u,vv=v+1;
			if(R[u][v]==1&&dfn[uu][vv]!=tot){
				dfn[uu][vv]=tot;
				if(ch[uu][vv]!=-1){
					if(ch[uu][vv]==col);
					else if(lev[uu][vv]<=lv)ans++;
				}else ans++;
			}
		}
		u=x,v=y;
		for(;;){
			if(ch[u][v]!=-1)
				if(lev[u][v]>lv||ch[u][v]==col)break;
			if(dfn[u][v]!=tot)ans++,dfn[u][v]=tot;
			if(u==1||ch[u][v]!=-1)break;
			int uu=u-1,vv=v;
			if(C[uu][vv]!=2)break;
			u=uu,v=vv;
		}
		u=x,v=y;
		for(;;){
			if(ch[u][v]!=-1)
				if(lev[u][v]>lv||ch[u][v]==col)break;
			if(dfn[u][v]!=tot)ans++,dfn[u][v]=tot;
			if(u==n||ch[u][v]!=-1)break;
			int uu=u+1,vv=v;
			if(C[u][v]!=2)break;
			u=uu,v=vv;
		}
		u=x,v=y;
		for(;;){
			if(ch[u][v]!=-1)
				if(lev[u][v]>lv||ch[u][v]==col)break;
			if(dfn[u][v]!=tot)ans++,dfn[u][v]=tot;
			if(v==1||ch[u][v]!=-1)break;
			int uu=u,vv=v-1;
			if(R[uu][vv]!=2)break;
			u=uu,v=vv;
		}
		u=x,v=y;
		for(;;){
			if(ch[u][v]!=-1)
				if(lev[u][v]>lv||ch[u][v]==col)break;
			if(dfn[u][v]!=tot)ans++,dfn[u][v]=tot;
			if(v==m||ch[u][v]!=-1)break;
			int uu=u,vv=v+1;
			if(R[u][v]!=2)break;
			u=uu,v=vv;
		}
		ch[x][y]=col,lev[x][y]=lv;
		printf("%d\n",ans-1);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--)sol();
	return 0;
}
