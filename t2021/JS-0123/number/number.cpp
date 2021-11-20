#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 10;

bool le[MAXN];

bool check(int x){
    if(x % 10 == 7){
        return false;
    }
    if(x > 9){
        return check(x / 10);
    }
    return true;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    memset(le, true, sizeof(le));
    for(int i = 1; i < MAXN; i++){
        if((i % 7 == 0 || !check(i)) && le[i]){
            for(int x = i; x < MAXN; x += i){
                le[x] = false;
            }
        }
    }
    int T;
    cin >> T;
    while(T--){
        int x;
        cin >> x;
        if(!le[x]){
            cout << "-1" << endl;
            continue;
        }
        for(int i = x + 1; i < MAXN; i++){
            if(le[i]){
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}