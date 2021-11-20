#include<bits/stdc++.h>
#define LL long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define DF(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define mp make_pair
using namespace std;
int read(){
	char ch=getchar();int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
const int M=1e7+10;
bitset<M> gg,h;
int n,nxt[M];
void init(){
	n=10000005;
	F(i,1,n){
		gg[i]=gg[i/10]|(i%10==7);
		if (gg[i]){
			for (int j=i;j<=n;j+=i){
				h[j]=1;
			}
		}
	}
	DF(i,n,1){
		if (!h[i]) nxt[i]=i;
		else nxt[i]=nxt[i+1];
	}
}
void work(){
	int x=read();
	if (!h[x]){
		cout<<nxt[x+1]<<"\n";
	}
	else{
		cout<<"-1\n";
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int T=read();
	while (T--) work();
	return 0;
}
/*

*/

