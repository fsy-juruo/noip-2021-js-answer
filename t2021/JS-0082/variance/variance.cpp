#include<bits/stdc++.h>
//#define int long long
//#define mo
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
double ansans=INT_MAX;
int n,a[10005],c[10005],x[10005];
void dfs(int l,int r,int t){
	if (t==0)
	{
		int b[10005],s=0;
		double ans=0;
		b[1]=a[1];
		s+=b[1];
		for(int i=1;i<n;i++)
			b[i+1]=b[i]+c[x[i]],s+=b[i+1];
		for(int i=1;i<=n;i++)
			ans+=(1.0*b[i]-1.0*s/n)*(1.0*b[i]-1.0*s/n);
		if (ans*n<ansans) ansans=ans*n;
		return;
	}
	x[l]=t; dfs(l+1,r,t-1);
	x[r]=t; dfs(l,r-1,t-1);
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=2;i<=n;i++) c[i-1]=a[i]-a[i-1];
	sort(c+1,c+n);
	dfs(1,n-1,n-1);
	cout<<ansans<<endl;
	return 0;
}

