#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;}
bool f[10000010];bool Sev[10000010];
int nxt[10000010];
void Pre(){
	rep(i,0,9)Sev[i]=0;
	Sev[7]=1;
	rep(i,10,10000001)Sev[i]=Sev[i/10]|(i%10==7);
	f[0]=0;
	rep(i,1,10000001){
		if(f[i]==1)continue;
		if(i%7==0||Sev[i]==1){
			for(int j=i;j<=10000001;j+=i)f[j]=1;
		}
	}
	int lst=10000001;
	rep2(i,10000000,1){
		if(f[i])continue;
		nxt[i]=lst;lst=i;
	}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	Pre();
	int T;read(T);
	while(T--){
		int x;read(x);
		if(f[x]){write(-1);}
		else{write(nxt[x]);}
	}
	return 0;
}

