#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x){
	long long ff=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')ff=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=ff;
}
template<typename T>inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);putchar('\n');
}
const int N=3e5;
int good(int x){
	int i=0;
	while(x){
		if(x%10==7)return i;
		x/=10;i++;
	}
	return -1;
}
int f[N+10];
int g[N+10];
void init(){
	for(int i=1;i<=N;i++){
		if(good(i)==-1)f[i]=1;
	}
	for(int i=1;i<=N;i++){
		if(!f[i]){
			for(int j=2;i*j<=N;j++){
				f[i*j]=0;
			}
		}
	}
	for(int i=1;i<=N;i++){
		if(f[i]){
			g[++g[0]]=i;
		}
	}
}
bool ck(int x){
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			if(good(i)!=-1||good(x/i)!=-1)return 0;
		}
	}
	return 1;
}
void solve(int x){
	if(x<=200000){
		int pos=lower_bound(g+1,g+g[0]+1,x)-g;
		if(g[pos]!=x){
			writeln(-1);return;
		}else{
			writeln(g[pos+1]);
		}
	}else{
		if(!ck(x)){
			writeln(-1);return;
		}
		x++;
		for(;;x++){
			if(ck(x)){
				writeln(x);break;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	init();

	int T;read(T);
	while(T--){
		int x;read(x);solve(x);
	}
	return 0;
}
/*
4
6
33
69
300

5
90
99
106
114
169

*/
