//niconiconiconi
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define endl "\n"
vector <int> v,SEq;
set <int> st;
void fct(int x) {
	for(int i=1;i*i<=x;i++) {
		if(x%i) continue;
		v.push_back(i);
		if(i*i!=x) v.push_back(x/i);
	}
}
bool sevenseven(int x) {
	for(int i=0;i<(int)v.size();i++) {
		int tmp=v[i];
		if(tmp%7==0) return 0;
		while(tmp) {
			if(tmp%10==7) return 0;
			tmp/=10;
		}
	}
	return 1;
}
void GenerATE1() {
	for(int i=1;i<=2e5;i++) {
		v.clear();
		fct(i);
		if(!sevenseven(i)) st.insert(i);
	}
}
void func1(int id) {
	v.clear(); 
	int N=SEq[id];
	fct(N);
	if(!sevenseven(N)) {
		puts("-1"); return;
	}
	set <int> :: iterator it=st.lower_bound(N); 
	while(*it<N) it++;
	int l=*it;
	if(l-N>1) {
		printf("%d\n",N+1); return;
	}
	it++; int r=*it;
	while(r-l<=1) {
		l=r; it++; r=*it;
	}
	printf("%d\n",l+1);
}
int main() {
	freopen("number.in","r",stdin); freopen("number.out","w",stdout);
	int T; cin>>T;
	int LIMit=0;
	for(int i=0;i<T;i++) {
		int x; scanf("%d",&x); SEq.push_back(x);
		LIMit=max(LIMit,x);
	}
	GenerATE1();
	for(int i=0;i<T;i++) func1(i);
	return 0;
}

