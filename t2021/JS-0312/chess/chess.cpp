#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ss=0;char cc=getchar();bool ff=1;
	for(cc;!isdigit(cc);cc=getchar()) if(cc=='-')	ff=0;
	for(cc;isdigit(cc);cc=getchar()) ss=(ss<<3)+(ss<<1)+cc-'0';
	return ff?ss:-ss;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cout<<"I have tried my best";
	return 0;
}

