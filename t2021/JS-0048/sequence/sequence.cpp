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
const int mod=998244353;
long long dp[33][33][110][33],c[33];
long long a[110],pw[110][33],fac[33],inv[33];
void add(ll &x,ll y){
	x=x+y;
	if(x>=mod)x-=mod;
}
int count(int x){
	if(!x)return 0;
	return 1+count(x-(x&-x));
}
ll C(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
ll Ksm(int x,int y){
	return pw[x][y];
}
ll ksm(ll x,ll y){
	if(y==0)return 1;
	if(y==1)return x%mod;
	ll res=ksm(x,y/2);
	res=res*res%mod;
	if(y%2==1)res=res*x%mod;
	return res;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,K;
	read(n),read(m),read(K);
	for(int i=1;i<=m+1;i++)read(a[i]);
	for(int i=1;i<=m+1;i++){
		pw[i][0]=1;
		for(int j=1;j<=n;j++)pw[i][j]=pw[i][j-1]*a[i]%mod;
	}
	for(int i=0;i<=n;i++){
		c[i]=count(i);
	} 
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=ksm(fac[i],mod-2);
	}
	dp[0][0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			for(int ii=0;ii<i;ii++){
				for(int k=1;k<=m+1;k++){
					for(int l=0;l<k;l++){
						for(int s=i-ii;s<=i;s++){
							ll lst=(1ll*(s-(i-ii)))<<(k-l);
							for(int f=0;f+lst<=ii;f++){
								if(f>>(k-l))break;
								int sum=f;
								int x=c[sum];
								if(x>j)continue;
								add(dp[i][j][k][s],dp[ii][j-x][l][f+lst]*C(n-ii,i-ii)%mod*Ksm(k,i-ii)%mod);
							}
						}	
					}
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=K;i++){
		for(int l=1;l<=m+1;l++)
		for(int j=1;j<=n;j++){
			if(i+count(j)<=K)add(ans,dp[n][i][l][j]);
		}
	}
	writeln(ans);
	return 0;
}
/*
正确文件
bat对拍
输出调试
特判0/-1
YES/NO大小写
5 1 1
2 1

4 1 2
1 2
*/

