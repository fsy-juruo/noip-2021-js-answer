#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int C(int n,int r){
    static int mem[35][35];
    if(n<r||r<0)return 0;
    if(n==r||r==0)return 1;
    int &res=mem[n][r];
    if(res)return res;
    return res=(C(n-1,r-1)+C(n-1,r))%mod;
}

int n,m,k,v[105],f[105][35][35][1<<5];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=0;i<=m;i++)cin>>v[i];
    for(int i=0,vp=1;i<=n;i++,vp=(ll)vp*v[0]%mod)f[0][i][i&1][i>>1]=vp;
    for(int i=0;i<m;i++){
        for(int len=0;len<=n;len++){
            for(int ck=0;ck<=len&&ck<=k;ck++){
                for(int msk=0;msk<1<<5;msk++){
                    int &state=f[i][len][ck][msk];
                    if(state)for(int put=0,vp=1;put+len<=n;put++,vp=(ll)vp*v[i+1]%mod){
                        int nmsk=msk+put;
                        int &nstate=f[i+1][len+put][ck+(nmsk&1)][nmsk>>1];
                        nstate=(nstate+(ll)state*C(len+put,put)%mod*vp)%mod;
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int a=0;a<=k;a++){
        for(int b=0;b<1<<5;b++){
            if(a+__builtin_popcount(b)<=k){
                ans+=f[m][n][a][b];
            }
        }
    }
    cout<<ans%mod;

    return 0;
}