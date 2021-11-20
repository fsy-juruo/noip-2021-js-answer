#include<bits/stdc++.h>
#define VNAME(x) (#x)
#define DE(x) cerr<<VNAME(x)<<":"<<x<<endl;
#define DEB(a,x)  cerr<<VNAME(a)<<"["<<x<<"]:"<<a[x]<<endl;
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
const int MAXN=10000107;
bitset<MAXN> cnb,nss;
int cb[MAXN],tot,T,ss[MAXN],tot2,pre[MAXN],N;
inline bool check(int x){
	while(x){
		int t=x%10;
		if(t==7)
		return true;
		x/=10;
	}
	return false;
}
inline void process(){
	nss[1]=1;
	for(register int i=2;i<=N;++i){
		cnb[i]=check(i);
		if(!nss[i]){
			ss[++tot2]=i;
		}
		for(register int j=1;j<=tot2&&i*ss[j]<=N;++j){
			nss[i*ss[j]]=1;
			if(i%ss[j]==0)
			break;
		}
	}
}
inline void process2(){
	for(register int i=2;i<=N;++i){
		if(!cnb[i]){
			cb[++tot]=i;
		}
		else{
			for(register int j=1;j<=tot2&&i*ss[j]<=N;++j){
				cnb[i*ss[j]]=1;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(T);
	for(register int i=1;i<=T;++i){
		read(pre[i]);
		N=max(N,pre[i]+100);
	}
	process();
	process2();
	for(register int i=1;i<=T;++i){
		int x=pre[i];
		if(cnb[x]){
			printf("-1\n");
		}
		else{
			printf("%d\n",*upper_bound(cb+1,cb+1+tot,x));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

