#include<bits/stdc++.h>
using namespace std;
int T;
bool f[10000100];
int a[10000100];
void work(){
	memset(f,true,sizeof(f));
	for(int i=7;i<=10000100;i+=10){
		if(!f[i])continue;
		for(int j=i;j<=10000100;j+=i){
			f[j]=false;
		}
	}             
	for(int i=70;i<=10000100;i+=100){
		for(int j=i;j<=i+9;j++){
			if(!f[j])continue;
			for(int k=j;k<=10000100;k+=j){
				f[k]=false;
			}
		}
	}
	for(int i=700;i<=10000100;i+=1000){
		for(int j=i;j<=i+99;j++){
			if(!f[j])continue;
			for(int k=j;k<=10000100;k+=j){
				f[k]=false;
			}
		}
	}
	for(int i=7000;i<=10000100;i+=10000){
		for(int j=i;j<=i+999;j++){
			if(!f[j])continue;
			for(int k=j;k<=10000100;k+=j){
				f[k]=false;
			}
		}
	}
	for(int i=70000;i<=10000100;i+=100000){
		for(int j=i;j<=i+9999;j++){
			if(!f[j])continue;
			for(int k=j;k<=10000100;k+=j){
				f[k]=false;
			}
		}
	}
	for(int i=700000;i<=10000100;i+=1000000){
		for(int j=i;j<=i+99999;j++){
			if(!f[j])continue;
			for(int k=j;k<=10000100;k+=j){
				f[k]=false;
			}
		}
	}
	for(int i=7000000;i<=10000100;i+=10000000){
		for(int j=i;j<=i+999999;j++){
			if(!f[j])continue;
			for(int k=j;k<=10000100;k+=j){
				f[k]=false;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	work();
	int l;
	for(int i=10000100;i>=1;i--){
		if(a[i])l=i;
	}
	for(int i=10000100;i>=1;i--){
		if(!f[i])a[i]=-1;
		else{
			a[i]=l;
			l=i;
		}
	}
	while(T--){
		int x;
		scanf("%d",&x);
//		cout<<x<<endl;
		printf("%d",a[x]);
		putchar('\n');
	}
	return 0;
}

