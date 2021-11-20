#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)

const int N=10000105;

int pr[N],f[N],nx[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,n,cnt=0;
	scanf("%d",&T);
	
	if (T<=10000)
	{
		rep(i,7,200100)
		{
			if (i%10==7 or (i/10)%10==7 or (i/100)%10==7 or (i/1000)%10==7 or (i/10000)%10==7 or (i/100000)%10==7 or (i/1000000)%10==7)
			{
				cnt++;
				f[i]=1;
				pr[cnt]=i;
			}
		}
	//	printf("%d\n",cnt);
	//	int num=0;
		rep(i,1,cnt)
		{
			rep(j,2,200100/pr[i])
			{
	//			num++;
				f[pr[i]*j]=1;
			}
		}
	//	printf("%d\n",num);
		int cur=2;
		rep(i,1,200000)
		{
			cur=max(cur,i+1);
			while(f[cur]) cur++;
			nx[i]=cur;
		}
	//	printf("%d\n",nx[200000]);
	//	printf("%d\n",nx[10000000]);
	}
	else
	{
		rep(i,7,10000100)
		{
			if (i%10==7 or (i/10)%10==7 or (i/100)%10==7 or (i/1000)%10==7 or (i/10000)%10==7 or (i/100000)%10==7 or (i/1000000)%10==7)
			{
				cnt++;
				f[i]=1;
				pr[cnt]=i;
			}
		}
	//	printf("%d\n",cnt);
	//	int num=0;
		rep(i,1,cnt)
		{
			rep(j,2,10000100/pr[i])
			{
	//			num++;
				f[pr[i]*j]=1;
			}
		}
	//	printf("%d\n",num);
		int cur=2;
		rep(i,1,10000000)
		{
			cur=max(cur,i+1);
			while(f[cur]) cur++;
			nx[i]=cur;
		}
	//	printf("%d\n",nx[200000]);
	//	printf("%d\n",nx[10000000]);
	}
	
	while(T--)
	{
		scanf("%d",&n);
		if (!f[n]) printf("%d\n",nx[n]); else printf("-1\n");
	}
	return 0;
}
