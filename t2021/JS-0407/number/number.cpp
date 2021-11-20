#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(int x)
{
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}
inline void fl()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
int a[200005],fa[10000005];
bool f[10000005];
int get(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=get(fa[x]);
}
inline bool check(int x)
{
	while(x)
	{
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}
int main()
{
	fl();
	int n=read(),m=10000002,i,j;
	for(i=1;i<=n;i++)
		a[i]=read();
	for(i=1;i<=m;i++)
	{
		fa[i]=i;
		if(!f[i])
		{
			f[i]=check(i);
			if(f[i])
				for(j=i;j<=m;j+=i)
					f[j]=true;
		}
	}
	for(i=1;i<=m;i++)
		if(f[i])
			fa[get(i-1)]=get(i);
	for(i=1;i<=n;i++)
		if(f[a[i]])
			puts("-1");
		else
		{
			write(get(a[i])+1);
			putchar('\n');
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
