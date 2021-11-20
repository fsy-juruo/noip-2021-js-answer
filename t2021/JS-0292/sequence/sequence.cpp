#include<bits/stdc++.h>
using namespace std;
const int mm=998244353;
int n,k,m,a[105],b[105];
long long sss=0,pp;
bool p(int x){
	int ans=0;
	while(x){
		if(x%2==1) ans++;
		x/=2;
	}
	return ans==k;
}
int jc(int x){
	int ans=1;
	for(int i=1;i<=x;i++)
		ans=(ans*i)%mm;
	return ans;
}
int aa(int x){
	int dd=1;
	for(int i=0;i<=x;i++)
		for(int j=1;j<=b[i];j++)
			dd=(dd*a[i])%mm;
	return dd;
}
void dfs(int dep,int lef,int sum){
	if(dep>m&&lef!=0) return; 
	if(lef==0){
		if(p(sum)){
			int temp=1;
			for(int i=0;i<=dep-1;i++)
				temp=(temp*jc(b[i]))%mm;
			sss=(sss+(pp/temp)*aa(dep))%mm;
		}
		return;
	}
	for(int i=0;i<=lef;i++){
		b[dep]=i;
		dfs(dep+1,lef-i,sum+i*(1<<dep));
	}
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>a[i];
		a[i]%=mm;
	}
	pp=jc(n);
	dfs(0,n,0);
	cout<<sss<<endl;
	return 0;
}
