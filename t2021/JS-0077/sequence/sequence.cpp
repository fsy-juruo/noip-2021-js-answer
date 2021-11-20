//成败在此一举。 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x);
const ll mod=998244353;
int n,m,k,a[1007],b[1007],ori;
ll v[1007],ans,num;
int exi[100000007];
int lowbit(int x){
	return x&(-x);
}
void check(){
	int now=0;
	for(int i=1;i<=n;i++){
		now+=(1<<a[i]);
	}
	int x=0;
	while(now){
		now-=lowbit(now);
		++x;
	}
	if(x<=k){
		ll res=1;
		for(int i=1;i<=n;i++){
			res=res*v[a[i]]%mod;
		}
		exi[ori]=int(res);
		ans=(ans+res)%mod;
	}
	else exi[ori]=-1;
}
void dfs(int dep){
	if(dep==n+1){
		check();
		return;
	}
	for(int i=0;i<=m;i++){
		a[dep]=i;
		dfs(dep+1);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
void read(int &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
}

