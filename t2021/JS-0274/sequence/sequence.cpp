#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
typedef long long LL; 

int n,k,m;
int val[110];
int a[110],b[110],cur;
LL C[110][110];
LL P[110][40];
LL ans;

inline void pre(){
	for(int i=1;i<=107;i++) C[i][0]=C[i][i]=1;
	for(int i=2;i<=107;i++){
		for(int j=1;j<i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]%=MOD;
		}
	}
	for(int i=0;i<=m;i++){
		P[i][0]=1;
		for(int j=1;j<=n;j++)
			P[i][j]=(P[i][j-1]*(LL)val[i])%(LL)MOD;
	}
}

inline void dfs(int dep){
	if(dep>m+1||cur>n) return ;
	if(cur==n){
		int cnt=0;
		for(int i=0;i<=m+6;i++) b[i]=0;
		for(int i=0;i<=m+6;i++){
			b[i]+=a[i];
			b[i+1]+=b[i]/2;
			b[i]&=1;
			cnt+=b[i];
		}
		if(cnt>k) return ;
		cnt=n;
		LL tot=1LL,tmp;
		for(int i=0;i<=m;i++){
			tmp=1LL;
			tmp=C[cnt][a[i]]*P[i][a[i]]%(LL)MOD;
			tot=(tot*tmp)%(LL)MOD;
			cnt-=a[i];
		}
		ans=(ans+tot)%(LL)MOD;
		return ;
	} else if(dep>m) return ;
	else if(dep<m){
		for(int i=0;i<=n-cur;i++){
			a[dep]=i;
			cur+=i;
			dfs(dep+1);
			a[dep]=0;
			cur-=i;
		}
	} else {
		a[dep]=n-cur;
		int Tmp=cur;
		cur=n;
		dfs(dep+1);
		a[dep]=0;
		cur=Tmp;
	}
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) cin>>val[i];
	pre();
	cur=0;
	dfs(0);
	cout<<ans%MOD<<endl;
	return 0;
}