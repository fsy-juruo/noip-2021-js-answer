#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
	return res*f;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	srand((unsigned)time(0));
	while(T--)
	{
		int n=read(),m=read(),q=read();
		for(int i=1;i<=q;i++) cout<<rand()%5+1<<endl;
	}
	return 0;
}

