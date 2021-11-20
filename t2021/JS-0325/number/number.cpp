#include <cstdio>
#include <algorithm>
#define MAXN 200005
#define MAXX 10000005
#define MAXXR 10000001

using namespace std;
int t,maxn=0;
int a[MAXN];
int res[MAXX];
int hasSeven(int x){
	while(x>0){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	int pre=0;
	for(int i=1;pre<=maxn;i++){
		if(res[i]==-1)continue;
		if(hasSeven(i)){
			res[i]=-1;
			for(int j=2;i*j<=MAXXR;j++){
				res[i*j]=-1;
			}
			continue;
		}
		res[pre]=i;
		pre=i;
	}
	for(int i=1;i<=t;i++){
		printf("%d\n",res[a[i]]);
	}
	return 0;
}
