#include <bits/stdc++.h>
using namespace std;

map < long long, bool > mp;

int a[10010];
int n;
long long ans = LONG_LONG_MAX;
int mx;

void dfs(){
	for (int i = 2; i < n; i++){
		int t = a[i];
		a[i] = a[i - 1] + a[i + 1] - a[i];
		long long sum = 0, sqrsum = 0, qaq = 0;
		for (int j = 1; j <= n; j++){
			qaq = qaq * (mx + 1) + a[j];
			sum += a[j];
			sqrsum += a[j] * a[j];
		}
		ans = min(ans, sqrsum * n - sum * sum);
		if (!mp[qaq]){
			mp[qaq] = 1;
			dfs(); 
		}
		a[i] = t;
	}
}

int main(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	if (n <= 4 && a[n] <= 10){
		mx = a[n];
		long long qaq = 0;
		for (int i = 1; i <= n; i++){
			qaq = qaq * (mx + 1) + a[i];
		}
		mp[qaq] = 1;
		dfs();
		cout << ans << endl;	
	}
	else{
		srand(19260817);
		int ok = 1;
		int cnt = 0;
		while (ok){
			cnt++;
			if (cnt * n >= 38000000) break;
			long long sum = 0, sqrsum = 0;
			for (int j = 1; j <= n; j++){
				sum += a[j];
				sqrsum += a[j] * a[j];
			}
			ok = 0;
			for (int i = 2; i < n; i++){
				if (a[i] * n <= sum && a[i - 1] + a[i + 1] - a[i] > a[i]){
					if (rand() % 100 + 1 <= 65){
						sum -= a[i];
						sqrsum -= a[i] * a[i];
						a[i] = a[i - 1] + a[i + 1] - a[i];
						sum += a[i];
						sqrsum += a[i] * a[i];
					}
					ok = 1;	
				}
				else{
					if (a[i] * n >= sum && a[i - 1] + a[i + 1] - a[i] < a[i]){
						if (rand() % 100 + 1 <= 65){
							sum -= a[i];
							sqrsum -= a[i] * a[i];
							a[i] = a[i - 1] + a[i + 1] - a[i];
							sum += a[i];
							sqrsum += a[i] * a[i];
						}
						ok = 1;
					}
					else{
						if (rand() % 100 + 1 <= 30){
							sum -= a[i];
							sqrsum -= a[i] * a[i];
							ok = 1;
							a[i] = a[i - 1] + a[i + 1] - a[i];
							sum += a[i];
							sqrsum += a[i] * a[i];
						}
					}
				}
				ans = min(ans, sqrsum * n - sum * sum);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
4
1 2 4 6

10
6 19 34 35 56 63 82 82 83 99

50
1 6 25 27 27 28 29 30 32 32 32 32 32 32 32 32 32 32 32 34 36 38 39 40 40 42 45 49 50 51 52 53 53 54 54 54 56 57 57 57 59 59 59 59 61 63 63 63 64 66
*/
