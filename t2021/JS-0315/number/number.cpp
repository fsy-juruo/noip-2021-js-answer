#include<bits/stdc++.h>
using namespace std;
int h[1000007],b[500000];
int pan1(int x){
	int t=x;
	while(t!=0){
		int yu=t%10;
		if(yu==7) return 2;
		t/=10;
	}
	return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,x,s=0;
	for(int i=1;i<=1000000;i++){
		h[i]=pan1(i);
		if(h[i]==2) b[++s]=i;
	}
	for(int i=1;i<=s;i++){
		for(int j=b[i];j<=1000000;j+=b[i]){
			h[j]=2;
		}
	}
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>x;
		
		if(h[x]==2) {
			cout<<"-1"<<endl;
			continue;
		}
		x++;
		while(h[x]!=1){
			x++;
		}
		cout<<x<<endl;
	}
	return 0;
}
