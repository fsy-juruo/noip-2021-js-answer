#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,k;
int a[102];
int nw[102]={0};
int ans=0;
int pw[32]={0};
int ipw[32]={0};
int ss[122];
int kasumi(int x,int y){
	if(y==0) return 1;
	long long ret=1;
	if(y%2) ret=x;
	int tmp=kasumi(x,y/2);
	ret=(((ret*tmp)%MOD)*tmp)%MOD;
	return int(ret);
}
int inv(int x){
	return kasumi(x,MOD-2);
}
int calc(){
	long long ret=pw[n];
	for(int i=1;i<=m+1;i++){
		ret=(ret*ipw[nw[i]])%MOD;
	}
	return int(ret);
}
bool check(){
	memset(ss,0,sizeof(ss));
	for(int i=1;i<=m+1;i++){
		ss[i]+=nw[i];
	}
	int cnt=0;
	for(int i=1;i<=120;i++){
		ss[i+1]+=ss[i]/2;
		ss[i]%=2;
		if(ss[i]) cnt++;
		if(cnt>k) return false;
	}
	return true;
}
void dfs(int x,int c){
	if(x>m+1){
		if(!check()||c!=n) return;
		long long val=1;
		for(int i=1;i<=m+1;i++){
			for(int j=0;j<nw[i];j++) val=(val*a[i])%MOD;
		}
		//cout<<calc()<<' '<<val<<endl;
		ans=(int)((1LL*calc()*val+ans)%MOD);
		return;
	}
	for(int i=0;i<=n-c;i++){
		nw[x]=i;
		dfs(x+1,c+i);
		nw[x]=0;
	}
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	pw[0]=1; ipw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*i;
		ipw[i]=inv(pw[i]);
	}
	for(int i=1;i<=m+1;i++) scanf("%d",&a[i]);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}

