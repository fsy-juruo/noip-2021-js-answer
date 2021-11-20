#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-48;
		c=getchar();
	}
	x*=f;
}

const int maxn = 2e5+7;
const int maxm = 1e7+7;

int T,cnt;
int x[maxn];
int nxt[maxm],in[maxm];
bool lzno[maxm],noself[maxm];

bool check(int x)
{
	while(x)
	{
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(T);
	for(int i=1;i<=T;++i)
		read(x[i]);
	for(int i=1;i<=maxm;++i)
	{
		if(!lzno[i]&&check(i))
			lzno[i]=1;
		//you hua
		//zhu yi you keng
		if(lzno[i])
		{
			if(!noself[i])
			{
				for(int j=2;i*j<=maxm;++j)
				{
					lzno[i*j]=1;
					noself[i*j]=1;
				}
			}
			
		}
		else
			in[++cnt]=i,nxt[in[cnt-1]]=in[cnt];
	}
	for(int i=1;i<=T;++i)
	{
		int nw = x[i];
		if(lzno[nw])
			puts("-1");
		else
			cout<<nxt[nw]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

