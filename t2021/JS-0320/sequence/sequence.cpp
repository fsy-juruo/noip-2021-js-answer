#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,k,v[105],a[35],s[35],ans=0;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return (f*x)%mod;
}
inline void write(int x){
	stack<int>s;char ch;
	if(x==0){putchar('0');return;}
	if(x<0){putchar('-');x=-x;}
	while(x!=0){s.push(x%10);x/=10;}
	while(!s.empty()){ch=s.top();s.pop();putchar(ch^48);}
	return;
}
int pw(int x,int y){
	int ans=1;
	while(y!=0){
		if(y&1)ans*=x;
		x*=x;
		ans=ans%mod;
		x=x%mod;
		y/=2;
	}
	return ans;
}
int jc(int x){
	int ans=1;
	for(int i=1;i<=x;i++){
		ans*=i;
		ans=ans%mod;
	}
	return ans;
}
int ny(int x){
	int ans;
	x=jc(x)%mod;
	ans=pw(x,mod-2)%mod;
	return ans;
}
void dfs(int t){
	if(t==n+1){
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++){
			if(s[a[i]]==0)s[a[i]]=1;
			else{
				int p=a[i];
				while(s[p]!=0){
					s[p]=0;
					p++;
				}
				s[p]=1;
			}
		}
		int cnt=0;
		for(int i=0;i<=30;i++)if(s[i]==1)cnt++;
		if(cnt<=k){
			int ans1=1,tong[105],ans2=1;
			memset(tong,0,sizeof(tong));
			for(int i=1;i<=n;i++){
				ans1=(ans1*v[a[i]])%mod;
				tong[a[i]]++;
			}
			for(int i=0;i<=m;i++){
				if(tong[i]!=0){
					ans2=(ans2*ny(tong[i]))%mod;
				}
			}
			ans2=(ans2*jc(n)%mod)%mod;
			ans1*=ans2;
			ans=(ans+ans1)%mod;
		}
		return;
	}
	for(int i=a[t-1];i<=m;i++){
		a[t]=i;
		dfs(t+1);
	}
	return;
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=0;i<=m;i++)v[i]=read();
	a[0]=0;
	dfs(1);
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
