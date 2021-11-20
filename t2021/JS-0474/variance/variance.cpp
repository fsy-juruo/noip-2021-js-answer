#include<bits/stdc++.h>
using namespace std;
int n,ycl=0;
double fc=0,pj=0,a[10010],ans,nba,he,nhe,nva,dn;
void dfs(double ba,double va){
	for(int i=2;i<n;++i){
		ycl++;
		if(ycl>=10000000){
			cout<<(int)ans<<endl;
			exit(0);
		}
		double x=a[i],nx=a[i-1]+a[i+1]-a[i];
		if(abs(nx-ba/n)<abs(x-ba/n)){
			a[i]=a[i+1]+a[i-1]-a[i];
			nba=ba+nx-x;
			nva=va+ba*ba+n*(nx*nx-x*x)-nba*nba;
			ans=min(ans,nva);
			dfs(nba,nva);
			a[i]=x;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	dn=n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pj+=a[i];
	}
	for(int i=1;i<=n;++i){
		fc+=a[i]*a[i];
	}
	fc=fc*n-pj*pj;
	ans=fc;
	dfs(pj,fc);
	cout<<(int)ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
