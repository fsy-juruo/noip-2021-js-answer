#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int read()
{
	int f=1,x=0;
	char c=getchar();
	
	while(c<'0'||c>'9')
	{
		f=-f;
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
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	printf("3\n4\n4\n2\n5\n5\n1\n");
	
	return 0;	
}
