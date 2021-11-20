#include <bits/stdc++.h>
#define rg register
using namespace std;
const int maxl=10000010;

int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')  w=-w;ch=getchar();}
	while (ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return s*w;
}
int n=10000000,T,pos;
bool fuck[maxl];
int nxt[maxl];

namespace ducati{
	bool judge(int val){
		while (val){
			if (val%10==7)  return false;
			val/=10;
		}
		return true;
	}
	void init1(){
		for (rg int i=1;i<=n;++i){
			if (!judge(i))  fuck[i]=1;
		}
	}
	void init2(){
		for (rg int i=1;i<=n;++i){
			if (!judge(i)){
				for (int j=i;j<=n;j+=i)  fuck[j]=1;
			}
		}
	}
	void init3(){
		nxt[n]=n+1;
		for (int i=n-1;i>=1;i--){
			if (!fuck[i])  nxt[i]=i;
			else nxt[i]=nxt[i+1];
		}
	}
	void answer_queries(){
		T=read();
		while (T--){
			int x=read();
			if (fuck[x])  puts("-1");
			else printf("%d\n",nxt[x+1]);
		}
	}
	void solve(){
		init1(),init2(),init3();
		answer_queries();
	}
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ducati::solve();
	return 0;
}
