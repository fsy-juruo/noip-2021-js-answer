#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N= 105;
const int Mod= 998244353; 
int n, m, k; 
int a[N];

struct P20
{
	ll ans= 0;
	int f[N], v[N];
	
	int check()
	{
		ll kk= 0;
		for(int i= 1; i<= n; i++ ) kk+= (1<< f[i]);
		int cnt= 0;
		for(int i= 0; i<= 15; i++ )
			if(kk>> i& 1) cnt++ ;
		if(cnt> k) return 0; ll cur= 1;
		for(int i= 1; i<= n; i++ ) cur= (ll)cur* a[f[i]]% Mod;
		return cur;
	}
	
	void dfs(int u)
	{
	    if(u== n+ 1) 
	    {
		    ans= ((ll)ans+ check())% Mod; return ;
		} 
		for(int i= 0; i<= m; i++ ) f[u]= i, dfs(u+ 1);
	}
	
	void solve()
	{
		dfs(1); cout<< ans<< endl; return ;
	}
}P20;

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin>> n>> m>> k;
	for(int i= 0; i<= m; i++ ) scanf("%d", &a[i]);
	
	P20.solve();
	
	return 0;
}



/*
5 1 1
2 1


8 9 4
934258593 150407625 187068439 162292791 219945760 512449588 803393963 983648121 484675481 412407699



*/
