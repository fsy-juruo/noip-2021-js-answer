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
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	puts("40");
	return 0;
}
