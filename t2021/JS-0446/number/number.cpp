#include<bits/stdc++.h>

using namespace std;

const int T = 2e5 + 5, N = 1e7 + 5, N2 = 2e5 + 10;
int t = 0, x[T] = {}, ky = 0;
bool p[N] = {};
vector<int> v;

bool check(int k){
	while(k){
		if(k % 10 == 7) return 1;
		k /= 10;
	}
	return 0;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &t);
	for(int i = 0 ; i < t ; ++ i){
		scanf("%d", &x[i]);
		if(x[i] > 2e5) ky = 1;
	}
	if(ky){
		for(int i = 1 ; i < N ; ++ i){
			if(check(i) && p[i] == 0){
				p[i] = 1;
				for(int j = 0 ; i * j < N ; ++ j) p[i * j] = 1;
			}
			if(p[i] == 0) v.push_back(i);
	    }
	}
	else{
		for(int i = 1 ; i < N2 ; ++ i){
			if(check(i)) p[i] = 1;
			if(p[i]) for(int j = 0 ; i * j < N2 ; ++ j) p[i * j] = 1;
			else v.push_back(i);
	    }
	}
	for(int i = 0 ; i < t ; ++ i){
		int idx = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
		if(v[idx] == x[i]) printf("%d\n", v[idx + 1]);
		else printf("-1\n");
	}
	return 0;
}

