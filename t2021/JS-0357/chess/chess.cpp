//best wishes to myself;
//rp++;
//see you nest time;
#include<bits/stdc++.h>
#define mp make_pair
#define mmp(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define np pn.first
#define pp pn.second
#define f1 first
#define s2 second
using namespace std;
int T,n,m,q;
const int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
map<pair<pair<int,int>,pair<int,int> >,int> ma;
map<pair<int,int>,bool> is;
map<pair<int,int>,pair<int,int> > ha;
map<pair<pair<int,int>,int>,bool> vis;
queue<pair<pair<int,int>,pair<int,int> > > que;
pair<pair<int,int>,pair<int,int> > pn;
int read(){
	char ch=getchar();
	int f=1,ans=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+(ch-'0');
		ch=getchar();
	}
	return f*ans;
}
bool checkout(int x,int y){
	if(x<1||y<1||x>n||y>m) return true;
	return false;
}
int cnt(int x,int y,int lv,int col){
	while(!que.empty()) que.pop();
	vis.clear();
	que.push(mmp(x,y,-1,-1));
	int num=-1;
	while(!que.empty()){
		int bk=ma[mmp(pp.f1,pp.s2,np.f1,np.s2)],nk;
		pn=que.front();
		que.pop();
		if(vis[mp(mp(np.f1,np.s2),bk)]) continue;
		if(is[np]){
			if(col!=ha[np].f1&&lv>=ha[np].s2){
				//printf("%d %d\n",np.f1,np.s2);
				num++;
				vis[mp(mp(np.f1,np.s2),bk)]=true;
			}
			continue;
		}
		//printf("%d %d\n",np.f1,np.s2);
		num++;
		vis[mp(mp(np.f1,np.s2),bk)]=true;
		if(pp.f1==-1&&pp.s2==-1){
			for(int i=0;i<4;i++){
				int xx=np.f1+dx[i],yy=np.s2+dy[i];
				if(checkout(xx,yy)) continue;
				if(ma[mmp(np.f1,np.s2,xx,yy)]==0) continue;
				que.push(mmp(xx,yy,np.f1,np.s2));
			}
		}
		else{
			for(int i=0;i<4;i++){
				int xx=np.f1+dx[i],yy=np.s2+dy[i];
				if(checkout(xx,yy)||mp(xx,yy)==pp) continue;
				nk=ma[mmp(np.f1,np.s2,xx,yy)];
				//if(xx==2&&yy==1) printf("there %d %d\n",nk,bk);//
				if(nk==0||bk!=nk) continue;
				if(bk==1) continue;
				if(nk==2&&((xx-np.f1)!=(np.f1-pp.f1))) continue;
				que.push(mmp(xx,yy,np.f1,np.s2));
			}
		}
	}
	return num;
}
void solve(){
	ma.clear();
	is.clear();
	ha.clear();
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch<'0'||ch>'3') ch=getchar();
		for(int j=1;j<m;j++){
			int kind=(ch-'0');
			ma[mmp(i,j,i,j+1)]=ma[mmp(i,j+1,i,j)]=kind;
			ch=getchar();
		}
	}
	for(int i=1;i<n;i++){
		char ch=getchar();
		while(ch<'0'||ch>'3') ch=getchar();
		for(int j=1;j<=m;j++){
			int kind=(ch-'0');
			ma[mmp(i,j,i+1,j)]=ma[mmp(i+1,j,i,j)]=kind;
			ch=getchar();
		}
	}
	//system("pause");
	while(q--){
		int col=read(),lv=read(),x=read(),y=read();
		printf("%d\n",cnt(x,y,lv,col));
		is[mp(x,y)]=true;
		ha[mp(x,y)]=mp(col,lv);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}
