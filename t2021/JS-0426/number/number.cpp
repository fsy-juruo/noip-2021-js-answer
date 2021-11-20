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
const int INF=0x3f3f3f3f;
//const ll INF=0x3f3f3f3f3f3f3f3f;
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
const int MAXX=1e7+100;
bool is[MAXX];
int nxt[MAXX];
int t;int qry[200200];
inline void solve1(){
	int A=1e6+1;
	REPA(i,A){
		int x=i;
		while(x){
			if(x%10==7){
				is[i]=1;
				break;
			}
			x/=10;
		}
	}
	//find that: about 5e6 numbers has number 7
	
	REPA(i,A)if(is[i]){
		for(int j=2;j*i<=A;++j)is[i*j]=1;
	}
	//find that: about 8.5e7 times counting
	//warning! nlogn may lead to TLE
	
	//luckily, 1e7 and 1e7+1 is not banned
	
	for(int lst=A,i=A-1;i>=1;--i)if(!is[i]){
		nxt[i]=lst;
		lst=i;
	}
	REP(i,t){
		int x=qry[i];
		if(is[x])printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
}
inline void solve2(){
	int A=1e7+1;
	REPA(i,A){
		int x=i;
		while(x){
			if(x%10==7){
				is[i]=1;
				break;
			}
			x/=10;
		}
	}
	//find that: about 5e6 numbers has number 7
	
	REPA(i,A)if(is[i]){
		for(int j=2;j*i<=A;++j)is[i*j]=1;
	}
	
	//find that: about 8.5e7 times counting
	//warning! nlogn may lead to TLE
	
	//luckily, 1e7 and 1e7+1 is not banned
	
	for(int lst=A,i=A-1;i>=1;--i)if(!is[i]){
		nxt[i]=lst;
		lst=i;
	}
	REP(i,t){
		int x=qry[i];
		if(is[x])printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	int maxa=0;
	REP(i,t){
		scanf("%d",qry+i);
		maxa=max(maxa,qry[i]);
	}
	int aaaa=1e6;
	if(maxa<=aaaa)solve1();
	else solve2();
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

