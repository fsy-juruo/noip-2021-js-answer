#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rl(){
	int a=0,nega=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')nega=-1;c=getchar();}
	while(isdigit(c)){a=(a*10)+(c^48);c=getchar();}
	return a*nega;
}
ll tans,a[11451],ap[303000][20];
ll n;
void js(){
	ll ab=0;
	for(int i=1;i<=n;i++){
		ab=(a[i]+ab);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=ans+(n*a[i]-ab)*(n*a[i]-ab);
	}
	ll pp=n;
	ans/=pp;
	tans=min(tans,ans);
}
int tot;
void dfs(){
	int flag=0;
	for(int i=1;i<=tot;i++){
		flag=0;
		for(int j=1;j<=n;j++){
			if(a[j]!=ap[i][j]){
				flag=1;
				break;
			}
		}
		if(flag==0)return;
	}tot++;
	for(int i=1;i<=n;i++)ap[tot][i]=a[i];js();
	for(int i=2;i<n;i++){
		a[i]=a[i-1]+a[i+1]-a[i];
		dfs();
		a[i]=a[i-1]+a[i+1]-a[i];
	}
	return;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	tans=LLONG_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs();
	cout<<tans<<endl;
	return 0;
}

