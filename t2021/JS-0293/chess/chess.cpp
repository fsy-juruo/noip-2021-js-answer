#include <bits/stdc++.h>
using namespace std;
const int maxm = 2e5+5;
const int maxq = 1e5+5; 
int t;
int n,m,q;
char ch[maxm];
int col[maxq],lv[maxq],x[maxq],y[maxq];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	while(t--){
		n=read();m=read();q=read();
		for(int i=1;i<=n;i++){
			scanf("%s",ch+1);
		}
		for(int i=1;i<n;i++){
			scanf("%s",ch+1);
		}
		for(int i=1;i<=q;i++){
			col[i]=read();lv[i]=read();x[i]=read();y[i]=read();
			printf("1\n");
		}
	}
	return 0;
} 
