#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
int read(){
	int num = 0,w = 1;
	char c = 0;
	while(c < '0' || c > '9'){if(c == '-')w = -1;c = getchar();}
	while(c >= '0' && c <= '9'){num = num * 10 + c - '0';c = getchar();}
	return num * w;
}

const int N = 2e5 + 10,M = 1e7 + 10;

int n;
bool st[N];
int ne[N],x;

bool get(int x)
{
	while(x)
	{
		int num = x % 10;
		x /= 10;
		if(num == 7) return 1;
	}
	return 0;
}

void check7()
{
	int last = 1;
	for(int i = 2; i < N; i ++)
	{
		if(get(i))
			for(int j = 1; j * i < N; j ++)
				st[j * i] = 1;
		if(!st[i])
		{
			ne[last] = i;
			last = i;
		}
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	check7();
	n = read();
	while(n --)
	{
		x = read();
		if(st[x]) puts("-1");
		else printf("%d\n",ne[x]);
	}
	
	return 0;
}

