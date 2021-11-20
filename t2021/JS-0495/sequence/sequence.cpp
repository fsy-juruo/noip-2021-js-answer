#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[101],xz[111];
bool ej[111];
long long vs,p=998244353,ans,C,s,ss;
bool check(){
	int c=0,ks=0,cc;
	memset(ej,0,sizeof(ej));
	for(int i=0;i<=m+10;i++){
		cc=xz[i]+c;
		c=0;
		if(cc!=0){
			if(!ej[i]){
				if(cc%2){
					ej[i]=1;
					ks++;
					c=cc/2;
				}
				else c=cc/2;
			}
			else{
				if(cc%2){
					ej[i]=0;
					ks--;
					c=(cc+1)/2;
				}
				else c=cc/2;
			}
		}
	}
	return ks<=k;
}
void dfs(int u,int c){
	if(c==0){
		if(check()){
			vs=1;
			ss=1;
			int ks=n;
			for(int i=0;i<=m;i++){
				s=1;C=1;
				for(int j=1;j<=xz[i];j++){
					vs=(vs*v[i])%p;
					C=(C*ks)%p;
					ks--;
					s=(s*j)%p;
				}
				ss=(ss*(C/s))%p;
			}
			ans=(ans+vs*ss)%p;
		}
		return;
	}
	if(u>m)return;
	for(int i=0;i<=c;i++){
		xz[u]=i;
		dfs(u+1,c-i);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)cin>>v[i];
	dfs(0,n);
	cout<<ans;
	return 0;
}
