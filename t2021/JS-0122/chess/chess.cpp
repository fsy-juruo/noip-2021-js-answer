#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf=0x3f3f3f3f;
const int N=2e5+10;

//struct edge{int u,v,opt,nxt;}g[N*4];int head[N],tot;
//void add(int u,int v,int opt){g[++tot]={u,v,opt,head[u]};head[u]=tot;}

int T;
int n,m,q;
char ch[N];
int lft[N],rgt[N],up[N],down[N];
int col[N],lv[N],x[N],y[N];
pair<int,int> f[N];
int mk[N];

int read(){
	int f=1,x=0;char ch=getchar();
	while (ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0' && ch<='9'){x=x*10-'0'+ch;ch=getchar();}
	return f*x;
}

int id(int x,int y){
	return ((x-1)*m+y);
}

namespace subtask1{
	int ans;
	
	bool empty(int u){return f[u].second==0;}
	
	bool eat(int u1,int u2){
		if (empty(u2))return 1;
//		if (f[u1].first==f[u2].first)cerr<<"Color fail"<<endl;
//		if (f[u1].second<f[u2].second)cerr<<"Level fail"<<endl;
		return (f[u1].first!=f[u2].first && f[u1].second>=f[u2].second);
	}
	
	void dfs(int ori,int xx,int yy,int opt,int dir){
		if (opt==0)return ;
		if (mk[id(xx,yy)]==opt){
//			cerr<<"Have been here("<<xx<<","<<yy<<")"<<endl;
			return ;
		}
		if (!eat(ori,id(xx,yy))){
//			cerr<<"Can't eat("<<xx<<","<<yy<<")"<<endl;
			return ;
		}
		if (xx<1 || xx>n || yy<1 || yy>m){return ;}
		
		if (opt==1){ans++;return ;}
		
		
		if (opt==2){
			if (!mk[id(xx,yy)]){ans++;mk[id(xx,yy)]=2;}
//			cerr<<xx<<' '<<yy<<' '<<opt<<' '<<dir<<endl;
			if (!empty(id(xx,yy)))return ;
			if (dir==0)dfs(ori,xx+1,yy,opt,dir);
			else if (dir==1)dfs(ori,xx-1,yy,opt,dir);
			else if (dir==2)dfs(ori,xx,yy+1,opt,dir);
			else if (dir==3)dfs(ori,xx,yy-1,opt,dir);
		}
		else if (opt==3){
			if (!mk[id(xx,yy)]){ans++;mk[id(xx,yy)]=3;}
//			cerr<<xx<<' '<<yy<<' '<<opt<<' '<<dir<<endl;
			if (!empty(id(xx,yy)))return ;
			if (lft[id(xx,yy)]==3)dfs(ori,xx,yy-1,opt,dir);
			if (rgt[id(xx,yy)]==3)dfs(ori,xx,yy+1,opt,dir);
			if (up[id(xx,yy)]==3)dfs(ori,xx-1,yy,opt,dir);
			if (down[id(xx,yy)]==3)dfs(ori,xx+1,yy,opt,dir);
		}
		
	}
	
	void solve(){
		for (int i=1;i<=q;i++){
			memset(mk,0,sizeof(mk));
//			cerr<<col[i]<<' '<<lv[i]<<' '<<x[i]<<' '<<y[i]<<endl;
			ans=0;
			f[id(x[i],y[i])]=make_pair(col[i],lv[i]);
//			if (i==3 && T==1){cerr<<"#"<<f[id(2,1)].first<<' '<<col[i]<<endl;}
			mk[id(x[i],y[i])]=1;
			dfs(id(x[i],y[i]),x[i]+1,y[i],down[id(x[i],y[i])],0);
			dfs(id(x[i],y[i]),x[i]-1,y[i],up[id(x[i],y[i])],1);
			dfs(id(x[i],y[i]),x[i],y[i]+1,rgt[id(x[i],y[i])],2);
			dfs(id(x[i],y[i]),x[i],y[i]-1,lft[id(x[i],y[i])],3);
			mk[id(x[i],y[i])]=0;
			printf("%d\n",ans);
//			cerr<<endl;
		}
	}
}

namespace subtask2{
	int ans;
	
	bool empty(int u){return f[u].second==0;}
	
	bool eat(int u1,int u2){
		if (empty(u2))return 1;
//		if (f[u1].first==f[u2].first)cerr<<"Color fail"<<endl;
//		if (f[u1].second<f[u2].second)cerr<<"Level fail"<<endl;
		return (f[u1].first!=f[u2].first && f[u1].second>=f[u2].second);
	}
	
	void solve(){
		for (int i=1;i<=q;i++){
			ans=0;
			if (up[i]==1 && eat(id(x[i],y[i]),id(x[i]-1,y[i])))ans++;
			if (down[i]==1 && eat(id(x[i],y[i]),id(x[i]+1,y[i])))ans++;
			if (lft[i]==1 && eat(id(x[i],y[i]),id(x[i],y[i]-1)))ans++;
			if (rgt[i]==1 && eat(id(x[i],y[i]),id(x[i],y[i]+1)))ans++;
			printf("%d\n",ans);
		}
	}
}

namespace subtask3{
	void solve(){
		
	}
}

void solve(){
	memset(lft,0,sizeof(lft));
	memset(rgt,0,sizeof(rgt));
	memset(up,0,sizeof(up));
	memset(down,0,sizeof(down));
	memset(f,0,sizeof(f));
	n=read();m=read();q=read();
	int flag1=0,flag2=0;
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1);
//		puts(ch+1);
		for (int j=1;j<m;j++){
			if (ch[j]!='0'){
				int u=id(i,j),v=id(i,j+1),opt=ch[j]-'0';
//				cerr<<i<<' '<<j<<' '<<i<<' '<<j+1<<' '<<opt<<endl;
//				add(u,v,opt);add(v,u,opt);
				rgt[u]=lft[v]=opt;
				if (opt==2)flag1=1;
				if (opt==3)flag2=1;
			}
		}
	}
	for (int i=1;i<n;i++){
		scanf("%s",ch+1);
//		puts(ch+1);
		for (int j=1;j<=m;j++){
			if (ch[j]!='0'){
				int u=id(i,j),v=id(i+1,j),opt=ch[j]-'0';
//				cerr<<i<<' '<<j<<' '<<i+1<<' '<<j<<' '<<opt<<endl;
//				add(u,v,opt);add(v,u,opt);
				down[u]=up[v]=opt;
				if (opt==2)flag1=1;
				if (opt==3)flag2=1;
			}
		}
	}
	
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++){
//			cerr<<i<<' '<<j<<' '<<up[id(i,j)]<<' '<<down[id(i,j)]<<' '<<lft[id(i,j)]<<' '<<rgt[id(i,j)]<<endl;
//		}
//	}
	int flag3=1,flag4=1;
	for (int i=1;i<=q;i++){
		col[i]=read();lv[i]=read();x[i]=read();y[i]=read();
		if (lv[i]!=i)flag3=0;
		if (lv[i]!=q-i+1)flag4=0;
	}
	
	if (!flag1 && !flag2)subtask2::solve();
	else if (n*m<=5000 && q<=2000)subtask1::solve();
	else if (!flag2)subtask3::solve();
	else subtask1::solve();
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while (T--)solve();
	

	return 0;
}

