#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long w=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		w=(w<<3)+(w<<1)+c-48;
		c=getchar();
	}
	return w*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
long long v[120],a[40],n,m,k,erjingzhi[160],eachnum[110],ans=0;
long long C(long long x,long long y){
	if(y-x<x)x=y-x;
	long long pp=1;
	for(long long i=1;i<=x;i++){
		pp*=(y-i+1);
		pp%=998244353;
	}
	for(long long j=1;j<=x;j++){
		pp/=j;
	}
	return pp;
}
void check(){
	long long xxx=0;
	memset(erjingzhi,0,sizeof(erjingzhi));
	for(long long i=1;i<=n;i++){
		erjingzhi[a[i]]++;
	}
	for(long long i=0;i<=150;i++){
		if(erjingzhi[i]%2==1)xxx++;
		if(xxx>k)return;
		erjingzhi[i+1]+=erjingzhi[i]/2;
	}
	memset(eachnum,0,sizeof(eachnum));
	for(long long i=1;i<=n;i++)eachnum[a[i]]++;
	long long ppp=1,leftnum=n;
	for(long long i=0;i<=m;i++){
		ppp=ppp*pow(v[i],eachnum[i])*C(eachnum[i],leftnum);
		leftnum-=eachnum[i];
	}
	ans+=ppp;
	ans%=998244353;
}
void dfs(long long dep,long long last){
	if(dep==n+1){
		check();
		return;
	}
	for(long long i=last;i<=m;i++){
		a[dep]=i;
		dfs(dep+1,i);
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(long long i=0;i<=m;i++)v[i]=read();
	dfs(1,0);
	write(ans);
	return 0;
}
