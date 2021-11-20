#include <bits/stdc++.h>

inline bool check(int x)
{
	while(x)
	{
		if(x%10 == 7)
			return false;
		x /= 10;
	}
	return true;
}

int ans[200050],pre;
bool ok[10000050];
std::pair<int,int> query[200050];

int main()
{	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&query[i].first);
		query[i].second=i;
	}
	std::stable_sort(query,query+q);
	memset(ok,true,sizeof(ok));
	int s=7,MAXN=(query[q-1].first <= (int)2e5 ?(int)3e5:(int)1e7+10);
	for(int k=0;k<q; )
	{
		while(query[k].first<7)
		{
			ans[query[k].second]=(query[k].first == 6 ?8:query[k].first+1);
			k++;
		}
		bool ook=true;
		for(int i=s;ook;i++)
		{
			if(!check(i))
				ok[i]=false;
			if(ok[i])
			{
				while(k<q && i>query[k].first)
				{	
					ans[query[k].second]=ok[query[k].first] ?i:-1;
					s=i;
					k++;
					ook=false;
				}
				continue;
			}
			while(k<q && i == query[k].first)
			{
				ans[query[k++].second]=-1;
				s=i;
				ook=false;
			}
			for(int j=2;1ll*i*j <= MAXN;j++)
				ok[i*j]=false;
		}
	}
	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
