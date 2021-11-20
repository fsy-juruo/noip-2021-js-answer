#include<bits/stdc++.h>
using namespace std;
int T;
int n;
bool h7(int k){
	while(k!=0){
		if((k%10)==7) return true;
		k/=10;
	}
	return false;
}
bool check(int k){
	if(h7(k)) return false;
	for(int i=2;i*i<=k;i++) if(k%i==0) if(h7(i)||h7(k/i)) return false;
	return true;
}
int get(int k){
	while(++k) {if(check(k)) return k;}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(!check(n)) printf("-1\n");
		else printf("%d\n",get(n));
	}
	return 0;
}
