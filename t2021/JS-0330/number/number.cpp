#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;
int st[MAXN],T,n,fn[MAXN],cnt;
bool px(int x) {
	while(x!=0) {
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
void work() {
	for(int i=n+1;;i++) {
		if(st[i]==0) {
			printf("%d\n",i);return;
		}
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=MAXN-5;i++) {
		st[i]=px(i);if(st[i]) fn[++cnt]=i;
	}
	for(int i=1;i<=MAXN-5;i++) {
		for(int j=1;fn[j]<=i/2;j++) {
			if(i%fn[j]==0) st[i]=1;
		}
	}
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		if(st[n]!=0) printf("-1\n");
		else work();
	}
	return 0;
}
