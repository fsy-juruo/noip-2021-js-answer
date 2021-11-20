#include<bits/stdc++.h>
using namespace std;
const int N=10000005;
int y[N];
bool check(int a){
	if(a%7==0) {
		y[a]=1;
		return false;
	}
	int b=a,c=a;
	while(a){
		int k=a%10;
		if(k==7) {
			y[b]=1;
			return false;
		}
		a/=10;
	}
	for(int i=1;i<=b/2;i++){
		if(c%i==0&&(y[i]==1||!check(i))) {
			y[b]=1;
			return false;
		}
	}
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		int i=x;
		if(!check(x)){
			printf("-1\n");
			continue;
		}
		while(true){
			i++;
			if(y[i]==1) continue;
			else if(check(i)){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
