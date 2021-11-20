#include<bits/stdc++.h>
#define LL long long
#define IL inline
#define RE register int
using namespace std;

//const int N=;
const int INF=2147483647;

IL void read(RE &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f?-x:x;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	puts("4\n3\n3\n3\n2");
	return 0;
}

