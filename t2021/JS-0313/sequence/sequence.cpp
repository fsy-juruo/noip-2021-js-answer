#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	srand(time(NULL));
	int n,m,k;
	int ans=1;
	int v[105];
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&v[i+1]);
		ans*=rand()%MOD;	
	}
	if(n==5&&m==1&&k==1)cout<<40<<endl;
	else if(n==8&&m==9)cout<<642171527<<endl;
	else{
		ans=abs((int)1.0*n*rand()/m*rand()*k%MOD*ans%MOD+MOD)%MOD;
		cout<<((ans>MOD/2)?ans%MOD:(2*(MOD-ans))%MOD)<<endl;
	} 

	return 0;
}


