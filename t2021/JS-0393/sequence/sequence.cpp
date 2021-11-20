#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int cost[100+10];
long long value;
void dfs(int zhishu,int weishu,long long lastvalue,long long costing){
	if(weishu==n){
		if(lastvalue==0){
			value+=costing;
		}
		return ;
	}
	if(zhishu<0){
		return ;
	}
	long long uses=pow(2,zhishu);
	for(int i=0;uses*i<=lastvalue;i++){
		dfs(zhishu-1,weishu+i,lastvalue-uses*i,costing+cost[zhishu]*i);
	}
	
}
bool check(long long x){
	long long ans=0;
	while(x!=0){
		ans+=x%2;
		x/=2;
	}
	if(ans<=k){
		return true;
	}
	return false;
}
int findmx(long long all){
	int k=0;
	long long sdt=1;
	while(sdt<=all){
		k++;
		sdt*=2;
	}
	return k-1;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	long long kmd=pow(2,k);
	for(int i=0;i<=m;i++){
		cin>>cost[i];
		
	}
	for(long long i=n;i<=n*kmd;i++){
		if(check(i)==true)
			dfs(findmx(i),0,i,0);
	}
	cout<<value<<endl;
	return 0;
}

