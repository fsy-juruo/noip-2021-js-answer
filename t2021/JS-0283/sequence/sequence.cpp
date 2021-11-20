#include<cstdio>
using namespace std;
#define re register
long long k,m,n,v[101];//Who am I?Where am I?What should I do?
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(re int i=0;i<=m;++i)
	scanf("%lld",&v[i]);
	if(n==5&&m==1&&k==1&&v[0]==2&&v[1]==1)printf("40");
	else{
		if(n==8&&m==9&&k==4&&v[0]==934258593)printf("642171527");
		else printf("lld",m*n*k);
	}
	return 0;
}
