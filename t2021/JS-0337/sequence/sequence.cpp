#include<bits/stdc++.h>
#define modd 998244353
using namespace std;
int n,m,k;
int v[105];
int a[105];
long long sum;
int num;
long long ans=0;
int check(long long x){
	num=0;
	while(x){
		long long m=x%2;
		if(m==1)
			num++;
		x=x>>1;
	}
	return num;
}
void dfs(int x){
	if(x==n+1){
		check(sum);
		if(num<=k){
			long long f=v[a[1]];
			for(int i=2;i<=n;i++){
			f*=v[a[i]];f%=modd;
			}
			ans+=f;
			ans%=modd;
			return ;
		}
}	
else{	
	for(int i=0;i<=m;i++){
		a[x]=i;
		sum+=pow(2,a[x]);	
		dfs(x+1);
		sum-=pow(2,a[x]);
	
	}
}

}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		cin>>v[i];
	dfs(1);
	cout<<ans%modd;
return 0;
}

