#include<bits/stdc++.h>
using namespace std;
#define N 1001
int n,x,ans=99999999;
vector<int>a;
map<vector<int>,int>m;
void dfs(int p,vector<int> s){
	m[s]=1;
	int tmp=0;
	for(int i=0;i<n;i++)
		tmp+=(s[i]*n-p)*(s[i]*n-p);
	ans=min(ans,tmp/n);
	for(int i=1;i<n-1;i++){
		int temp=s[i];
		s[i]=s[i-1]+s[i+1]-s[i];
		if(m[s]==1){
			s[i]=temp;
			continue;
		}
		dfs(p+s[i-1]+s[i+1]-2*temp,s);
		s[i]=temp;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	int p=0;
	for(int i=1;i<=n;i++){
		cin>>x;p+=x;
		a.push_back(x);
	}
	dfs(p,a);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
