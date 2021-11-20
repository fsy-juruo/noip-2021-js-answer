#include<bits/stdc++.h>
using namespace std;
int T,n;
bool a[100010];
void number(){
	for(int i=7;i<=12050;i++){
		int x=i;
		if(a[i]==0)
		while(x!=0){
			if(x%10==7){
				a[i]=1;
				break;
			}
			x=x/10;
		}
		if(a[i]==0)
		for(int j=7;j<=i;j++){
			if(a[j]==1&&(i%j==0))a[i]=1;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	number();
	for(int k=1;k<=T;k++){
		scanf("%d",&n);
		if(a[n]==1){
			printf("%d\n",-1);
		}
		else{
			while(1){
				n++;
				if(a[n]==0){
					printf("%d\n",n);
					break;
				}
			}
		}
	}
	return 0;
}
