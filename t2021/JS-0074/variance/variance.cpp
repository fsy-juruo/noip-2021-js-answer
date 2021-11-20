#include <bits/stdc++.h>
#include <random>
typedef int main_ret;
#define int long long
#define sqr(x) ((x)*(x))
using namespace std;
int n, a[10010], sum, ssum, sump, ssump, var, varp;
main_ret main() {
    freopen("variance.in",  "r", stdin);
    freopen("variance.out", "w", stdout);
    srand(time(NULL));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a+i), sum += a[i], ssum += sqr(a[i]);
    var = n * ssum - sqr(sum);
    for(int j = 1; j <= n*n; j++)
    for(int i = 2; i < n; i++) {
        sump = sum - 2 * a[i] + a[i-1] + a[i+1];
        ssump = ssum - sqr(a[i]) + sqr(a[i-1] + a[i+1] - a[i]);
        if(n*ssump - sqr(sump) < var || ((n >= 10 ? true : false) && rand() < 10000))
            a[i] = a[i-1] + a[i+1] - a[i], sum = sump, ssum = ssump, var = n*ssump - sqr(sum);
    }
    //copy(a+1, a+n+1, ostream_iterator<int>(cerr," ")); cerr << endl;
    printf("%lld\n", var);
}