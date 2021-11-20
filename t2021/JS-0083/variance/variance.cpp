#include<bits/stdc++.h>
using namespace std;
#define io_speed_up ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define lson x<<1
#define rson x<<1|1
typedef long long ll;
typedef unsigned long long ull;

const int MAXN=1e3+5;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double EPS=1e-8;
int n,sum,a[MAXN],b[MAXN];
int fc()
{   
    int ret=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        ret+=b[i]*b[i];
        sum+=b[i];
    }
    ret=ret*n-sum*(sum<<1-1);
    return ret;
}
int main()
{
    io_speed_up;
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i];sum+=a[i];}
    for(int i=1;i<=n;i++) b[i]=a[i];
    int ans=fc();
    for(int x=2;x<=n-1;x++)
    {
        for(int k=1;k<=n;k++) b[k]=a[k];
        int res=INF;
        while(res>fc())
        {
            res=fc();
            // if(res!=INF) b[x]=b[x-1]+b[x+1]-b[x];
            for(int i=x-1;i>=2;i--)
                if(b[i+1]-b[i]>b[i]-b[i-1]) 
                    b[i]=b[i+1]+b[i-1]-b[i];
            for(int i=x+1;i<=n-1;i++)
                if(b[i+1]-b[i]>b[i]-b[i-1]) 
                    b[i]=b[i+1]+b[i-1]-b[i];
        }
        ans=min(ans,fc());
    }
    cout<<ans<<endl;
    return 0;
}