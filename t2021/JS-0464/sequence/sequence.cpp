#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,len,v[110],seq[110],sum[110],yh[110][110],base[110];
const int MOD(998244353);
inline int read(){
	int FF=0,RR=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())
		if(ch=='-')
			RR=-1;
	for(;isdigit(ch);ch=getchar())
		FF=(FF<<1)+(FF<<3)+ch-48;
	return FF*RR;
}
int fastpow(int x,int y){
	int ret=1;
	for(;y;y>>=1){
		if(y&1)
			ret=ret*x%MOD;
		x=x*x%MOD;
	}
	return ret;
}
void buildA(int dep,int fnl,int cur,int num){
	if(dep>m){
		if(cur==fnl&&num==n){
//			for(int i=0;i<=m;i++)
//				cout<<sum[i]<<' ';
//			cout<<'\n';
			int tmp=n,eqi=1,once=1;
			for(int i=0;i<=m;i++){
				eqi=eqi*yh[tmp+1][sum[i]+1]%MOD;
				tmp-=sum[i];
				once=once*fastpow(v[i],sum[i])%MOD;
			}
			ans=(ans+once*eqi%MOD)%MOD;
		}
		return;
	}
	if(cur+base[dep]*(n-num)>fnl||cur+base[m]*(n-num)<fnl)
		return;
	for(int i=num;i<=n;i++){
		int x=cur+base[dep]*(i-num);
		if(x<=fnl){
			sum[dep]=i-num;
			buildA(dep+1,fnl,x,i);
		}
		else
			break;
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=1;i<=100;i++)
		for(int j=1;j<=i;j++)
			if(j==1||i==j)
				yh[i][j]=1;
			else
				yh[i][j]=(yh[i-1][j-1]+yh[i-1][j])%MOD;
	base[0]=1;
	for(int i=1;i<=100;i++)
		base[i]=(base[i-1]*2)%MOD;
//	cout<<"+++"<<base[1]<<'\n';
	n=read();m=read();k=read();
//	cout<<(1<<m)<<" "<<base[m]<<'\n';
	for(int i=0;i<=m;i++)
		v[i]=read();
	for(int i=n;i<=n*base[m];i++){
		int tmp=i,s1=0;
		len=0;
		for(;tmp;tmp>>=1,len++){
			seq[len]=tmp%2;
			if(seq[len]==1)
				s1++;
		}
		if(s1>k)
			continue;
//		cout<<i<<' ';
		buildA(0,i,0,0);
	}
	printf("%lld",ans);
	return 0;
}

