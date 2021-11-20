#include <bits/stdc++.h>
using namespace std;
bool ok[1000005];
int lnxt[1000005];
bool check(int n){
	while(n){
		if(n%10==7){
			return false;
		}
		n/=10;
	}
	return true;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(ok,1,sizeof(ok));
	for(int i=1;i<=1000000;i++){
		if(!check(i)&&ok[i]){
			for(int j=i;j<=1000000;j+=i){
				ok[j]=0;
			}
		}
	}
	int lst=10000001;
	for(int i=1000000;i>=1;i--){
		lnxt[i]=lst;
		if(ok[i]){
			lst=i;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(!ok[n]){
			cout<<-1;
		}
		else{
			cout<<lnxt[n];
		}
		cout<<endl;
	}
	return 0;
}

