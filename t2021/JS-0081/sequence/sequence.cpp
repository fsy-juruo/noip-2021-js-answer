#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,a[200],ans,cs[110],h[110],mi,mx;
int read(){
	int xx=0,ff=1;char ch=getchar();
	while (!isdigit(ch)) {if (ch=='-') ff=-1; ch=getchar();}
	while (isdigit(ch)) {xx=(xx<<1)+(xx<<3)+ch-'0';ch=getchar();}
	return xx*ff;
}
void dfs(int x,int sum){
	if (sum>mx) return;
	if (sum+(n-x+1)*cs[m]<mi) return;
	if (x==n+1){
		int kk=sum,s=0;
		while (kk) {
			if (kk%2==1) s++;
			kk/=2;
		}
		if (s<=k){
			int ss=1;
			for (int i=1; i<=n; i++){
			//	cout<<a[h[i]]<<' ';
				ss=ss*a[h[i]]%998244353;
			}//cout<<endl;
			ans=(ans+ss)%998244353;
		}
		return;
	}
	for (int i=0; i<=m; i++)
	{
		h[x]=i;
	    dfs(x+1,(sum+cs[i])%998244353);
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    n=read(),m=read(),k=read();
    
    for (int i=0; i<=m; i++)
    a[i]=read();
    int s=1;cs[0]=1;
    for (int i=1; i<=100; i++)
      s=s*2%998244353,cs[i]=s;
    mi=n,mx=n*cs[m];
    dfs(1,0);
    cout<<ans<<endl;
	return 0;
}
