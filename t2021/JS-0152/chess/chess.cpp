#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,q;
int pa[2][200002]={0};
pair<int,int> nwg[200002];
int read(){
	char c=getchar();
	int ret=0;
	while(c>='0'&&c<='9'){
		ret=(ret<<3)+(ret<<1)+(c-'0');
		c=getchar();
	}
	return ret;
}
void print(int x){
	string ssss;
	int xx=x;
	while(xx){
		ssss+=char(xx%10+'0');
		xx/=10;
	}
	for(int i=(int)ssss.length()-1;i>=0;i--) putchar(ssss[i]);
	return;
}
inline int ad(int x,int y){return (x-1)*m+y;}
inline pair<int,int> iad(int x){return make_pair((x-1)%m+1,(x-1)/m);}
void solve23(){
	while(q--){
		int c,v,x,y;
		c=read(); v=read(); x=read(); y=read();
		nwg[ad(x,y)]=make_pair(c,v);
		int cnt=0;
		if(y!=m&&pa[0][ad(x,y)]==1&&(nwg[ad(x,y+1)].second==0||(nwg[ad(x,y+1)].first!=nwg[ad(x,y)].first&&nwg[ad(x,y+1)].second<=nwg[ad(x,y)].second))) cnt++;
		if(x!=n&&pa[1][ad(x,y)]==1&&(nwg[ad(x+1,y)].second==0||(nwg[ad(x+1,y)].first!=nwg[ad(x,y)].first&&nwg[ad(x+1,y)].second<=nwg[ad(x,y)].second))) cnt++;
		if(y!=1&&pa[0][ad(x,y-1)]==1&&(nwg[ad(x,y-1)].second==0||(nwg[ad(x,y-1)].first!=nwg[ad(x,y)].first&&nwg[ad(x,y-1)].second<=nwg[ad(x,y)].second))) cnt++;
		if(x!=1&&pa[0][ad(x-1,y)]==1&&(nwg[ad(x-1,y)].second==0||(nwg[ad(x-1,y)].first!=nwg[ad(x,y)].first&&nwg[ad(x-1,y)].second<=nwg[ad(x,y)].second))) cnt++;
		print(cnt);
		putchar('\n');
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	while(t--){
		for(int i=0;i<=200000;i++) nwg[i]=make_pair(0,0);
		bool no[4];
		no[2]=no[3]=true;
		n=read(); m=read(); q=read();
		for(int i=1;i<=n;i++){
			for(int j=0;j<m-1;j++){
				char c=getchar();
				pa[0][(i-1)*m+j+1]=int(c-'0');
				if(int(c-'0')==2) no[2]=false;
				else if(int(c-'0')==3) no[3]=false;
			}
			char c=getchar();
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<m;j++){
				char c=getchar();
				pa[1][(i-1)*m+j+1]=int(c-'0');
				if(int(c-'0')==2) no[2]=false;
				else if(int(c-'0')==3) no[3]=false;
			}
			char c=getchar();
		}
		if(no[2]&&no[3]) solve23();
		//else if(no[2]) solve2();
		//else if(no[3]) solve3();
		//else solve0();
	}
}

