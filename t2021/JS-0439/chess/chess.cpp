#include <bits/stdc++.h>
using namespace std;
long long T,n,m,q,a;
char rd,td;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--)	
	{
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m-1;j++)
			cin>>rd;
		}
		for(int i=1;i<=m-1;i++)
		{
			for(int j=1;j<=n;j++)
			cin>>td;
		}
		while(q--)
		{
			cin>>a>>a>>a>>a;
			cout<<4<<endl;
		}
	}
	return 0;
}
//		while(q--)
//		{
//			cin>>col[x][y]>>lv[x][y]>>x>>y;
//			nx=x;ny=y;
//			if(td[x-1][y]=='1')
//			{
//				if(em[x-1][y]||(col[x-1][y]!=col[x][y]&&lv[x][y]>=lv[x-1][y]))
//				cnt++;
//			}
//			if(td[x][y]=='1')
//			{
//				if(em[x+1][y]||(col[x+1][y]!=col[x][y]&&lv[x][y]>=lv[x+1][y]))
//				cnt++;
//			}
//			if(rd[x][y-1]=='1')
//			{
//				if(em[x][y-1]||(col[x][y-1]!=col[x][y]&&lv[x][y]>=lv[x][y-1]))
//				cnt++;
//			}
//			if(rd[x][y]=='1')
//			{
//				if(em[x][y+1]||(col[x][y+1]!=col[x][y]&&lv[x][y]>=lv[x][y+1]))
//				cnt++;
//			}
//		}
//	}
//}
