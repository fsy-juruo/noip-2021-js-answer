//WSQ
#include<cstdio>
#define maxn 10005050
using namespace std;
int T;
int l[maxn+5000],p[maxn+5000];
void init(){
	for(int i=1;i<=maxn;i++)if(!p[i]){
		int ii=i;
		while(ii){
			if(ii%10==7){
				p[i]=1;
				for(int j=2*i;j<=maxn;j+=i)p[j]=1;
				break;
			}ii/=10;
		}
	}
	for(int i=maxn;i>=1;i--){
		if(p[i]==0)l[i]=0;
		else l[i]=l[i+1]+1;
	}
}
int fastr(){
	int ret=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){
		ret=ret*10+(ch-'0');
		ch=getchar();
	}
	return ret;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=fastr();
	init();
	while(T--){
		int x=fastr();
		if(p[x])printf("-1\n");
		else printf("%d\n",x+1+l[x+1]);
	}
	return 0;
}
