#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+ch-48;ch=getchar();}
	return sum*f;
}
inline void write(int x)
{
	if(!x)return;
	write(x/10);
	putchar(x%10+48);
}
inline void writeln(int x)
{
	if(x==-1){putchar('-');putchar('1');putchar('\n');return;}
	if(x==0){putchar('0');putchar('\n');return;}
	write(x);
	putchar('\n');
}
bool canot[10000035];
bool G[10000035];
int nxt[100000035];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	int n;
//	n=read();
	for(int i=1;i<=10000010;i++)
	{
//		if(i%1000000==0)cout<<i<<endl;
		int g=i;
		while(g)
		{
			int x=g%10;
			if(x==7){G[i]=1;break;}
			g/=10;
		}
	}
	for(int i=1;i<=10000010;i++)
	{
		if(G[i])
		{
			if(canot[i])continue;
			for(int j=i;j<=10000010;j+=i)
			{
				canot[j]=1;
			}
		}
	}
	int las=-1;
	for(int i=10000010;i>=1;i--)
		if(!canot[i]){nxt[i]=las;las=i;}
		else nxt[i]=-1;
	int T;
	T=read();
	while(T--)
	{
		int x;
		x=read();
		writeln(nxt[x]);
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
