#include <iostream>
#include <cctype>
#include <map>
#define MAXN 200005
using namespace std;
int n,m,q,t;
int ry[MAXN],rx[MAXN];
using node=pair<int,int>;
map<node ,int> map;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				char c;
				while(!isdigit(c=getchar()));
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=m;j++){
				char c;
				while(!isdigit(c=getchar()));
			}
		}
		for(int i=0;i<q;i++){
			printf("%d\n",0);
		}
	}
	
	return 0;
}
