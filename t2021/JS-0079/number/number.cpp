#include <bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;

ll t, x, maxn, a[N];
bool vh[10000010];
bool sev(ll x){
	while(x){
		if(x % 10 == 7) return true;
		x /= 10;
	}
	return false;
}
void ins(ll x){
	if(vh[x]) return ;
	vh[x] = true;
	ll i = 1;
	while(i * x <= maxn){
		vh[i * x] = true;
		i++;
	}
}
bool check(ll x){
	for(int i = 1; i * i <= x; i++){
		if(x % i == 0){
			if(sev(i) || sev(x/i)) return true;
		}
	}
	return false;
}
ll calc(ll x){
	if(vh[x]) return -1;
	ll xx = x + 1;
	while(vh[xx]){
		xx++;
	}
	if(xx > maxn){
		while(check(xx)) xx++;
	}
	return xx;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&t);
	for(int i = 1; i <= t; i++){
		scanf("%lld",&a[i]);
		maxn = max(maxn,a[i]);
	}
	for(int i = 1; i <= maxn; i++)
		if(sev(i) && (!vh[i])) ins(i);
	for(int i = 1; i <= t; i++){
		printf("%lld\n",calc(a[i]));
	}
	return 0;
}
