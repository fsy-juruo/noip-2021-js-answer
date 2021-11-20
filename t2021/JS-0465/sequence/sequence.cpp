#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[200],s;
long long N=998244353,x,dp[32][32];
int read(){
	char c=' ';
	int x=0,y=1;
	while(c==' '||c=='\n')c=getchar();
	while(c!=' '&&c!='\n'){
		if(c!='-')x=x*10+c-'0';
		else y=-1;
		c=getchar();
	}
	return x*y;
}
void put(int x,char y){
	string s="";
	if(x<0){
		putchar('-');
		x=-x;
	}
	while(x!=0){
		s=s+char(x%10+'0');
		x/=10;
	}
	for(int i=s.size()-1;i>=0;i--){
		putchar(s[i]);
	}
	putchar(y);
}
int ksm(long long n,int x){
	long long ans=1;
	while(x!=0){
		if(x%2==1)ans=ans*n%N;
		n=n*n%N;
		x/=2;
	}
	return ans%N;
}
int c(long long n,long long m){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%N;
	}
	for(int i=1;i<=m;i++){
		ans=ans*ksm(i,N-2)%N;
	}
	for(int i=1;i<=n-m;i++){
		ans=ans*ksm(i,N-2)%N;
	}
	return ans;
}
map<string,bool>fl;
void dfs(int x,int a[]){
	if(x>n){
		return;
	}
	if(a[1]<=m){
		string s="";
		for(int i=1;i<=x;i++){
			s=s+char(a[i]+'0');
		}
		if(fl[s])return;
		fl[s]=1;
		int ans=1;
		for(int i=1;i<=x;i++){
			ans=ans*v[a[i]]%N;
		}
//		cout<<'\n';
		int gs=1,js=1,y=0;
		for(int i=1;i<x;i++){
			if(a[i]!=a[i+1]){
				gs=gs*c(x-y,js)%N;
				y+=js;
				js=1;
			}
			else{
				js++;
			}
		}
//		cout<<x<<' '<<gs<<' '<<ans<<'\n';
		dp[1][x]+=gs*ans%N;
	}
//	for(int i=1;i<=x;i++)cout<<a[i]<<" ";
//		cout<<'\n';
	int b[x+2];
	for(int i=1;i<=x;i++){
		if(a[i]<1)break; 
		if(i==x){
			for(int j=1;j<=x;j++){
				b[j]=a[j];
			}
			b[x]--;
			b[x+1]=b[x];
			dfs(x+1,b);
		}
		else if(a[i]!=a[i+1]){
			for(int j=1;j<=i;j++){
				b[j]=a[j];
			}
			b[i]--;
			b[i+1]=b[i];
			for(int j=i+1;j<=x;j++){
				b[j+1]=a[j];
			}
			dfs(x+1,b);
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=0;i<=m;i++){
		v[i]=read();
	}
	s=0;
	x=1;
	while(x<n){
		s++;
		x*=2;
	}
	int ss=s;
	while(s<=m+ss-1){
		int jdybd[2]={0,s};
		dfs(1,jdybd);
		s++;
	}
	int ans=dp[1][n];
//	for(int i=2;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<j;k++){
//				for(int k2=1;k2<i;k2++){
//					if(dp[k2][k]!=0&&dp[i-k2][n-k]!=0){
//						dp[i][j]+=dp[k2][k]+dp[i-k2][n-k];
//					}
//				}
//			}
//		}
//		ans+=dp[i][n];
//	}
	put(ans,'\n');
	return 0;
}
