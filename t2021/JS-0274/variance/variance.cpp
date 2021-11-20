#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
const int INF=0x3f3f3f3f;

int n;
int a[N],b[N],c[N],d[N];
int tot,ans=INF,cnt;

int main(){
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==4){
        tot=0,cnt=0;
        for(int i=1;i<=n;i++) tot+=a[i];
        for(int i=1;i<=n;i++)
            cnt+=(tot-n*a[i])*(tot-n*a[i]);
        ans=min(ans,cnt);
        for(int i=1;i<=n;i++) b[i]=a[i];
        b[2]=b[1]+b[3]-b[2];
        tot=tot-a[2]+b[2],cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=(tot-n*b[i])*(tot-n*b[i]);
        ans=min(ans,cnt);
        for(int i=1;i<=n;i++) b[i]=a[i];
        b[3]=b[2]+b[4]-b[3];
        tot=tot-a[3]+b[3],cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=(tot-n*b[i])*(tot-n*b[i]);
        ans=min(ans,cnt);
        for(int i=1;i<=n;i++) b[i]=a[i];
        b[2]=b[1]+b[3]-b[2];
        b[3]=b[2]+b[4]-b[3];
        tot=tot-a[2]+b[2]-a[3]+b[3],cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=(tot-n*b[i])*(tot-n*b[i]);
        ans=min(ans,cnt);
        b[3]=b[2]+b[4]-b[3];
        b[2]=b[1]+b[3]-b[2];
        tot=tot-a[2]+b[2]-a[3]+b[3],cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=(tot-n*b[i])*(tot-n*b[i]);
        ans=min(ans,cnt);
        cout<<ans/4<<endl;
    }
    return 0;
}