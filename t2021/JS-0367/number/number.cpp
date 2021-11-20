#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int maxi=200005;
bool p[10000005];
bool find(int n){
	while(n!=0){
		int cur=n%10;
		if(cur==7){
			return false;
		}
		n=n/10;
	}
	return true;
}
void multi(int n){
	for(int i=1;i<=maxi/n;i++){
		p[n*i]=false;
	}
	return;
}
int next(int a){
	int ans;
	a++;
	ans=a;
	while(p[a]==false){
		ans=++a;
	}
	return ans;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	scanf("%d",&t);
	if(t>10000){
		maxi=10000000;
	}
	memset(p,true,sizeof(p));
	for(int i=7;i<=maxi;i++){
		if(p[i]==true){
			if(find(i)==false){
				multi(i);
			}
		}
	}
	for(int i=1;i<=t;i++){
		int x;
		scanf("%d",&x);
		if(p[x]==false){
			printf("%d\n",-1);
		}
		else{
			printf("%d\n",next(x));
		}
	}	
	return 0;
}
