#include <bits/stdc++.h>
using namespace std;

const int N= (int)1e7+ 5;

bool st;
int v[N], len, vis[N];
bool ed;
int T; 

int check(int x)
{
	while(x)
	{
		if((x% 10)== 7) return 1;
		x/= 10;
	} 
	return 0;
}

void init()
{
	v[++ len]= 1; int M;
	if(T<= 10000) M= 200005; else M= 10000000;
	for(int i= 2; i<= M; i++ )
	{
		if(vis[i]|| check(i)|| (i% 7== 0)) vis[i]= 1;
		if(! vis[i]) {v[++ len]= i; continue;}
		for(int j= 1; j* i<= M; j++ ) vis[j* i]= 1;
	}
	
	return ;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>> T;
	init();
	while(T-- )
	{
		int x; scanf("%d", &x);
		int u= lower_bound(v+ 1, v+ len+ 1, x)- v;
		if(v[u]!= x) puts("-1");
		else if(u== len) printf("%d\n", 10000001); 
		else printf("%d\n", v[u+ 1]);
	}
	return 0;
}

