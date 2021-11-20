#include <bits/stdc++.h>
using namespace std;
int a[5],n;
map<int,int> mp;
int minv;
void dfs(){
	if(mp[a[1]+a[2]*15+a[3]*225+a[4]*3375]){
		return ;
	}
	mp[a[1]+a[2]*15+a[3]*225+a[4]*3375]=1;
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		ans+=(sum-a[i]*n)*(sum-a[i]*n);
	}
	ans/=n;
	minv=min(minv,ans);
	a[2]=a[1]+a[3]-a[2];
	dfs();
	a[2]=a[1]+a[3]-a[2];
	a[3]=a[2]+a[4]-a[3];
	dfs();
	a[3]=a[2]+a[4]-a[3];
	return ;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	if(n>4||n<3){
		int b[n+1];
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>b[i];
			sum+=b[i];
			b[i]*=n; 
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=(sum-b[i])*(sum-b[i]);
		}
		ans/=n;
		cout<<ans;
		return 0;
	}
	if(n==3){
		int b[n+1];
		int sum=0,sum2=0;
		for(int i=1;i<=n;i++){
			cin>>b[i];
			sum+=b[i];
			if(i!=2){
				sum2+=b[i];
			}
			b[i]*=n; 
		}
		sum2+=(b[1]+b[3]-b[2])/n;
		int ans=0,ans2=0;
		for(int i=1;i<=n;i++){
			ans+=(sum-b[i])*(sum-b[i]);
			if(i!=2){
				ans2+=(sum2-b[i])*(sum2-b[i]);
			}
			else{
				ans2+=(sum2-(b[1]+b[3]-b[2]))*(sum2-(b[1]+b[3]-b[2]));
			}
		}
		ans/=n;
		ans2/=n;
		cout<<min(ans,ans2);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	minv=1e9+7;
	dfs();
	cout<<minv;
	return 0;
}
/*
Things to check:
1. freopen
2. read twice ~~code ones,,debuh forever~~
3. for dp: any more dimensions? what does it mean? how to transfer?
4. keep your code clumsy but easy to understand.
5. check:i++ or j++?
6. if you feel bad,just write brute force and try to make it quicker
7. write every problem: just brute force for T3,T4
*/
/*
高级整活：试卷中的错误。
“4. 因违反以上三点而出现的错误或问题，申述时一律不予受理。”，申诉，not申述。
“但他们两个 除了天天下飞行器以外”，教我怎么下“飞行器”。 
*/
