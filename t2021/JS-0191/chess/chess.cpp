#include <bits/stdc++.h>
using namespace std;
int scan()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=(x<<3)+(x<<1)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
#define scan scan()
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	puts("CCFÍòËê");
	return 0;
}
