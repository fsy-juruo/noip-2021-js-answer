#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,a[N],ans,sum;
double ab,fang;
inline int read(){
	int ss=0;char cc=getchar();
	for(;!isdigit(cc);cc=getchar());
	for(;isdigit(cc);cc=getchar()) ss=(ss<<1)+(ss<<3)+cc-'0';
	return ss;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();sum+=a[i];
	}
	ab=sum*1.0/n;
	for(int i=1;i<=n;++i) fang+=(a[i]-ab)*(a[i]-ab);
	ans=fang*n;
	printf("%d\n",ans);
	return 0;
}
