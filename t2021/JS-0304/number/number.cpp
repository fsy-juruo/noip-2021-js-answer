#include<bits/stdc++.h>
using namespace std;
int T,s;
bool a[10000010];
void biao(){
	for(int i=1;i<=10000010;i++){
		if(a[i]!=1){
			int q=i;
			while(q){
				int u=q%10;
				q=q/10;
				if(u==7){
					a[i]=1;
					break;
				}
			}
			if(a[i]==1){
				for(int j=1;j*i<=10000000;j++){
					a[i*j]=1;
				}
			}
		}
	}
}
void check(int s){
	if(a[s]==0){
		for(int i=s;i++;i<=10000000){
			if(a[i]==0){
			cout<<i<<endl;
			break;
			}
		}
	}
	else
		cout<<-1<<endl;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	biao();
	for(int i=1;i<=T;i++){
		scanf("%d",&s);
		check(s);	
	}
	return 0;
}
