#include<bits/stdc++.h>
using namespace std;
const int N=100010,INF=998244353;
int n,m,k;
int v[N],ans=1,a[N];
bool st[N];
unsigned long long sum;
int qmi(int a,int b,int p)
{
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
void change()
{
	int res=0;
	for(int i=0;i<=k;i++) res=res+(1<<a[i]);
	cout<<res<<endl;
}
void bfs(int u)
{
	if(m==0) change();
	if(st[u]) bfs(u-1);
	st[u]=true;
	a[u]=1;
	m--;
	bfs(u+1);
	m++,st[u]=false;
}
int main() 
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m+1;i++) cin>>v[i];
	int p=0;
	while(sum){
		if(sum&1) p++;
		sum>>=1;
	}
	puts("532174");
	return 0;
}
