#include <bits/stdc++.h>
using namespace std;

const int MAXN = 32;
const int MAXM = 105;
const __int128 MOD = 998244353;

int n, m, k;
int v[MAXM], c[MAXM];
__int128 nn = 1, res = 0;

void print(__int128 x){
    if(x < 0){
        putchar('-');
        x *= -1;
    }
    if(x > 9){
        print(x / 10);
    }
    putchar(x % 10 + '0');
}


void dfs(int num, int sum, int nowM){
    if(nowM == 0){
        c[0] = num;
        int s = sum + num;
        int ct = 0;
        for(int j = 0; j <= MAXN; j++){
            if(s & (1 << j)){
                ct += 1;
            }
        }
        if(ct > k){
            return;
        }
        __int128 V = 0;
        __int128 x = 1;
        for(int i = 0; i <= m; i++){
            __int128 xx = c[i];
            V += (xx * v[i]) % MOD;
            V %= MOD;
            for(int j = c[i]; j >= 1; j--){
                x *= j;
            }
        }
        __int128 y = nn / x;
        __int128 ans = y * V % MOD;
        res = (res + ans) % MOD;

        return;
    }

    for(int i = 0; i <= num; i++){
        c[nowM] = i;
        dfs(num - i, sum + i * (1 << nowM), nowM - 1);
    }     
    c[nowM] = 0;   
}

int main(){
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    //std::ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(__int128 i = n; i >= 1; i--){
        nn *= i;
    }
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }
    dfs(n, 0, m);
    print(res);
    return 0;
}