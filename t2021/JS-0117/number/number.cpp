#include <cstdio>

using namespace std;

template <class t>
t read() {
    t x = 0; bool f = false;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        f |= ch == '-';
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f ? -x : x;
}

const int maxn = 10001000;
bool banned[maxn];
int next_pos[maxn];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    const int t = read<int>();
    if (t <= 10000) {
        for (int i = 1; i < 200030; i++) {
            int x = i;
            while (x) {
                int p = x % 10; x /= 10;
                if (p == 7) {
                    for (int j = 1; i * j < 200030; j++)
                        banned[i * j] = true;
                    break;
                }
            }
        }
        next_pos[20029] = 20030;
        for (int i = 200028; i >= 0; i--) {
            if (banned[i]) next_pos[i] = next_pos[i + 1];
            else next_pos[i] = i;
        }
        for (int i = 0; i < t; i++) {
            int x = read<int>();
            if (banned[x]) {
                puts("-1");
            } else {
                printf("%d\n", next_pos[x + 1]);
            }
        }
    } else {
        for (int i = 1; i < maxn; i++) {
            int x = i;
            while (x) {
                int p = x % 10; x /= 10;
                if (p == 7) {
                    for (int j = 1; i * j < maxn; j++)
                        banned[i * j] = true;
                    break;
                }
            }
        }
        next_pos[maxn - 1] = maxn;
        for (int i = maxn - 2; i >= 0; i--) {
            if (banned[i]) next_pos[i] = next_pos[i + 1];
            else next_pos[i] = i;
        }
        for (int i = 0; i < t; i++) {
            int x = read<int>();
            if (banned[x]) {
                putchar('-');
                putchar('1');
                putchar('\n');
            } else {
                printf("%u\n", (unsigned)next_pos[x + 1]);
            }
        }
    }
}