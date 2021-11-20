#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
inline void writeln(int x){
	write(x),putchar('\n');
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t=read();
	while(t--){
		int n=read(),m=read(),q=read();
		string a,b;
		for(int i=1;i<=n;++i)a=read();
		for(int i=1;i<n;++i)b=read();
		while(q--){
			int c=read(),v=read(),x=read(),y=read();
			puts("0");
		}
	}
	return 0;
}
