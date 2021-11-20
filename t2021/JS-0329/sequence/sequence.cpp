#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int count1,w[107];
long long v[105],ans=0,ansn;
int pd(int a[],int y){
	a[y]--;
	bool flag=true;
	if(a[y]<0){
		flag=false;
		for(int j=y+1;j<=count1;j++){
			if(a[j]>0){
				flag=true;
			}
		}
	}
	if(flag==true){
		return 1;
	}
	else{
		return -1;
	}
}
void dp(int a[],int y){
	for(int t=count1;t>=0;t--){
		if(pd(a,t)==1){
			y--;
			ansn=ansn*v[t];
			dp(a,y);
			y++;
			ansn=ansn/v[t];
		}
	} 
	if(y==0){
		bool flag=true;
		for(int i=0;i<=count1;i){
			if(a[i]!=0){
				flag=false;
				break;
			}
		}
		if(flag==true){
			ans+=ansn%998244353;
			ans=ans%998244353;
		}
		return;
	}
}
void p(int o){
	int e=n;
	if(k==0){
		ansn=0;
		dp(w,e);
		return;
	}
	w[o]=1;
	k--;
	o--;
	p(o);
	k++;
	w[o]=0;
	o--;
	p(o);
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m+1;i++){
		cin>>v[i];
	}
	int count=1,l=n;
	while(l>0){
		count++;
		l=l/2;
	}
	count1=m+1+count;
	for(int i=0;i<count1;i++){
		w[i]=0;
	}
	p(count1);
	cout<<ans%998244353;
	return 0;
}
