#include <bits/stdc++.h>
using namespace std;

const int maxn = 100003;
int n,m,k;

int v[maxn];

int lowbit(long long int n){
	return n & -n;
}

int calc_pailie(int up,int down){
	long long int ans1 = 1;
	long long int ans2 = 1;
	int down1 = up - down;
	for(int i = 2 ; i<= up ; i ++){
		ans1 *= i;
	}
	for(int i = 2 ; i <= down1 ; i ++){
		ans2 *= i;
	}
	ans2 *= down;
	return ans1/ans2;
}

int sum_one(long long int n){
	int ans = 0;
	while(n != 0){
		if(n % 2 == 1){
			ans ++;
			cout << 1;
		}
		cout << 0;
		n >>= 1;
	}
	return ans;
	
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m + 1 ; i ++){
		cin >> v[i];
	}
	int left = n ;
	int right = n * (1<<m);
	int numone,numa;
	for(int i = left ; i <= right ; i ++){
		numone = sum_one(i);
		if(numone <= k){
			// calc 
			numa = i / 2;
			
		}
	}
	cout << left << "    " << right;
}
