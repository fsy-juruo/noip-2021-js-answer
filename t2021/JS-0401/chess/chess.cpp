#include <bits/stdc++.h>
#define ll int
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 200010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		ret=(ret*10+(c-48));
		c=getchar();
	}
	return ret;
}
void rout(ll x){
	if(x<10) putchar(48+x);
	else rout(x/10),putchar(48+(x%10));
	return;
}
ll n,m,q,rd[N][4],cnt[4],col[N],lv[N],dirx[]={0,1,0,-1},diry[]={1,0,-1,0};
bool vis[N];
char buf[N];
ll trv1(ll x,ll y)
{
	ll tx,ty,i,ret=0;
	for(i=0;i<4;++i)
	{
		tx=x+dirx[i];
		ty=y+diry[i];
		if(tx>=0&&tx<n&&ty>=0&&ty<m)
		{
			if(rd[x*m+y][i]==1)
			{
				if(col[tx*m+ty]==-1||(col[tx*m+ty]!=col[x*m+y]&&lv[tx*m+ty]<=lv[x*m+y]))
				{
					vis[tx*m+ty]=true;
					++ret;
				}
			}
		}
	}
	return ret;
}
void trv2(ll x,ll y)
{
	ll i,tx,ty;
	for(i=0;i<4;++i)
	{
		tx=x,ty=y;
		while(tx<n&&ty<m&&tx>=0&&ty>=0)
		{
			if(rd[tx*m+ty][i]!=2)
			{
				break;
			}
			tx+=dirx[i];
			ty+=diry[i];
			if(!(tx<n&&ty<m&&tx>=0&&ty>=0))
			{
				break;
			}
			if(col[tx*m+ty]!=-1&&(col[tx*m+ty]==col[x*m+y]||lv[tx*m+ty]>lv[x*m+y]))
			{
				break;
			}
			vis[tx*m+ty]=true;
			if(col[tx*m+ty]!=-1)
			{
				break;
			}
		}
	}
	return;
}
void dfs(ll x,ll y,ll oc,ll ol)
{
	ll i,tx,ty;
	vis[x*m+y]=true;
	for(i=0;i<4;++i)
	{
		if(rd[x*m+y][i]==3)
		{
			tx=x+dirx[i];
			ty=y+diry[i];
			if(tx>=0&&tx<n&&ty>=0&&ty<m)
			{
				if(!vis[tx*m+ty])
				{
					if(col[tx*m+ty]==-1)
					{
						dfs(tx,ty,oc,ol);
					}
					else if(col[tx*m+ty]!=oc&&lv[tx*m+ty]<=ol)
					{
						vis[tx*m+ty]=true;
					}
				}
			}
		}
	}
	return;
}
void solve1()
{
	ll c,l,x,y,i;
	while(q--)
	{
		c=rint(),l=rint(),x=rint()-1,y=rint()-1;
		col[x*m+y]=c;
		lv[x*m+y]=l;
		for(i=0;i<n*m;++i)
		{
			vis[i]=false;
		}
		dfs(x,y,c,l);
		trv1(x,y),trv2(x,y);
		vis[x*m+y]=false;
		ll ans=0;
		for(i=0;i<n*m;++i)
		{
			if(vis[i])
			{
				++ans;
			}
		}
		rout(ans),putchar('\n');
	}
	return;
}
void solve2()
{
	ll c,l,x,y;
	while(q--)
	{
		c=rint(),l=rint(),x=rint()-1,y=rint()-1;
		col[x*m+y]=c;
		lv[x*m+y]=l;
		rout(trv1(x,y)),putchar('\n');
	}
	return;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ll T=rint(),i,j;
	while(T--)
	{
		n=rint(),m=rint(),q=rint();
		for(i=0;i<n*m;++i)
		{
			col[i]=-1;
		}
		cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
		for(i=0;i<n;++i)
		{
			scanf("%s",&buf);
			for(j=0;j+1<m;++j)
			{
				rd[i*m+j][0]=(buf[j]-48);
				rd[i*m+j+1][2]=(buf[j]-48);
				++cnt[buf[j]-48];
			}
		}
		for(i=0;i+1<n;++i)
		{
			scanf("%s",&buf);
			for(j=0;j<m;++j)
			{
				rd[i*m+j][1]=(buf[j]-48);
				rd[(i+1)*m+j][3]=(buf[j]-48);
				++cnt[buf[j]-48];
			}
		}
		if(cnt[2]==0&&cnt[3]==0)
		{
			solve2();
		}
		else
		{
			solve1();
		}
	}
	return 0;
}
