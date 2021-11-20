#include<bits/stdc++.h>
using namespace std;
int t,n;
int hasSeven(int x){
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int isPrime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		} 
	}
	return 1;
}
int p[10000006],rec[10000006];
vector<int>ava;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	scanf("%d",&t);
	n=10000000; 
	for(int i=1;i<=n;i++){
		if(p[i]==0&&hasSeven(i)){
			p[i]=1;
			for(int j=i+i;j<=n;j+=i){
				p[j]=1;
			}
		}
	}
	
	ava.reserve(n);
	for(int i=1;i<=n;i++){
		if(p[i]==0){
			ava.push_back(i);
		}
	}
	
	for(int i=1;i<=t;i++){
		int x;
		scanf("%d",&x);//
		if(p[x]==1){
			printf("-1\n");
		}else{
			auto p=upper_bound(ava.begin(),ava.end(),x);
			if(p==ava.end()){
				printf("%d\n",n); 
				continue;
			}
			printf("%d\n",*p);
		}
	}
	
	
	return 0; 
}
/*
4
6
33
69
300
*/
/*
5
90
99
106
114
169
*/
