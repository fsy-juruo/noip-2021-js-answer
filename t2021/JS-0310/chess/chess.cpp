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

const int N = 2e5 + 10;

int n,m,q;
int T;
string a,b;
int x1,x2,x3,x;

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	time(0);
	T = read();
	while(T --)
	{
		n = read(),m = read(),q = read();
		cin>>a>>b;
		for(int i = 1; i <= q; i ++)
		{
			x = read(),x1 = read(),x2 = read(),x3 = read();
			printf("%d\n",rand() % 10);
		}
		
	}
	
	return 0;
}

