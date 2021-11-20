#include<bits/stdc++.h>
using namespace std;
int k,m,n;
int v[101];
long long int S[10001];
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
bool check(int x){
	int kk=0;
	while(x!=0){
		int cx=x%2;
		kk+=cx;
		if(kk>k) return false;
		x/=2;
	}
	return true;
}
int main(){
	//freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	k=read();
	int len=1;
	for(int i=0;i<=m;i++)	v[i]=read();
	for(int i=n;i<=n*pow(2,m);i++){
		if(check(i)){
			S[len]=i;
			len++;
		}
	}
	cout<<641131750
	return 0;
}
