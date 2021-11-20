#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fn "variance"
const int MAXN=12450;
int n;
double a[MAXN],a1,a2,a3,a4;

inline LL read(){
	LL xs=0,ys=1;char ss=getchar();
	while(ss<'0'||ss>'9'){if(ss=='-')ys=-1;ss=getchar();}
	while(ss>='0'&&ss<='9'){xs=xs*10+ss-'0';ss=getchar();}
	return xs*ys;
}

double fc(double a1,double a2,double a3,double a4){
	double tmp1=(a1+a2+a3+a4)/4.0,tmp2=0.0;
	tmp2+=(a1-tmp1)*(a1-tmp1);
	tmp2+=(a2-tmp1)*(a2-tmp1);
	tmp2+=(a3-tmp1)*(a3-tmp1);
	tmp2+=(a4-tmp1)*(a4-tmp1);
	return tmp2;
}

int main(){
	freopen(fn".in","r",stdin);
	freopen(fn".out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) cin>>a[i];
	a1=a[1];
	a2=a[2];
	a3=a[3];
	a4=a[4];
	if(n==4){
		cout<<(int)n*min(fc(a1,a2,a3,a4),min(fc(a1,a1+a3-a2,a3,a4),fc(a1,a2,a2+a4-a3,a4)));
	}
	return 0;
}

