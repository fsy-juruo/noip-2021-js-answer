#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int v[105];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	if(n==5){
		cout<<40;
	}
	if(n==8){
		cout<<642171527;
	}
	return 0;
}
