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
const int MAXN=10007;
long long n,in[MAXN],maxx,tmp[MAXN];
long long ans=LONG_LONG_MAX;
inline void work(long long now){
	for(register int i=1;i<=n;++i){
		tmp[i]=in[i];
	}
	for(register int i=1;i<=n;++i){
		for(register int j=2;j<n;++j){
			if(abs(tmp[i-1]+tmp[i+1]-tmp[i]-now)<abs(tmp[i]-now)){
				tmp[i]=tmp[i-1]+tmp[i+1]-tmp[i];
			}
		}
	}
	double pjs=0;
	for(register int i=1;i<=n;++i){
		pjs+=(double)tmp[i];
	}
	pjs/=(double)n;
	double fc=0;
	for(register int i=1;i<=n;++i){
		fc+=((double)tmp[i]-pjs)*((double)tmp[i]-pjs);
	}
	ans=min(ans,(long long)(fc*n));
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(register int i=1;i<=n;++i){
		read(in[i]);
		maxx=max(maxx,in[i]);
	}
	for(register int i=0;i<=maxx;++i){
		work(i);
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

