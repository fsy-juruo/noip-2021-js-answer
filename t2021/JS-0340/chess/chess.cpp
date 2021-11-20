#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<fstream>

using namespace std;

const int maxn=900007;
struct aaa{
	int you,col,lv;
}dian[maxn];
struct Node{
	int lued,zt;
	Node(int _lued,int _zt)
	{
		lued=_lued;
		zt=_zt;
	}
};
struct ccc{
	int dq,las,zht,len;
}dui[maxn];
vector<Node>qp[maxn];
int n,m,q,T;
int tot;
int vis[maxn];


int suan(int x,int y)
{
	return (x-1)*m+y;
}
int huix(int xh)
{
	return (xh-1)/m+1;
}
int huiy(int xh)
{
	return xh-(huix(xh)-1)*m;
}
void bfs(int x)
{
	int l=1,r=2;
	dui[l].dq=x;
	dui[l].las=0;
	dui[l].zht=-1;
	dui[l].len=0;
	vis[x]=1;
	while(l<r)
	{
		int aa=dui[l].dq;
		for(int i=0;i<qp[aa].size();i++)
		{
			int bb=qp[aa][i].lued,cc=qp[aa][i].zt;
			if(cc!=dui[l].zht&&dui[l].len>=1) continue;
			if(cc==2&&dui[l].len>=1&&((huix(aa)==huix(dui[l].las)&&huix(aa)!=huix(bb))||(huiy(aa)==huiy(dui[l].las)&&huiy(aa)!=huiy(bb)))) 
			continue;
			if(cc==1)
			{
				tot++;
				continue;
			}
			if(vis[bb]==0)
			{
				dui[r].las=l;
				dui[r].dq=bb;
				dui[r].zht=cc;
				dui[r].len=dui[l].len+1;
				vis[bb]=1;
				if(dui[r].len==1) tot++;
				r++;
			}	
//			if(dian[bb].you==1&&bb!=x)
//			{
//				if(dian[x].col!=dian[bb].col&&dian[x].lv>dian[bb].lv)
//				{
//					tot++;
//					vis[bb]=1;
//					continue;
//				}
//			}
//			if(vis[bb]==0) 
//			{
//				if(cc==2&&dui[l].len>=1&&((huix(aa)==huix(dui[l].las)&&huix(aa)!=huix(bb))||(huiy(aa)==huiy(dui[l].las)&&huiy(aa)!=huiy(bb))))	
//				{
//					vis[bb]=1;
//					continue;	
//				}
//				if(cc==1)
//				{
//					tot++;
//					vis[bb]=1;
//					continue;
//				}
//				dui[r].las=l;
//				dui[r].dq=bb;
//				dui[r].zht=cc;
//				dui[r].len=dui[l].len+1;
//				vis[bb]=1;
//				if(dui[r].len==1) tot++;
//				if(dui[r].len>1&&dui[r].zht==dui[l].zht) tot++;
//				r++;
			}
			l++;	
		}
		
	}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(qp,0,sizeof(qp));
		memset(dian,0,sizeof(dian));

		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
		{
			string aa;
			cin>>aa;
			for(int j=0;j<aa.size();j++)
			{
				if(aa[j]-48!=0)
				{
					qp[suan(i,j+1)].push_back(Node(suan(i,j+2),aa[j]-48));
					qp[suan(i,j+2)].push_back(Node(suan(i,j+1),aa[j]-48));
				}
			}
		}
		for(int i=1;i<=n-1;i++)
		{
			string aa;
			cin>>aa;
			for(int j=0;j<aa.size();j++)
			{
				if(aa[j]-48!=0)
				{
					qp[suan(i,j+1)].push_back(Node(suan(i+1,j+1),aa[j]-48));
					qp[suan(i+1,j+1)].push_back(Node(suan(i,j+1),aa[j]-48));
				}			
			}
		}
		for(int i=1,a,b,c,d;i<=q;i++)
		{
			tot=0;
			memset(vis,0,sizeof(vis));	
			scanf("%d%d%d%d",&a,&b,&c,&d);
			int dh=suan(c,d);
			dian[dh].col=a;
			dian[dh].lv=b;
			dian[dh].you=1;
			bfs(dh);
			printf("%d\n",tot);
		}
	}
	
	
	
	return 0;
}
