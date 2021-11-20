#include<bits/stdc++.h>
using namespace std;

int n;
int a[10005];
bool vis[605][10005];

inline int read()
{
	int res=0,t=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') 
	{
		if(ch='-') t=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*t;
}

inline double fc(double num,double average)
{
	return (abs(num-average))*(abs(num-average));
}

int main()
{
		freopen("variance.in","r",stdin);	
	freopen("variance.out","w",stdout);
	n=read();
	memset(vis,false,sizeof(vis));
	double mins=99999999;
	double tot=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		tot+=a[i];
	}
	double aver;
	aver=tot/n;
	double total=0;
	for(int i=1;i<=n;i++)
	{
		total+=fc(a[i],aver);
	}
	if(total/n<=mins) mins=total/n;
	int now=2;
	total=0;
	while(now>=2&&now<=n-1)
	{
		total=0;
		while(!vis[a[now]][now])
		{	
		total=0;
//			tot-=a[now];
//			a[now]=a[now-1]+a[now+1]-a[now];
//			tot+=a[now];
//			aver=tot/n;
//			vis[a[now]][now]=true;
			for(int j=1;j<=n;j++)
			{
				total+=fc(a[j],aver);
			}
			if(total/n<=mins) mins=total/n;
			vis[a[now]][now]=true;
			tot-=a[now];
			a[now]=a[now-1]+a[now+1]-a[now];
			tot+=a[now];
			aver=tot/n;
		}
		now++;
	}
	printf("%.0f",mins*n*n);
	
	return 0;
}
