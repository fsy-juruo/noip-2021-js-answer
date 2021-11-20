#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int n,sum,a[505],t=1,dfr,v[100005];
double  fc,p,ans=1e9+7;

void dfs(){
	for(int i=2;i<n;i++){
		int u=a[i];
	    a[i]=a[i-1]+a[i+1]-u;
	    if(a[i]!=u){
	    	sum=fc=0;
	        for(int i=1;i<=n;i++) sum+=a[i];
	        p=1.0*sum/n;
	        for(int i=1;i<=n;i++) fc+=(1.0*a[i]-p)*(1.0*a[i]-p);
	        if((fc/n)<ans||(fc/n)>ans){
			    ans=min(ans,fc/n);
			    dfs();
			    a[i]=u;
			}
		}
	}
}

int main(){
    freopen("varience.in","r",stdin);
    freopen("varience.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) sum+=a[i];
	p=1.0*sum/n;
	for(int i=1;i<=n;i++) fc+=(1.0*a[i]-p)*(1.0*a[i]-p);
	ans=min(ans,fc/n);
    dfs();
	printf("%d\n",int(ans*n*n));
	return 0;
}
