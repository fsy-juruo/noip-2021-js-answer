#include<bits/stdc++.h>
using namespace std;
int t,a[6000010],cnt,b[10000010];
inline int read()
{
	int x=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x;
}
bool pd(int x)
{
	while(x){
		if((x%10)==7)return true;
		x/=10;
	}
	return false;
}
void mjm()
{
	register int i,j;
	for(i=1;i<=10000002;i++){
		if(pd(i))a[++cnt]=i,b[i]=1;
	}
	for(i=1;i<=10000;i++){
		for(j=1;j<=10000;j++){
			if(a[j]*i>10000000)break;
			b[a[j]*i]=1;
		}
	}
}
void mmc()
{
	register int i,j;
	for(i=1;i<=10000002;i++){
		if(pd(i))a[++cnt]=i,b[i]=1;
	}
	for(i=1;i<=100000;i++){
		for(j=1;j<=100000;j++){
			if((double)clock()/CLOCKS_PER_SEC>0.95)return;
			if(a[j]*i>10000000)break;
			b[a[j]*i]=1;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,x;
	t=read();
	if(t<=1000)mjm();
	else mmc();
	for(i=1;i<=t;i++){
		x=read();
		if(b[x]){printf("-1\n");continue;}
		for(j=x+1;;j++)if(!b[j]){printf("%d\n",j);break;}
	}
}
