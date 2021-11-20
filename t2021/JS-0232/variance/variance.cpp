#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long sz=0,fh=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')fh=-1;ch=getchar();}
	while(isdigit(ch)){sz=sz*10+(ch-'0');ch=getchar();}
	return sz*fh;
}
const int N=10100;
long long n,a[N],s1=0,s2=0,ans=LONG_LONG_MAX;
long long calc(long long las,long long now){
	s1=s1-las*las+now*now;
	s2=s2-las+now;
	return n*s1-s2*s2;
}
int vis[100100];
void dfs(int lasi,long long sum){
	ans=min(ans,sum);
	if(vis[ans])return;
	vis[ans]=1; 
	for(int i=2;i<n;i++){
		if(i==lasi)continue;
		long long lass=a[i],nows=a[i-1]+a[i+1]-a[i];
		if(lass==nows)continue;
		a[i]=nows;
		//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		//cout<<endl;
		dfs(i,calc(lass,nows));
		a[i]=lass; 
	} 
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		//b[i]=a[i];
		s1+=a[i]*a[i];
		s2+=a[i];
	}
	dfs(1,calc(0,0));
	cout<<ans<<endl;
	//cout<<calc(0,0)<<endl;
	//cout<<calc(2,3)<<endl;
	return 0;
}

