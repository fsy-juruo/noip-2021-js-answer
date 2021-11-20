#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=1e7+5;

inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)){
		x=x*10+(c^48);
		c=getchar();
	}
	return x;
}

void putint(int x){
	if(x>9) putint(x/10);
	putchar(x%10+'0');
}

bool st[N];
bool stt[N];
int ne[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for(int i=1;i<N;++i) if(i%10==7||st[i/10]) st[i]=true;

	for(int i=7;i<N;i+=7) stt[i]=st[i]=true;
	for(int i=1;i<N;++i) if(st[i]&&!stt[i])
		for(int j=(i<<1);j<N;j+=i) st[j]=true;	
	
	ne[N-5]=N-4;
	for(int i=N-6;i;--i){
		if(st[i+1]) ne[i]=ne[i+1];
		else ne[i]=i+1;
	}
	
	int T=getint();
	while(T--){
		int x=getint();
		if(st[x]) putchar('-'),putchar('1');
		else putint(ne[x]);
		putchar('\n');
	}
	
	return 0;
}
