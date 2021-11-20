#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
#define rep(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(int (i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(int (i)=(j);(i)>=(k);(i)--)
#define sit set<int>::iterator
#define mit map<int,int>::iterator
#define pb push_back
#define pii pair<int,int>
#define mpr make_pair
typedef long long ll;
int T,n;
bool g[10500005];
int nxt[10500005];
bool good(int n){
	while(n) {
		if(n % 10 == 7) return 0;
		n /= 10;
	}
	return 1;
}
void sieve(int n){
	rep(i,2,n) if(!good(i)) {
		for(int j = i;j <= n;j += i) g[j] = 1;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	sieve(10500000);
	per(i,10500000,0) if(!g[i]) nxt[i] = i;else nxt[i] = nxt[i + 1];
	scanf("%d",&T);
	while(T--) {
		int x;
		scanf("%d",&x);
		x++;
		if(!g[x - 1])
		printf("%d\n",nxt[x]);
		else puts("-1");
	}
	return 0;
}
