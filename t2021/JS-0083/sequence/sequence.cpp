#include<bits/stdc++.h>
using namespace std;
#define io_speed_up ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define lson x<<1
#define rson x<<1|1
typedef long long ll;
typedef unsigned long long ull;

const ll MAXN=1e2+5;
const ll INF=0x3f3f3f3f;
const ll MOD=998244353;
const double EPS=1e-8;
int n,m,k,v[MAXN],a[MAXN],N;
ll Pow(ll a,ll b)
{
    ll ret=1;
    while(b&1)
    {
        ret=(ret*a)%MOD;
        a=(a*a)%MOD;b>>=1;
    }
    return ret;
} 
int check(int x)
{
    int ret=0;N=-1;
    while(x)
    {
        N++;
        if(x&1) ret+=a[N]=1;
        x>>=1;
    }
    return ret;
}
ll dfs(ll x)
{
    if(x==n)
    {
        ll ret=1;
        for(int i=0;i<=N;i++)
        {
            ret=(ret*Pow(v[i],a[i]))%MOD;
        }
        return ret;
    }
    for(ll i=2;i<=N;i++) cout<<"???"<<endl;
}
int main()
{
    io_speed_up;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=n;i<=n*(1<<m);i++)
    {
        if(check(i)>k) continue;

    }
    return 0;
}