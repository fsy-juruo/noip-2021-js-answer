#include <bits/stdc++.h>
#define MAXX 10000100
using namespace std;

int T;
bool able[MAXX+1];

bool have7(int x) {
    while(x) {
        if(x%10 == 7) {
            return true;
        }
        x /= 10;
    }
    return false;
}

int main() {
    // clock_t t = clock();
    ios::sync_with_stdio(false);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    memset(able, 1, sizeof(able));
    for(int i = 1; i <= MAXX; i++) {
        if(!able[i]) {
            continue;
        }
        if(have7(i)) {
            for(int j = i; j <= MAXX; j += i) {
                able[j] = false;
            }
        }
    }
    cin >> T;
    for(int i = 1; i <= T; i++) {
        int x;
        cin >> x;
        if(!able[x]) {
            cout << -1 << endl;
            continue;
        }
        int j;
        for(j = x+1; !able[j]; j++);
        cout << j << endl;
    }
    // t = clock()-t;
    // cout << "time: " << (double)t/(double)CLOCKS_PER_SEC << endl;
    return 0;
}