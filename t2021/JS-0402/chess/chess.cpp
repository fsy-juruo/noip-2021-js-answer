#include<bits/stdc++.h>
using namespace std;
#define ll long long
int readint()
{
	char c=getchar(); int neg=1,ret=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) ret=(ret<<3)+(ret<<1)+(c&15);
	return neg*ret;
}
ll readll()
{
	char c=getchar(); ll neg=1,ret=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) ret=(ret<<3)+(ret<<1)+(c&15);
	return neg*ret;
}
void writeint(int x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[15]; int top=0;
	while(x) {int nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void writell(ll x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[25]; int top=0;
	while(x) {ll nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void Writeint(int x,char c) {writeint(x); putchar(c); return;}
void Writell(ll x,char c) {writell(x); putchar(c); return;}
int n,m,queries;
vector<string> rght,down;
vector<vector<int> > col,lvl,vis[3],alr;
int co1,lv1,cnt1;
void dfs(int x,int y,int type)
{
	if(vis[type][x][y]) return;
	vis[type][x][y]=true;
	if(col[x][y]==co1) return;
	if(lvl[x][y])
	{
		if(lv1>=lvl[x][y]&&!alr[x][y])
		{
			alr[x][y]=1;
			cnt1++;
		}
		return;
	}
	if(!alr[x][y])
	{
		alr[x][y]=1;
		cnt1++;
	}
	if(x>0&&((down[x-1][y]==2&&type==0)||(down[x-1][y]==3&&type==2))) dfs(x-1,y,type);
	if(x<n-1&&((down[x][y]==2&&type==0)||(down[x][y]==3&&type==2))) dfs(x+1,y,type);
	if(y>0&&((rght[x][y-1]==2&&type==1)||(rght[x][y-1]==3&&type==2))) dfs(x,y-1,type);
	if(y<m-1&&((rght[x][y]==2&&type==1)||(rght[x][y]==3&&type==2))) dfs(x,y+1,type);
	return;
}
void slv1()
{
	rght.clear(); down.clear();
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		for(int j=0;j<m-1;j++)
			s[j]-='0';
		rght.push_back(s);
	}
	for(int i=0;i<n-1;i++)
	{
		string s; cin>>s;
		for(int j=0;j<m;j++)
			s[j]-='0';
		down.push_back(s);
	}
	col.clear(); col.resize(n,vector<int>(m,-1));
	lvl.clear(); lvl.resize(n,vector<int>(m,0));
	while(queries--)
	{
		int x,y;
		cin>>co1>>lv1>>x>>y;
		for(int i=0;i<3;i++)
		{
			vis[i].clear();
			vis[i].resize(n,vector<int>(m,0));
		}
		alr.clear(); alr.resize(n,vector<int>(m,0));
		x--; y--; cnt1=-1; dfs(x,y,0); dfs(x,y,1); dfs(x,y,2);
		if(x>0&&down[x-1][y]==1&&col[x-1][y]!=co1&&lvl[x-1][y]<=lv1&&!alr[x-1][y]) cnt1++;
		if(x<n-1&&down[x][y]==1&&col[x+1][y]!=co1&&lvl[x+1][y]<=lv1&&!alr[x+1][y]) cnt1++;
		if(y>0&&rght[x][y-1]==1&&col[x][y-1]!=co1&&lvl[x][y-1]<=lv1&&!alr[x][y-1]) cnt1++;
		if(y<m-1&&rght[x][y]==1&&col[x][y+1]!=co1&&lvl[x][y+1]<=lv1&&!alr[x][y+1]) cnt1++; 
		cout<<cnt1<<'\n';
		col[x][y]=co1; lvl[x][y]=lv1;
	}
	return;
}
void slv2()
{
	rght.clear(); down.clear();
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		for(int j=0;j<m-1;j++)
			s[j]-='0';
		rght.push_back(s);
	}
	for(int i=0;i<n-1;i++)
	{
		string s; cin>>s;
		for(int j=0;j<m;j++)
			s[j]-='0';
		down.push_back(s);
	}
	col.clear(); col.resize(n,vector<int>(m,-1));
	lvl.clear(); lvl.resize(n,vector<int>(m,0));
	while(queries--)
	{
		int x,y;
		cin>>co1>>lv1>>x>>y;
		x--; y--; cnt1=0;
		if(x>0&&down[x-1][y]==1&&col[x-1][y]!=co1&&lvl[x-1][y]<=lv1) cnt1++;
		if(x<n-1&&down[x][y]==1&&col[x+1][y]!=co1&&lvl[x+1][y]<=lv1) cnt1++;
		if(y>0&&rght[x][y-1]==1&&col[x][y-1]!=co1&&lvl[x][y-1]<=lv1) cnt1++;
		if(y<m-1&&rght[x][y]==1&&col[x][y+1]!=co1&&lvl[x][y+1]<=lv1) cnt1++; 
		cout<<cnt1<<'\n';
		col[x][y]=co1; lvl[x][y]=lv1;
	}
	return;
}
void fl()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
}
int main()
{
	fl();
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
		cin>>n>>m>>queries;
		if(1ll*n*m*queries<=20000000) slv1();
		else slv2();
	}
	return 0;
}
/*
2
2 3 4
22
33
123
0 2 1 2
0 1 2 1
1 2 1 3
0 3 2 2
3 2 3
3
1
3
32
32
0 2 1 2
1 2 3 2
0 1 2 2
*/

