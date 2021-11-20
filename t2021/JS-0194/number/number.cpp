#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read() {
	int s=0,w=1; char ch=getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w=-1; ch=getchar();}
	while(ch <= '9' && ch >= '0') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
const int N=10000100;
bool check(int x) {
	while(x) {
		if(x%10== 7) return true;
		x/=10;
	}
	return false;
}
int t,p[800040],vis[N],cnt,x,n,q[200010],js;
void init() {
	//int mid=(n+2)/2;
	for(int i=7;i<=n;i++) {
		if(vis[i]) continue;
		if(check(i)) {
			vis[i]=1;
			//if(i > mid) continue;
			for(int j=2;i*j<=n;j++) vis[i*j]=1;
		} 
	} 
	for(int i=1;i<=n;i++) if(!vis[i]) p[++cnt]=i;
	return;
}
int main() {
	freopen("number.in","r",stdin);   
	freopen("number.out","w",stdout); 
	t=read();
	while(t--) {
		q[++js]=read();
		n=max(q[js],n);
	}
	n+=30;
	init();
	for(int i=1;i<=js;i++) {
		if(vis[q[i]]) { 
			printf("-1\n"); continue;
		}
		int k=lower_bound(p+1,p+cnt+1,q[i])-p;
		printf("%d\n",p[k+1]); //763408
	}
	return 0;
}
/*
4
6
33
69
300

5 
90
99
106
114
169
*/
