#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int MAXM=10000005;
int n,m,ask[MAXN],mx;
int cnt,a[MAXM];
bool flag[MAXM];
bool judge(int x)
{
	while(x)
	{
		if(x%10==7)
			return 0;
		x/=10;
	}
	return 1;
}
void init1()
{
	for(int i=1;i<=200005;i++)
	{
		bool t=judge(i);
		if(!t)
			for(int j=1;j*i<=200005;j++)
				flag[i*j]=1;
		if(flag[i]==0)
			a[++cnt]=i;
	}
}
void init2()
{
	for(int i=1;i<=10000001;i++)
	{
		bool t=judge(i);
		if(!t)
			for(int j=1;j*i<=10000001;j++)
				flag[i*j]=1;
		if(flag[i]==0)
			a[++cnt]=i;
	}
}
int main()
{
	ifstream fin("number.in");
	ofstream fout("number.out");
	fin>>n;
	for(int i=1;i<=n;i++)
	{
		fin>>ask[i];
		mx=max(mx,ask[i]);
	}
	if(mx<=200000)
		init1();
	else
		init2();
	for(int i=1;i<=n;i++)
	{
		int x=ask[i];
		if(flag[x])
		{
			fout<<-1<<endl;
			continue;
		}
		int ans=*upper_bound(a+1,a+cnt+1,x);
		fout<<ans<<endl;
	}
	return 0;
}
