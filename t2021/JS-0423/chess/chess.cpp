#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,i##__##akioi=n;i<i##__##akioi;++i)
#define per(i,n) for(int i=int(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,i##__##aknoi=n;i<=i##__##aknoi;++i)
#define per1(i,n) for(int i=n;i>=1;--i)
#define y0 ak_csp_ak_noip
#define y1 i_love_luogu
#define pq priority_queue
#define np next_permutation
typedef long long ll;
typedef unsigned long long ull;
const ll mod1=998244353;
const ll mod2=1000000007;
using namespace std;
int t,n,m,q,_c,_l,_x,_y;
int cl[100005];
int lv[100005];
vector<int> pnt[100005];
string lr[100005];
string ud[100005];
bool flag;
void read(int&x)
{
	x=0;char c=getchar();
	while(c<48||c>57) c=getchar();
	while(48<=c&&c<=57)
	{
		x=x*10+(c&15);c=getchar();
	}
}
void read(string&x)
{
	x="";char c=getchar();
	while(c<48||c>57) c=getchar();
	while(48<=c&&c<=57)
	{
		x=x+c;c=getchar();
		if(c>49)
		{
			flag=1;
		}
	}
}
void print(int x)
{
	if(x>10) print(x/10);
	putchar((x%10)|48);
}
bool check(int x,int y)
{
	return 0<=x&&x<n&&0<=y&&y<m;
}
void rd()
{
	flag=0;
	cl[0]=-1;
	read(n);read(m);read(q);
	rep(i,n) pnt[i]=vector<int>(m,0);
	rep(i,n) read(lr[i]);
	rep(i,n-1) read(ud[i]);
	//cout<<"-----"<<endl;
}
namespace sol_78{
	const int dx[4]={0,1,0,-1};
	const int dy[4]={1,0,-1,0};
	bool canplace(int x,int y,int mine)
	{
		return (cl[pnt[x][y]]!=cl[mine]&&lv[mine]>=lv[pnt[x][y]]);
	}
	int calc_ans(int x,int y,int ii,int C,int LV)
	{
		int cnt=0;
		cl[ii]=C;lv[ii]=LV;
		rep(i,4)
		{
			int X=x+dx[i],Y=y+dy[i];
			if(!check(X,Y)) continue;
			if(!canplace(X,Y,ii)) continue;
			char flag;
			switch(i)
			{
				case 0:
					/*x,y->x,y+1*/
					flag=lr[x][y];
					break;
				case 1:
					flag=ud[x][y];
					break;
				case 2:
					flag=lr[x][y-1];
					break;
				case 3:
					flag=ud[x-1][y];
					break;
			}
			if(flag=='1') ++cnt;
		}
		pnt[x][y]=ii;
		return cnt;
	}
	void fQ()//full query,already read
	{
		for(int i=1;i<=q;++i)
		{
			read(_c);read(_l);read(_x);read(_y);
			--_x;--_y;
			print(calc_ans(_x,_y,i,_c,_l));
			putchar(10);
		}
	}
}
void fQ()
{
	rd();
	if(!flag)
	sol_78::fQ();
	else
	{
		//do something
		//cout<<"I Bao0 NOIP"<<endl;
	}
}
int main()
{
	#ifndef DEBUG
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	#endif
	read(t);
	while(t--)
	fQ();
	return 0;
}
/*
visit me qwq: www.luogu.com.cn/user/483824
I have contestId 56666 !(this is not factorial
www.luogu.com.cn/contest/56666
friends(have met): @huagaohan @sszcdjr @littlewave
//freopen ".ans" "1.in" "1.out" ".txt"
ccf ak ioi

*/


