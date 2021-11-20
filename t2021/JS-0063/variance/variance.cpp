#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	char c=0;int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
const int MAXN=1e4+5;
int n,a[MAXN],tmp[MAXN],ans=2e9,maxsiz;
map<LL,bool>vis;
LL mymul[55];
void dfs(int t1,int t2,LL res){
	if(vis[res])return;
	vis[res]=1;
	ans=std::min(ans,n*t1-t2*t2);
	int bef;
	for(int i=2;i<n;++i){
		bef=tmp[i];
		tmp[i]=tmp[i-1]+tmp[i+1]-tmp[i];
		dfs(t1-bef*bef+tmp[i]*tmp[i],t2-bef+tmp[i],res+(tmp[i]-bef)*mymul[i]);
		tmp[i]=bef;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	if(n==1){
		printf("0\n");
	}
	else if(n==2){
		printf("%d\n",2*(a[1]*a[1]+a[2]*a[2])-(a[1]+a[2])*(a[1]+a[2]));
	}
	else if(n==3){
		int t1,t2,t3;
		t1=a[1],t2=a[2],t3=a[3];
		ans=std::min(ans,n*(t1*t1+t2*t2+t3*t3)-(t1+t2+t3)*(t1+t2+t3));
		t2=a[1]+a[3]-a[2];
		ans=std::min(ans,n*(t1*t1+t2*t2+t3*t3)-(t1+t2+t3)*(t1+t2+t3));
		printf("%d\n",ans);
	}
	else if(n==4){
		int t1,t2,t3,t4;
		t1=a[1],t2=a[2],t3=a[3],t4=a[4];
		ans=std::min(ans,n*(t1*t1+t2*t2+t3*t3+t4*t4)-(t1+t2+t3+t4)*(t1+t2+t3+t4));
		t2=a[1]+a[3]-a[2];
		ans=std::min(ans,n*(t1*t1+t2*t2+t3*t3+t4*t4)-(t1+t2+t3+t4)*(t1+t2+t3+t4));
		t3=a[1]+a[4]-a[2];
		ans=std::min(ans,n*(t1*t1+t2*t2+t3*t3+t4*t4)-(t1+t2+t3+t4)*(t1+t2+t3+t4));
		t2=a[2],t3=a[2]+a[4]-a[3];
		ans=std::min(ans,n*(t1*t1+t2*t2+t3*t3+t4*t4)-(t1+t2+t3+t4)*(t1+t2+t3+t4));
		t2=a[1]+a[4]-a[3];
		ans=std::min(ans,n*(t1*t1+t2*t2+t3*t3+t4*t4)-(t1+t2+t3+t4)*(t1+t2+t3+t4));
		printf("%d\n",ans);
	}
	else if(n<=15){
		int t1=0,t2=0;
		for(int i=1;i<=n;++i)tmp[i]=a[i],maxsiz=std::max(maxsiz,tmp[i]),t1+=(tmp[i]*tmp[i]),t2+=tmp[i];
		mymul[n]=1;
		for(int i=n-1;i>=1;--i)mymul[i]=mymul[i+1]*maxsiz;
		LL res=0;
		for(int i=1;i<=n;++i)res=res*maxsiz+tmp[i]-1;
		dfs(t1,t2,res);
		printf("%d\n",ans);
	}
	else{
		int t1=0,t2=0;
		for(int i=1;i<=n;++i)tmp[i]=a[i];
		for(int i=n-1;i>1;--i)tmp[i]=tmp[i-1]+tmp[i+1]-tmp[i],t1+=(tmp[i]*tmp[i]),t2+=tmp[i];
		t1+=(a[1]*a[1]+a[n]*a[n]),t2+=(a[1]+a[n]);
		ans=std::min(ans,n*t1-t2*t2);
		t1=0,t2=0;
		for(int i=1;i<=n;++i)tmp[i]=a[i];
		for(int i=2;i<n;++i)tmp[i]=tmp[i-1]+tmp[i+1]-tmp[i],t1+=(tmp[i]*tmp[i]),t2+=tmp[i];
		t1+=(a[1]*a[1]+a[n]*a[n]),t2+=(a[1]+a[n]);
		ans=std::min(ans,n*t1-t2*t2);
		printf("%d\n",ans);
	}
	return 0;
}
