#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
int search(int x){
	bool flag=true;
	for(int i=1;i<=sqrt(x);i++){
		if(x%i==0){
			int m=i,n=x/i;
			while(m>1){
				if(m%10==7){
					flag=false;
				}
				m=m/10;
			}
			while(n>1){
				if(n%10==7){
					flag=false;
				}
				n=n/10;
			}
		}
		if(flag==false){
			break;
		}
	}
	if(flag==false){
		return -1;
	}
	else{
		return 1;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=a[i];;j++){
			int ans=search(j);
			if(ans==-1&&j==a[i]){
				cout<<"-1"<<endl;
				break;
			}
			else if(ans==1&&j!=a[i]){
				printf("%d\n",j);
				break;
			}
		}
	}
	return 0;
}
