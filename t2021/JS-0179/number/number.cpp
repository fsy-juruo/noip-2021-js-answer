#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
int hs[inf+5],n;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-48;c=getchar();}
	return x*f;
}
void Write(int x)
{
	if(x<0){x=-x;putchar('-');}
	if(!x)return;
	Write(x/10);
	putchar(x%10+48);
}
bool check(int x)
{
	while(x)
	{
		if(x%10==7)
			return 1;
		x/=10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=read();
	for(int i=1;i<=inf;i++)
	{
		if(hs[i])continue;
		if(check(i))
			for(int j=i;j<=inf;j+=i)
				hs[j]=-1;
	}
	for(int i=inf,x=inf+1;i>0;i--)
		if(!hs[i])hs[i]=x,x=i;
	while(n--)
	{
		Write(hs[read()]);
		putchar('\n');
	}
	return 0;
}
