#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mem_beg;
const int inf=0x7fffefff;
bool p[200005];
bool mem_end;
bool check(int x)
{
	do
	{
		if(x%10==7)
		{
			return true;
		}
		x=x/10;
	}
	while(x!=0);
	return false;
}
void prep()
{
	memset(p,0,sizeof(p));
	int i,j;
	for(i=0;i<200002;i=i+7)
	{
		p[i]=true;
	}
	for(i=0;i<200002;++i)
	{
		if(check(i))
		{
			p[i]=true;
			for(j=2*i;j<200002;j=j+i)
			{
				p[j]=true;
			}
		}
	}
}
int main()
{
//	printf("%.4f\n",(&mem_end-&mem_beg)/1024.0/1024);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	prep();
	int t,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		if(p[x]==1)
		{
			printf("-1\n");
		}
		else
		{
			do
			{
				x++;
			}
			while(p[x]==1);
			printf("%d\n",x);
		}
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
