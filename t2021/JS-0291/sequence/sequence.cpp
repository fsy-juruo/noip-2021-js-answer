#include<bits/stdc++.h>
using namespace std;
int v[110],k,m,p=998244353,sf=1,fs,n,func[100];
map<int,int> mt;
bitset<110> nn,nm,s[2];
inline void cha(int ids,int i)
{
	int a;
	for(a=i;a<=109;a++)
	{
		if(s[ids][a]==1)
		s[ids][a]=0;
		else
		{
			s[ids][a]=1;
			break;
		}
	}
	return;
}
inline void acha(int i)
{
	int a;
	for(a=i;a<=109;a++)
	{
		if(s[1][a]==0)
		s[1][a]=1;
		else
		{
			s[1][a]=0;
			break;
		}
	}
	return;
}
inline int inn(int i)
{
	int a,b;
	b=p-2;
	a=1;
	while(b)
	{
		if(b%2==1)
		a=1ll*a*i%p;
		i=1ll*i*i%p;
		b>>=1;
	}
	return a;
}
inline void dfs(int ids,int i)
{
	int a;
	if(ids==n)
	{
		if(s[1]==s[0])
		{
			int u;
			u=1;
			for(a=0;a<=m;a++)
			u=1ll*u*func[mt[a]]%p;
			u=inn(u);
			u=1ll*u*func[n]%p;
			fs=(1ll*u*sf%p+fs)%p;
		}
		return;
	}
	for(a=i;a<=m;a++)
	{
		cha(1,a);
		sf=1ll*sf*v[a]%p;
		mt[a]+=1;
		dfs(ids+1,a);
		acha(a);
		mt[a]-=1;
		sf=1ll*sf*inn(v[a])%p;
	}
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int a;
	scanf("%d%d%d",&n,&m,&k);
	for(a=0;a<=m;a++)
	{
		scanf("%d",&v[a]);
		mt.insert(make_pair(a,0));
	}
	func[0]=1;
	for(a=1;a<=n;a++)
	func[a]=1ll*func[a-1]*a%p;
	for(a=0;a<=log2(n)+1;a++)
	{
		if((n&(1<<a))!=0)
		nn[a]=1;
	}
	nm=(nn<<m);
	for(a=0;a<=109;a++)
	{
		if(nm[a]==1)
		nm[a]=0;
		else
		{
			nm[a]=1;
			break;
		}
	}
	for(s[0]=nn;s[0]!=nm;cha(0,0))
	{
		if(s[0].count()<=k)
		dfs(0,0);
	}
	printf("%d",fs);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
