//This is the last program I write in my OI life.
//Write it carefully
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define mo ((ak)998244353)
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
ak n,m,k,v[1111],a[1111],ans=0;
bool cxk(ak xx){
	ak x=xx,cnt=0;
	while(x){
		cnt+=(x&1);
		x>>=1;
	}
	return cnt<=k;
}
ak calc(){
	ak add=1;
	F(i,1,n)add=(add*v[a[i]])%mo;
	return add;
}
void dfs(ak dep,ak sum){
	if(dep==n){
		if(cxk(sum))ans=(ans+calc())%mo;
	}
	F(i,0,m)a[dep]=i,dfs(dep+1,sum+(1<<i));
}
int main(){
	#ifndef lpcak
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#endif
	
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	F(i,0,m)cin>>v[i];
	dfs(1,0);cout<<ans<<"\n";
	return 0;
}
/*

5 1 1 2 1

*/
