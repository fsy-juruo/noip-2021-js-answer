#include <bits/stdc++.h>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
int q[210000],svn[5000000],p,t,tot,T,i,j,n,N,c;
bool a[20000001];
int read(){
	int x=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	rep(i,1,T){
		q[i]=read();
		n=max(n,q[i]);
	}
	N=n+10000;
	if (n>100000) N=n+n/10;
	rep(i,1,N){
		t=i,p=0;
		while (t){
			c=t%10;
			if (c==7){p=1;break;}
		    t/=10;
		}
		if (p==1) svn[++tot]=i;
	}
	rep(i,1,tot){
		t=svn[i];
		while (t<=N){
			a[t]=1;
			t=t+svn[i];
		}
	}
	rep(i,1,T){
		t=q[i],p=0;
		while (t){
			c=t%10;
			if (c==7){p=1;break;}
		    t/=10;
		}
		if (p==1) {printf("-1\n");continue;}
		if (a[q[i]]) {printf("-1\n");continue;}
		t=q[i]+1;
		while (t){
			if (!a[t]){printf("%d\n",t);break;}
			t++;
		}
	}
	return 0;
}
