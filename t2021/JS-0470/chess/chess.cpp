#include<bits/stdc++.h>
using namespace std;

int n, m, q;
int cols[800005], lvs[800005], cl[800005], rw[800005], v[800005][3];

int rd()
{
	char c=getchar();
	while( c<'0' ||  c>'9') c=getchar();
	return c-'0';
}

int rds()
{
	char c=getchar();
	int ans=0;
	while(  c<'0' ||  c>'9' ) c=getchar();
	while( c>='0' && c<='9' ) ans=ans*10+c-'0', c=getchar();
	return ans;
}

void wrts(int a)
{
	if(a<10) putchar(a%10+'0'); 
	else wrts(a/10), putchar(a%10+'0');
}

int dfs(int col, int lv, int x, int y, int k=-1, int cr=-1)
{
	if(x<1 || y<1 || x==n || y==m) return 0;
	int cnt=(k==-1 || v[x*m+y][0]==q ? 0 : 1);
	v[x*m+y][0]=q;
	if(cols[x*m+y]!=0)
	{
		if(col==cols[x*m+y] || lv<lvs[x*m+y]) return 0;
		return cnt;
	}
	if(k==-2) return cnt;
	if(k==-1)
	{
		if(cl[x*m+y]==1) cnt+=dfs(col, lv, x+1, y, -2);
		if(rw[x*m+y]==1) cnt+=dfs(col, lv, x, y+1, -2);
		if(cl[x*m+y-m]==1) cnt+=dfs(col, lv, x-1, y, -2);
		if(rw[x*m+y-1]==1) cnt+=dfs(col, lv, x, y-1, -2);
	}
	if((k==-1 || k==2) && v[x*m+y][1]!=q)
	{
		v[x*m+y][1]=q;
		if(k==-1)
		{
			if(cl[x*m+y]==2) cnt+=dfs(col, lv, x+1, y, 2, 1);
			if(rw[x*m+y]==2) cnt+=dfs(col, lv, x, y+1, 2, 2);
			if(cl[x*m+y-m]==2) cnt+=dfs(col, lv, x-1, y, 2, 1);
			if(rw[x*m+y-1]==2) cnt+=dfs(col, lv, x, y-1, 2, 2);
		}
		else
		{
			if(cr==1)
			{
				if(cl[x*m+y]==2) cnt+=dfs(col, lv, x+1, y, 2, 1);
				if(cl[x*m+y-m]==2) cnt+=dfs(col, lv, x-1, y, 2, 1);
				
			}
			else
			{
				if(rw[x*m+y]==2) cnt+=dfs(col, lv, x, y+1, 2, 2);
				if(rw[x*m+y-1]==2) cnt+=dfs(col, lv, x, y-1, 2, 2);
			}
		}
	}
	if((k==-1 || k==3) && v[x*m+y][2]!=q)
	{
		v[x*m+y][2]=q;
		if(cl[x*m+y]==3) cnt+=dfs(col, lv, x+1, y, 3);
		if(rw[x*m+y]==3) cnt+=dfs(col, lv, x, y+1, 3);
		if(cl[x*m+y-m]==3) cnt+=dfs(col, lv, x-1, y, 3);
		if(rw[x*m+y-1]==3) cnt+=dfs(col, lv, x, y-1, 3);
	}
	return cnt;
}

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int i, j;
	int col, lv, x, y;
	int T=rds();
	while(T--)
	{
		n=rds(), m=rds(), q=rds(); n++, m++;
		for(i=1; i<n; i++) for(j=1; j<m-1; j++) rw[i*m+j]=rd();
		for(i=1; i<n-1; i++) for(j=1; j<m; j++) cl[i*m+j]=rd();
		while(q--)
		{
			col=rds(), lv=rds(), x=rds(), y=rds(); col++;
			wrts(dfs(col, lv, x, y)); putchar('\n');
			cols[x*m+y]=col, lvs[x*m+y]=lv;
		}
		for(i=0; i<=n*m; i++) v[i][0]=0, v[i][1]=0, v[i][2]=0, cols[i]=0, lvs[i]=0;
	}
	return 0;
}
