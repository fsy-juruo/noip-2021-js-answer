#include<bits/stdc++.h>
using namespace std;
map<vector<int>,bool> mp;
int n;
vector<int> a;
int ans=INT_MAX;
int turn=0;
void dfs(vector<int> cur){
	//turn++;cout<<turn<<endl;
	//cout<<"cur="<<endl;
	//for(int i=0;i<cur.size();i++)cout<<cur[i]<<" ";
	//cout<<endl;
	int res=0,sum=0;
	for(int i=0;i<cur.size();i++){
		sum+=cur[i];
		res+=n*cur[i]*cur[i];
	}
	for(int i=0;i<cur.size();i++){
		res-=2*cur[i]*sum;
	}
	res+=sum*sum;
	//cout<<"and the res="<<res<<endl;
	ans=min(ans,res);
	for(int i=1;i<=cur.size()-2;i++){
		int tmp=cur[i];
		cur[i]=cur[i-1]+cur[i+1]-cur[i];
		if(mp[cur]==0){
			mp[cur]=1;
			dfs(cur);
		}
		cur[i]=tmp;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	mp[a]=1;
	dfs(a);
	cout<<ans<<endl;
	return 0;
}
