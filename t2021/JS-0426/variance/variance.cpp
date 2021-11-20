#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define REP(x,y) for(int x=0;x<y;++x)
#define REPA(x,y) for(int x=1;x<=y;++x)
#define vi vector<int>
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define mp make_pair
using namespace std;
const ll MOD=1e9+7;
//const ll MOD=998244353;
//const int INF=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
inline ll quick_power(ll A,ll B){
	A%=MOD;ll ret=1;
	while(B){
		if(B&1)ret=ret*A%MOD;
		B>>=1;
		A=A*A%MOD;
	}
	return ret;
}
inline int lowbit(int x){return x&-x;}
const int MAXN=110;
int N;int A[MAXN];
int d[MAXN];
ll sum=0,sum2=0,ans=INF;
bool used[MAXN];
void dfs2(int pos,int now){
//	cout<<pos<<':'<<now<<endl;
	if(pos==N){
		ans=min(ans,sum2*N-sum*sum);
//		cout<<sum2<<' '<<sum<<':'<<ans<<endl;
	}
	REP(i,N-1)if(!used[i]){
		ll _sum=sum,_sum2=sum2;
		for(int j=0,p=pos,nw=now;j<N-1;++j){
			if(!used[j]){
				_sum2+=1ll*(N-p)*(2ll*nw*d[j]+1ll*d[j]*d[j]);
				nw+=d[j];
				++p;
			}
		}
		for(int j=N-2,p=pos;j>=0;--j){
			if(!used[j]){
				_sum+=d[j]*(N-p);
				++p;
			}
		}
		if(N*_sum2-_sum*_sum>ans)continue;
		ll tmpsum=sum,tmpsum2=sum2;
		sum=sum+d[i]*(N-pos),sum2=sum2+1ll*(N-pos)*(2ll*now*d[i]+1ll*d[i]*d[i]);
		used[i]=1;
		dfs2(pos+1,now+d[i]);
		sum=tmpsum,sum2=tmpsum2,used[i]=0;
	}
}
void dfs(int pos,int now){
//	cout<<pos<<':'<<now<<endl;
	if(pos==N){
		ans=min(ans,sum2*N-sum*sum);
//		cout<<sum2<<' '<<sum<<':'<<ans<<endl;
	}
	REP(i,N-1)if(!used[i]){
		ll tmpsum=sum,tmpsum2=sum2;
		sum=sum+d[i]*(N-pos),sum2=sum2+1ll*(N-pos)*(2ll*now*d[i]+1ll*d[i]*d[i]);
		used[i]=1;
		dfs(pos+1,now+d[i]);
		sum=tmpsum,sum2=tmpsum2,used[i]=0;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&N);
	REP(i,N)scanf("%d",A+i);
	REPA(i,N-1)d[i-1]=A[i]-A[i-1];
	sort(d,d+N-1);
	sum=A[0]*N,sum2=1ll*A[0]*A[0]*N;
	if(N<=10)dfs(1,A[0]);
	else dfs2(1,A[0]);
	printf("%lld",ans);
	return 0;
}
/*
think twice, code once;
think once, debug forever.
*/
/*
sto QL orz
sto HJ orz
sto H2 orz
sto ET orz
sto I9 orz
sto FG orz
haoba, yyds!
*/

