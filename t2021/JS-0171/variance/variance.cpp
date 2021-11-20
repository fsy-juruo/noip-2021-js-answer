#include <bits/stdc++.h>
using namespace std;
#define re register
#define ft first
#define sd second
#define INF 0x3f3f3f3f
#define P pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
int n;
const int MAXN = 1e4 + 5;
int a[MAXN];
ll pre[MAXN],chazhi1[MAXN],chazhi2[MAXN];
ll pj;
long double fangcha;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin >> n;
	for(re int i = 1; i <= n; ++i){
		cin >> a[i];
		pj += a[i];
	}
	for(re int i = 2; i < n; ++i){
		chazhi1[i] = abs(n*a[i] - pj);
		chazhi2[i] = abs(n*(a[i-1] + a[i + 1] - a[i]) - pj);
		if(chazhi1[i] < chazhi2[i]) continue;
		else{
			pj = pj + (a[i-1] + a[i + 1] - 2*a[i]);
			a[i] = a[i-1] + a[i + 1] - a[i];
			i = 1;
		}
	}	
	for(re int i = 1; i <= n; ++i){
		fangcha += (n*a[i]-pj)*(n*a[i] - pj);
	}
	fangcha /= n;
	cout<<fixed << setprecision(0) << fangcha << endl;
	return 0;
}

