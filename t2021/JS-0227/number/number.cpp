#include<bits/stdc++.h>
using namespace std;
int t,n,cha[11000005],d,suf[11000005];
bool v[11000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1,p=1;i<=7;i++,p*=10){
		for(int j=0;j*p*10+7*p<=11000000;j++){
			cha[j*p*10+7*p]++;
			if(j*p*10+8*p<=11000000)
				cha[j*p*10+8*p]--;			
		}
	}
	for(int i=1;i<=11000000;i++){
		d+=cha[i];
		if(d&&!v[i])
			for(int j=i;j<=11000000;j+=i)
				v[j]=1;		
	}
	for(int i=11000000;i;i--)
		if(!v[i])
			suf[i]=i;
		else
			suf[i]=suf[i+1];
	cin>>t;
	while(t--){
		cin>>n;
		if(v[n])
			cout<<"-1\n";
		else
			cout<<suf[n+1]<<'\n';
	}
	return 0;
}

