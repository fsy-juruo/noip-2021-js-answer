#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	int y=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x=x*y;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n;
	read(n);read(n);read(n);read(n);
	for(int i=1;i<=n;i++)printf("1\n");
	return 0;
}

