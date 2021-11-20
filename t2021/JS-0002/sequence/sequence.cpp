#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define mp pair<int,int>
using namespace std;
const int MOD=998244353;
const int MAXN=35;
const int MAXM=105;
int n,m,k;
int v[MAXM];
int dp[MAXM][MAXN][MAXN][MAXN];
int ppcnt[MAXN];
void add(int & A,int B){
	A+=B;
	if(A>=MOD) A-=MOD;
}
int pw[MAXM][MAXN];
int ifact[MAXN],fact[MAXN];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
int main(){
//	cout<<sizeof(dp)/1024/1024<<endl;
	
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	fact[0]=1;
	rb(i,1,n) fact[i]=1ll*fact[i-1]*i%MOD;
	rb(i,0,n) ifact[i]=quick(fact[i],MOD-2);
	m++;
	rb(i,1,m) cin>>v[i];
	rb(i,1,m){
		pw[i][0]=1;
		rb(j,1,n){
			pw[i][j]=1ll*pw[i][j-1]*v[i]%MOD;
		}
	}
	rb(i,0,n){
		int tmp=i;
		while(tmp){
			ppcnt[i]+=tmp&1;
			tmp>>=1;
		}
	}
	dp[0][0][0][0]=1;
	rb(i,0,m-1) rb(j,0,n) rb(z,0,j) rb(hv,0,j){
		if(dp[i][j][z][hv]){
			int val=dp[i][j][z][hv];
			rb(now,0,n-j){
				int rl=now+z;
				add(dp[i+1][j+now][rl/2][hv+(rl&1)],1ll*val*ifact[now]%MOD*pw[i+1][now]%MOD);
			}
		}
	}
	int answer=0;
	rb(z,0,n) rb(hv,0,n){
		int val=dp[m][n][z][hv];
		if(hv+ppcnt[z]<=k){
			add(answer,val);
		}
	}
	cout<<1ll*answer*fact[n]%MOD<<endl;
	return 0;
}
