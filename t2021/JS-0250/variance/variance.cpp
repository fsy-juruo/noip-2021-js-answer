#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}

#define int long long
#define lowbit(n) n&(-n)
int s1,s2,n,a[10010],ans;
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),s1+=a[i]*a[i],s2+=a[i];
	ans=n*s1-s2*s2;
		for (int i=1;i<=100000;i++){
		int id,sss1,sss2,pp,g=ans;
		for (int j=n-1;j>1;j--){
			if (a[j]>0&&a[j+1]>0&&a[j-1]>0){
				int p=a[j-1]+a[j+1]-a[j];
				int ss1=s1-a[j]*a[j]+p*p;
				int ss2=s2-a[j]+p;
				if (n*ss1-ss2*ss2<g){
					g=n*ss1-ss2*ss2;
					id=j; pp=p;
					sss1=ss1; sss2=ss2;
				}
			}
		
		}
		a[id]=pp; s1=sss1; s2=sss2;
		if (g==ans) break;
		ans=g;
		}
	cout<<ans<<endl;
	return 0;
}

