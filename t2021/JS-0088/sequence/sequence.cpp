#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[1005],b[1005],ans,v;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
	cin>>a[i];
	v=n;
	while(!b[n+1]){
		int t=0,x=v;
		while(x){
			if(x&1==1)t++;
			x=x>>1;
		}
		if(t<=k){
			long long sum=1;
			for(int i=1;i<=n;i++)
			sum=sum*a[b[i]]%998244353;
			ans=(ans+sum)%998244353;
		}
		b[1]++;
		v=v+(1<<(b[1]-1));
		int j=1;
		while(b[j]>m){
			b[j]=0;
			j++;
			b[j]++;
			v=v-(1<<(m+1))+1+(1<<(b[j]-1));
		}
	}
	cout<<ans;
	return 0;
}
