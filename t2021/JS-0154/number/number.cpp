#include<bits/stdc++.h>
using namespace std;
#define MAX 10000007
typedef long long ll;
typedef unsigned long long ull;
#define SIZE(X) int((X).size())

int read()
{
	int ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
void write(int x)
{
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void writesp(int x) {write(x); putchar(' ');}
void writeln(int x) {write(x); putchar('\n');}

int fa[MAX];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

ll mypow10[11];
bool v[MAX], p[MAX];
vector<int> seven[11];

void find_seven(int w)
{
	if(w > 2) find_seven(w - 1);
	for(int i = 0;i < SIZE(seven[w - 1]);++i)
	{
		for(int j = 0;j <= 9;++j)
		{
			seven[w].push_back(seven[w - 1][i] * 10 + j);
			p[seven[w - 1][i] * 10 + j] = 1;
		}
	}
	for(int i = mypow10[w - 2];i < mypow10[w - 1];++i)
		if(!p[i * 10 + 7])
		{
			seven[w].push_back(i * 10 + 7);
			p[i * 10 + 7] = 1;
		}
}

void init()
{
	mypow10[0] = 1;
	for(int i = 1;i <= 8;++i) mypow10[i] = mypow10[i - 1] * 10;
	
	seven[1].push_back(7);
	p[7] = 1;
	find_seven(7);
	
	int n = 10000001;
	v[0] = v[1] = 1;
	for(int i = 2;i <= n;++i)
	{
		if(!v[i])
		{
			for(int j = i;(ll)j * i <= n;++j)
			{
				v[j * i] = 1;
				if(p[i] == 1 || p[j] == 1) p[j * i] = 1;
			}
		}
	}
	
	for(int i = 1;i <= n;++i) fa[i] = i;
	for(int i = n;i >= 1;--i)
		if(p[i])
			fa[i] = i + 1;
			
}

void work()
{
	int x = read();
	if(p[x]) printf("-1\n");
	else writeln(find(x + 1));
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int t = read();
	while(t--) work();
	return 0;
}
