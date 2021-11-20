#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int base=29;
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
int n,nm=0;
int aa[maxn],b[maxn][405];
struct node{
	int a[maxn];
};
queue<node> q;
int ans=inf;
void bfs()
{
	nm++;
	node x;
	for(int i=1;i<=n;i++)
	{
		x.a[i]=aa[i];
		b[nm][i]=aa[i];
	}
	q.push(x);
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=b[nm][i];
	double xb=sum*1.0/n*1.0;
	double fc=0.0;
	for(int i=1;i<=n;i++)
		fc=fc+(b[nm][i]*1.0-xb)*1.0*(b[nm][i]*1.0-xb)*1.0*n*1.0;
	ans=min(ans,int(fc));
	
	int js=0,js2=0;
	while(!q.empty())
	{
		js2++;
		node x=q.front();
		q.pop();
		for(int i=2;i<=n-1;i++)
		{
			if(x.a[i-1]+x.a[i+1]-x.a[i]!=x.a[i])
			{
				int tmp=x.a[i];
				x.a[i]=x.a[i-1]+x.a[i+1]-x.a[i];
				int flg=0,sfg=0;
				for(int j=1;j<=nm;j++)
				{
					sfg=0;
					for(int k=1;k<=n;k++)
					{
						if(x.a[k]!=b[j][k])
						{
							sfg=1;
							break;
						}
					}
					if(sfg==0)
					{
						flg=1;
						break;
					}
				}
				if(flg==0)
				{
					nm++;
					node xx;
					for(int j=1;j<=n;j++)
					{
						xx.a[j]=x.a[j];
						b[nm][j]=x.a[j];
					}
					q.push(xx);
					
					int sum=0;
					for(int j=1;j<=n;j++)
						sum+=b[nm][j];
					double xb=sum*1.0/n*1.0;
					double fc=0.0;
					for(int j=1;j<=n;j++)
						fc=fc+(b[nm][j]*1.0-xb)*1.0*(b[nm][j]*1.0-xb)*1.0*n*1.0;
					ans=min(ans,int(fc));
//					cout<<ans<<endl;
					
					if(nm==100000)
					{
						js=1;
						break;
					}
				}
				x.a[i]=tmp;
			}
		}
		if(js==1||js2==5000)
			break;
//		for(int i=1;i<=nm;i++)
//		{
//			for(int j=1;j<=n;j++)
//				cout<<b[i][j]<<" ";
//			cout<<endl;
//		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&aa[i]);
	bfs();
//	for(int i=1;i<=nm;i++)
//	{
//		for(int j=1;j<=n;j++)
//			cout<<b[i][j]<<" ";
//		cout<<endl;
//	}
	printf("%d\n",ans);
	return 0;
}

