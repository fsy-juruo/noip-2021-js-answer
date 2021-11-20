#include<bits/stdc++.h>
using namespace std;
short f[10000010];
int p(int a){
    short res = -1;
    int t = a;
    while (t){
        if (t % 10 == 7){
            res = 1;
            break;
        }
        t /= 10;
    }
    return res;
}
int pp(int a){
    if(!f[a]){
        short res = -1;
        if (p(a) == 1){
            res = 1;
        }else{
            for (int i = 2; i * i <= a; i++){
                if (a % i == 0){
                    if (pp(i) == 1 || pp(a / i) == 1){
                        res = 1;
                    }
                }
            }
        }
        f[a] = res;
    }
    return f[a];
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int T;
    cin >> T;
    while (T--){
        int x;
        cin >> x;
        if (pp(x) == 1){
            cout << -1 << '\n';
            continue;
        }
        for (int i = x + 1; i < 10000010; i++){
            if (pp(i) == -1){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
