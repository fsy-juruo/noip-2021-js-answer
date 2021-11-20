/*
NOIP 2021
By XGN from HHS
It is strictly prohibited to upload this file to Luogu without the author's consent
Especially for certain "analyzing" purpose.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
/*
I am a wolf, a fox, and a rabbit!
- Wulpit
*/

template<typename T1,typename T2> ostream& operator<<(ostream& os,pair<T1,T2> p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<typename T> ostream& operator<<(ostream& os,vector<T> v){
	os<<"[";
	for(auto x:v){
		os<<x<<" ";
	}
	os<<"]";
	return os;
}

const int MAX=11000000;
bool ok[MAX+5];
int ans[MAX+5];

bool Ok(int n){
	while(n!=0){
		if(n%10==7){
			return false;
		}
		n/=10;
	}
	return true;
}

int main(){
	freopen("number.in","r",stdin);
	#ifndef XGN
	freopen("number.out","w",stdout);
	#endif

	memset(ok,true,sizeof(ok));
	
	for(int i=7;i<=MAX;i++){
		if(!ok[i]) continue;
		
		ok[i]=Ok(i);
		if(!ok[i]){
			for(int j=i;j<=MAX;j+=i){
				ok[j]=false;
			}
		}
	}
	
	int lastOk=0;
	for(int i=MAX;i>=1;i--){
		if(ok[i]){
			ans[i]=lastOk;
			lastOk=i;
		}else{
			ans[i]=-1;
		}
	}
	
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		cout<<ans[x]<<endl;
	}
	return 0;
}

/*
HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021
HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021
HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021
HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021
HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021
HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021
HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021
HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021
HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021 HHS-XGN 2021   
*/
