#include<bits/stdc++.h>
using namespace std ;
template<typename T> void read(T &x){
	x = 0 ; int flag = 1 ;
	char c = getchar() ;
	while(!isdigit(c)){
		if(c=='-')
			flag = -1 ;
		c = getchar() ;
	}
	while(isdigit(c)){
		x = x * 10 + c - '0' ;
		c = getchar() ;
	}
	x = x*flag ;
}
int n,m,q,t,l,col ;
const int maxn = 2e5+10 ;
vector<int>a[maxn],lv[maxn],c[maxn],vis[maxn],ans[maxn] ;
string s1[maxn],s2[maxn] ;
int opt1,opt2,opt3 ; // opt2 = 1 hengxianh ; opt2 = 2  zongxiang
void dfs(int x,int y,int ch){
//	cout<<x<<" "<<y<<endl ;
	int nx,ny ;
	nx = x+1 ,ny = y ;
	if(nx!=n&&s2[x][y]!=0&&vis[nx][ny]==0){
		if(lv[nx][ny]<=l&&c[nx][ny]!=col&&lv[nx][ny]>=0&&(ch==(int)(s2[x][y]-'0')||ch==1))
			if(ch!=2||(ch==2&&opt2==2))ans[nx][ny] = 1 ;
		if(lv[nx][ny]<0&&s2[x][y]=='1'&&ch==(int)(s2[x][y]-'0'))
			ans[nx][ny] = 1 ;
		if(lv[nx][ny]<0&&s2[x][y]=='2'){
			if(ch==1||(ch==2&&opt2==2))
				vis[x][y] = 1 , opt2 = 2 , ans[nx][ny] = 1 ,dfs(nx,ny,2) ,opt2 = 0 ,vis[x][y] = 0 ;
		}
		if(lv[nx][ny]<0&&s2[x][y]=='3'&&(ch==1||ch==3))
			vis[x][y] = 1 , ans[nx][ny] = 1 , dfs(nx,ny,3) , vis[x][y] = 0 ;
	}
	
	nx = x-1 ,ny = y ;// if(x==1&&y==0)cout<<nx<<" "<<ny<<" "<<endl ;
	if(nx>=0&&s2[nx][y]!=0&&vis[nx][ny]==0){
		if(lv[nx][ny]<=l&&c[nx][ny]!=col&&lv[nx][ny]>=0&&(ch==(int)(s2[nx][y]-'0')||ch==1))
			if(ch!=2||(ch==2&&opt2==2))ans[nx][ny] = 1 ;
		//if(nx==1&&ny==0)cout<<ans[nx][ny]<<endl ;
		if(lv[nx][ny]<0&&s2[nx][ny]=='1'&&ch==(int)(s2[nx][y]-'0'))
			ans[nx][ny] = 1 ;
		if(lv[nx][ny]<0&&s2[nx][ny]=='2'){
			if(ch==1||(ch==2&&opt2==2))
				vis[x][y] = 1 , opt2 = 2 , ans[nx][ny] = 1 ,dfs(nx,ny,2) ,opt2 = 0 ,vis[x][y] = 0 ;
		}
		if(lv[nx][ny]<0&&s2[nx][ny]=='3'&&(ch==1||ch==3))
			vis[x][y] = 1 , ans[nx][ny] = 1 , dfs(nx,ny,3) , vis[x][y] = 0 ;
	}
	
	nx = x ,ny = y+1 ;
	if(ny<m&&s1[x][y]!=0&&vis[nx][ny]==0){
//	if(x==1&&y==1&&l==2&&col==0)cout<<ch<<endl ;
		if(lv[nx][ny]<=l&&c[nx][ny]!=col&&lv[nx][ny]>=0&&(ch==(int)(s1[x][y]-'0')||ch==1))
			if(ch!=2||(ch==2&&opt2==1))ans[nx][ny] = 1 ;
		if(lv[nx][ny]<0&&s1[x][y]=='1'&&ch==(int)(s1[x][y]-'0'))
			ans[nx][ny] = 1 ;
		//if(x==1&&y==1)cout<<ch<<endl ;
		if(lv[nx][ny]<0&&s1[x][y]=='2'){
			if(ch==1||(ch==2&&opt2==1))
				vis[x][y] = 1 , opt2 = 1 , ans[nx][ny] = 1 ,dfs(nx,ny,2) ,opt2 = 0 ,vis[x][y] = 0 ;
		}
		if(lv[nx][ny]<0&&s1[x][y]=='3'&&(ch==1||ch==3))
			vis[x][y] = 1 , ans[nx][ny] = 1 , dfs(nx,ny,3) , vis[x][y] = 0 ;
	}
	
	nx = x ,ny = y-1 ;
	if(ny>=0&&s1[x][ny]!=0&&vis[nx][ny]==0){
		
		if(lv[nx][ny]<=l&&c[nx][ny]!=col&&lv[nx][ny]>=0&&(ch==(int)(s1[x][ny]-'0')||ch==1))
			if(ch!=2||(ch==2&&opt2==1))ans[nx][ny] = 1 ;
		if(lv[nx][ny]<0&&s1[x][ny]=='1'&&ch==(int)(s1[x][ny]-'0'))
			ans[nx][ny] = 1 ;
		//if(x==0&&y==1)cout<<1<<endl ;
		if(lv[nx][ny]<0&&s1[x][ny]=='2'){
			if(ch==1||(ch==2&&opt2==1))
				vis[x][y] = 1 , opt2 = 1 , ans[nx][ny] = 1 ,dfs(nx,ny,2) ,opt2 = 0 ,vis[x][y] = 0 ;
		}
		if(lv[nx][ny]<0&&s1[x][ny]=='3'&&(ch==1||ch==3))
			vis[x][y] = 1 , ans[nx][ny] = 1 , dfs(nx,ny,3) , vis[x][y] = 0 ;
	}
}
int main(){
	freopen("chess.in","r",stdin) ;
	freopen("chess.out","w",stdout) ;
	read(t) ;
	while(t--){
		read(n) ; read(m) ; read(q) ;
		for(int i = 0 ; i < n ; i++)
			cin>>s1[i] ;
		for(int i = 0 ; i < n ; i++){
			if(i!=n-1)cin >> s2[i] ;
			while(a[i].size()<m)
				a[i].push_back(0),lv[i].push_back(-1),c[i].push_back(-1),vis[i].push_back(0),ans[i].push_back(0) ;
		}
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				lv[i][j] = -1 , c[i][j] = -1  ;
		while(q--){
			int x,y ;
			read(col) ; read(l) ;  read(x) ; read(y) ;
			x-- ; y-- ; 
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < m ; j++)
					vis[i][j] = 0 , ans[i][j] = 0 ;
			vis[x][y] = 1 ;
			dfs(x,y,1) ;	
			int ans2 = 0 ;	
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < m ; j++){
					ans2+=ans[i][j] ;
				//	if(ans[i][j]==1)
					//	cout<<1+i<<" "<<1+j<<endl ;
				}
			lv[x][y] = l ; c[x][y] = col ;
			printf("%d\n",ans2) ;
		}
	}
		
	return 0 ;
}

