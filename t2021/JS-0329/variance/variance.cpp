#include<bits/stdc++.h>
using namespace std;
int n,c;
float ans,s=0,a[10001],be[10001];
int j(float p[]){
	float ansn=0,l=0;
	for(int i=0;i<n;i++){
		l+=p[i];
	}
	for(int i=0;i<n;i++){
		ansn+=(p[i]-l/n)*(p[i]-l/n);
	}
	return ansn;
}
void w(float k[]){
	for(int i=1;i<=n-2;i++){
		if(k[i-1]+k[i+1]-k[i]!=k[i]&&k[i-1]+k[i+1]!=k[i]+be[c]){
			int u=k[i];
			be[i]=k[i];
			c=i;
			k[i]=k[i-1]+k[i+1]-k[i];
			if(ans>j(k)){
				ans=j(k);
			}
			w(k);
			k[i]=u;
		}
	}
	return;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		s+=a[i];
	}
	for(int i=0;i<n;i++){
		ans+=(a[i]-s/n)*(a[i]-s/n);
	}
	w(a);
	cout<<ans*n;
}
