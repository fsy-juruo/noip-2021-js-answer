#include <iostream>
using namespace std;

const int MAXN = 1e4 + 10;
const int INF = 0x3f3f3f3f;

int n;
int a[MAXN];


int main(){
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin >> n;
    int sum = 0, sa2 = 0, minAns;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        sa2 += a[i] * a[i];
    }
    minAns = n * sa2 - sum * sum;
    while(true){
        int sub = 0;
        for(int i = 2; i <= n - 1; i++){
            if(a[i - 1]<= sum / n && a[i] >= sum / n){
                sub = i;
                break;
            }
        }
        for(int i = sub - 1; i >= 2; i--){
            if(a[i + 1] - a[i] > a[i] - a[i - 1]){
                sum -= a[i]; sa2 -= a[i] * a[i];
                a[i] = a[i + 1] + a[i - 1] - a[i];
                sum += a[i]; sa2 += a[i] * a[i];
            }
        }
        for(int i = sub + 1; i <= n - 1; i++){
            if(a[i + 1] - a[i] < a[i] - a[i - 1]){
                sum -= a[i]; sa2 -= a[i] * a[i];
                a[i] = a[i + 1] + a[i - 1] - a[i];
                sum += a[i]; sa2 += a[i] * a[i];
            }
        }
        int ans = n * sa2 - sum * sum;
        if(ans < minAns){
            minAns = ans;
        } else {
            break;
        }
    }
    cout << minAns;
    return 0;
}