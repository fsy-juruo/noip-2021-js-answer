#include<bits/stdc++.h>
using namespace std;


int T,i,a[10000001],p=0,x[200001];

bool s(int n){
	for(int i=1;i<=n;i*=10){
		if(n/i%10==7)return 1;
	}
	return false;
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
 scanf("%d",&T);
for(i=1;i<=T;i++){
	scanf("%d",&x[i]);
	p=max(p,x[i]);
}
for(i=1;i<=min(2*p,10000000);i++){
if(a[i]==0){
	if(s(i)==1)for(int k=1;k*i<=min(2*p,10000000);k++)
      a[k*i]=1;	
}
}
for(i=1;i<=T;i++){
	if(a[x[i]])cout<<"-1"<<endl;
else { 
x[i]++;
while(a[x[i]]==1)x[i]++;
 cout<<x[i]<<endl;
}	
 }


	return 0;
}
