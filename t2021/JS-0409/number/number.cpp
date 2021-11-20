#include <bits/stdc++.h>
#define inf 1000000007
#define mod 1000000007
//#define int long long
using namespace std;
template <typename T> void read(T &x){
	x=0;int fh=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
template <typename T> void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int tc;
int mx;
int lim;
int x[200005];
bool ban[10000005];
int sum[10000005];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(tc);
	for(int i=1;i<=tc;++i)
	{
		read(x[i]);
		mx=max(mx,x[i]);
	}
	lim=(mx<=200000?1000000:10000000);
	int tmp;
	bool flag;
	for(int i=1;i<=lim;++i)
		if(!ban[i])
		{
			tmp=i;
			flag=true;
			while(tmp)
			{
				if(tmp%10==7)
				{
					flag=false;
					break;
				}
				tmp/=10;
			}
			if(!flag)
			{
				for(int j=i;j<=lim;j+=i)
					ban[j]=1;
			}
		}
	for(int i=1;i<=lim+3;++i)
		sum[i]=sum[i-1]+ban[i];
	for(int i=1;i<=tc;++i)
	{
		if(ban[x[i]])
		{
			puts("-1");
			continue;
		}
		int l=x[i]+1,r=lim+3;
		while(l<r)
		{
			int mid=l+r>>1;
			if(sum[mid]-sum[x[i]]!=mid-x[i]) r=mid;
			else l=mid+1;
		}
		writeln(l);
	}
	return 0;
}

