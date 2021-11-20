#include<bits/stdc++.h>
using namespace std;
int t,a[200010],maxn,b[10000010],js;
bool v[10000010];
bool check(int x){
	while(x){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
int find (int x){
	int l=0,r=js;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(b[mid]<x)l=mid;
		else r=mid;
//		cout<<l<<endl;
	}
	return b[r+1];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=maxn+100;i++){
		if(!v[i]&&!check(i)){
			b[++js]=i;
		}
		if(check(i)){
			for(int j=1;j*i<=maxn;j++){
				v[j*i]=1;
			}
		}
	}
//	for(int i=1;i<=js;i++)
//	cout<<b[i]<<endl;
	for(int i=1;i<=t;i++){
		if(v[a[i]]){
			printf("-1\n");
		}else{
			printf("%d\n",find(a[i]));
		}
	}
	return 0;
}
