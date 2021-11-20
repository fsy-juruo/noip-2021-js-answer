#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7+5;
int t,x;
bool forbidden[MAXN];
int nxt[MAXN];
bool have7(int x){
	while(x){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
bool bad(int x){
	if(forbidden[x])return true;
	for(int i=1;i*i<=x;++i)
		if(x%i==0&&(have7(i)||have7(x/i)))return forbidden[x]=true;
	return false;
}
inline int read(){
	int x=0;char ch=getchar();
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}
void write(int x){
	if(x>10)write(x/10);
	putchar((x%10)^48);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	while(t--){
		x=read();
		if(bad(x)){putchar('-');putchar('1');putchar('\n');}
		else{
			if(nxt[x]){
				write(nxt[x]);
				putchar('\n');
				continue;
			}
			int tx=x+1;
			while(bad(tx))++tx;
			nxt[x]=tx;
			write(tx);
			putchar('\n');
		}
	}
	return 0;
}
