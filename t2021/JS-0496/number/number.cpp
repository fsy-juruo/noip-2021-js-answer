#include<cstdio>
#define MAXN 10000005

using namespace std;

int n;
bool b[MAXN];
int c[MAXN];

bool judge(int x)
{
	while(x)
	{
		if(x%10==7) return true;
		x /= 10;
	}
	return false;
}

void init()
{
	for(int i=1; i<=MAXN; i++)
	{
		if(!b[i] && judge(i))
		{
			for(int j=1; i*j<=MAXN; j++)
				b[i*j] = 1;
		}
	}
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	init();
	for(int i=MAXN; i>=1; i--)
	{
		if(b[i]==0) c[i]=i;
		else c[i]=c[i+1];
	}
//	for(int i=1; i<=20; i++) printf("%d ", c[i]);printf("\n");
//	printf("%d", c[10000000]);
	
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		if(b[x]) printf("-1\n");
		else printf("%d\n", c[x+1]);
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
