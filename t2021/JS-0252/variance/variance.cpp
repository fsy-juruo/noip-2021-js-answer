#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10005;
const int INF=1000000007;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

ll ans=1e18,s;
int n;
int a[maxn];
int b[maxn];
int c[maxn];

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=0;i<n;++i){
		a[i]=read();
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)b[j]=a[j];
		int t=i;
		while(1){
			bool flag=true;
			for(int j=t;j>=1;--j){
				if(b[j]<b[j-1]+b[j+1]-b[j]){
				b[j]=b[j-1]+b[j+1]-b[j];
					flag=false;
				}
			}
			if(flag)break;
		}
		while(1){
			bool flag=true;
			for(int j=t+1;j+1<n;++j){
				if(b[j]>b[j-1]+b[j+1]-b[j]){
					b[j]=b[j-1]+b[j+1]-b[j];
					flag=false;
				}
			}
			if(flag)break;
		}
		s=0;
		for(int j=0;j<n;++j)s+=b[j];
		ll v=0;
		for(int j=0;j<n;++j){
			v+=(n*b[j]-s)*(n*b[j]-s);
		}
		ans=min(ans,v/n);
	}
	printf("%lld\n",ans);
	return 0;
}

