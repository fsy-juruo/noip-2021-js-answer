#include<bits/stdc++.h>
using namespace std;

struct aaa{
	int a[4];
}way[5010][5010];

struct q{
	int c,lv;
}point[5010][5010];

int T,n,m,q,d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}},out,v[5010][5010],v2[5010][5010];
string s;

void find(int x,int y,int step)
{
	for(int i = 0;i < 4;i++)
	{
		if(point[x + d[i][0]][y + d[i][1]].c != point[x][y].c && point[x][y].lv >= point[x + d[i][0]][y + d[i][1]].lv)
		{
			if(way[x][y].a[i] == 1)
			{
//				cout<<"!: "<<x<<' '<<y<<' '<<i<<' '<<endl;
				if(v[x + d[i][0]][y + d[i][1]] != step)
				out++,v[x + d[i][0]][y + d[i][1]] = step;
			}
			else if(way[x][y].a[i] == 2)
			{
				int nx,ny;
				nx = x,ny = y;
				while(way[nx][ny].a[i] == 2 && point[nx + d[i][0]][ny + d[i][1]].c != point[x][y].c && point[x][y].lv >= point[nx + d[i][0]][ny + d[i][1]].lv)
				{
					nx = nx + d[i][0],ny = ny + d[i][1];
					if(v[nx][ny] != step)
					out++,v[nx][ny] = step;
					if(point[nx][ny].c != 0) break;
				}
			}
		}
	}
	queue < int > qx,qy;
	qx.push(x),qy.push(y);
	while(!qx.empty())
	{
		int nx = qx.front(),ny = qy.front();
//		cout<<nx<<' '<<ny<<endl;
		v2[nx][ny] = step;
		for(int i = 0;i < 4;i++)
		{
//			cout<<"?: ("<<nx + d[i][0]<<','<<ny + d[i][1]<<")"<<(point[nx + d[i][0]][ny + d[i][1]].c != point[x][y].c)<<' '<<way[nx][ny].a[i]<<' '<<(point[nx][ny].lv >= point[nx + d[i][0]][ny + d[i][1]].lv)<<endl;
			if(v2[nx + d[i][0]][ny + d[i][1]] != step && way[nx][ny].a[i] == 3 && point[nx + d[i][0]][ny + d[i][1]].c != point[x][y].c && point[x][y].lv >= point[nx + d[i][0]][ny + d[i][1]].lv)
			{
				v2[nx + d[i][0]][ny + d[i][1]] = step;
				if(point[nx + d[i][0]][ny + d[i][1]].c == 0)
				qx.push(nx + d[i][0]),qy.push(ny + d[i][1]);
				if(v[nx + d[i][0]][ny + d[i][1]] != step)
				out++,v[nx + d[i][0]][ny + d[i][1]] = step;
			}
		}
		qx.pop(),qy.pop();
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>q;
		for(int i = 1;i <= n;i++)
		{
			cin>>s;
			for(int j = 1;j < m;j++)
			{
				way[i][j].a[1] = s[j - 1] - '0';
				way[i][j + 1].a[3] = s[j - 1] - '0';
			}
		}
		for(int i = 1;i < n;i++)
		{
			cin>>s;
			for(int j = 1;j <= m;j++)
			{
				way[i][j].a[2] = s[j - 1] - '0';
				way[i + 1][j].a[0] = s[j - 1] - '0';
			}
		}
		
		for(int i = 1;i <= q;i++)
		{
			out = 0;
			int in1,in2,in3,in4;
			cin>>in1>>in2>>in3>>in4;
			point[in3][in4].c = in1 + 1;
			point[in3][in4].lv = in2;
			find(in3,in4,i);
			cout<<out<<endl;
		}
		
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				for(int k = 0;k < 4;k ++)
				way[i][j].a[k] = 0;
				point[i][j].c = 0,point[i][j].lv = 0;
				v[i][j] = 0,v2[i][j] = 0;
			}
		}
	}
	
	return 0;
}

