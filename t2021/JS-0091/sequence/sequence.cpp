#include<bits/stdc++.h>
#define VNAME(x) (#x)
#define DE(x) cerr<<VNAME(x)<<":"<<x<<endl;
#define DEB(a,x)  cerr<<VNAME(a)<<"["<<x<<"]"<<a[x]<<endl;
using namespace std;
template<typename Tp>
void read(Tp &num){
	num=0;
	Tp f=1;
	char c=getchar();
	while(!isdigit(c))   f=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))    num=num*10+(c^48),c=getchar();
	num*=f;
}
template<typename Tp,typename... etc>
void read(Tp &num,etc&... more){
	read(num);
	read(more...);
}
const int MAXN=107;
const long long mo=998244353;
int n,m,k,hm[MAXN],maxx;
long long val[MAXN],ans,jc[MAXN],jcny[MAXN];
long long ksm(long long x,long long p){
	long long res=1;
	while(p){
		if(p&1){
			res=res*x%mo;
		}
		x=x*x%mo;
		p>>=1;
	}
	return res;
}
long long C(long long x,long long y){
	return jc[x]*jcny[y]%mo*jcny[x-y]%mo;
}
inline void add(){
	long long sum=1,cnt=0;
	for(register int i=0;i<=m;++i){
		sum*=ksm(val[i],hm[i])*C(n-cnt,hm[i])%mo;
		sum%=mo;
		cnt+=hm[i];
	}
	sum%=mo;
	ans+=sum;
	ans%=mo;
}
void dfs2(int now,int hmn){
	if(hmn>n){
		return;
	}
	if(hmn==n){
		if(now<=m)
		add();
		return;
	}
	if(now==0){
		return;
	}
	if(now>m){
		hm[now-1]+=hm[now]*2;
		dfs2(now-1,hmn+hm[now]);
		hm[now-1]-=hm[now]*2;
	}
	else for(register int i=0;i<=hm[now];++i){
		hm[now]-=i;
		hm[now-1]+=i*2;
		dfs2(now-1,hmn+i);
		hm[now]+=i;
		hm[now-1]-=i*2;
	}
}
void dfs1(int now,int hm1){
//	DE(now) DE(hm1)
	if(hm1>n)
	return;
	if(hm1==n||now==maxx+1){
		dfs2(maxx,hm1);
		return;
	}
	if(hm1<k){
		hm[now]=1;
		dfs1(now+1,hm1+1);
		hm[now]=0;
	}
	dfs1(now+1,hm1);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n,m,k);
	jc[0]=1;
	for(register long long i=1;i<=n;++i){
		jc[i]=jc[i-1]*i%mo;
	}
	jcny[n]=ksm(jc[n],mo-2);
	for(register long long i=n-1;i>=0;--i){
		jcny[i]=jcny[i+1]*(i+1)%mo;
	}
	maxx=m+log2(n);
	for(register int i=0;i<=m;++i){
		read(val[i]);
	}
	dfs1(0,0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

