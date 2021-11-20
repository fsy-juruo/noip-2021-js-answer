#include <bits/stdc++.h>
using namespace std;
const int N= 1e7+100;
int T;
inline int read(){ 
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-48;c=getchar();}
	return x*f;
}
inline void writ(int x){
	if(x<0){putchar('-');x=-x;}
	if(x/10)writ(x/10);
	putchar(x%10+48);
}
bool h[N];
int m[N];
bool check(int x){
	if(!x%7)return 1;
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int las=0;
	for(int i=1;i<N;++i){
		if(h[i])continue ;
		if(check(i)){
			h[i]=1;
			int cnt=1;
			while(i*cnt<N){
				h[i*cnt]=1;
				cnt++;
			}
		}
		else {
			m[las]=i;
			las=i;
		}
	}
	T=read();
	while(T){
		T--;
		int x=read();
		if(h[x])puts("-1");
		else {
		writ(m[x]);putchar('\n');
		}
	}
	return 0;
}

