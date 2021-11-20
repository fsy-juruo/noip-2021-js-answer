#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (i=a;i<b;++i)
int xx[]={-1,1,0,0},yy[]={0,0,-1,1},x,y,col,lv,cnt,ans;
struct node{
	//int up,dn,lt,rt;
	int dir[4];
	int sta=-1,lv;
}a[1000][1000];
void rd(int i){
	x+=xx[i];y+=yy[i];
	for (int j=0;j<4 and j!=(i+2)%4;++j){
		if(a[x][y].sta==-1&&a[x][y].dir[j]==3){
			ans++;rd(j);
			}
	}x-=xx[i];y-=yy[i];
	
}
void dfs(){
	ans=0;
	for (int i=0;i<4;++i){
		if (a[x][y].dir[i]==1 and a[x+xx[i]][y+yy[i]].sta!=a[x][y].sta)ans++;
		if (a[x][y].dir[i]==2){
			ans++;
			for(cnt=1;a[x+xx[i]*cnt][y+yy[i]*cnt].dir[i]==2 and a[x+xx[i]*cnt][y+yy[i]*cnt].sta==-1;cnt++){
				ans++;
			}if(a[x+xx[i]*cnt][y+yy[i]*cnt].sta==a[x][y].sta)ans--;
			//cout<<'k'<<ans<<endl;
		}
		if (a[x][y].dir[i]==3){
			//if(a[x+xx[i]][y+yy[i]].sta!=a[x][y].sta)ans++;
			rd(i);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t,m,n,q,i,j;string s;
	cin>>t;cin>>n>>m>>q;
	for (i=1;i<=n;++i){
		cin>>s;
		for (j=1;j<=m-1;++j){
			a[i][j].dir[3]=s[j-1]-48;
			a[i][j+1].dir[2]=s[j-1]-48;
		}
	}
	
	for (i=1;i<=n-1;++i){
		cin>>s;
		for (j=1;j<=m;++j){
			a[i][j].dir[1]=s[j-1]-48;
			a[i+1][j].dir[0]=s[j-1]-48;
		}
	}
	//cout<<a[3][3].dir[0];
	for(i=1;i<=q;++i){
		cin>>col>>lv>>x>>y;
		a[x][y].sta=col;a[x][y].lv=lv;
		dfs();
		cout<<ans<<endl;
	}
	return 0;
}
