//start:8:44
#include <bits/stdc++.h>
using namespace std;
int cas,mx;
const int N=2e5+100,M=2e7+100;
int c[N],nxt[M];
short b[M];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> cas;
	for (int i=1;i<=cas;i++){
		cin >> c[i];mx=max(mx,c[i]);
	}
	mx+=10000;
	for (int i=1;i<=mx;i++){
		if (i%10==7 || b[i/10]) b[i]=1;
	}
	for (int i=1;i<=mx;i++) if (b[i]==1){
		for (int j=i+i;j<=mx;j+=i) b[j]=2;
	}
//	for (int i=10000001;;i++){
//		if (!b[i]){
//			cerr << i << endl;break;
//		}
//	}
//	for (int i=1;i<=mx;i++) cout << i << ' ' << b[i] << endl;
	for (int i=mx;i>=1;i--){
		if (b[i]) nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
	for (int i=1;i<=cas;i++){
		if (b[c[i]]) cout << -1 << endl;
		else cout << nxt[c[i]+1] << endl;
	}
	return 0;
}
