#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
int x=1;
bool vis[200005];
vector<int>ve;
vector<long long int>vv[200005];
struct node{
	int ww;
	int tt;
}; 
vector<node>vv2;
int co(int x){
	int cnt=0;
	while(x)
	{
		if(x%2)
		cnt++;
		x/=2;
	}
}
int C(int x){
	int cnt=0;
	while(x){
		x/=2;
		cnt++;
	}
	return cnt;
}
void work(int now,int cnt){
	if(now>n*x)
	return ;
	if(now>n)
	ve.push_back(now);
	for(int i=1;now<<i<=n*x;i++){
		if(!vis[now<<i])
		{
		vis[now<<i]=1;
		work(now<<i,cnt);
		}
		if(cnt<k&&!vis[now<<i+1])
		{
		vis[now<<i+1]=1;
		work(now<<i+1,cnt+1);
		}
	}
	for(int i=C(now);now+1<<i<=n*x;i++){
		if(!vis[now+1<<i]&&cnt+co(i)<k)
		{
		vis[now+1<<i]=1;
		work(now+1<<i,cnt+co(i));
		}
	}
}
void work2(int num,int mm,int now,vector<node>vv2){
	if(num==0)
	{
	vector<int>v;
	int cnt[2005];
	long long int t1=1,t2=1;
	for(int i=0;i<vv2.size();i++){
	t1*=v[vv2[i].ww];
	t1%=(long long)998244353;
	}
	for(int i=1;i<=n;i++){
		t2*=i;
		t2%=(long long)998244353;
	}
	for(int i=0;i<vv2.size();i++){
		t2/=vv2[i].tt;
	}
	t2%=(long long)998244353;
	vv[now].push_back(t1*t2);
	return ;
	}
	if(mm==m){
	{
	while(num<n)
	vv2.push_back((node){mm,n-num});
	now+=(n-num)*pow(2,mm);
	vector<int>v;
	int cnt[2005];
	long long int t1=1,t2=1;
	for(int i=0;i<vv2.size();i++){
	t1*=v[vv2[i].ww];
	t1%=(long long)998244353;
	}
	for(int i=1;i<=n;i++){
		t2*=i;
		t2%=(long long)998244353;
	}
	for(int i=0;i<vv2.size();i++){
		t2/=vv2[i].tt;
	}
	t2%=(long long)998244353;
	vv[now].push_back(t1*t2);
	return;
	}
	for(int i=0;i<=n-num;i++){
		if(i)
		vv2.push_back((node){mm,i});
		work2(num+i,mm+1,now+i*pow(2,mm),vv2);
	}
}
}
int cnt[1005];
int v[105];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	x=pow(2,m);
	work(1,1);
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	work2(n,1,0,vv2);
	for(int i=0;i<ve.size();i++){
		for(int j=0;j<vv[ve[i]].size();j++)
		{
		ans+=vv[ve[i]][j]%(long long)998244353;
		ans%=(long long)998244353;
		}
	}
	cout<<ans%(long long)998244353;
}
