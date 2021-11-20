#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template <typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
		x*=f;
	}
	template <typename T>inline void write(T x){
		if(x<0){putchar('-');x=-x;}
		if(x>9)write(x/10);
		putchar(x%10+'0');
	}
	template <typename T>inline void writeln(T x){
		write(x);putchar('\n');
	}
	template <typename T>inline void writesp(T x){
		write(x);putchar(' ');
	}
}
using namespace IO;
const int M=998244353;
const int dir[10]={1,2,4,8,16,32,64,128}; 
long long ans;
int n,m,k,T;
int v[205]; 
int p[205];
void tj(int dep){
	if(dep==n){
		++T;
		return;
	}
	for(int i=0;i<=m;++i){
		if(p[i]){
			--p[i];
			tj(dep+1);
			++p[i];
		}
	}
}
int ksm(int x,int y){
	int s=1;
	while(x){
		if(x&1)s=(long long)s*y%M;
		y=(long long)y*y%M;
		x>>=1;
	}
	return s;
}
void work(){
	long long s=1;
	for(int i=0;i<=m;++i){
		if(p[i])s=s*ksm(p[i],v[i])%M;
	}
	T=0;
	tj(0);
	ans=(ans+(long long)s*T)%M;
}
void dfs(int x,int dep,int num){
	if(num==n){
//		for(int i=0;i<=m;++i)cout<<p[i]<<' ';
//		cout<<endl; 
		work();
		return;
	}
	if(x==0)return;
	
	if(!v[x]){
		int tmp=p[x]; 
		p[x-1]=p[x]*2;
		p[x]=0;
		dfs(x-1,dep+1,num+tmp);
		p[x-1]=0; 
		return;
	}
	
	for(int i=1;i<=p[x];++i){
		p[x]-=i;
		p[x-1]=i*2;
		dfs(x-1,dep+1,num+i);
		p[x-1]=0; 
		p[x]+=i;
	}
}
bool check(int x,int sum){
	while(x){
		sum+=(x&1);
		if(sum>k)return 0;
		x>>=1;
	}
	return 1;
}
void dfs2(int x,int y,int num,int sum){
	if(num<n&&sum>=k)return;
	if(x>m)return;
	if(num==n){
		if(!check(y/2,sum))return; 
		work();
		return;
	}
	if(!v[x]){
		dfs2(x+1,y/2,num,sum+((y/2)&1));
		return;
	}
	for(int i=0;i<=n-num;++i){
		p[x]=i;
		dfs2(x+1,i+y/2,num+i,sum+((i+y/2)&1));
		p[x]=0;
	}
} 
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);

	read(n);read(m);read(k);
	for(int i=0;i<=m;++i)read(v[i]);
	
	if(k==1){
		for(int i=m+15;i>=1;--i){
			p[i]=1;
			dfs(i,0,1);
		}
		writeln(ans);
		return 0;
	}
	
	dfs2(0,0,0,0);
	
	writeln(ans);
	return 0;
}

