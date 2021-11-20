#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod=998244353;
int n,m,k,v[500],a[500],ans=0;
int minn=INT_MAX,maxn=INT_MIN;
int read(){
	int xx=0,ff=1;
	char ch=getchar();
	while (!isdigit(ch)){
		if (ch=='-')ff=-1;
		ch=getchar();
	}
	while (isdigit(ch)){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return ff*xx;
}
void write(int x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x>9)write(x/10);
	putchar(x%10+'0');
}
int qpow(int a,int b){
	int sum=1,base=a;
	while (b>0){
		if (b&1)sum*=base;
		base=base*base;
		b>>=1;
	}
	return sum;
}
int fj(int sum){
	int cnt=0;
	while (sum!=0){
		int x=sum%2;
		sum/=2;
		if (x==1)cnt++;
	}
	return cnt;
}
int C(int x,int y){
	int s1=1,s2=1;
	for (int i=1;i<=y;i++)
	   s1*=i;
	for (int i=1;i<=x;i++)
	   s2*=i;
	for (int i=1;i<=y-x;i++)
	   s2*=i;
	return s1/s2;
}
inline void dfs(int dep,int sum,int val){
	if (sum>maxn)return ;
	if (dep>n){
		if (sum<minn||sum>maxn)return ;
		if (fj(sum)<=k){
			ans+=val;
			ans%=mod;
		}
		return ;
	}
	for (int i=0;i<=m;i++)
	   dfs(dep+1,sum+qpow(2,i),(val*v[i])%mod);
	return ;
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i=0;i<=m;i++)v[i]=read();
	minn=n;maxn=n*qpow(2,m);
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}


