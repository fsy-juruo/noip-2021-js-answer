#include<bits/stdc++.h>
using namespace std;
int t;
int sum[10001011],ans[10001011],n,ex,kk[10001011];
int read()
{
	int y=0;
	char x=getchar();
	while(x<'0'||x>'9')
	x=getchar();
	while(x>='0'&&x<='9')
	{
		y=y*10+x-48;
		x=getchar();
	}
	return y;
}
void dfs(int x,int pd,int num)
{
	if(x>6)
	{
		kk[num]=pd;
	}
	else
	{
		if(pd==1)
		{
			for(int i=0;i<=9;i++)
				dfs(x+1,1,num*10+i);
		}
		else
		{
			for(int i=0;i<=6;i++)
				dfs(x+1,0,num*10+i);
			dfs(x+1,1,num*10+7);
			for(int i=8;i<=9;i++)
				dfs(x+1,0,num*10+i);
		}
	}
}
bool did(int x)
{
	int z=x;
	while(z>0)
	{
		int t=z%10;
		z=z/10;
		if(t==7)
		return true;
	}
	return false ;
}
int main()
{
 freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
 	t=read();
 	dfs(0,0,0);
	for(int i=1;i<=10001010;i++)
	{
		if(sum[i]==0)
		{
			if(kk[i]==1)
			{
				sum[i]=1;
				for(int j=1;j*i<=10001010;j++)
				{
					sum[j*i]=1;
				}
			}
		}
	}
	for(int i=10001010;i>=1;i--)
	{
		if(sum[i]==0)
		{
			if(ex==0)
			{
				ex=i;
			}
			else
			{
				ans[i]=ex;
				ex=i;
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		n=read();
		if(ans[n]==0)
		cout<<-1<<endl;
		else
		cout<<ans[n]<<endl;
	}
	return 0;
}