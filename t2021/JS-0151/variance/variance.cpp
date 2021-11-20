#include<bits/stdc++.h>
using namespace std;

inline long long read(){
	long long s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-')
			w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		s = s * 10 + ch - '0';
	return s * w;
}

inline void fre(){
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
}

int n, a[10033];

inline long long ask(){
	int sum = 0;
	long long res = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i];
	for (int i = 1; i <= n; i++)
		res += (a[i]*n - sum) * (a[i]*n - sum);
	res /= n;
	return res;
}

inline void change(int x){
	a[x] = a[x+1] + a[x-1] - a[x];
}
inline void work1(){
	if (n == 2){
		cout << ask() << endl;
	}
	else if (n == 1){
		cout << 0 << endl;
	}
	else if (n == 3){
		long long ans = ask();
		a[2] = a[1] + a[3] - a[2];
		ans = min(ans, ask());
		cout << ans << endl;
	}
	else{
		long long ans = ask();
		change(2);
		ans = min(ans, ask());
		change(3);
		ans = min(ans, ask());
		change(2);
		ans = min(ans, ask());
		change(2);
		change(3);
		change(2);
		change(3);
		ans = min(ans, ask());
		change(2);
		ans = min(ans, ask());
		cout << ans << endl;
	}
}

inline void work2(){
	long long t[10033];
	for (int i = 2; i < n; i++)
		t[i] = a[i+1] + a[i-1] - a[i] * 2;
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i];
}

int main(){
	fre();
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	if (n <= 4)
		work1();
	else
		work2();
	return 0;
}

