#include<bits/stdc++.h>
using namespace std;
inline void file(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
inline bool check(int xsc){
	while(xsc){
		int nyq=xsc%10;
		xsc/=10;
		if(nyq==7)return false;
	}
	return true;
}
inline bool ck(int xsc){
	if(!check(xsc))return false;
	for(register int i=2;i<=sqrt(xsc);i++){
		if(xsc%i!=0)continue;
		if(!check(i))return false;
		if(!check(xsc/i))return false;
	}
	return true;
}
int f[200007];
int main(){
	ios::sync_with_stdio(0);
//	freopen("form.out","w",stdout);
	file();
	int n=201000;int cnt=0;int xsc;
	int last=0;
	for(register int i=1;i<=n;i++){
		if(ck(i))++cnt;
		else continue;
		f[last]=i;
		last=i;
	}
	int T;
	cin>>T;
	while(T--){
		int xsc;
		cin>>xsc;
		if(!f[xsc])cout<<-1<<endl;
		else cout<<f[xsc]<<endl;
	}
	return 0;
}

