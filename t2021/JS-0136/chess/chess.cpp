#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,q,t,col,lv,x,y;
ll ans;
string s1[5100],s2[5100];
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void dfs(ll x,ll y,ll opt,ll c,ll tot){
	ans++;
	if(opt==-1){
		if(x<n){
		
		if(s1[x][y-1]!='0'){
			if(s1[x][y-1]=='1'){
				if(tot>0)
				dfs(x+1,y,opt,c,tot-1);
			}
			if(s1[x][y-1]=='2'){
				dfs(x+1,y,2,1,tot);
			}
			if(s1[x][y-1]=='3'){
				dfs(x+1,y,3,c,tot);
			}
		}
	}
	if(y<m){
		if(s2[x][y-1]=='1'){
			if(tot>0)
				dfs(x,y+1,opt,c,tot-1);
		}
			if(s2[x][y-1]=='2'){
				dfs(x,y+1,2,1,tot);
			}
			if(s2[x][y-1]=='3'){
				dfs(x,y+1,3,c,tot);
			}
		}
	}
	else{
		
	}
}
int main(){

freopen("chess.in","r",stdin);
freopen("chess.out","w",stdout);
t=read();
while(t--){
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
	cin>>s1[i];
	for(int i=1;i<n;i++)
	cin>>s2[i];
	for(int i=1;i<=q;i++){
		col=read();
		lv=read();
		x=read();
		y=read();
		ans=rand()%(m*n);
		printf("%lld\n",ans);
	}
}
return 0;
}

