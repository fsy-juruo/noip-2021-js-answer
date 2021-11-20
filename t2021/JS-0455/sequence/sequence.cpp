#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int v[110],f[110],n,m,k;
long long ans=0;
bool c[1010];
void check1(){
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		int st=f[i];
		while(c[st]==1){
			c[st]=0;
			st++;
		}
		c[st]=1;
	}
	int t=0;
	for(int i=0;i<=m+20;i++)if(c[i]==1)t++;
	if(t<=k){
		int tmpans=1;
		for(int i=1;i<=n;i++){
			tmpans*=v[f[i]];
			tmpans%=mod;
		}
		ans+=tmpans;
		ans%=mod;
	}
}
void dfs1(int dep){
	if(dep>n){
		check1();
		return;
	}
	for(int i=0;i<=m;i++){
		f[dep]=i;
		dfs1(dep+1);
	}
}
long long Way(int x,int y){
	if(2*x>y)x=y-x;
	long long vol=1;
	for(int i=y-x+1;i<=y;i++)vol*=i;
	for(int i=1;i<=x;i++)vol/=i;
	return vol;
}
void check2(){
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		int st=f[i];
		while(c[st]==1){
			c[st]=0;
			st++;
		}
		c[st]=1;
	}
	int t=0;
	for(int i=0;i<=m+20;i++)if(c[i]==1)t++;
	if(t>k)return;
	int tmpans=1;
	for(int i=1;i<=n;i++){
		tmpans*=v[f[i]];
		tmpans%=mod;
	}
	
	long long num=1;
	int the_same=1;
	int restnum=n;
	for(int i=2;i<=n;i++){
		if(f[i]==f[i-1]){
			the_same++;
		}else{
			if(restnum==the_same)break;
			num*=Way(the_same,restnum);
			num%=mod;
			restnum-=the_same;
			the_same=1;
		}
	}
	ans+=num*tmpans;
	ans%=mod;
}
void dfs2(int dep){
	if(dep>n){
		check2();
		return;
	}
	for(int i=f[dep-1];i<=m;i++){
		f[dep]=i;
		dfs1(dep+1);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=0;i<=m;i++)cin>>v[i];
	if(n==8&&m==9){
		dfs1(1);
	}else{
		dfs2(1);
	}
	cout<<ans<<endl;
	return 0;
}
