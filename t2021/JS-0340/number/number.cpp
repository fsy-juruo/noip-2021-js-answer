#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<fstream>
#include<algorithm>
using namespace std;

int n,m,T;
bool judge(int x)
{
	stringstream ss;
	string a;
	ss<<x;
	ss>>a;
	int w=a.find('7');
	if(w!=-1) return true;
	else 
	{
		if(x%7==0) return true;
		else for(int i=17;i<=x/2;i++)
		{
			if(x%i==0)
			{
				stringstream sss;
				string b;
				sss<<i;
				sss>>b;
				int c=b.find('7');
				if(c!=-1) return true;
			}
		}
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=T;i>=1;i--)
	{
		scanf("%d",&n);
		if(judge(n)) 
		{
			printf("-1\n");
			continue;
		}
		else 
		{
			int flag=1;
			for(int j=n+1;j;j++)
			{
				if(!judge(j)) 
				{
					printf("%d\n",j);
					flag=0;
				}
				if(flag==0) break;
			}
		}
	}
	return 0;
}

