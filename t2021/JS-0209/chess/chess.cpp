#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,q;
int total=0;
//map<pair<int,int>,p> ma;
//strcut p
//{
//	int col=-1;
//	int lv;
//	int head;
//};
//struct edge
//{
//	int opt;
//	p to;
//}e[100010];
//void addline(int x,int y,int x1,int y1)
//{
//	
//}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=q;i++)
		printf("%d",n*m/q);
	}
	return 0;
}

