#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define re register
#define ft first
#define sd second
#define INF 0x3f3f3f3f
#define P pair<int,int>
#define mp make_pair
#define pb push_back
int n, m, k,jsq;
const ll mod = 998244353;
ll v[105],cnt,pos,ans,jiecheng[25],daan;
ll wz[200];
inline void prepare(){
	jiecheng[0] = 1;
	for(re int i = 1; i <= 20; ++i)jiecheng[i] = i * jiecheng[i - 1];
}
inline bool check(int x){
	memset(wz,0,sizeof(wz));
	cnt = 0;
	pos = 0;
	while(x > 0){
		int temp = x%2;
		if(temp == 1){
			cnt++;
			wz[pos] = 1;
		}	
		pos++;
		x /= 2;
	}
	if(cnt <= k)return 1;
	return 0;
}
inline void handle(int x){
	ans = 1;
	while(pos > (m + 1)){
		pos--;
		wz[pos - 1] += 2*wz[pos];
		cnt += wz[pos];
		wz[pos] = 0;
	}
	while(cnt < n){
		--wz[pos - 1];
		wz[pos - 2] += 2;
		cnt++;
		if(!wz[pos - 1])pos--;
	}
	if(cnt == n){
		ans = (ans*jiecheng[cnt])%mod;
		for(re int i = 0; i < pos; ++i){
			ans /= jiecheng[wz[i]];	
			for(re int j = 0; j < wz[i]; ++j){
				ans = (ans*v[i]) % mod;
			}
		}
	}
//	cout << ans << endl;
	daan = (daan + ans)%mod;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin >> n >> m >> k;
	prepare();
	for(re int i = 0; i <= m; ++i) cin  >> v[i];
	int js = n*pow(2,m);
	for(int i = n; i <= js; ++i){
		if(check(i)){
			handle(i);
		}
	}
	cout << daan << endl;
	return 0;
}

