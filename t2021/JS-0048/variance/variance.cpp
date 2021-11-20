#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define pll pair<long long,long long>
#define pb push_back
#define mp make_pair
using namespace std;
template<typename T>inline void read(T &x){
	x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template<typename T>inline void wrt(T x){
	if(x>9)wrt(x/10);
	putchar(x%10+'0');
}
template<typename T>inline void write(T x){
	if(x<0){putchar('-');x=-x;}
	wrt(x);
}
template<typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template<typename T>inline void writeln(T x){
	write(x);
	puts("");
}
const int MAXN=1e4+10;
int a[MAXN],bh[MAXN];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	int l=1,r=n;
	while(l<=r){
		for(int i=l+1;i<r;i++){
			if(i==l+1){
				a[i]=max(a[i],a[i+1]+a[i-1]-a[i]);
			}
			else a[i]=min(a[i],a[i+1]+a[i-1]-a[i]);
		}
		int s1=a[l+1],s2;
		for(int i=r-1;i>l;i--){
			if(i==r-1){
				a[i]=min(a[i],a[i+1]+a[i-1]-a[i]);
			}
			else a[i]=max(a[i],a[i+1]+a[i-1]-a[i]);
		}
		s2=a[l+1];
		bh[l-1]=s1-s2;
		l++;r--;
	}
	ll ans=0,sum=0,maxx=1e18;
	for(int i=0;i<=(1<<l)-1;i++){
		ans=0;sum=0;
		int x=i;
		for(int j=0;j<=l;j++){
			if(i&(1<<j)){
				for(int i=j+1;i<=n-j-1;i++){
					a[i]+=bh[j];
				}
			}
		}
		for(int i=1;i<=n;i++)sum+=a[i];
		for(int i=1;i<=n;i++)ans=ans+1ll*(a[i]*n-sum)*(a[i]*n-sum); 
		for(int j=0;j<=l;j++){
			if(i&(1<<j)){
				for(int i=j+1;i<=n-j-1;i++){
					a[i]-=bh[j];
				}
			}
		}
		maxx=min(maxx,ans/n);
	}
	writeln(maxx);
	return 0;
}
/*
正确文件
bat对拍
输出调试
特判0/-1
YES/NO大小写
*/

