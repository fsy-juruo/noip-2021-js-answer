#include<bits/stdc++.h>
using namespace std;
long long n,m,k,z,ans=0;
long long v[102];
int dfs(int he,int cou,int zhi){
	if(he==z&&cou==n){
		ans+=zhi;
		ans%=998244353;
	}
	else if(he==z&&cou!=n){
		return 0;
	}
	else if(he>z){
		return 0;
	}
	else if(cou>n){
		return 0;
	}
	int y;
	for(int i=0;i<m;i++){
		y=1;
		y*=2;
	}
	y*=(n-cou);
	if(he+y<z){
		return 0;
	}
	for(int i=0;i<=m;i++){
		int q=1;
		for(int j=1;j<=i;j++){
			q*=2;
		}
		if((he+q)<=z){
			dfs((he+q),cou+1,(zhi*v[i])%998244353);
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	long long t=n;
	long long w=n;
	for(int i=0;i<m;i++){
		w*=2;
	}
	long long cou=0;
	long long c;
	for(int i=t;i<=w;i++){
		c=i;
		cou=0;
		while(c!=0){
			if(c%2==1){
				cou++;
			}
			c/=2;
		}
		if(cou<=k){
			z=i;
			dfs(0,0,1);
		}
	}
	cout<<ans%998244353;
}
