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
int n,m,k;
const int maxn=35;
const int maxm=110;
const int mod=998244353;
long long f[maxn][maxm][maxn][maxn];
long long v[maxm];
long long ks[maxm][maxn],p[maxn],inv[maxn];
long long ksm(int a,int b)
{
    return ks[a][b];
}
long long ksmm(long long a,int n)
{
    long long ans=1;
    while(n)
    {
        if(n&1){ans=ans*a%mod;}
        n>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long C(int n,int m)
{
    if(m<0)return 0;
    if(n<m)return 0;
    return p[n]*inv[m]%mod*inv[n-m]%mod;
}
int q(int x)
{
    int res=0;
    while(x)
    {
        if(x&1)res++;
        x>>=1;
    }
    return res; 
}
int main()
{
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    yin>>n>>m>>k;
    ++m;
    for(int i=1;i<=m;i++)yin>>v[i];
    for(int i=1;i<=m;i++)
    {
        long long res=1;
        for(int j=0;j<=n;j++)
        {
            ks[i][j]=res;
            (res*=v[i])%=mod;
        }
    }
    inv[0]=p[0]=1;
    for(int i=1;i<=n;i++)p[i]=p[i-1]*i%mod,inv[i]=inv[i-1]*ksmm(i,mod-2)%mod;
    // for(int j=0;j<=m;j++)
    f[0][0][0][0]=1;
    for(int j=1;j<=m;j++)
    {
        for(int i=0;i<=n;i++)
        {
            for(int ws=0;ws<=k;ws++)
            {
                for(int ll=0;ll<=i;ll++)
                {
                    for(int kk=0;kk<=i;kk++)
                    {
                        if(ll*2-kk>n)continue;
                        if(ll*2-kk>=0)
                        f[i][j][ws][ll]+=(f[i-kk][j-1][ws][ll*2-kk])*ksm(j,kk)%mod*C(i,kk)%mod;
                        if(ll*2+1-kk>=0&&ws>=1)
                        f[i][j][ws][ll]+=(f[i-kk][j-1][ws-1][ll*2+1-kk])*ksm(j,kk)%mod*C(i,kk)%mod;
                        f[i][j][ws][ll]%=mod;
                        // cerr<<i<<" "<<j<<" "<<ws<<" "<<ll<<" "<<kk<<" "<<j-1<<" "<<f[i][j][ws][ll]<<" "<<ksm(j,kk)<<" "<<C(i,kk)<<endl;
                    }
                    // if(i==1){
                    //     cerr<<j<<" "<<i<<" "<<ws<<" "<<ll<<" "<<f[i][j][ws][ll]<<endl;
                    // }
                }
            }
        }
    }
    long long ans=0;
    for(int ws=0;ws<=k;ws++)
    {
        for(int ll=0;ll<=n;ll++)
        {
            // cerr<<q(ll)<<endl;
            if(q(ll)+ws<=k)
            {
                ans+=f[n][m][ws][ll];
                ans%=mod;
            }
        }
    }
    cout<<ans<<endl;
}