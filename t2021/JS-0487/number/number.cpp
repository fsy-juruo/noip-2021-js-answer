#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define inf 0x3f3f3f3f
#define djq 998244353
inline void file(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
inline int read(){
	int ret=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
int _,x[200005],mx;
int ans[11000005];
bitset<11000001> vis;
bool p[10005];
inline bool check(int x){
	bool ret=0;
	while(x&&!ret){
		ret|=(x%10==7);
		x/=10;
	}
	return ret;
}
void work(int n){
	for(int i=1;i<10000;++i) p[i]=check(i);
	for(int i=1;i<=n;++i){
		if(p[i%10000]|p[i/10000]){
			if(!vis[i])
				for(int j=1;i*j<=n;++j)
					vis[i*j]=1;
			vis[i]=1;
		}
	}
	int pre=-1;
	for(int i=n;i;--i){
		if(!vis[i]) ans[i]=pre,pre=i;
		else ans[i]=-1;
	}
	//printf("%d\n",now);
}
signed main(){
	//system("fc number4.out number4.ans");
	file();
	_=read();
	for(int i=1;i<=_;++i){
		x[i]=read(); mx=max(mx,x[i]);
	}
	work(min(11000000,mx+500000));
	for(int i=1;i<=_;++i) printf("%d\n",ans[x[i]]);
	return 0;
}
