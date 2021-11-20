// hyh ak ioi
#include <bits/stdc++.h>
using namespace std;
#define N 40
#define M 115
#define mod 998244353
#define int long long
#define pcnt __builtin_popcount

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

int  fc[200],fi[200];
int lg[200];
int qpow(int a,int b,int m=mod)
{
    int r=1;
    while(b)
    {
        if (b&1) r=r*a%m;
        a=a*a%m,b>>=1;
    }
    return r;
}
void init()
{
    int n=100;
    fc[0]=1; F(i,1,n) fc[i]=fc[i-1]*i%mod;
    fi[n]=qpow(fc[n],mod-2); D(i,n-1,0) fi[i]=fi[i+1]*(i+1)%mod;
    lg[1]=1;
    F(i,2,100) lg[i]=lg[i>>1]+1;
}
int n,m,limk; int v[M];
int f[M][M][N][N];
inline void add(int&x,int a) {x=(x+a%mod)%mod;}
void flandre()
{
    n=I(); m=I(); limk=I();
    F(i,0,m) v[i]=I();

    F(x,0,n) f[0][pcnt(x)][x][x]=qpow(v[0],x)*fi[x]%mod;
    F(i,0,m-1) F(k,0,100) F(s,0,n) F(S,0,31) if (f[i][k][s][S])
    {
        // printf("f(%lld,%lld,%lld,%lld)=%lld\n",i,k,s,S,f[i][k][s][S]);
        F(x,0,n-s)
        {
            int ad=qpow(v[i+1],x)*fi[x]%mod;
            if (ad)
            {
                int tmp=S+(x<<1);
                int d_k=pcnt(tmp)-pcnt(S); // k change
                int S2=(tmp>>1);
                if (k+d_k>=0)
                {
                    // printf(" add x=%lld\n",x);
                    // printf(" tmp=%d\n",tmp);
                    // printf(" *%lld -> f(%d,%d,%d,%d)\n",ad,i+1,k+d_k,s+x,S2);
                    add(f[i+1][k+d_k][s+x][S2],ad*f[i][k][s][S]%mod);
                }
                // else puts("fuck!");
            }
        }
    }

    int ans=0;
    F(k,0,limk) F(s,0,31)
    {
        add(ans,f[m][k][n][s]);
    }
    ans=ans*fc[n]%mod;
    printf("%lld\n",ans);
}

#undef int
int main()
{
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    init();
    flandre();
    return 0;
}
