#include<bits/stdc++.h>
using namespace std;
int ck[500005],T,x,flag1=0,flag2=0;
bool check(int n)
{
	int a=n;
	while(a)
	{
		if(a%10==7) return true;
		else a/=10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	for(int i=1;i<=500005;i++)
		if(check(i)) ck[++cnt]=i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
		if(check(x))
		{
			printf("-1\n");
			continue;
		}
		else
		{
			for(int i=1;i<=cnt&&x>ck[i];i++)
				if(x%ck[i]==0)
				{
					printf("-1\n");
					flag1=1;
					break;
				}
			if(!flag1)
				while(++x)
				{
					if(check(x)) continue;
					for(int i=1;i<=cnt&&x>ck[i];i++)
						if(x%ck[i]==0) flag2=1;
					
					if(!flag2)
					{
						printf("%d\n",x); 
						break;
					}
					flag2=0;
				}	
		}
		flag1=0,flag2=0;
	}
	return 0;
}
