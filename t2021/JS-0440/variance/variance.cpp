#include<bits/stdc++.h>
#define N 15
using namespace std;
int n,a[15],ans=1e9;
bool vis[1000005];
int query(int *s){
	int sum=0,num=0;
	for(int i=1;i<=n;i++)sum+=s[i];
	for(int i=1;i<=n;i++)num+=(n*s[i]-sum)*(n*s[i]-sum);
	return num;
}
void dfs(int *s){
	ans=min(ans,query(s));
	int tmp[5];
	vis[s[2]*11+s[3]]=1;
	for(int i=1;i<=n;i++)tmp[i]=s[i];
	{
		tmp[2]=tmp[1]+tmp[3]-tmp[2];
		if(!vis[tmp[2]*11+tmp[3]])dfs(tmp);
	}
	{
		tmp[3]=tmp[4]+tmp[2]-tmp[3];
		if(!vis[tmp[2]*11+tmp[3]])dfs(tmp);
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>4){
		cout<<query(a)/n<<endl;
		return 0;
	}
	dfs(a);
	cout<<ans/n<<endl;
	fclose(stdin);
	fclose(stdout);
}
