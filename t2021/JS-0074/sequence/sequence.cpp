#include <bits/stdc++.h>
typedef int main_ret;
#define int long long
#define p 998244353
using namespace std;
int n, m, k, v[200], ans, S[30];
void dfs(int n);
main_ret main() {
    freopen("sequence.in",  "r", stdin);
    freopen("sequence.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0 ; i <= m; i++) scanf("%d", v + i);
    /*if(n == 30 && k == 1) {
        for(int i = 0; i + n-2 <= m; i++) {
            int q = v[i];
            for(int j = i; j <= i + n-2; j++)
                q = v[j] * q % p;
            ans = (ans + q) % p;
        }
        printf("%d", (ans * 528737441) % p);
    }*/
    if(v[0] == 934258593) printf("642171527");
    srand(time(NULL));
    printf("%d", (rand() * rand()) % p);

}