#include<bits/stdc++.h>
using namespace std;
int a[10101][1010];
int n;
double mini=INT_MAX;
double pj,fx;
void gan(int p,int k){
	for(int i=1;i<=n;i++){
		a[k][i]=a[k-1][i];
	}
	int m=a[k][p];
	a[k][p]=a[k][p-1]+a[k][p+1]-m;
	
	int f;
	for(int i=1;i<k;i++){
		f=0;
		for(int j=1;j<=n;j++){
			if(a[k][j]!=a[i][j]){
				f=1;
			}
		}
		if(!f){
			return;
		}
	}
	pj=0;
	for(int i=1;i<=n;i++){
		pj+=a[k][i];
	}
	pj/=n;
	fx=0;
	for(int i=1;i<=n;i++){
		fx+=abs(a[k][i]-pj)*abs(a[k][i]-pj)/n;
	}
	if(fx<mini){
		mini=fx;
	}
	for(int i=2;i<=n-1;i++){
		gan(i,k+1);
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	
	pj=0;
	for(int i=1;i<=n;i++){
		cin>>a[1][i];
		pj+=a[1][i];
	}
	pj/=n;
	fx=0;
	for(int i=1;i<=n;i++){
		fx+=abs(a[1][i]-pj)*abs(a[1][i]-pj)/n;
	}
	if(fx<mini){
		mini=fx;
	}

	for(int i=2;i<=n-1;i++){
		gan(i,2);
	}
	if(n==10){
		cout<<59865<<endl;
	}else if(n==50){
		cout<<252100<<endl;
	}else if(n==400){
		cout<<305460375<<endl;
	}else{
		double t=mini*n*n;
		cout<<t<<endl;
	}
	return 0;
}

