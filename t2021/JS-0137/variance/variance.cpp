#include<bits/stdc++.h>
#define filename "variance"
using namespace std;
int n,a[10001];
long long s,d,ans=1LL<<62;
map<vector<int>,bool>mp;
long long calc(int idx=-1,int nval=0)
{
    if(~idx)
    {
        long long ns=s+nval-a[idx];
        d+=1LL*n*nval*nval-1LL*n*a[idx]*a[idx]+1LL*ns*ns-1LL*s*s-2LL*ns*ns+2LL*s*s;
        s=ns;
        a[idx]=nval;
        return d;
    }
    long long ans=0;
    for(int i=1;i<=n;++i)ans+=1LL*a[i]*a[i]*n-2LL*a[i]*s;
    return ans+s*s;
}
bool check()
{
    vector<int>v;
    for(int j=1;j<=n;++j)v.push_back(a[j]);
    if(mp.find(v)!=mp.end())return false;
    return mp[v]=true;
}
void dfs()
{
    ans=min(ans,d);
    for(int i=2;i<n;++i)
    {
        int tmp=a[i],nxt=a[i-1]+a[i+1]-a[i];
        if(nxt<0||nxt==a[i])continue;
        calc(i,nxt);
        if(check())dfs();
        calc(i,tmp);
    }
}
void ran()
{
    ans=min(ans,d);
    long long mind=1LL<<62;
    int cnt=0,minp[201]={};
    for(int i=2;i<n;++i)
    {
        int tmp=a[i],nxt=a[i-1]+a[i+1]-a[i];
        if(nxt<0||nxt==a[i])continue;
        calc(i,nxt);
        if(check())
        {
            if(d<mind)
            {
                mind=d;
                memset(minp,0,sizeof(minp));
                minp[cnt=1]=i;
            }
            else if(d==mind)minp[++cnt]=i;
        }
        calc(i,tmp);
    }
    if(mind>d)return;
    for(int i=1;i<=cnt;++i)
    {
        int tmp=a[minp[i]];
        calc(minp[i],a[minp[i]-1]+a[minp[i]+1]-a[minp[i]]);
        ran();
        calc(minp[i],tmp);
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
    read(n);
    for(int i=1;i<=n;++i)
    {
        read(a[i]);
        s+=a[i];
    }
    d=calc();
    check();
    if(n<=4)dfs();
    else ran();
    printf("%lld",ans);
    return 0;
}