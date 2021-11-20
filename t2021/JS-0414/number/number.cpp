#include <bits/stdc++.h>

using std::bitset;
using std::vector;

bitset<10000080> bs;
vector<int> bn;
int r[10000080];

inline bool check(int x) {
    while (x > 0) {
        if (x % 10 == 7) {
            return 1;
        }
        x /= 10;
    }
    return 0;
}

inline int kyread(void) {
    register int c = 0;
    while ((c = getchar()) < '0' || c > '9') {
        if (c == -1) {
            return 0;
        }
        continue;
    }
    register int x = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') {
        x *= 10;
        x += c - '0';
    }
    return x;
}

int st[30];

inline void kywrite(int x) {
    register int t = 0;
    while (x > 0) {
        st[++t] = x % 10;
        x /= 10;
    }
    while (t > 0) {
        putchar(st[t] + '0');
        --t;
    }
}

int qq[200010];

int main(void) {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
    int q;
    scanf("%d", &q);
    int sss = 0;
    if (q <= 10000) {
        for (int i = 0; i < q; ++i) {
            scanf("%d", &qq[i]);
            sss = std::max(sss, qq[i]);
        }
    } else {
        for (int i = 0; i < q; ++i) {
            qq[i] = kyread();
            sss = std::max(sss, qq[i]);
        }
    }
    
    bs.reset();
    bn.clear();
    
    if (sss <= 200000) {
        for (int i = 1; i <= 400000; ++i) {
            if (check(i)) {
                bn.push_back(i);
                bs.set(i - 1);
            }
        }
        for (int i = 2; i <= 400000; ++i) {
            for (auto x : bn) {
                if ((long long)x * i > 400000) {
                    break;
                }
                bs.set(i * x - 1);
                if (i % x == 0) {
                    break;
                }
            }
        }
        
        for (int i = 400000 - 2; i >= 1; --i) {
            r[i] = r[i + 1];
            if (!bs[i]) {
                r[i] = i + 1;
            }
        }
    } else {
        for (int i = 1; i <= 10000020; ++i) {
            if (check(i)) {
                bn.push_back(i);
                bs.set(i - 1);
            }
        }
        for (int i = 2; i <= 10000020; ++i) {
            for (auto x : bn) {
                if ((long long)x * i > 10000020) {
                    break;
                }
                bs.set(i * x - 1);
                if (i % x == 0) {
                    break;
                }
            }
        }
        
        for (int i = 10000020 - 2; i >= 1; --i) {
            r[i] = r[i + 1];
            if (!bs[i]) {
                r[i] = i + 1;
            }
        }
    }
    
    if (q <= 10000) {
        for (int i = 0; i < q; ++i) {
            if (bs[qq[i] - 1]) {
                putchar('-'); putchar('1'); putchar('\n');
            } else {
                printf("%d\n", r[qq[i]]);
            }
        }
    } else {
        for (int i = 0; i < q; ++i) {
            if (bs[qq[i] - 1]) {
                putchar('-'); putchar('1'); putchar('\n');
            } else {
                kywrite(r[qq[i]]); putchar('\n');
            }
        }
    }
    
    return 0;
}

