#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long ans[35],tot=0;
int n,m,k;
int v[105];
template<typename _T>
void read(_T &x){
	int f=1;x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
}
long long qpow(int a,int b){
	long long ans=1;
	while(b){
		if(b&1){
			ans*=a;
			ans%=Mod;
		}
		a*=a;
		a%=Mod;
		b/=2;
	}
	return ans;
}
long long cal(){
	long long t=1;
	for(int i=1;i<=n;i++){
		t*=v[ans[i]];
		t%=Mod;
	}
	return t;
}
bool check(){
	long long S=0;
	for(int i=1;i<=n;i++){
		S+=qpow(2,ans[i]);
	}
	int sum=0;
	while(S){
		if(S%2==1) sum++;
		S/=2;
	}
	if(sum<=k) return true;
	return false;
}
void dfs(int cnt){
	if(cnt==n+1){
		if(check()==true){
			tot+=cal();
			tot%=Mod;
		}
		return ;
	}
	for(int i=0;i<=m;i++){
		ans[cnt]=i;
		dfs(cnt+1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    memset(ans,0,sizeof(ans));
    read(n),read(m),read(k);
    for(int i=0;i<=m;i++){
    	read(v[i]);
	}
	dfs(1);
	printf("%lld\n",tot);
	return 0;
}
