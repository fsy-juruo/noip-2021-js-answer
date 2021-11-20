#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,V,a[10005];
ll f[2][500050];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);

    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    V=n*(a[n]-a[1]+1);
    for(int i=1;i<n;i++){
        a[i]=a[i+1]-a[i];
    }
    sort(a+1,a+n);
    ll ans=1e18;
    for(int ff=1;ff<=n-1;ff++){
        int fst=a[ff];
        for(int i=ff;i>1;i--)a[i]=a[i-1];
        a[1]=fst;
        memset(f[1],0x3f,(V+5)*8);
        for(int i=0;i<=a[1]*n;i++)f[1][i]=(ll)i*i+(ll)(a[1]*n-i)*(a[1]*n-i);
        for(int i=1,ps=a[1];i<=n-1;ps+=a[++i]){
            ll *cf=f[i&1],*nf=f[i&1^1];
            memset(nf,0x3f,(V+5)*8);
            for(int j=0;j<=ps*n;j++){
                nf[j+a[i+1]*n]=min(nf[j+a[i+1]*n],cf[j]+(ll)(j+a[i+1]*n)*(j+a[i+1]*n));
                nf[j]=min(nf[j],cf[j]+(ll)(ps*n-j+a[i+1]*n)*(ps*n-j+a[i+1]*n));
            }
        }
        ans=min(ans,*min_element(f[n-1&1],f[n-1&1]+V+5)/n);
        for(int i=1;i<ff;i++)a[i]=a[i+1];
        a[ff]=fst;
    }
    cout<<ans;

    return 0;
}