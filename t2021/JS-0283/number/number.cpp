#include<cstdio>
using namespace std;
#define re register
int T,x,a[10000001];
inline bool pd(int baoli){
	int CaO;
	while(baoli>0){
		CaO=baoli%10;
		if(CaO==7)return 1;
		baoli=baoli/10;
	}
	return 0;
}
int main(){
	for(re int i=1;i<10000001;++i){
		if(pd(i)){
			re int j=i;
			while(j<10000001){
				a[j]=1;
				j=j+i;
			}
		}
	}
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(re int kt=0;kt<T;++kt){
		scanf("%d",&x);
		if(a[x])printf("-1\n");
		else{
			++x;
			while(a[x])++x;
			printf("%d\n",x);
		}
	}
	return 0;
}
