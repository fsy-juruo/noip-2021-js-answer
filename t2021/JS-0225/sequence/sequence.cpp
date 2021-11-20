#include <cstdio>
#include <cctype>

typedef long long ll;

ll n,m,k;
ll v[105];

ll const M = 998244353;

inline void read(ll &x){
    x = 0;
    char c = getchar();
    ll f = 1;
    while(!isdigit(c)){ if(c=='-') f=-1; c = getchar();}
    while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
    x *= f;
}

inline ll cnt(int S){
    ll ans = 0;
    while(S > 0){
        ans += S & 1;
        S >>= 1;
    }
    return ans; 
}

ll pascal[65][65];

inline void init(){
    pascal[0][0] = 1;
    for(int i = 1;i <= 64;++i){
        pascal[i][0] = 1;
        for(int j = 1;j <= 64;++j){
            pascal[i][j] =( pascal[i-1][j] + pascal[i-1][j-1]) % M;
        }
    }
}

inline ll sol(int n,int i){
    return pascal[i + n][i];
}

bool vpow[50][50];
ll mpow[50][50];

inline ll pow(int i,ll a){
    if (vpow[i][a]){
        return mpow[i][a];
    }
    ll aa = a;
    vpow[i][a] = 1;
    ll x = v[i];
    ll ans = 1;
    while(a > 0){
        if(a & 1){
            ans = (ans * x) % M;
        }
        x = (x * x) % M;
        a >>= 1;
    }
    mpow[i][aa] = ans;
    return ans;
}

ll mem[35][15][(1 << 15)];
bool vis[35][15][(1 << 15)];


ll dfs(int n,int m,int S){
    if(S < 0) return 0;
    if(n == 0){
        if (S == 0) return 1;
        else return 0;
    }
    if(m == 0){
        if(S == n) return vis[n][m][S] = 1,mem[n][m][S] = pow(0,n);
        else return 0;
    }
    
    if(vis[n][m][S]){
        return mem[n][m][S];
    }
    vis[n][m][S] = 1;

    ll ans = 0;
    for(int i = 0;i <= n;++i){ //i表示选择m次数
        if((1 << m) * i > S) break;
        ans += ((sol(n - i,i) * (dfs(n-i,m-1,S - (1 << m) * i)) % M * pow(m,i))) % M;  
        ans %= M;
    }
    mem[n][m][S] = ans % M; 
    return ans % M;
}

inline void inp(){
    read(n),read(m),read(k);
    for(int i = 0;i <= m;++i){
        read(v[i]);
    }
}

int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    ll ans = 0;
    inp();
    init();
    for(int i = 1; i <= (1 << m) * n;++i){
        if(cnt(i) <= k){
            ans = (ans + dfs(n,m,i)) % M;
        }
    }

    printf("%lld\n",ans);
    return 0;
}