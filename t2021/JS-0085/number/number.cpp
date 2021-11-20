#include <bits/stdc++.h>
using namespace std;
int a,n;
bool f[10010086];
int nxt[10010086];
bool ck(int x){
	while(x>0){
		a=x%10;
		x=x/10;
		if(a==7)return true;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10010000;i++){
		if(!f[i]&&ck(i)){
			for(int j=1;j<=10010000/i;j++){
				f[i*j]=true;
			}
		}
	}
	int last=0;
	for(int i=1;i<=10010000;i++){
		if(!f[i]){
			nxt[last]=i;
			last=i;
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int inp;
		scanf("%d",&inp);
		if(f[inp]){
			printf("-1\n");
		}else{
			printf("%d\n",nxt[inp]);
		}
	}
	return 0;
}
