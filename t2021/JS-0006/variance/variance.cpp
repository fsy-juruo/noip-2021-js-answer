#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,S,a[10100],b[10100];
ll res=0x3f3f3f3f3f3f3f3f;
bool sd[10100],mns[10100];
mt19937 rnd(17680321);
inline ll sqr(int x){return 1ll*x*x;}
ll calc(){
	int s=0,t=0,sum=0;
//	for(int i=1;i<=m;i++)printf("%d ",sd[i]);puts("");
	for(int i=1;i<=m;i++){
		if(sd[i])sum+=s,s+=b[i];
		else sum+=S-t,t+=b[i];
	}
	sum+=s*(n-m);
//	printf("%d\n",sum);
	ll ret=1ll*sqr(s*n-sum)*(n-m);
	s=t=0;
	for(int i=1;i<=m;i++){
		if(sd[i])ret+=sqr(s*n-sum),s+=b[i];
		else ret+=sqr((S-t)*n-sum),t+=b[i];
	}
	return ret;
}
const double Delta=0.9995;
const double eps=1e-6;
void SA(){
	double T=100000000;
	ll now=res;for(int i=1;i<=m;i++)sd[i]=mns[i];
	while(T>eps){
//		printf("%lf\n",T);
		int x=rnd()%m+1;
		sd[x]^=1;ll nex=calc(),del=nex-now;
//		printf("%d:%lld,%lf:%lf,%lf\n",x,del,T,-del/T,log(4294967295));
		if(nex<=res){res=nex;for(int i=1;i<=m;i++)mns[i]=sd[i];}
		else if(exp(-del/T)*4294967295>rnd())now=nex;
		else sd[x]^=1;
		T*=Delta;
	}
}
void climb(){
	for(int i=1;i<=m;i++)mns[i]=rnd()&1;
	ll now=res=calc();
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=m;j++)sd[j]=mns[j];
		for(int j=1;j<=log(i)+1;j++)sd[rnd()%m+1]^=1;
		ll nex=calc();
		if(nex<now){res=now=nex;for(int j=1;j<=m;j++)mns[j]=sd[j];}
	}
}
namespace FIFO{
//char buf[1<<23],*p1=buf,*p2=buf;
//#define gc() (p1==p2&&(p2=buf+fread(p1=buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define gc() getchar()
void read(int&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
void print(int x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
}using namespace FIFO;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	S=a[n]-a[1];
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	sort(b+1,b+n),reverse(b+1,b+n);
	m=n-1;while(m&&!b[m])m--;
//	for(int i=1;i<=m;i++)printf("%d ",b[i]);puts("");
	if(!m){puts("0");return 0;}
	for(int i=1;i<=m;i++)mns[i]=sd[i]=rnd()&1;
	res=calc();
//	printf("%d\n",res);
	climb();
	for(int i=1;i<=10;i++)SA();
	printf("%lld\n",res/n);
	return 0;
}
