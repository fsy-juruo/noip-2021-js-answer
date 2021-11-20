#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}
	return s*f;
}
int n,a[10001],ans=INT_MAX;
double pj2(){
	double s=0;
	for(int i=1;i<=n;i++){
		s+=(double)a[i];
	}
	return ((double)s/(double)n);
}
double fc(double p){
	double s=0;
	for(int i=1;i<=n;i++){
		s+=(a[i]-p)*(a[i]-p);
	}
	return s*n;
}
double t(){
	return fc(pj2());
}
void dfs(){
	for(int i=2;i<n;i++){
		double x=pj2();
		int l=a[i];
		double u=abs(a[i]-x);
		double v=abs(a[i-1]+a[i+1]-a[i]-x);

		
		if(v<u){
			a[i]=a[i-1]+a[i+1]-a[i];
			int f=t();
			ans=min(ans,f);;
			dfs();
			a[i]=l;
		}
	}
}
int main(){

freopen("variance.in","r",stdin);
freopen("variance.out","w",stdout);

n=read();
for(int i=1;i<=n;i++){
	a[i]=read();
}
ans=t();
dfs();
cout<<ans<<endl;	
return 0;
}

