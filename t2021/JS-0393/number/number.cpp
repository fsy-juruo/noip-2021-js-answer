#include<bits/stdc++.h>
using namespace std;

bool check[10100000+1000];
long long t;

void fuzhi(long long k){
	for(long long i=k;i<=10001000;i+=k){
		check[i]=true;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(long long i=7000000;i<=7999999;i+=1){
		check[i]=true;
	}
	for(long long i=700000;i<=10001000;i+=1000000){
		for(long long j=0;j<=99999;j++){
			if(check[i+j]==false){
				fuzhi(i+j);
			}
		}
	}
	for(long long i=70000;i<=10001000;i+=100000){
		for(long long j=0;j<=9999;j++){
			if(check[i+j]==false){
				fuzhi(i+j);
			}
		}
	}
	for(long long i=7000;i<=10001000;i+=10000){
		for(long long j=0;j<=999;j++){
			if(check[i+j]==false){
				fuzhi(i+j);
			}
		}
	}
	for(long long i=700;i<=10000500;i+=1000){
		for(long long j=0;j<=99;j++){
			if(check[i+j]==false){
				fuzhi(i+j);
			}
		}
	}
	for(long long i=70;i<=10000500;i+=100){
		for(long long j=0;j<=9;j++){
			if(check[i+j]==false){
				fuzhi(i+j);
			}
		}
	}
	for(long long i=7;i<=10000500;i+=10){
		if(check[i]==false)
			fuzhi(i);
	}
	cin>>t;
	long long x;
	for(long long i=1;i<=t;i++){
		cin>>x;
		if(check[x]==true){
			cout<<"-1"<<endl;
		}
		else{
			for(long long j=x+1;j<=10005000;j++){
				if(check[j]==false){
					printf("%lld\n",j);
					break;
				}
			}
		}
	}
	return 0;
}
