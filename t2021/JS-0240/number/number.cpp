#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxx=5e5+5;
ll maxn;
bitset<maxx> vis;
vector<int> pr,v;
int find(int x)
{
	for(int i=10;i<maxn;i*=10)
		if((x%i)/(i/10)==7)
			return i/10;
	return 0;
}
void init()
{
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i])
			pr.push_back(i);
		int sz=pr.size();
		for(int j=0;j<sz;j++)
		{
			if(i*pr[j]>=maxn)
				break;
			vis[i*pr[j]]=1;
			if(i%pr[j]==0)
				break;
		}
	}
	vis=0;
	int tail=1;
	for(int i=1;i<maxn;i++)
	{
		bool ok=0;
		if(tail<=i)
			tail=find(i)+i;
		if(tail<=i&&!vis[i])
			v.push_back(i);
		if(tail>i)
			ok=1;
		if(tail>i||vis[i])
		{
			for(int j=0;j<pr.size();j++)
			{
				if(i*pr[j]>=maxn)
					break;
				vis[i*pr[j]]=1;
				if(i%pr[j]==0&&!ok)
					break;
			}
		}
	}
} 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	cin>>t;
	maxn=5e5+5;
	init();
	int x;
	while(t--)
	{
		scanf("%d",&x); 
		int p=lower_bound(v.begin(),v.end(),x)-v.begin();
		if(v[p]!=x||p==v.size())
			printf("-1\n");
		else
			printf("%d\n",v[p+1]);
	}
	return 0;
} 
