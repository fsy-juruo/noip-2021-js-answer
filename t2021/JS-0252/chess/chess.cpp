#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200005;
const int INF=1000000007;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

int n,m,q;
vector<pii> mp[maxn];
vector<bool> vis[maxn];
char s[maxn];
vector<int> verdict1[maxn];
vector<int> verdict2[maxn];

struct status{
	int type;
	int dir; //if has zhixing 0~3 else -1
	int x,y; //coodirnate
	bool e;
};

int getver(int x,int y,int dir){
//	cerr<<"Accessing to "<<x<<' '<<y<<' '<<dir<<endl;
	if(dir==0){
		return verdict2[x-1][y];
	}
	if(dir==1){
		return verdict2[x][y];
	}
	if(dir==2){
		return verdict1[x][y-1];
	}
	if(dir==3){
		return verdict1[x][y];
	}
}

void print(status s){
	fprintf(stderr,"In the current status, while at (%d,%d),facing %d\n",s.x+1,s.y+1,s.dir);
	fprintf(stderr,"Road type=%d\n",s.type);
	if(s.e)fprintf(stderr,"The chess has eaten another chess.\n");
	else fprintf(stderr,"The chess hasn't eaten another chess.\n");
	puts("----------------------");
}

void solve1(){
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)mp[i][j]=pii(-1,-1);
	for(int i=0;i<q;++i){
		int c=read(),lv=read(),x=read()-1,y=read()-1;
		for(int j=0;j<n;++j)for(int k=0;k<m;++k)vis[j][k]=false;
		queue<status> Q;
		Q.push({-1,-2,x,y,false});
		vis[x][y]=true;
		int ans=0;
		while(Q.size()){
			status s=Q.front();
			Q.pop();
		//	print(s);
			++ans;
			if(s.e)continue;
			for(int k=0;k<4;++k){
				if(s.type==2&&s.dir!=-2&&s.dir!=k)continue;
				int xx=s.x+dx[k],yy=s.y+dy[k];
			//	cerr<<xx<<' '<<yy<<endl;
				bool e=false;
				int dir=k;
				if(!(xx>=0&&xx<n&&yy>=0&&yy<m))continue;
				if(vis[xx][yy])continue;
				int v=getver(s.x,s.y,k);
				if(!v)continue;
				if(s.type!=-1&&s.type!=v)continue;
				if(s.e&&mp[xx][yy]!=pii(-1,-1))continue;
				if(mp[xx][yy]!=pii(-1,-1)){
			//		cerr<<xx<<' '<<yy<<' '<<mp[xx][yy].first<<' '<<mp[xx][yy].second<<endl;
					if(mp[xx][yy].first==c)continue;
					else if(mp[xx][yy].second>lv)continue;
					e=true;
				}
				if(v==2&&s.dir==-1)continue;
				if(s.dir==-2)dir=k;
				else if(s.dir==-1)dir=-1;
				else if(s.dir!=k)dir=-1;
				else dir=k;
				vis[xx][yy]=true;
				Q.push({v,dir,xx,yy,e});
			}
		}
		mp[x][y]=make_pair(c,lv);
		printf("%d\n",ans-1);
//		fprintf(stderr,"The chess finished\n");
	}
}

void solve(){
	n=read(),m=read(),q=read();
	for(int i=0;i<n;++i)verdict1[i].resize(m+5),verdict2[i].resize(m+5),mp[i].resize(m+5),vis[i].resize(m+5);
	for(int i=0;i<n;++i){
		scanf("%s",s);
		for(int j=0;j<m-1;++j){verdict1[i][j]=s[j]-'0';}
	}
	for(int i=0;i<n-1;++i){
		scanf("%s",s);
		for(int j=0;j<m;++j){verdict2[i][j]=s[j]-'0';}
	}
	solve1();
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while(T--)solve();
	return 0;
}

