#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n;
vector<int> a,v;
set<vector<int> > S;
vector<vector<int> > seq;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a.push_back(x);	
	}
	S.insert(a);
	seq.push_back(a);
	double ans=1e9;
	for(int i=0;i<(int)seq.size();i++)
	{
		v=seq[i];
		int sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=v[j];
		}
		double ave=(double)sum/(double)n;
		double cur=0;
		for(int j=0;j<n;j++)
		{
			cur+=(v[j]-ave)*(v[j]-ave);
		}
		ans=min(ans,cur*n);
		for(int j=1;j<n-1;j++)
		{
			int tmp=v[j];
			v[j]=v[j-1]+v[j+1]-v[j];
			if(S.find(v)==S.end())
			{
				S.insert(v);
				seq.push_back(v);
			}
			v[j]=tmp;
		}
	}
	printf("%d\n",(int)ans);
	return 0;
}
/*
1. copy the names of the problems
2. freopen
3. int, long long overflow
4. memory overflow
5. delete debug sentences
6. list the main ideas
7. special cases
*/
