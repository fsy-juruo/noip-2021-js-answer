#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10000010;
const int INF=1000000007;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int n,mmm;
bool f[maxn+5];
int sum[maxn+5];
int qq[200005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=read();
	for(int i=0;i<T;++i){
		qq[i]=read();
		mmm=max(qq[i],mmm);
	}
	mmm=min(maxn,mmm+100000);
	for(int i=1;i<=mmm;++i){
		if(f[i])continue;
		int t=i;
		bool flag=true;
		while(t){
			if(t%10==7){
				flag=false;
				break;
			}
			t/=10;
		}
		if(flag){continue;}
		for(int j=i;j<=mmm;j+=i)f[j]=true;
	}
	sum[1]=int(f[1]);
	for(int i=2;i<=mmm;++i){
		if(f[i])sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	for(int i=0;i<T;++i){
		int x=qq[i];
		if(f[x]){
			puts("-1");
			continue;
		}
		int l=x+1,r=maxn,mid,res=-1;
		while(l<=r){
			mid=l+r>>1;
			if(sum[mid]-sum[x]==mid-x){
				l=mid+1;
			}
			else{
				r=mid-1;
				res=mid;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

