#include<bits/stdc++.h>
using namespace std;
#define io_speed_up ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define lson x<<1
#define rson x<<1|1
typedef long long ll;
typedef unsigned long long ull;

const int MAXN=2e5+5;
const int MAXM=1e7+5;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double EPS=1e-8;
int n;
bool vis[MAXM];
struct Order
{
    int x,idx;
}a[MAXN];
int ans[MAXN],lis[MAXN],N;
const bool cmp(Order &a,Order &b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.idx<b.idx;
}
bool check(int k)
{
    while(k)
    {
        if(k%10==7) return true;
        k/=10;
    }
    return false;
}
int main()
{
    io_speed_up;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        a[i]={k,i};
    }
    sort(a+1,a+n+1,cmp);
    int m=a[n].x;
    for(int i=1;i<=m;i++)
    {
        if(vis[i]==true) continue;
        if(check(i)==true)
            for(int j=1;i*j<=m;j++) 
                vis[i*j]=true;
        else lis[++N]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[a[i].x]==true) ans[a[i].idx]=-1;
        else ans[a[i].idx]=*upper_bound(lis+1,lis+N+1,a[i].x);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
    return 0;
}

