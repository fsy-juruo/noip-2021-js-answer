#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=10000000+10;
int tag[maxn];
bool check(int num){
	if(num%7==0)
		return true;
	int p=num;
	while(p!=0){
		if(p%10==7)
			return true;
		p/=10;
	} 
	return false;
}
inline void init(){
	for(int i=1;i<=maxn;i++){
		if(!tag[i])
			if(check(i)) 
				for(int j=1;i*j<=maxn;j++)
					tag[i*j]=1;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout) ;
	init();
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		int a;
		scanf("%d",&a);
		if(tag[a])
			printf("-1\n");
		else
			for(int j=a+1;j<=maxn;j++)
				if(!tag[j]){
					printf("%d\n",j);
					break;
				}
	}
	return 0;
}
