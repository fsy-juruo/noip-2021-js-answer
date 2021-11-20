#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')	{if(ch=='-')	w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')	{s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t=read();
	int n,m,q;
	while(t--)
	{
		n=read();
		m=read();
		q=read();		
	}
	return 0;
}

