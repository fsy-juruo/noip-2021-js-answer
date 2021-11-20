#include <bits/stdc++.h>
#define MP make_pair
#define Fst first
#define Snd second
#define PII pair<int,int>
using namespace std;
int tac,n,m,tim;
string r[200010],c[200010];
char str[200010];
pair< PII,PII > p[100010];
vector<bool> vis[200010];
vector< PII > a[200010];
inline bool ok(PII x,PII y)
{
	if (y.Fst==-1) return 1;
	else return x.Fst==y.Fst ? 0 : x.Snd>=y.Snd;
}
inline void func1()
{
	for (int i=0;i<n;i++) vis[i].resize(m),a[i].resize(m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) a[i][j]=MP(-1,-1);
	for (int tc=0;tc<tim;tc++)
	{
		//cout <<tc<<" ####################\n";
		for (int i=0;i<n;i++) fill(vis[i].begin(),vis[i].end(),0);
		int x=p[tc].Snd.Fst,y=p[tc].Snd.Snd,col=p[tc].Fst.Fst,lv=p[tc].Fst.Snd;
		if (x>0 && c[x-1][y]=='1' && ok(MP(col,lv),a[x-1][y])) vis[x-1][y]=1;
		if (x<n-1 && c[x][y]=='1' && ok(MP(col,lv),a[x+1][y])) vis[x+1][y]=1;
		if (y>0 && r[x][y-1]=='1' && ok(MP(col,lv),a[x][y-1])) vis[x][y-1]=1;
		if (y<m-1 && r[x][y]=='1' && ok(MP(col,lv),a[x][y+1])) vis[x][y+1]=1;
		int xi=x,yi=y;
		while (yi<m-1 && r[xi][yi]=='2' && ok(MP(col,lv),a[xi][yi+1]))
		{
			yi++,vis[xi][yi]=1;
			if (a[xi][yi].Fst!=-1) break;
		}
		xi=x,yi=y;
		while (yi>0 && r[xi][yi-1]=='2' && ok(MP(col,lv),a[xi][yi-1]))
		{
			yi--,vis[xi][yi]=1;
			if (a[xi][yi].Fst!=-1) break;
		}
		xi=x,yi=y;
		while (xi<n-1 && c[xi][yi]=='2' && ok(MP(col,lv),a[xi+1][yi]))
		{
			xi++,vis[xi][yi]=1;
			if (a[xi][yi].Fst!=-1) break;
		}
		xi=x,yi=y;
		while (xi>0 && c[xi-1][yi]=='2' && ok(MP(col,lv),a[xi-1][yi]))
		{
			xi--,vis[xi][yi]=1;
			if (a[xi][yi].Fst!=-1) break;
		}
		queue<PII> q;
		q.push(MP(x,y)),vis[x][y]=1;
		while (!q.empty())
		{
			x=q.front().Fst,y=q.front().Snd; q.pop();
			if (a[x][y].Fst!=-1) continue;
			//cout <<x<<" "<<y<<" #\n";
			if (x>0 && c[x-1][y]=='3' && !vis[x-1][y] && ok(MP(col,lv),a[x-1][y])) vis[x-1][y]=1,q.push(MP(x-1,y));
			if (x<n-1 && c[x][y]=='3' && !vis[x+1][y] && ok(MP(col,lv),a[x+1][y])) vis[x+1][y]=1,q.push(MP(x+1,y));
			if (y>0 && r[x][y-1]=='3' && !vis[x][y-1] && ok(MP(col,lv),a[x][y-1])) vis[x][y-1]=1,q.push(MP(x,y-1));
			if (y<m-1 && r[x][y]=='3' && !vis[x][y+1] && ok(MP(col,lv),a[x][y+1])) vis[x][y+1]=1,q.push(MP(x,y+1));
		}
		int res=0;
		for (int i=0;i<n;i++)
		{
			//for (int j=0;j<m;j++) if (vis[i][j]) cout <<i<<" "<<j<<" ##\n";
			res+=count(vis[i].begin(),vis[i].end(),1);
		}
		printf("%d\n",res-1);
		x=p[tc].Snd.Fst,y=p[tc].Snd.Snd;
		a[x][y]=MP(col,lv);
	}
} 
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&tac);
	while (tac--)
	{
		scanf("%d%d%d",&n,&m,&tim);
		for (int i=0;i<n;i++) scanf("%s",str),r[i]=str;
		for (int i=0;i<n-1;i++) scanf("%s",str),c[i]=str;
		for (int i=0;i<tim;i++) scanf("%d%d%d%d",&p[i].Fst.Fst,&p[i].Fst.Snd,&p[i].Snd.Fst,&p[i].Snd.Snd),p[i].Snd.Fst--,p[i].Snd.Snd--;
		if (n*m<=5000 && tim<=2000) func1();
	}
	return 0;
}
