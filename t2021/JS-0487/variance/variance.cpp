#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define inf 0x3f3f3f3f3f3f3f3f
#define djq 998244353
inline void file(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
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
int n,a[10005],b[10005],x;
ll sum,now,ans;
signed main(){
	//system("fc number4.out number4.ans");
	file();
	n=read();
	srand(time(0));
	for(int i=1;i<=n;++i){
		b[i]=a[i]=read();
		sum+=a[i]; now+=a[i]*a[i];
	}
	ans=now*n-sum*sum; x=1;
	int tot=40000000;
	while(tot--){
		x=rand()%(n-2)+2;
		sum-=a[x]; now-=a[x]*a[x];
		int tmp=a[x]; a[x]=a[x-1]+a[x+1]-a[x];
		sum+=a[x]; now+=a[x]*a[x];
		if(now*n-sum*sum>ans&&(now*n-sum*sum-ans)>tot){
			sum-=a[x]; now-=a[x]*a[x];
			a[x]=tmp;
			sum+=a[x]; now+=a[x]*a[x];
		}
		ans=min(ans,now*n-sum*sum);
	}
	printf("%lld",ans);
	return 0;
}
/*
4
1 2 4 6
10
6 19 34 35 56 63 82 82 83 99
*/
