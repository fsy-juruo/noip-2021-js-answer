#include<bits/stdc++.h>
using namespace std;

const int N=1000005;
const long long INF=0x3f3f3f3f3f3f3f3f;
int n,a[N],tot;
long long d[N],s[N],ans=INF;
map<vector<int>,int> mp;
vector<vector<int> > vv;
queue<int> q;

void solva()
{
	vector<int> tmp,uu;
	for(int i=1;i<=n;i++) tmp.push_back(a[i]);
	mp[tmp]=tot=0,vv.push_back(tmp);
	for(int i=1;i<=n;i++) s[0]+=a[i],d[0]+=a[i]*a[i];
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		uu=vv[u];
//		cout<<u<<' '<<d[u]*n-s[u]*s[u]<<endl;
		ans=min(ans,d[u]*n-s[u]*s[u]);
		for(int i=1;i<n-1;i++)
		{
			tmp=uu,tmp[i]=uu[i-1]+uu[i+1]-uu[i];
			if(mp.count(tmp)) continue;
			mp[tmp]=++tot,vv.push_back(tmp);
			s[tot]=s[u]+tmp[i]-uu[i];
			d[tot]=d[u]+tmp[i]*tmp[i]-uu[i]*uu[i];
//			cout<<' '<<i<<' '<<uu[i]<<' '<<tmp[i]<<endl;
			q.push(tot);
		}
	}
	printf("%lld\n",ans);
}

void solvb()
{
	vector<int> tmp,uu;
	for(int i=1;i<=n;i++) tmp.push_back(a[i]);
	mp[tmp]=tot=0,vv.push_back(tmp);
	for(int i=1;i<=n;i++) s[0]+=a[i],d[0]+=a[i]*a[i];
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		uu=vv[u];
//		cout<<u<<' '<<d[u]*n-s[u]*s[u]<<endl;
		ans=min(ans,d[u]*n-s[u]*s[u]);
		for(int i=1;i<n-1;i++)
		{
			tmp=uu,tmp[i]=uu[i-1]+uu[i+1]-uu[i];
			if(mp.count(tmp)) continue;
			mp[tmp]=++tot,vv.push_back(tmp);
			s[tot]=s[u]+tmp[i]-uu[i];
			d[tot]=d[u]+tmp[i]*tmp[i]-uu[i]*uu[i];
			if(d[u]*n-s[u]*s[u]<d[tot]*n-s[tot]*s[tot]) continue;
//			cout<<' '<<i<<' '<<uu[i]<<' '<<tmp[i]<<endl;
			q.push(tot);
		}
	}
//	cout<<tot<<endl;
	printf("%lld\n",ans);
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=10) solva();
	else solvb();
} 
