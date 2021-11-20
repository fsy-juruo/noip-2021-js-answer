#include <cstdio>
#include <iostream>
#include <string> 
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int maxn=10e5+10;
int n,m,q,num;
string s1[maxn],s2[maxn];
int col[maxn],lv[maxn],x[maxn],y[maxn];
vector<int> v[maxn];
int visit[10000][10010];
struct item{
	int x,y;
}; 
struct node{
	int col,lv;
};
map<item,node> ms;
void gogo1(int x,int y,item orign){
	if(x<1)	return;
	item p1;	p1.x=x,p1.y=y;
	if(ms.find(orign)!=ms.end()){
		if(ms[p1].col != ms[p1].col && ms[p1].lv>=ms[p1].lv)
			num++;
		return; 
	}
	num++;
	int nx1=x-1;
	if(s1[nx1][y]!='0')	return;
	gogo1(nx1,y,orign);
}
void gogo2(int x,int y,item orign){
	if(x>n)	return;
	item p1;	p1.x=x,p1.y=y;
	if(ms.find(orign)!=ms.end()){
		if(ms[p1].col != ms[p1].col && ms[p1].lv>=ms[p1].lv)
			num++;
		return; 
	}
	num++;
	int nx1=x+1;
	if(s1[x][y]!='0')	return;
	gogo1(x+1,y,orign);
}
void gogo3(int x,int y,item orign){
	if(y<1)	return;
	item p1;	p1.x=x,p1.y=y;
	if(ms.find(orign)!=ms.end()){
		if(ms[p1].col != ms[p1].col && ms[p1].lv>=ms[p1].lv)
			num++;
		return; 
	}
	num++;
	int ny1=y-1;
	if(s1[x][ny1]!='0')	return;
	gogo1(x,ny1,orign);
}
void gogo4(int x,int y,item orign){
	if(y>m)	return;
	item p1;	p1.x=x,p1.y=y;
	if(ms.find(orign)!=ms.end()){
		if(ms[p1].col != ms[p1].col && ms[p1].lv>=ms[p1].lv)
			num++;
		return; 
	}
	num++;
	int ny1=y+1;
	if(s1[x][ny1]!='0')	return;
	gogo4(x,ny1,orign);
}
void firw1(int x,int y,item orign){
	item p1;	p1.x=x,p1.y=y;
	if(visit[x][y]||x<1 || x>n|| y<1||y>m)	return;
	int nx1=x-1,nx2=x+1,ny1=y-1,ny2=y+1;
	if(ms.find(orign)!=ms.end()){
		if(ms[orign].col != ms[p1].col && ms[orign].lv>=ms[p1].lv)
			num++;
		return; 
	}
	num++;	
	if(s1[nx1][y]=='2')	
		firw1(nx1,y,orign);
	if(s1[x][y]=='2')
		firw1(nx2,y,orign);
	if(s2[x][ny1]=='2')
		firw1(x,ny1,orign);
	if(s2[x][ny2]=='2')
		firw1(x,ny2,orign);
	return;
}
void dfs(int id){
	memset(visit,0,sizeof(0));
	visit[x[id]][y[id]]=1;
	item p1;
	p1.x=x[id],p1.y=y[id];
	int nx1=x[id]-1,nx2=x[id]+1,ny1=y[id]-1,ny2=y[id]+1;
	if(s1[nx1][y[id]]=='0') return;
	if(s1[nx1][y[id]]=='1')
		gogo1(nx1,y[id],p1);
	if(s1[nx1][y[id]]=='2')
		firw1(nx1,y[id],p1);
	
	memset(visit,0,sizeof(0));
	visit[x[id]][y[id]]=1;
	if(s1[x[id]][y[id]]=='0')	return;
	if(s1[x[id]][y[id]]=='1')
		gogo2(nx2,y[id],p1);
	if(s1[x[id]][y[id]]=='2')
		firw1(nx2,y[id],p1);
	
	memset(visit,0,sizeof(0));
	visit[x[id]][y[id]]=1;
	if(s2[x[id]][ny1]=='0')	return;
	if(s2[x[id]][ny1]=='1')
		gogo3(x[id],ny1,p1);
	if(s2[x[id]][ny1]=='2')
		firw1(x[id],ny1,p1);
	
	memset(visit,0,sizeof(0));
	visit[x[id]][y[id]]=1;
	if(s2[x[id]][y[id]]=='0')	return;
	if(s2[x[id]][y[id]]=='1')
		gogo4(x[id],ny2,p1);
	if(s2[x[id]][y[id]]=='2')
		firw1(x[id],ny2,p1);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
			cin>>s1[i];
		for(int i=1;i<=n-1;i++)
			cin>>s2[i];
		for(int i=1;i<=q;i++){
			scanf("%d%d%d%d",&col[i],&lv[i],&x[i],&y[i]);
			item p1; p1.x=x[i],p1.y=y[i];
			node p2; p2.col=col[i],p2.lv=lv[i];
			ms[p1]=p2;
			dfs(i);
			cout<<num<<endl;
		}
	}
	return 0;
}
