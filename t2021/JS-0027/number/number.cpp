#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define F first
#define S second
#define N 11000005
#define mod 1000000007
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
int b[N],cnt=0,p[N],nxt[N];
inline int jd(int x){
	while(x){
		if(x%10==7) return 2;
		x/=10;
	}
	return 0;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int a,pr=0;
	for(int i=1;i<N;++i){
		if(!b[i]){
			b[i]=jd(i);
			if(b[i]==2){
				p[cnt++]=i;
				for(int j=2;i*j<N;++j) b[i*j]=1;
			}
		}
		/*
		for(int j=0;j<cnt;++j){
			t=1ll*i*p[j];
			if(t>=N) break;
			b[t]=1;
			if(i%p[j]==0) break;
		}
		*/
	}
	memset(nxt,-1,sizeof(nxt));
	for(int i=1;i<N;++i){
		if(b[i]) continue;
		nxt[pr]=i;
		pr=i;
	}
	//for(int i=0;i<cnt;++i)printf("%d ",p[i]);puts("");
	/*
	for(int i=1;i<=100;++i){
		printf("%d ",b[i]);
		if(i%20==0) puts("");
	}
	*/
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&a);
		printf("%d\n",nxt[a]);
	}
	return 0;
}
