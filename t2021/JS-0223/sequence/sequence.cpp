//shit.
//when i asked them they told me that there isn't a size limit for code.
//it's already 11:00
//i'm done.
//fuck jsoi
//why not NOI Linux
//i could only use bruteforce for the following problems.
//fuck.

//shit this problem could probably get zero with bruteforce
//i'm done again
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long v[107],ans;
const int MOD=998244353;
unsigned long long lim;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
ll binmul(ll a,ll b,ll m){
    ull c = (ull) a*b-(ull)((ld) a/m*b+0.5l)*m;
    if(c<m) return c;
    return c+m;
}
void dfs(int sum,int cnt,long long mul){
    if(sum>lim) return;
    if(cnt==n){
        if(__builtin_popcount(sum)<=k){
            ans+=mul;
            ans%=MOD;
            return;
        }
        else return;
    }
    for(int i=m;i>=0;i--){
        dfs(sum+(int)pow(2,i),cnt+1,binmul(v[i],mul,MOD));
    }
}
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++){
        cin>>v[i];
    }
    lim=n*pow(2,m);
    dfs(0,0,1);
    cout<<ans<<endl;
}