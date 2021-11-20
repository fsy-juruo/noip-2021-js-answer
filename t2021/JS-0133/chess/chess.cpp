#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5000;
const int maxm=2e5+5000;
inline int read(){
	char c=getchar();bool f=0;int num=0;
	for(;c<'0'||c>'9';f=(c=='-')?1:0,c=getchar());
	for(;c>='0'&&c<='9';num=(num<<3)+(num<<1)+(c^'0'),c=getchar());
	return  f?-num:num;
}
int n,m,q;
int T;
int g(int x,int y){
	return (x-1)*m+y;
}
struct node{
	int x,y;
};
node nu(int num){
	node a;
	a.y=num%m;
	a.x=num/m+1;
	if(a.y==0){
		a.y=m;
		a.x--;
		
	}
	return a;
}
int Head[maxn],Next[maxm],V[maxm],W[maxm];
int cnt;
void Add(int u,int v,int w){
	cnt++;
	W[cnt]=w;
	V[cnt]=v;
	Next[cnt]=Head[u];
	Head[u]=cnt;
	return;
}

char c[100000+500];
struct qua{
	int col,lv;
};
int ans;
map<int,qua>G;
map<int,bool>vis;
map<int,bool>cont;
void init(){
	cnt=0;
	G.clear();
	for(int i=0;i<=maxm;i++){
		Next[i]=0;
		V[i]=0;
		W[i]=0;
	} 
	for(int i=0;i<=maxn;i++){
		Head[i]=0;
	}
	return;
}
//dis:1вС 2ио 3ср 4об 
void dfs(int num,int last,int col,int lv,bool walk1,int dis,int st){
	int u=num;
	int D=dis;
	for(int i=Head[u];i;i=Next[i]){
		int v=V[i];
		int w=W[i];
	
		if(w==0||vis[v]||(last!=-1&&w!=last)||(walk1&&w==1)) continue;
//		cout<<u<<" "<<v<<" "<<dis<<endl;
		
		if(w==2){
			node s=nu(u);
			node t=nu(v);
//			cout<<u<<" "<<v<<" "<<dis<<endl;
			if(dis==-1){
//			cout<<dis<<" "<<s.x<<" "<<s.y<<" "<<t.x<<" "<<t.y<<endl;
				
				if(t.y==(s.y-1)) D=1;
				if(t.x==(s.x-1)) D=2;
				if(t.y==(s.y+1)) D=3;
				if(t.x==(s.x+1)) D=4;
			}
//			cout<<"   "<<dis<<" "<<t.y<<" "<<s.y<<endl;
			if(dis==1&&(t.y!=s.y-1)) continue;
			if(dis==2&&(t.x!=s.x-1)) continue;
			if(dis==3&&(t.y!=s.y+1)) continue;
			if(dis==4&&(t.x!=s.x+1)) continue;
		}
//		cout<<u<<" "<<v<<" "<<" "<<last<<" "<<w<<endl;
		if(G[v].lv!=0){
			qua ene=G[v];
			if(ene.col!=col&&ene.lv<=lv){
				ans++;
				vis[v]=1;
				continue;
			}else{
				vis[v]=1;
				continue;
			}
		}else{
//			cout<<nu(v).x<<" "<<nu(v).y<<endl;
			if(cont[v]==0) ans++;
//			cout<<v<<endl;
			vis[v]=1;
			cont[v]=1;
			bool W=0;
			if(w==1) W=1;
			dfs(v,w,col,lv,walk1||W,D,st);
			vis[v]=0;
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--){
		init();
		n=read();
		m=read();
		q=read();
		for(int i=1;i<=n;i++){
			scanf("%s",c+1);
			for(int j=1;j<m;j++){
				Add(g(i,j),g(i,j+1),c[j]-'0');
				Add(g(i,j+1),g(i,j),c[j]-'0');
//				cout<<g(i,j)<<" "<<g(i,j+1)<<" "<<c[j]-'0'<<endl;
			}	
		}
		for(int i=1;i<n;i++){
			scanf("%s",c+1);
			for(int j=1;j<=m;j++){
				Add(g(i,j),g(i+1,j),c[j]-'0');
				Add(g(i+1,j),g(i,j),c[j]-'0');
//				cout<<g(i,j)<<" "<<g(i+1,j)<<" "<<c[j]-'0'<<endl;
			}	
		}
		
		for(int i=1;i<=q;i++){
			node a;qua b;
			b.col=read();
			b.lv=read();
			a.x=read();
			a.y=read();
			G[g(a.x,a.y)]=b;
			ans=0;
			vis.clear();
			cont.clear();
//			cout<<g(a.x,a.y)<<endl;
			vis[g(a.x,a.y)]=1;
			dfs(g(a.x,a.y),-1,b.col,b.lv,0,-1,g(a.x,a.y));
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
