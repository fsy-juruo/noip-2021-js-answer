#include <bits/stdc++.h>
#define lint long long
using namespace std;
const int maxn=10000005;
int a[maxn],cn,q,maxx;
bool b[maxn];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool check(int x)
{
	while(x)
	{
		if(x%10==7)
		return true;
		x=x/10;
	}
	return false;
}
//int ef(int x)
//{
//	int h=1,t=cn;
//	while(h<f)
//	{
//		int mid=(h+t)>>1;
//		if(a[mid]==x)
//		{
//			return mid;
//		}
//	}
//}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	q=read();
	if(q<=10000)
	{
		maxx=200000;
	}
	else
	{
		maxx=10000000;
	}
    for(int i=1;i<=maxx;i++)
    {
    	if(!b[i])
    	{
    		if(check(i))
    		{
//    			printf("%d ",i);
    			int y=1;
    			while(y*i<=maxx)
    			{
    				b[y*i]=true;
    			    y++;
				}
			}
			else
			{
//				printf("%d ",i);
				a[++cn]=i;
			}
		}
	}
//	for(int i=1;i<=cn;i++)
//	{
//		printf("%d ",a[i]);
//	}

	for(int i=1;i<=q;i++)
	{
		int x=read();
		if(b[x])
		{
			printf("-1\n");
		}
		else
		{
			int y=upper_bound(a+1,a+cn+1,x)-a;
			printf("%d\n",a[y]);
		}	
	}
	return 0;
}

