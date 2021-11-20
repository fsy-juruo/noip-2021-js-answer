#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+3;
int T,bo[maxn],nxt[maxn];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void print(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		print(x/10);
	}
	putchar(x%10+'0');
}
bool check(int x)
{
	while(x>0)
	{
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
void ycl()
{
	for(int i=1;i<=maxn;i++)
	{
		if(bo[i])
		{
			continue;
		}
		if(check(i))
		{
			int j=i;
			//if(i<=50) cout<<j<<endl;
			while(j<=maxn)
			{
				bo[j]=1;
				//if(j<=50)  cout<<j<<' '<<bo[j]<<endl;
				j+=i;
			}
		}
	}
	/*for(int i=maxn;i>=1;i--)
	{
		if(bo[i]==0)
		{
			int j=i-1;
			while(1)
			{
				nxt[j]=i;
				if(bo[j]==x)
				{
					
				}
				j--;
			}
			i=j;
		}
		else continue;
	}*/
	int i=1;
	while(i<=maxn)
	{
		int j=i+1;
		while(bo[j]==1)
		{
			j++;
		}
		nxt[i]=j;
		i=j;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::sync_with_stdio(0);
//	for(int i=1;i<=10;i++)
//		cout<<bo[i]<<endl;
//	for(int i=1;i<=10;i++)
//		cout<<check(i)<<endl;
//	cout<<maxn<<endl;
	T=read();
	ycl();
//	for(int i=1;i<=10;i++)
//		cout<<bo[i]<<endl;
//	for(int i=1;i<=10;i++)
//		cout<<nxt[i]<<endl;
	//cout<<maxn<<endl;
	while(T--)
	{
		int x;
		x=read();
		if(bo[x]==1) 
		{
			printf("-1");
			printf("\n");
		}
		else
		{
			print(nxt[x]);
			printf("\n");
		}
	}
	return 0;
}
/*
4
6
33
69
300
*/