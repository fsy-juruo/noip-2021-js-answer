#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
bool flg[N],fld[N];
int nxt[N];
void init(){
	for(int i=1;i<N;i++){
		flg[i]=flg[i/10]|(i%10==7);
		if(flg[i]&&!fld[i])
			for(int j=i;j<N;j+=i)fld[j]=1;
	}
	for(int i=N-2;~i;i--){
		if(!fld[i+1])nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int T;scanf("%d",&T);
	while(T--){
		int x;scanf("%d",&x);
		if(fld[x])puts("-1");
		else write(nxt[x]),puts("");
	}
	return 0;
}
