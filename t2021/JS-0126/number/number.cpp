#include <bits/stdc++.h>
using namespace std;

const int maxn=10000111,maxm=10000100;

int q,n;
bool ok[maxn];

inline int mread()
{
	int ret=0,sgn=1;
	char c=getchar();
	while(c!='-'&&(c<'0'||'9'<c)) c=getchar();
	
	if(c=='-') sgn=-1, c=getchar();
	
	while('0'<=c&&c<='9') ret=ret*10+c-'0', c=getchar();
	
	return sgn*ret;
}

inline void mprint(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) mprint(x/10);
	putchar(x%10+'0');
}

inline bool check(int x)
{
	for(;x;x/=10) if((x%10)==7) return 1;
	return 0;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	for(int i=1;i<maxm;i++) if(check(i))
	{
		for(int j=i;j<maxm;j+=i) ok[j]=1;
	}
	
	q=mread();
	while(q--)
	{
		int x=mread();
		
		if(ok[x]) puts("-1");
		else
		{
			do x++; while(ok[x]);
			mprint(x); puts("");
		}
	}
	
	return 0;
}
