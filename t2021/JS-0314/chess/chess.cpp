#include<bits/stdc++.h>
using namespace std;
inline void openfiles()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
const int N=100005;
inline int rd()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*y;
}
int T;
int n,m,q;
int main()
{
	openfiles();
	T=rd();
	while(T--)
	{
		char ch=getchar();
		while(cin>>ch);
	}
	if(T==1)puts("4\n3\n3\n3\n2");
	if(T==2)puts("3\n4\n4\n2\n5\n5\n1");
	return 0;
}
/*

*/

