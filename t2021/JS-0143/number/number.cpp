#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
int T,n,p[700000],idx,cnt,M,i2;
bool a[10000010],f,pr[10000010];
inline int calc(int x){
	int cnt = 1;
	f = false;
	while(x){
		if(x % 10 == 7)f = true;
		x /= 10;
		cnt *= 10;
	}
	return cnt;
}
inline int read(){
	char ch;
	while(!isdigit(ch = getchar()));
	int v = ch - '0';
	while(isdigit(ch = getchar()))v = v * 10 + ch - '0';
	return v;
}
inline int put(int x){
	if(x >= 10)put(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T = read();
	if(T <= 10000)M = 400000;
	else M = 10000005;
	a[7] = 1;
	pr[1] = 1;
	for(re int i = 2;i <= M;i++){
		if(!pr[i])p[++idx] = i;
		for(re int j = 1;j <= idx && (ll)(i) * p[j] <= M;j++){
			pr[i * p[j]] = true;
		}
	}
	for(re int i = 1;i <= M;i++){
		int x = calc(i);
		if(!a[i]){
			if((ll)i * 10 + 7 <= M)a[i * 10 + 7] = true;
			if((ll)x * 7 + i <= M)a[7 * x + i] = true;
			continue;
		}
		else
			for(re int j = 1;j <= idx && (ll)i * p[j] <= M;j++){
				a[i * p[j]] = true;
			}
		if(f)
			for(re int j = 1;j <= 9;j++){
				if((ll)j * x + i <= M)a[j * x + i] = true;
				if((ll)i * 10 + j <= M)a[i * 10 + j] = true;
			}
	}
	while(T--){
		n = read();
		if(a[n])puts("-1");
		else {
			for(int i = n + 1;;i++){
				if(!a[i]){put(i);putchar('\n');break;}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
