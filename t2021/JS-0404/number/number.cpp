#include<bits/stdc++.h>
#define RE return
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define P pair
#define F first
#define S second
#define ALL(a) a.begin(),a.end()
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
void read(int &x){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	x=0;
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-'0',c=getchar();
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int f[10010005],f2[10010005];
int mx=1e7+100;
void solve(){
	int x;
	read(x);
	if(f2[x]){
		puts("-1");
	}else{
		write(f[x+1]);
		putchar('\n');
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	read(T);
	FOR(i,1,mx){
		if(i%10==7||f[i/10]){
			f[i]=1;
		}
	}
	FOR(i,1,mx)if(f[i]){
		for(int j=i;j<=mx;j+=i)f2[j]=1;
	}
	FILL(f,0);
	for(int i=mx;i>=1;i--){
		if(f2[i]){
			f[i]=f[i+1];
		}else f[i]=i;
	}
	while(T--)solve();
	RE 0;
}

