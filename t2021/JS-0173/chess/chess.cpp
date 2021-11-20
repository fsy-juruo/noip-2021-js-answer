#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int v[N][N],n,m,q,p[N][N],ans,t,v1[N][N];char a[N][N],b[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};string s1[200005],s2[200005];
struct ch{int c,lv,x,y;}c[200005];queue<ch> q1;map<pair<int,int> ,int> mp;
bool in(int x,int y){return x<=n && y<=m && x && y;}
char get(int x,int y,int xx,int yy){
	if(x==xx){return yy>y?a[x][y]:a[xx][yy];}
	return xx>x?b[x][y]:b[xx][yy];
}
void bl(){
	int col,lv,x,y,z=0;
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<n;i++) scanf("%s",b[i]+1);
	while(q--){
		scanf("%d%d%d%d",&col,&lv,&x,&y);ans=0;
		c[++z]=(ch){col,lv,x,y};p[x][y]=z;
		q1.push((ch){0,0,x,y});
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) v[i][j]=0,v1[i][j]=0;
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(!in(xx,yy)) continue;
			char z2=get(x,y,xx,yy);
			if(z2=='3' || z2=='0') continue;
			if(p[xx][yy] && (c[p[xx][yy]].c==col || c[p[xx][yy]].lv>lv)) continue;
			if(z2=='1'){v[xx][yy]=1;continue;}
			v[xx][yy]=1;if(p[xx][yy]) continue;
			while(1){
				xx+=dx[i],yy+=dy[i];
				if(!in(xx,yy) || get(xx-dx[i],yy-dy[i],xx,yy)!='2') break;
				if(p[xx][yy] && (c[p[xx][yy]].c==col || c[p[xx][yy]].lv>lv)) break;
				v[xx][yy]=1;if(p[xx][yy]) break;
			}
		}
		while(!q1.empty()){
			ch z1=q1.front();q1.pop();v[z1.x][z1.y]=1;v1[z1.x][z1.y]=1;
			for(int i=0;i<4;i++){
				int xx=z1.x+dx[i],yy=z1.y+dy[i];
				if(!in(xx,yy) || v1[xx][yy]) continue;
				char z2=get(z1.x,z1.y,xx,yy);
				if(z2!='3') continue;
				if(p[xx][yy] && (c[p[xx][yy]].c==col || c[p[xx][yy]].lv>lv)) continue;
				if(p[xx][yy]){v[xx][yy]=1;continue;}
				v1[xx][yy]=1;q1.push((ch){0,0,xx,yy});
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) ans+=v[i][j];
		printf("%d\n",ans-1);
	}
}
char get2(int x,int y,int xx,int yy){
	if(x==xx) return y>yy?s1[xx][yy-1]:s1[x][y];
	return x>xx?s2[xx][yy-1]:s2[x][y];
}
int main( ){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>q;if(q<=2000){bl();continue;}
		int col,lv,x,y,z=0;
		for(int i=1;i<=n;i++) cin>>s1[i];
		for(int i=1;i<n;i++) cin>>s2[i];mp.clear();
		while(q--){
			scanf("%d%d%d%d",&col,&lv,&x,&y);ans=0;
			c[++z]=(ch){col,lv,x,y};mp[make_pair(x,y)]=z;
			for(int i=0;i<4;i++){
				int xx=x+dx[i],yy=y+dy[i];
				if(!in(xx,yy)) continue;
				char z2=get2(x,y,xx,yy);
				if(z2=='0') continue;int z3=mp[make_pair(xx,yy)];
				if(z3 && (c[z3].c==col || c[z3].lv>lv)) continue;ans++;
			}
			printf("%d\n",ans);
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

