#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fn "number"
const int MAXN=10000777;
int T,c[MAXN],v[MAXN],tot=0;

inline LL read(){
	LL xs=0,ys=1;char ss=getchar();
	while(ss<'0'||ss>'9'){if(ss=='-')ys=-1;ss=getchar();}
	while(ss>='0'&&ss<='9'){xs=xs*10+ss-'0';ss=getchar();}
	return xs*ys;
}


bool p(int nm){
	while(nm){
		if(nm%10==7) return true;
		nm/=10;
	}
	return nm;
}

int main(){
	freopen(fn".in","r",stdin);
	freopen(fn".out","w",stdout);
	T=read();
	memset(c,0,sizeof(c));
//	int n=read();
	for(int i=1;i<MAXN;++i){
		if(c[i]==0) {
			if(p(i))for(int j=1;i*j<MAXN;++j) c[i*j]=-1;
			else {
				++tot;
				v[tot]=i;
				c[i]=tot;
			}
		}
	}
	for(int i=1;i<=T;++i) {
		int num=read();
		if(c[num]==-1) {
			printf("-1\n");
			continue;
		}
		printf("%d\n",v[c[num]+1]);
	} 
	return 0;
}

