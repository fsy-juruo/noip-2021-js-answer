#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;++i)
#define repp(i,n) for(int i=1;i<=n;++i)
#define forr(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
#define init(a,i) memset(a,i,sizeof(a))
const int N=10000001;
bool f[N+10];
int x,cur=0;
int a[N+10];
void solve(){
	cin>>x;
	if(f[x])cout<<-1<<endl;
	else cout<<*upper_bound(a,a+cur,x)<<endl;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	repp(i,N){
		if(f[i])continue; 
		x=i;
		while(x){
			if(x%10==7)f[i]=1;
			x/=10;
		}
		if(f[i])for(int j=2*i;j<=N;j+=i)f[j]=1;
	}
	repp(i,N)if(!f[i])a[cur++]=i;
	int T=1;
	cin>>T;
	while(T--){solve();}
	return 0;
}

