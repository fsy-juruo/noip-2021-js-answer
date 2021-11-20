#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define fi first
#define sc second
using namespace std;

int rdi(){
	int cur=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		cur*=10;
		cur+=((int)ch-'0');
		ch=getchar();
	}
	return cur;
}
int n,m,q;
int v[4][5010][5010];
bool can[5010][5010];
pair<int,int> a[5010][5010];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int getans(){
	memset(can,0,sizeof(can));
	int x,y,l,c;
	cin>>c>>l>>x>>y;
	c++;
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		int sx=p.fi,sy=p.sc;
		//cout<<sx<<" "<<sy<<endl;
		rep(i,4){
			if(v[i][sx][sy]!=3){
				continue;
			}
			int tx=sx+dx[i],ty=sy+dy[i];
			//cout<<"t"<<tx<<" "<<ty<<endl;
			if(tx<1||ty<1||tx>m||ty>n){
				continue;
			}
			if(can[tx][ty]){
				continue;
			}
			if(a[tx][ty].fi==c||a[tx][ty].sc>l){
				continue;
			}
			can[tx][ty]=1;
			//cout<<"pos:"<<tx<<" "<<ty<<endl;
			if(a[tx][ty].fi==0)q.push(make_pair(tx,ty));
		}
	}
	rep(i,4){
		int tx=x+dx[i],ty=y+dy[i];
		if(v[i][x][y]==1){
			if(a[tx][ty].fi==0||(a[tx][ty].fi!=c&&a[tx][ty].fi<=l))can[tx][ty]=1;
		}
		else if(v[i][x][y]==2){
			//tx=x;ty=y;
			//cout<<"2:"<<tx<<" "<<ty<<endl;
			while(1){
				if(tx<=0||ty<=0||tx>m||ty>n){
					break;
				}
				if(a[tx][ty].fi==c||a[tx][ty].fi>l){
					break;
				}
				//cout<<"22:"<<tx<<" "<<ty<<" "<<v[i][tx][ty]<<endl;
				can[tx][ty]=1;
				if(v[i][tx][ty]!=2){
					break;
				}
				if(a[tx][ty].fi!=0){
					break;
				}
				tx+=dx[i];
				ty+=dy[i];
				//cout<<tx<<" "<<ty<<endl;
			}
		}
	}
	can[x][y]=0;
	int ans=0;
	forn(i,n){
		forn(j,m){
			//if(can[i][j])cout<<"k:"<<i<<" "<<j<<endl;
			ans+=(int)can[i][j];
		}
	}
	a[x][y]=make_pair(c,l);
	return ans;
}
void g1(){
	memset(can,0,sizeof(can));
	forn(i,q){
		cout<<getans()<<endl;
	}
}
void solve(){
	cin>>n>>m>>q;
	memset(v,0,sizeof(v));
	forn(i,n){
		string s;
		cin>>s;
		forn(j,m-1){
			int x=s[j-1]-'0';
			v[0][i][j]=x;
			v[1][i][j+1]=x;
		}
	}
	forn(i,n-1){
		string s;
		cin>>s;
		forn(j,m){
			int x=s[j-1]-'0';
			v[2][i][j]=x;
			v[3][i+1][j]=x;
		}
	}
	if(n*m<=5000){
		g1();
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
