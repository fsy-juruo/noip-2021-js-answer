#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int N=1e7+5;
int t,x;
bool vis[N];
inline int read(){
	int ss=0;char cc=getchar();
	for(;!isdigit(cc);cc=getchar());
	for(;isdigit(cc);cc=getchar()) ss=(ss<<1)+(ss<<3)+cc-'0';
	return ss;
}
inline void shu(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) shu(x/10);
	putchar(x%10+48);
}
bool check(int x){
	for(;x;x/=10) if(x%10==7) return false;
	return true;
}
void init(){
	for(int i=1;i<=N;++i){
		if(vis[i]) continue;
		if(!check(i)) for(int j=1;i*j<=N;++j) vis[i*j]=1;
	}
}
int ser(int x){
	while(vis[x]) x++;
	return x;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	t=read();
	for(int i=1;i<=t;++i){
		x=read();
		if(vis[x]) shu(-1);
		else shu(ser(x+1));
		putchar(10);
	}
	return 0;
}
