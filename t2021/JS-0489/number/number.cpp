#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+200;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int vis[maxn],a[maxn],nm,b[maxn];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=maxn-5;i++)
	{
		if(vis[i]==1)
			continue;
		int flg=0,x=i;
		while(x!=0)
		{
			int r=x%10;
			if(r==7)
			{
				flg=1;
				break;
			}
			x=x/10;
		}
		if(flg==1)
		{
			vis[i]=1;
			for(int j=2;;j++)
			{
				int x=j*i;
				if(x>=maxn-5)
					break;
				vis[x]=1;
			}
		}
		else
		{
			a[++nm]=i;
			b[i]=nm;
		}
	}
//	for(int i=1;i<=nm;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x;
		scanf("%d",&x);
		if(vis[x]==1)
			printf("-1\n");
		else
		{
			int nw=b[x];
			printf("%d\n",a[nw+1]); 
		}
	}
	return 0;
}

