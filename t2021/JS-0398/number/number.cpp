#include <bits/stdc++.h>
using namespace std;

int p[10000010],nxt[10000010];

inline int getint()
{
	int r=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		r=(r<<3)+(r<<1)+ch-'0';
		ch=getchar();
	}
	return r;
}

inline void printint(int x)
{
	if(x>=10) printint(x/10);
	putchar('0'^(x%10));
}

inline void init()
{
	for(int i=1;i<=10000001;i++){
		if(!p[i]){
			int x=i;
			while(x){
				p[i]|=((x%10)==7);
				x/=10; 
			}
			if(p[i]){
				for(int j=i+i;j<=10000001;j+=i) p[j]=1;
			}
		}
	}
	int now=10000001;
	for(int i=10000000;i>=1;i--){
		if(!p[i]){
			nxt[i]=now;now=i;
		}
	}
}

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int cases=getint();
	while(cases--){
		int x=getint();
		if(p[x]){
			putchar('-');putchar('1');putchar('\n');
		}
		else{
			printint(nxt[x]);putchar('\n');
		}
	}
	return 0;
}
