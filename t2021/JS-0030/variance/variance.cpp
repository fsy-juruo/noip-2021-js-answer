// hyh ak ioi
#include <bits/stdc++.h>
using namespace std;

#define N   10004
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define D(i,r,l) for(int i=r;i>=l;--i)
#define MEM(x,a) memset(x,a,sizeof(x))
#define FK(x) MEM(x,0)
int I()
{
    int x=0; char c=getchar(); bool f=0;
    while(!isdigit(c)) c=getchar(),f=(c=='-');
    while(isdigit(c)) x=(x*10+c-'0'),c=getchar();
    return f?-x:x;
}

int n,a[N],d[N];
int Q[N*3],head,tail; int f[N],g[N],sf[N];
void get_fg()
{
    F(i,head,tail) f[i]=(i-head+1)*Q[i],g[i]=(tail-i+1)*Q[i];
    sf[head]=f[head]; F(i,head+1,tail) sf[i]=sf[i-1]+f[i];
}
int calc()
{
    get_fg();
    int ans=0;
    F(i,head,tail) ans+=f[i]*g[i];
    F(i,head+1,tail) ans+=2*g[i]*sf[i-1];
    return ans;
}
void flandre()
{
    n=I();
    F(i,1,n) a[i]=I();
    F(i,1,n-1) d[i]=a[i+1]-a[i];
    sort(d+1,d+n);

    int ans=1e18;
    F(s,0,(1<<(n-2))-1)
    {
        head=10000,tail=head-1;
        Q[++tail]=d[1];
        int cur=s;
        F(i,2,n-1)
        {
            if (cur&1) Q[--head]=d[i];
            else Q[++tail]=d[i];
            cur>>=1;
        }
        ans=min(ans,calc());   
    }
    printf("%lld\n",ans);
}
#undef int
int main()
{
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    flandre();
    return 0;
}