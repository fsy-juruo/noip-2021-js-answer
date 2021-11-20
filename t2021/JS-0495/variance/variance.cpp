#include<bits/stdc++.h>
using namespace std;
int n,t;
long long ans=10000000000000001;
string st,ss,ys[10]={"0","1","2","3","4","5","6","7","8","9"};
map <string,bool> mp;
string tost(int a[]){
	ss="";
	for(int i=1;i<=n;i++){
		ss+="/";
		int w=a[i];
		while(w!=0){
			ss+=ys[w%10];
			w/=10;
		}
	}
	return ss;
}
void dfs(int a[]){
	int c;
	for(int i=2;i<n;i++){
		if(a[i-1]+a[i+1]-a[i]!=a[i]){
			c=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			st=tost(a);
			if(mp[st]){
				a[i]=c;
				continue;
			}
			mp[st]=1;
			long long fz=0,s=0;
			for(int j=1;j<=n;j++)s+=a[j];
			for(int j=1;j<=n;j++)fz+=(a[j]*n-s)*(a[j]*n-s);
			ans=min(fz/n,ans);
			t+=n;
			if(t>100000000){
				a[i]=c;
				continue;
			}
			dfs(a);
			a[i]=c;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	int a[10001];
	for(int i=1;i<=n;i++)cin>>a[i];
	st=tost(a);
	mp[st]=1;
	dfs(a);
	cout<<ans;
	return 0;
}
