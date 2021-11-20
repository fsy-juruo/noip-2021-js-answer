#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
//priority_queue
queue<int>q;
const int maxn=1e7+10;
int tp[maxn],pri[100000],t[maxn];	
int n,nm[11],x2=0,pm[10];
int rd()
{
	char c;
	c=getchar();
	
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,k,a,b,c,d,e,f,g;
	int m=1;
	pri[0]=2;
	for(i=3;i<=5e5;i+=2)
	{
		if(t[i]==0)
		{
			pri[m++]=i;
			if(i>1e4)
				continue;
			long long x=i*i;
			//cout<<x<<endl;
			while(x<=1e7)
			{
				t[x]=1;
				x+=i*2;
			}
		}
		else
			continue;
	}
	//cout<<1<<endl;
	for(b=0;b<6;b++)
	for(c=0;c<10;c++)
	for(d=0;d<10;d++)
	for(e=0;e<10;e++)
	for(f=0;f<10;f++)
	for(g=0;g<10;g++)
		if(b==7 ||c==7 ||d==7 ||e==7 ||f==7 ||g==7)
		{
			int x=b*1e5+c*1e4+d*1e3+e*1e2+f*1e1+g;
			tp[x]=-1;
		}
		//pm[0]=1;
	//dfs(0);
	//tp[7]=-1;
		for(i=1;i<=5e5;i++)
	{
		if(tp[i]==-1)
		{
			for(j=0;j<=m;j++)
			{
				if(i*pri[j]<=1e6)
					tp[i*pri[j]]=-1;
				else
					break;
			}
		}
	} 
	int lst=0;
	for(i=5e5-1;i>=1;i--)
	{
		if(tp[i]==0)
		{
			tp[i]=lst;
			lst=i;
		}
		//cout<<tp[i]<<endl;
	}
	cin>>n;
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		cout<<tp[x]<<endl;
	}
	return 0;
}
