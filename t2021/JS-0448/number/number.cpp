#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
#define MP make_pair
using namespace std;
typedef long long ll;

inline void read(int &x) {
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
}
const int N=1e7+30;
bool vis[N];
int cnt,nxt[N],T;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=1e7+15;i++) {
		if(i%7==0) vis[i]=true;
		int x=i;
		bool flag=false;
		while(x) {
			if(x%10==7) {
				flag=true;
				break;
			}
			x/=10;
		}
		if(flag) {
			vis[i]=true;
			for(int j=i+i;j<=1e7+15;j+=i) {
				vis[j]=true;
			}
		}
	}
	int k=0;
	for(int i=1e7+15;i>=1;i--) {
		nxt[i]=k;
		if(!vis[i]) k=i;
	}
	read(T);
	while(T--) {
		int x;
		read(x);
		if(vis[x]) printf("-1\n");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
