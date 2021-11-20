#include<bits/stdc++.h>
using namespace std;
	int n,a[10005],ans[10005],key[200005],k=1;
	bool b[200005]={1};
	bool check(int x){
		if(x%7==0)return 0;
		int t=x;
		while(t){
			if(t%10==7)return 0;
			t/=10;
		}
		return 1;
	}
	int find(int x){
		int l=1,r=k,mid;
		while(l<k){
			mid=(l+r)/2;
			if(key[mid]>x){
				r=mid;
			}else if(key[mid]<x){
				l=mid+1;
			}else if(key[mid]==x){
				return mid;
			}
		}
		return 0;
	}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=200005;i++){
		b[i]=check(i);
		
	}
	
	for(int i=1;i<=200005;i++){
		if(!b[i]){
			for(int j=1;j*i<=200005;j++){
				b[i*j]=0;
			}
		}
	}
	
	for(int i=1;i<=200005;i++){
		if(b[i]==1){
			key[k++]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[a[i]]==0){
			ans[i]=-1;
		}else{
			ans[i]=key[find(a[i])+1];
		} 
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
