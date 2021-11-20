#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[120],a[120];
long long rt=0,ans=0,t=1;
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++) cin>>v[i];
    for(int i=1;i<=n;i++) a[i]=0;
    while(!a[0]){
    	rt=0;
    	for(int i=1;i<=n;i++) rt+=(1<<a[i]);
    	if(__builtin_popcountll(rt)<=k){
    		t=1;
    		for(int i=1;i<=n;i++) t*=v[a[i]];
    		ans+=t;
		}
		for(int i=n;i>=0;i--){
			if(a[i]==m) a[i]=0;
			else{
				a[i]++;
				break;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
