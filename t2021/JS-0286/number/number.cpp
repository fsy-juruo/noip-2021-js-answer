#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 10;

struct Rec{
	bool p;
	int w = 0;
};

int T,x,tot;
int sev[MAXN];
bool V[MAXN];

bool check(int x){
	for(int i = 1; i <= tot; i++)
		if(x % sev[i] == 0){
			return true;
			V[x] = true;
		}
	return false;
}

Rec brk(int x){
	Rec ret;
	ret.p = false;
	for(int i = 0; i <= 6; i++){
		int a = x;
		a /= pow(10, i);
		if(a == 0)
			break;
		a %= 10;
		if(a == 7){
			sev[++tot] = x;
			V[x] = true;
			ret.p = true;
			ret.w = i;
		}
	}
	if(ret.p)
		return ret;
	ret.p = false;
	return ret;
}

bool fj(int x){
	for(int i = 2; i <= sqrt(x); i++)
		if(x % i == 0){
			if(V[x / i])
				return true;
			Rec r = brk(x / i);
			if(r.p)
				return true;
			if(V[i])
				return true;
			r = brk(i);
			if(r.p)
				return true;
		}
	return false;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &x);
		Rec a = brk(x);
		if(a.p || V[x] || check(x))
			printf("-1\n");
		else if(fj(x))
			printf("-1\n");
		else{
			for(int i = x+1; ; i++){
				if(V[i])
					continue;
				Rec k = brk(i);
				if(k.p){
					int Pow = pow(10, k.w);
					i /= Pow, i++;
					i *= Pow, i--;
					continue;
				}
				if(!check(i)){
					if(fj(i))
						continue;
				}
				else
					continue;
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
