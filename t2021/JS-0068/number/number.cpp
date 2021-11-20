#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+100;
int ans[maxn],zz;
int p[maxn],ys[maxn];
namespace FAST_IO
{
	template<typename T> void read(T &x)
	{
		T f=1;
		x=0;
		char c=getchar();
		while(!isdigit(c))
		{
			if(c=='-')
			{
				f=-1;	
			}
			c=getchar();
		}
		while(isdigit(c))
		{
			x=x*10+c-'0';
			c=getchar();
		}
		x=x*f;
	}
	template<typename T> void write(T x)
	{
		if(x<10)
		{
			putchar(x+'0');
		}	
		else
		{
			write(x/10);
			putchar(x%10+'0');
		}
	} 
}
int check(int x)
{
	while(x)
	{
		if(x%10==7)
		{
			return 1;
		}
		x/=10;
	}
	return 0;
}
void init()
{
	for(int i=0;i<maxn;i++)
	{
		if(p[i])
		{
			continue;
		}
		if(check(i))
		{
			for(int j=i;j<maxn;j+=i)
			{
				p[j]=1;
			}
		}
		else
		{
			zz++;
			ans[zz]=i;
			ys[i]=zz;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	FAST_IO::read(t);
	init();
	while(t--)
	{
		int r;
		FAST_IO::read(r);
		//scanf("%d",&r);
		if(p[r])
		{
			puts("-1");
			continue;
		}
	//	int tmp=lower_bound(ans+1,ans+zz+1,r)-ans;
		FAST_IO::write(ans[ys[r]+1]);
		puts("");
	}
	//cout<<zz<<endl;
	//cout<<zz<<endl;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//2e8±¬²Èccf²âÆÀ»ú£¡ 
}

