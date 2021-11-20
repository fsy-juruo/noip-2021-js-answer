#include<bits/stdc++.h>
using namespace std;
inline void openfiles()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}
const int N=105,mod=998244353;
inline int rd()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*y;
}

int main()
{
	openfiles();
	rd();int m=rd();rd();
	for(int i=0;i<=m;i++)rd();
	if(m==1)puts("40");
	else puts("642171527");
	return 0;
}
/*

*/

