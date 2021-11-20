#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

template <typename T1,typename T2>
ostream & operator << (ostream &cout,const pair<T1,T2> &o)
{
	cout<<'('<<o.first<<','<<o.second<<')';
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,const vector<T> &v)
{
	cout<<'{';
	for(int i=0;i<(int)v.size();i++)
	{
		cout<<v[i];
		if(i!=(int)v.size()-1) cout<<',';
	}
	cout<<'}';
	return cout;
}

int getnum()
{
    int res=0;
    char ch=0;
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch))
    {
        res=res*10+ch-'0';
        ch=getchar();
    }
    return res;
}

int n,m,q;
string rw[100005],cl[100005];
char buf[100005];
int col2[200005],lv2[200005];
vector<int> col[100005],lv[100005];
int vis[200005];
int que[200005],l,r;
int stk[200005],top;
vector<int> edges[200005];
void solve()
{
    n=getnum();m=getnum();q=getnum();
    for(int i=0;i<n*m;i++) edges[i].clear(),col2[i]=lv2[i]=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",buf);
        rw[i].clear();
        rw[i]=buf;
        col[i].clear();lv[i].clear();
        col[i].resize(m,-1);
        lv[i].resize(m,-1);
        for(int j=0;j<m-1;j++)
        {
            // cout<<rw[i][j];
            if(rw[i][j]=='3') edges[i*m+j].emplace_back(i*m+j+1),edges[i*m+j+1].emplace_back(i*m+j);
        }
        // cout<<endl;
    }
    // cout<<endl;
    for(int i=0;i<n-1;i++)
    {
        scanf("%s",buf);
        cl[i].clear();
        cl[i]=buf;
        for(int j=0;j<m;j++)
        {
            if(cl[i][j]=='3') edges[i*m+j].emplace_back(i*m+j+m),edges[i*m+j+m].emplace_back(i*m+j);
        }
    }
    while(q--)
    {
        int a=getnum(),b=getnum(),c=getnum()-1,d=getnum()-1;
        l=r=0;
        que[r++]=c*m+d;
        vis[c*m+d]=1;
        int res=0;
        top=0;
        while(l!=r)
        {
            int x=que[l++];
            for(auto u:edges[x])
            {
                if(vis[u] || col2[u]==a || lv2[u]>b) continue;
                vis[u]=1;
                res++;
                if(lv2[u]==-1) que[r++]=u;
                stk[top++]=u;
            }
        }
        for(int j=d-1;j>=0;j--)
        {
            if(rw[c][j]!='2' || col[c][j]==a || lv[c][j]>b) break;
            if(!vis[c*m+j]) res++;
            if(lv[c][j]!=-1) break;
        }
        for(int j=d+1;j<m;j++)
        {
            if(rw[c][j-1]!='2' || col[c][j]==a || lv[c][j]>b) break;
            if(!vis[c*m+j]) res++;
            if(lv[c][j]!=-1) break;
        }
        for(int i=c-1;i>=0;i--)
        {
            if(cl[i][d]!='2' || col[i][d]==a || lv[i][d]>b) break;
            if(!vis[i*m+d]) res++;
            if(lv[i][d]!=-1) break;
        }
        for(int i=c+1;i<n;i++)
        {
            if(cl[i-1][d]!='2' || col[i][d]==a || lv[i][d]>b) break;
            if(!vis[i*m+d]) res++;
            if(lv[i][d]!=-1) break;
        }
        if(c && cl[c-1][d]=='1' && !vis[(c-1)*m+d] && (lv[c-1][d]<=b) && (col[c-1][d]!=a)) res++;
        if(c<n-1 && cl[c][d]=='1' && !vis[(c+1)*m+d] && (lv[c+1][d]<=b) && (col[c+1][d]!=a)) res++;
        if(d && rw[c][d-1]=='1' && !vis[c*m+d-1] && (lv[c][d-1]<=b) && (col[c][d-1]!=a)) res++;
        if(d<m-1 && rw[c][d]=='1' && !vis[c*m+d+1] && (lv[c][d+1]<=b) && (col[c][d+1]!=a)) res++;
        col[c][d]=a;col2[c*m+d]=a;
        lv[c][d]=b;lv2[c*m+d]=b;
        for(int i=0;i<top;i++) vis[stk[i]]=0;
        vis[c*m+d]=0;
        printf("%d\n",res);
    }
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    int T=getnum();
    while(T--) solve();
	return 0;
}