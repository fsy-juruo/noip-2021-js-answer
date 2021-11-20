#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=10010;
const ll maxx=10000000000000;

int n,a[N],b[N];
ll tot,per,minn=maxx;

void chu(){
	for(int i=1;i<=n;i++){
		a[i]=b[i];
	}
}

ll two(ll x){
	return x*x;
}

ll math(ll pjs){
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=two(pjs-a[i]);
	return ans;
} 

bool check(int cha,int t,ll goal){
	ll x1=abs(cha-goal);
	ll x2=abs(a[t]-goal);
	if(x1<x2) return true;
	else return false;
}

void did(int j,ll goal){
	int ch=a[j-1]+a[j+1]-a[j];
		if(ch!=a[j]&&check(ch,j,goal)){
			per=per*n-a[j]+ch;
			per/=n;
			a[j]=ch;
	}
}

int find(ll goal){
	int ll=2,rr=n-1;
	while(ll<rr){
		int mid=(ll+rr)>>1;
		if(a[mid]<goal) ll=mid+1;
		else rr=mid;
	}
	return ll;
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]*=n;
		tot+=b[i];
	}
	per=tot/n;
	minn=math(per);
	ll l=b[1],r=b[n];
	for(ll k=l;k<=r;k+=n){
		chu();per=tot/n;
		for(int i=1;i<=100;i++){
			int bh=find(k);
			for(int j=n-1;j>=2;j--) did(j,k);
			for(int j=2;j<n;j++) did(j,k);
		}
		minn=min(minn,math(per));
	}
	cout<<minn/n;
	return 0;
}

