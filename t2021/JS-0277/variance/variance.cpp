#include <bits/stdc++.h>
using namespace std;
const int N=300010;
bool a[N];
bool wh7(int x){
	while(x>0){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int T,n;
int gcd(int a,int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main(int argc, char** argv) {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout); 
	scanf("%d",&T);
	for(int i=7;i<=N;i++){
		if(wh7(i)&&!a[i]){
			for(int j=1;j*i<=N;j++){
				a[i*j]=1;
			}
		}
	}
	while(T>0){
		T--;
		scanf("%d",&n);
		if(a[n])printf("%d\n",-1);
		else{
			while(a[++n]);
			printf("%d\n",n);
		}
	}
	scanf("%d",&T);
	for(int i=7;i<=N;i++){
		if(wh7(i)&&!a[i]){
			for(int j=1;j*i<=N;j++){
				a[i*j]=1;
			}
		}
	}
	while(T>0){
		T--;
		scanf("%d",&n);
		if(a[n])printf("%d\n",-1);
		else{
			while(a[++n]);
			printf("%d\n",n);
		}
	}
	return 0;
}
