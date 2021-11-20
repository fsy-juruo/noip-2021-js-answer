#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int v[1000005];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		cin>>v[i];
		ans=1;
	if(n==k){
		for(int i=0;i<=m;i++)
			ans*=v[i];
		cout<<ans<<endl;
		return 0;
	}
	else cout<<0;
	return 0;
}
