#include<cstdio>
#include<algorithm>
#define N 10100005
using namespace std;

int T,sum;
int a[N],ans[N],nxt[N];

bool check(int x){
	while(x){
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}

void init(){
	sum=0;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&a[i]);
		sum=max(sum,a[i]);
	}
	sum+=100000;
}

void solve(){
	for(int i=7;i<=sum;i++){
		if(!ans[i]&&check(i)){
			ans[i]=1;
			for(int j=2;j*i<=sum;j++) ans[i*j]=1;
		}
	}
	int x;
	for(int i=sum-1;i>=1;i--){
		if(!ans[i+1]) nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
	for(int i=1;i<=T;i++){
		if(ans[a[i]]) printf("-1\n");
		else printf("%d\n",nxt[a[i]]);
	}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	solve();
	return 0;
}
