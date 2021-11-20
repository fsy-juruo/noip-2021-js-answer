#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,k,v[105];
long long ans;
void z(int x,int s,int sv){
	if(x==0){
		int c=0;
		while(s){
			if(s&1)c++;
			s>>=1;
		}
		if(c<=k)ans=(ans+sv)%p;
		return;
	}
	for(int i=0;i<=m;i++){
		z(x-1,s+(1<<i),sv*v[i]);
	}
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	z(n,0,1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
