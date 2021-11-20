#include<bits/stdc++.h>
using namespace std;
int mod=998244353,n,m,k,a[102],gs[9000],opt[50][9000],sm[50][50][9000],c[31][31],ans;
int qgs(int x){
	int ans;
	while(x!=0){
		x-=(x&-x);
		ans++;
	}
	return ans;
}
int mi(int x,int y){
	int tmp=1;
	for(int i=1;i<=y;i++)
	tmp=tmp*x%mod;
	return tmp;
}
void dfs(int y,int yf,int f,int yn){
	if(f==-1)
	return;
	int gjl=(1<<(yf-f));
	if(gjl>yn)
	return;
	sm[f][yn][y]=sm[f][yn-gjl][y-(1<<yf)]+gjl;
	opt[yn][y]=(opt[yn][y]+(opt[yn-gjl][y-(1<<yf)]/c[yn-gjl][sm[f][yn-gjl][y-(1<<yf)]]*c[yn][sm[f][yn][y]]%mod*mi(a[f],gjl)%mod))%mod;
	dfs(y,yf,f-1,yn);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=0;i<=m;i++)
    cin >> a[i];
    for(int i=0;i<=31;i++)
    for(int j=0;j<=i;j++)
    c[i][j]=1;
    for(int i=2;i<=31;i++)
    for(int j=1;j<=i;j++){
    	c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for(int i=1;i<=31;i++)
	for(int j=1;j<=4097;j++)
	opt[i][j]=1;
	for(int i=1;i<=4097;i++)
	gs[i]=qgs(i);
	for(int i=0;i<(1<<(m+1));i++){
		for(int j=0;j<=m;j++){
			if(i&(1<<j)){
				for(int q=1;q<=n;q++)
				dfs(i,j,j,q);
			}
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<(1<<(m+1));j++)
			if(gs[j]<=k)
			ans=(ans+opt[n][j])%mod;
	}
	cout << ans << endl;
	return 0;
}
