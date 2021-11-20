#include <bits/stdc++.h>
using namespace std;
#define re register
#define ft first
#define sd second
#define INF 0x3f3f3f3f
#define P pair<int,int>
#define mp make_pair
#define pb push_back
//ifstream ("number") ;
//ofstream ("number");
//#define cin fin
//#define cout fout
const int MAXN = 2e5; 
int t;
bool p[MAXN  + 5];
inline bool check(int x){
	stringstream temp;
	string t;
	temp << x;
	temp >> t;
	int sz = t.size();
	for(re int i = 0; i < sz; ++i){
		if(t[i] == '7'){
			temp.str("");
			return 0;
		}
	}
	return 1;
}
inline void handle(int x){
	int cnt = 1;
	while(x * cnt <= MAXN){
		p[x*cnt] = 1;
		++cnt;
	}
}
inline void putout(int x){
	for(re int i = x + 1; i <= MAXN; ++i){
		if(!p[i]){
			cout << i << endl;
			return;
		}
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(re int i = 1; i <= MAXN; ++i){
		if(!check(i)){
			handle(i);
		}
	}
	cin >> t;
	if(t > 10000){
		for(re int i = 0; i < t; ++i){
			cout << -1 << endl;
		}
		return 0;
	}
	int r;
	for(re int i = 0; i < t; ++i){
		cin >> r;
		if(p[r]) cout << -1 << endl;
		else putout(r);
	}
	return 0;
}

