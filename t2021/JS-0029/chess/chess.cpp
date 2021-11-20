#include<bits/stdc++.h>
using namespace std;
struct ins{
    template<typename T>void read(T &n)
    {
        n=0;char c=getchar();bool f=1;
        for(;!isdigit(c);c=getchar())if(c=='-')f=0;
        for(;isdigit(c);c=getchar())n=n*10+c-'0';
        if(f==0)n=-n;
    }
    template<typename T>ins operator >>(T &n)
    {
        read(n);
        return *this;
    }
}yin;
int n,m,q;
#define id(x,y) ((x-1)*m+y-1)
const int maxn=2e5+10;
vector<pair<int,int> > e[maxn];
void add(int x,int y,int z)
{
    e[x].push_back({y,z});
    e[y].push_back({x,z});
}
pair<int,int> vis[maxn];
int bfs(int u,int w,int col,int val,int cc)
{
    if(w==1)
    {
        if(vis[u].first==0)return 1;
        if(vis[u].first==col)return 0;
        return vis[u].second<=val;
    }
    if(w==2)
    {
        int t=u-cc;
        int p=u;
        if(vis[u].first==col)return 0;
        else if(vis[u].first!=0)
        return vis[u].second<=val;
        int ans=1;
        while(1)
        {
            int tmp=p;
            for(int i=0;i<e[p].size();i++)
            {
                if(e[p][i].first!=t+p)continue;
                if(e[p][i].second!=w)continue;
                if(vis[e[p][i].first].first)
                {
                    if(vis[e[p][i].first].first==col)return ans;
                    return (vis[e[p][i].first].second<=val)+ans;
                }
                p=e[p][i].first;
                break;
            }
            if(p==tmp)break;
            ++ans;
        }
        return ans;
    }
    return 0;
}
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int TTT;
    yin>>TTT;
    while(TTT--)
    {
        yin>>n>>m>>q;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<m;j++)
            {
                char c;
                cin>>c;
                if(c!='0')
                add(id(i,j),id(i,j+1),c-'0');
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c!='0')
                add(id(i,j),id(i+1,j),c-'0');
            }
        }
        while(q--)
        {
            int col,val,x,y;
            yin>>col>>val>>x>>y;
            ++col;
            int ans=0;
            for(int i=0;i<e[id(x,y)].size();i++)
            {
                ans+=bfs(e[id(x,y)][i].first,e[id(x,y)][i].second,col,val,id(x,y));
            }
            cout<<ans<<endl;
            vis[id(x,y)]={col,val};
        }
    }
    return 0;
}