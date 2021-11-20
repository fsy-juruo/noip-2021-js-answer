#include <cstdio>
#include <algorithm>

using std::min;

bool vis[50005];

int a[10005];

inline int hash(int x,int y,int z,int w){
    return x + y * 12 + z * 144 + w * 1728;
}

inline int calc(int x,int y,int z,int w){
    int sum = x + y + z + w;
    return (x*x + y*y + z*z + w*w) * 4 - sum * sum; 
}

int dfs(){
    vis[hash(a[1],a[2],a[3],a[4])] = 1;
    int ans = calc(a[1],a[2],a[3],a[4]);
    int aa = a[2];
    a[2] = a[1] + a[3] - a[2];
    if(!vis[hash(a[1],a[2],a[3],a[4])]){
        ans = min(ans,dfs());
    }
    a[2] = aa;
    aa = a[3];
    a[3] = a[2] + a[4] - a[3];
    if(!vis[hash(a[1],a[2],a[3],a[4])]){
        ans = min(ans,dfs());
    }
    a[3] = aa;
    return ans;
}

int n;

inline void garbage(){
    long long s = 0,ss = 0;
    for(int i = 1;i <= n;++i){
        s += (long long)(a[i]);
        ss += (long long)(a[i])*(long long)(a[i]);
    }
    printf("%lld",s * s - ss);
}

int main(){
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){
        scanf("%d",a+i);
    }
    if(n == 1){
        printf("%d\n",0);
    }
    if(n == 2){
        printf("%d\n", -(a[1]*a[1] + a[2]*a[2] - (a[1]+a[2]) * (a[1] + a[2])));
    }
    if(n == 3){
        printf("%d\n",min( -(a[1]*a[1] + a[2]*a[2] + a[3]*a[3] - (a[1]+a[2] + a[3]) * (a[1] + a[2] + a[3])),-(a[1]*a[1] + (a[1] + a[3] - a[2])*(a[1] + a[3] - a[2]) + a[3]*a[3] - (2*a[1] - a[2] + 2*a[3]) * (2*a[1] - a[2] + 2*a[3]))));
    }
    if(n == 4)
        printf("%d\n",dfs());
    if(n > 4) garbage();
    return 0;
}