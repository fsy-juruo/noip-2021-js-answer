#include<bits/stdc++.h>
using namespace std;
const int NB=200005;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	map<int,int> b;
	for(int i=1;i<=NB;i++){
		int a=i;
		while(a!=0){
			if(a%10==7){
				b[i]=1;
				break;
			}
			a=a/10;
		}
	}
	for(int i=1;i<=NB;i++){
		if(b[i]==1){
			for(int j=i;j<=NB;j+=i){
				b[j]=1;
			}
		}
	}
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n;
		scanf("%d",&n);
		if(b[n]==1){
			printf("%d\n",-1);
		}
		else{
			for(int j=n+1;j<=NB;j++){
				if(b[j]==0){
					printf("%d\n",j);
					break;
				}
			}
		}
	}
	return 0;
}
