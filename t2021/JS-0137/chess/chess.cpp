#include<bits/stdc++.h>
#define filename "chess"
using namespace std;
const int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int T,n,m,q;
char s[5005];
set<pair<int,int> >S;
struct node
{
    int col,lv;
}a[5005][5005],cur;
int maps[5005][5005][4];
void dfs(int x,int y,int d,int type,bool norm,bool st)
{
    if(S.find(make_pair(x,y))!=S.end()||(~a[x][y].col&&a[x][y].col!=cur.col&&a[x][y].lv>cur.lv))return;
    S.insert(make_pair(x,y));
    switch(type)
    {
        case 0: return;
        case 1:
        {
            if(norm||st)break;
            for(int i=0;i<4;++i)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<1||ny<1||nx>n||ny>m)continue;
                dfs(nx,ny,i,maps[x][y][i],true,false);
            }
            break;
        }
        case 2:
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<1||ny<1||nx>n||ny>m)return;
            dfs(nx,ny,d,maps[x][y][d],norm,true);
            break;
        }
        case 3:
        {
            if(st)break;
            for(int i=0;i<4;++i)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<1||ny<1||nx>n||ny>m)continue;
                dfs(nx,ny,i,maps[x][y][i],norm,st);
            }
            break;
        }
    }
}
int main()
{
    freopen(filename".in","r",stdin);
    freopen(filename".out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                a[i][j]=(node){-1,0};
        for(int i=1;i<=n;++i)
        {
            scanf("%s",s+1);
            for(int j=1;j<m;++j)maps[i][j][2]=maps[i][j+1][1]=s[j]^48;
        }
        for(int i=1;i<n;++i)
        {
            scanf("%s",s+1);
            for(int j=1;j<=m;++j)maps[i][j][3]=maps[i+1][j][0]=s[j]^48;
        }
        for(int i=1,x,y;i<=q;++i)
        {
            scanf("%d%d%d%d",&cur.col,&cur.lv,&x,&y);
            int ans=0;
            S.clear();
            for(int j=0;j<4;++j)
            {
                S.clear();
                dfs(x,y,j,maps[x][y][j],false,false);
                ans=max(ans,int(S.size()));
            }
            printf("%d\n",ans);
            a[x][y]=cur;
        }
    }
    return 0;
}
