#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const ull mod=998244353;
const int M=105;
const int N=35;

ull n,m,k,ans;
ull v[M],a[N];

ull fpow(ull _a, int _p){
	if(_p==1) return _a;
	ull last=fpow(_a,_p/2)%mod;
	if(_p&1) return last*last*_a%mod;
	else return last*last%mod;
}

ull C(int m, int n){
	ull _ans=1;
	bool _f[N];
	memset(_f,false,sizeof(_f));
	for(int i=m; i>=m-n+1; i--){
		_ans*=i;
		for(int j=n; j>=2; j--){
			if(_ans%j==0&&!_f[j]){
				_f[j]=true;
				_ans/=j;
			}
		}
	}
	return _ans%mod;
}

ull reone(ull _a){
	ull num=0;
	while(_a){
		num+=_a%2;
		_a/=2;
	}
	return num;
}

void calc(){
	ull one=1,_num,_m=0,_ans;
	for(int i=1; i<=n; i++)
		one=one*v[a[i]]%mod;
	bool F[M];
	memset(F,false,sizeof(F));
	for(int i=1; i<=n; i++)
		F[a[i]]=true;
	for(int i=0; i<=m; i++)
		_m+=F[i];
	_num=C(n,_m);
	_ans=(one%mod)*(_num%mod)%mod;
	ans+=_ans;
}

void dfs(int last, int p, ull sum){
	if(p>=n+1){
		if(reone(sum)<=k) calc();
		return ;
	}
	for(int i=last; i<=m; i++){
		a[p]=i;
		/*  fpow(2,i)  */
		dfs(i,p+1,sum+(1<<i));
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=0; i<=m; i++)
		cin>>v[i];
	
//	if(m<=50){
		dfs(0,1,0);
		cout<<ans%mod<<endl;
//		return 0;
//	}
	
	
	return 0;
}

