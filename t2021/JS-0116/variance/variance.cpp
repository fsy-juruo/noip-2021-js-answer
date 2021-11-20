#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[10010],ans,S,b[10010],c[10010],s[10010],ed,N;
bool d[100];
void dfs1(int x){
	if(x==n-1){
	for(int i=1;i<n;i++)a[i]=a[i-1]+c[i-1];
	ans=S=0;
	ll N=n;
	for(int i=0;i<n;i++){
		ans+=a[i]*a[i];
		S+=a[i];
	}ed=min(ed,N*ans-S*S);
	return;
	}
	for(int i=0;i<n-1;i++) if(!d[i]){
		d[i]=1;
		c[x]=b[i];
		dfs1(x+1);
		d[i]=0;
	}
}
void dfs(int x){
	if(x==n-1){
	for(int i=1;i<n;i++)a[i]=a[i-1]+c[i-1];
	ans=S=0;
	ll N=n;
	for(int i=0;i<n;i++){
		ans+=a[i]*a[i];
		S+=a[i];
	}
	//cout<<N*ans-S*S<<endl;
	if(N*ans-S*S==ed){
		for(int i=0;i<n-1;i++)cout<<c[i]<<' ';
		cout<<endl;
	}
	return;
	}
	for(int i=0;i<n-1;i++) if(!d[i]){
		d[i]=1;
		c[x]=b[i];
		dfs(x+1);
		d[i]=0;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ed=1e18;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++)b[i]=a[i+1]-a[i];
	sort(b,b+n-1);
	/*c[0]=b[n-2];
	s[0]=0;
	for(int i=1;i<n-1;i++){
		ed=10000000000000000;
		c[i]=b[n-2-i];
		for(int k=1;k<=i;k++)a[k]=a[k-1]+c[k-1];
		ans=S=0;
		N=n;
		for(int k=0;k<n;k++){
			ans+=a[k]*a[k];
			S+=a[k];
		}
		int j=i,o;
		while(j>0){
			if(ed>N*ans-S*S){
				ed=N*ans-S*S;
				o=j;
			}
			swap(c[j],c[j-1]);
			ans=S=0;
			for(int k=1;k<=i;k++)a[k]=a[k-1]+c[k-1];
			for(int k=0;k<n;k++){
				ans+=a[k]*a[k];
				S+=a[k];
			}
			j--;
		}
		while(j<o){
			swap(c[j],c[j+1]);
			j++;
		}
	}*/
	if(n<12){
		ed=10000000000000000;
		dfs1(0);
		cout<<ed<<endl;
		return 0;
	}
//	dfs(0);{
//	cout<<ed<<endl;
	ll s1=0,s2=0;
	ll l=0,r=n-2,p=n-2;
	while(l<r){
		if(s1+b[p]*l<s2+b[p]*(n-2-r)){
			c[l]=b[p];
			s1+=b[p]*l;
			l++;
		}else{
			c[r]=b[p];
			s2+=b[p]*(n-2-r);
			r--;
		}
		p--;
	}
	if(l==r)c[l]=b[0];

	
		for(int k=1;k<n-1;k++)a[k]=a[k-1]+c[k-1];
		ans=S=0;
		N=n;
		for(int k=0;k<n;k++){
			ans+=a[k]*a[k];
			S+=a[k];
		}
		cout<<N*ans-S*S<<endl;
	return 0;
}
