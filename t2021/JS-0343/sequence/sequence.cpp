#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ull mod=998244353;
ull ans=0;
const ull maxm=110;
ull n,m,k;
ull v[maxm],a[50];
inline bool legal(){
	if(n==1)return k>=1;
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=1;i<=n;++i)
		q.push(a[i]);
	ull cnt=0;
	do{
		int a=q.top();
		q.pop();
		if(q.empty()){
			++cnt;
			break;
		}
		int b=q.top();
		if(a!=b){
			++cnt;
		}else{
			q.pop();
			q.push(a+1);
		}
	}while(!q.empty());
	return cnt<=k;
}
bool legal2(){
	ull x=0;
	for(int i=1;i<=n;++i){
		x+=(1ull<<a[i]);
	}
	int cnt=0;
	for(;x;x&=(x-1),++cnt);
	return cnt<=k;
}
ull eval(){
	ull temp=1;
	for(int i=1;i<=n;++i){
		temp=v[a[i]]*temp%mod;
	}
	return temp;
}
void dfs(int index){
	if(index==n+1){
		if(legal2()){
			ans=(ans+eval())%mod;
//			for(int i=1;i<=n;++i){
//				cout<<a[i]<<" ";
//			}
//			cout<<"\n";
		}
		return;
	}
	for(int i=0;i<=m;++i){
		a[index]=i;
		dfs(index+1);
	}
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;++i)
		cin>>v[i];
	dfs(1);
	cout<<ans%mod;
	return 0;
}


