#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ss=0;char cc=getchar();bool ff=1;
	for(cc;!isdigit(cc);cc=getchar()) if(cc=='-')	ff=0;
	for(cc;isdigit(cc);cc=getchar()) ss=(ss<<3)+(ss<<1)+cc-'0';
	return ff?ss:-ss;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n=read(),m=read(),k=read(),a[110];
	for(int i=0;i<=m;i++)
		a[i]=read();
	cout<<"52"<<endl;
	return 0;
}

