#include<bits/stdc++.h>
//#define int long long
//#define mo
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int T,n,m,q;
char vis[5005][5005];
pair<int,int> xx[5005][5005];
string st1[100005],st2[100005];
void dfs(int col,int lv,int x,int y,char tp){
	if (xx[x][y].first==-1) vis[x][y]=tp;
	else 
	{
		if (xx[x][y].first!=col&&xx[x][y].second<=lv) vis[x][y]=tp;
		return;
	}
	if (tp=='1') return;
	if (tp=='4') if (x>1&&st2[x-1][y]=='2') dfs(col,lv,x-1,y,'4');
	if (tp=='5') if (x<n&&st2[x][y]=='2') dfs(col,lv,x+1,y,'5');
	if (tp=='6') if (y>1&&st1[x][y-1]=='2') dfs(col,lv,x,y-1,'6');
	if (tp=='7') if (y<m&&st1[x][y]=='2') dfs(col,lv,x,y+1,'7');
	if (tp=='3')
	{
	if (x>1&&vis[x-1][y]!=tp&&st2[x-1][y]==tp) dfs(col,lv,x-1,y,st2[x-1][y]);
	if (x<n&&vis[x+1][y]!=tp&&st2[x][y]==tp) dfs(col,lv,x+1,y,st2[x][y]);
	if (y>1&&vis[x][y-1]!=tp&&st1[x][y-1]==tp) dfs(col,lv,x,y-1,st1[x][y-1]);
	if (y<m&&vis[x][y+1]!=tp&&st1[x][y]==tp) dfs(col,lv,x,y+1,st1[x][y]);
	}
}
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				xx[i][j]=make_pair(-1,-1);
		for(int i=1;i<=n;i++)
		{
			cin>>st1[i];
			st1[i]=' '+st1[i];
		}
		for(int i=1;i<=n-1;i++)
		{
			cin>>st2[i];
			st2[i]=' '+st2[i];
		}
		for(int i=1;i<=q;i++)
		{
			int col=read(),lv=read(),x=read(),y=read(),ans=0;
			xx[x][y]=make_pair(col,lv);
			for(int j=1;j<=n;j++)
				for(int k=1;k<=m;k++)
					vis[j][k]=' ';
			vis[x][y]='3';
			if (x>1&&st2[x-1][y]!='0') if (st2[x-1][y]=='2') dfs(col,lv,x-1,y,'4');else dfs(col,lv,x-1,y,st2[x-1][y]);
			if (x<n&&st2[x][y]!='0') if (st2[x][y]=='2') dfs(col,lv,x+1,y,'5');else dfs(col,lv,x+1,y,st2[x][y]);
			if (y>1&&st1[x][y-1]!='0') if (st1[x][y-1]=='2') dfs(col,lv,x,y-1,'6');else dfs(col,lv,x,y-1,st1[x][y-1]);
			if (y<m&&st1[x][y]!='0') if (st1[x][y]=='2') dfs(col,lv,x,y+1,'7');else dfs(col,lv,x,y+1,st1[x][y]);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					if (vis[i][j]!=' ') ans++;
			cout<<ans-1<<endl;
		}
	}
	return 0;
}

