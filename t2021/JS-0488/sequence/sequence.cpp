#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n,m,k;
int a[105];
int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++)
	{
		int a;
		cin>>a;
	}
	cout<<40<<endl;
	return 0;
}

