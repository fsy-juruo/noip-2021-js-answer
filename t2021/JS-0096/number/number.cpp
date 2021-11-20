#include <bits/stdc++.h>
#define re register
#define SIZE 10000005
#define INF 10000000
using namespace std;
template <typename T>
inline void read(T &x)
{
	int f;char c;
	x=0;f=0;c=getchar();
	while(c<'0' || '9'<c)	f|=(c=='-'),c=getchar();
	while('0'<=c && c<='9')	x=(x<<3)+(x<<1)+c-48,c=getchar();
	x=f?-x:x;
}
int T,a;
int isok[SIZE];
int cnt=0,num[SIZE];
inline bool have7(int x)
{
	int sum=x;
	while(sum>0)
	{
		if(sum%10==7)
			return true;
		sum/=10;
	}
	return false;
}
inline void make_num()
{
	for(re int i=1;i<=INF;++i)
	{
		if(isok[i]==-1)
			continue;
		if(have7(i))
		{
			isok[i]=-1;
			for(re int j=2;i*j<=INF;++j)
				isok[i*j]=-1;
		}
		else
			++cnt,num[cnt]=i;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(T);
	make_num();
	for(re int t=1;t<=T;++t)
	{
		read(a);
		int p=lower_bound(num+1,num+cnt+1,a)-num;
		if(num[p]!=a)
			printf("-1\n");
		else
			printf("%d\n",num[p+1]);
	}
	return 0;
}
