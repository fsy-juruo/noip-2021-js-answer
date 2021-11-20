#include<bits/stdc++.h>
const int maxn=100000;
using namespace std;
inline int read(){
	char c=getchar();bool f=0;int num=0;
	for(;c<'0'||c>'9';f=(c=='-')?1:0,c=getchar());
	for(;c>='0'&&c<='9';num=(num<<3)+(num<<1)+(c^'0'),c=getchar());
	return  f?-num:num;
}
int	n,ans=99999999;
int a[maxn],b[maxn];
int count(){
	int s=0;
	for(int i=1;i<=n;i++) s+=a[i];
	int sum=0;
	for(int i=1;i<=n;i++) sum+=(n*a[i]-s)*(n*a[i]-s);
	sum/=n;
	return sum;
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=a[max(1,n/2-5)];i<=a[min(n,n/2+5)];i++){//枚举开始的点 

		for(int j=2;j<n;j++) if(abs(a[j-1]+a[j+1]-a[j]-i)<abs(a[j]-i)) a[j]=a[j-1]+a[j+1]-a[j];
		ans=min(ans,count());
		for(int j=n-1;j>=2;j--) if(abs(a[j-1]+a[j+1]-a[j]-i)<abs(a[j]-i)) a[j]=a[j-1]+a[j+1]-a[j];
		ans=min(ans,count());
		for(int j=1;j<=n;j++) a[j]=b[j];
	}
	printf("%d",ans);
	return 0;
}

