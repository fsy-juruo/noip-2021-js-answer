#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define N 10000007
int n,m,k;
int hmo[N];//how many ones
void pre(){
	for(int i=1;i<=N;i++){
		int x=i;
		while(x){
			if(x&1){
				hmo[i]++;
			}
			x>>=1;
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	pre();
	for(int i=n;i<=n*pow(2,m);i++){
		if(hmo[i]<=k){
			
		}
	}
//	for(int i=1;i<=10;i++){
//		cout<<hmo[i]<<" ";
//	}
	return 0;
}

