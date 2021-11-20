#include<bits/stdc++.h>
using namespace std;
int T,x;
bool a[200110];
void Doing(int Q)
{
	for(int i=7;i<=Q;i+=10)
	{
		for(int j=1;j*i<=Q;j++)
		a[i*j]=1;
	}
	for(int i=70;i<=Q;i++)
	{
		int asa=i;
		while(asa!=0)
		{
			if(asa%10==7)
				break;
			asa/=10;
		}
		if(asa)
		for(int j=1;j*i<=Q;j++)
		a[i*j]=1;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	Doing(200104);
	while(T--)
	{
		scanf("%d",&x);
		if(a[x])
		    printf("-1\n");
		else
		{
			for(int i=x+1;i<=200104;i++)
			if(!a[i])
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
