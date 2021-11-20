#include<bits/stdc++.h>
using namespace std;

struct chesspiece{
    int col,lv;
    chesspiece(){
        col=-1;
        lv=-1;
    }
    chesspiece(int c,int l){
        col=c;
        lv=l;
    }
    bool eat(const chesspiece &a){
        return col!=a.col&&lv>=a.lv;
    }
};

int n,m,q;
vector<vector<int>> lr,ud,lm,rm,um,dm;
vector<int> g[500005],adj[500005];
bool vis[500005];
chesspiece occ[500005];
set<int> row[500005],col[500005];

int id(int x,int y){
    return (x-1)*m+y;
}

int getx(int x){
    return (x-1)/m+1;
}

int gety(int x){
    return (x-1)%m+1;
}

int top,bot,lft,rit;

bool nstar(int x,int sx,int sy){
    if(getx(x)==sx&&lft<=gety(x)&&rit>=gety(x)||gety(x)==sy&&top<=getx(x)&&bot>=getx(x))return false;
    for(int u:adj[x])if(u==id(sx,sy))return false;
    return true;
}

int bfs(int s,int sx,int sy){
    memset(vis+1,0,n*m);
    vis[s]=1;
    int res=0;
    queue<int> q;
    q.emplace(s);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        res+=nstar(x,sx,sy);
        for(int y:g[x])if(!vis[y]){
            if(occ[y].col==-1){
                q.emplace(y);
            }else res+=nstar(y,sx,sy)&&occ[s].eat(occ[y]);
            vis[y]=1;
        }
    }
    return res;
}

void mian(){
    cin>>n>>m>>q;
    for(int i=1;i<=n*m;i++){
        g[i].clear();
        adj[i].clear();
        occ[i]=chesspiece();
    }
    lr.assign(n+1,vector<int>(m));
    ud.assign(n,vector<int>(m+1));
    lm.assign(n+1,vector<int>(m+1));
    rm.assign(n+1,vector<int>(m+1));
    um.assign(n+1,vector<int>(m+1));
    dm.assign(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        row[i].clear();
        for(int j=1;j<=m;j++){
            lm[i][j]=rm[i][j]=j;
            um[i][j]=dm[i][j]=i;
            if(i==1)col[j].clear();
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            char c;
            cin>>c;
            lr[i][j]=c-'0';
            if(lr[i][j]==1){
                adj[id(i,j)].emplace_back(id(i,j+1));
                adj[id(i,j+1)].emplace_back(id(i,j));
            }else if(lr[i][j]==2){
                lm[i][j+1]=lm[i][j];
            }else if(lr[i][j]==3){
                g[id(i,j)].emplace_back(id(i,j+1));
                g[id(i,j+1)].emplace_back(id(i,j));
            }
        }
        for(int j=m-1;j>=1;j--)if(lr[i][j]==2){
            rm[i][j]=rm[i][j+1];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            ud[i][j]=c-'0';
            if(ud[i][j]==1){
                adj[id(i,j)].emplace_back(id(i+1,j));
                adj[id(i+1,j)].emplace_back(id(i,j));
            }else if(ud[i][j]==2){
                um[i+1][j]=um[i][j];
            }else if(ud[i][j]==3){
                g[id(i,j)].emplace_back(id(i+1,j));
                g[id(i+1,j)].emplace_back(id(i,j));
            }
        }
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(ud[i][j]==2){
                dm[i][j]=dm[i+1][j];
            }
        }
    }
    while(q--){
        int c,l,x,y;
        cin>>c>>l>>x>>y;
        int u=id(x,y);
        occ[u]=chesspiece(c,l);
        row[x].emplace(y);
        col[y].emplace(x);
        //type 1
        int res=0;
        for(int v:adj[u])if(occ[u].eat(occ[v])){
            res++;
        }
        //type 2
        //up
        top=um[x][y];
        if(col[y].lower_bound(x)!=col[y].begin()){
            int nx=*--col[y].lower_bound(x);
            top=max(top,nx+!occ[u].eat(occ[id(nx,y)]));
        }
        res+=x-top;
        //down
        bot=dm[x][y];
        if(col[y].upper_bound(x)!=col[y].end()){
            int nx=*col[y].upper_bound(x);
            bot=min(bot,nx-!occ[u].eat(occ[id(nx,y)]));
        }
        res+=bot-x;
        //left
        lft=lm[x][y];
        if(row[x].lower_bound(y)!=row[x].begin()){
            int ny=*--row[x].lower_bound(y);
            lft=max(lft,ny+!occ[u].eat(occ[id(x,ny)]));
        }
        res+=y-lft;
        //down
        rit=rm[x][y];
        if(row[x].upper_bound(y)!=row[x].end()){
            int ny=*row[x].upper_bound(y);
            rit=min(rit,ny-!occ[u].eat(occ[id(x,ny)]));
        }
        res+=rit-y;
        //type 3
        res+=bfs(u,x,y);
        cout<<res<<'\n';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}