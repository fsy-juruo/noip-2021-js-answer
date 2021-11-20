#include<bits/stdc++.h>
#define filename "sequence"
using namespace std;
const long long mod=998244353;
int n,m,k,a[35];
long long ans,v[105];
long long power(long long a,long long b)
{
    long long s=1;
    while(b)
    {
        if(b&1)s=s*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return s;
}
bool check(long long x)
{
    int s=0;
    while(x)
    {
        s+=(x&1);
        if(s>k)return false;
        x>>=1;
    }
    return true;
}
long long C(int a,int b)
{
    long long s=1;
    for(int i=a-b+1;i<=a;++i)s=s*i%mod;
    for(int i=2;i<=b;++i)s=s*power(i,mod-2)%mod;
    return s;
}
void dfs(int k,long long S)
{
    if(k>n)
    {
        if(S<n||!check(S))return;
        long long cur=1,mul=1;
        int tot=0,cnt=0,tmp=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]!=a[tmp])
            {
                mul=mul*C(tot+cnt,cnt)%mod;
                tot+=cnt;
                tmp=i;
                cnt=0;
            }
            cur=cur*v[a[i]]%mod;
            ++cnt;
        }
        ans=(ans+cur*(mul*C(tot+cnt,cnt)%mod)%mod)%mod;
        return;
    }
    for(int i=a[k-1];i<=m;++i)
    {
        a[k]=i;
        dfs(k+1,S+(1LL<<i));
    }
}
template<typename T>void read(T &x)
{
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
}
int main()
{
    freopen(filename".in","r",stdin);
    freopen(filename".out","w",stdout);
    read(n),read(m),read(k);
    for(int i=0;i<=m;++i)read(v[i]);
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}