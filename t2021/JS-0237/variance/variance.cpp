#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 10010;

double ans = 2147483647;
int a[maxn],n;


const int mod1 = 19260817,mod2 = 19491001,mod3 = 998244353;
gp_hash_table<int,int> hsh;

inline int gen_hash(int n){
	int r1 = 0,r2 = 0;
	for (int i=1;i<=n;i++){
		r1 = (r1 + (int)(a[i]*i)) % mod1;
		r2 = (r2 + (int)(a[i]*(n+1-i))) % mod2;
	}
	
	return (r1*97+r2)%mod3;
}

int intern = 1;
int dfs(){
	int gsh = gen_hash(n);
	if (hsh.find(gsh) != hsh.end()) return hsh[gsh];
	
	//cout<<"Intern = "<<intern<<endl;
	intern++;
	if (intern > 18000) {
		intern--;
		return 0; //Prevent Stack Exploit
	}
	double ave = 0,cur = 0;
	for (int i=1;i<=n;i++) ave += a[i];
	ave /= n;
	for (int i=1;i<=n;i++) cur += (a[i]-ave) * (a[i]-ave) * n;
	hsh[gsh] = cur;
	if (cur < ans){
		ans = cur;
	}
	
	for (int i=2;i<n;i++){
		int tmp = a[i];
		a[i] = a[i+1] + a[i-1] - a[i];
		ave += (a[i]-tmp) / n;
		dfs();
		a[i] = tmp;
	}
	
	intern--;
	return cur;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	dfs();
	cout<<ans;
	return 0;
}
