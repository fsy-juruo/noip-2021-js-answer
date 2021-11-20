#include<bits/stdc++.h>
#define M %998244353
using namespace std;
long long read(){
	long long s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}
	return s*f;
}
long long n,m,k,v[120],ans;
long long qpow(long long a,long long b){
	if(b==0)return 1;
	return b%2==1?qpow(a,b-1)*a M:qpow(2*a,b/2) M;
}
bool check(long long s){
	long long t=0;
	while(s>0){
		if(s%2==1)t++;
		s/=2;
	}
	if(t<=k)return true;
	return false;
}
void dfs(long long dep,long long s,long long as){
	if(dep==n){
		if(check(s)==1)ans=(ans+as)M;
		//cout<<s<<' '<<as<<endl;
		return;
	}
	for(long long i=0;i<=m;i++){
		dfs(dep+1,(s+qpow(2,i))M,as*v[i]M);
	}
}
int main(){

freopen("sequence.in","r",stdin);
freopen("sequence.out","w",stdout);

n=read();
m=read();
k=read();
for(long long i=0;i<=m;i++)v[i]=read();
dfs(0,0,1);
cout<<ans<<endl;
return 0;
}

