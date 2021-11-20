#include<bits/stdc++.h>
using namespace std;
const int N=200010,M=2*N;
int h[N],e[M],ne[M],w[M],idx;
int T;
int ans;
struct Node{
	int c,l,step;
}p[N];
string innn;
int n,m,q;
void add(int a,int b,int c){
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
bool check(int x,int y){
	return (p[x].c!=p[y].c&&p[x].l>=p[y].l);
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(h,-1,sizeof(h));
		idx=0;
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++){
			cin>>innn;
			for(int j=0;j<m-1;j++){
				int a=m*(i-1)+j,inn=innn[j]-'0';
				if(inn) add(a,a+1,inn),add(a+1,a,inn);
			}
		}
		for(int i=1;i<n;i++){
			cin>>innn;
			for(int j=0;j<m;j++){
				int a=m*(i-1)+j,inn=innn[j]-'0';
				if(inn) add(a,a+m,inn),add(a+m,a,inn);
			}
		}
		while(q--){
			int cc,ll,x,y;
			scanf("%d%d%d%d",&cc,&ll,&x,&y);
			int a=m*(x-1)+y;
			p[a]={cc,ll,q};
			ans=0;
			for(int i=h[a];~i;i=ne[i]){
				int j=e[i];
				if(!p[j].step) ans++;
				else if(p[i].step==p[j].step&&check(a,j)) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
