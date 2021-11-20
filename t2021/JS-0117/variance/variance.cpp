#include <cstdio>
#include <cstring>
#include <queue>

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

void make_bigger(int *begin, int *end, int ma) {
    if (end <= begin) return;
    int *arr = begin, sz = end - begin;
    bool in_q[20000] = {};
    in_q[0] = in_q[sz - 1] = true;
    queue<int> q;
    for (int i = 1; i < sz - 1; i++) {
        q.push(i);
        in_q[i] = true;
    }
    while (q.size()) {
        int i = q.front(); q.pop();
        in_q[i] = false;
        if (arr[i - 1] + arr[i + 1] - arr[i] > arr[i]
                && arr[i - 1] + arr[i + 1] - arr[i] <= ma) {
            arr[i] = arr[i - 1] + arr[i + 1] - arr[i];
            if (!in_q[i - 1]) {
                in_q[i - 1] = true;
                q.push(i - 1);
            }
            if (!in_q[i + 1]) {
                in_q[i + 1] = true;
                q.push(i + 1);
            }
        }
    }
}

void make_smaller(int *begin, int *end, int mi) {
    if (end <= begin) return;
    int *arr = begin, sz = end - begin;
    bool in_q[20000] = {};
    in_q[0] = in_q[sz - 1] = true;
    queue<int> q;
    for (int i = 1; i < sz - 1; i++) {
        q.push(i);
        in_q[i] = true;
    }
    while (q.size()) {
        int i = q.front(); q.pop();
        in_q[i] = false;
        if (arr[i - 1] + arr[i + 1] - arr[i] < arr[i]
                && arr[i - 1] + arr[i + 1] - arr[i] >= mi) {
            arr[i] = arr[i - 1] + arr[i + 1] - arr[i];
            if (!in_q[i - 1]) {
                in_q[i - 1] = true;
                q.push(i - 1);
            }
            if (!in_q[i + 1]) {
                in_q[i + 1] = true;
                q.push(i + 1);
            }
        }
    }
}

int a[20000];

int main() {
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    const int n = read<int>();
    for (int i = 1; i <= n; i++)
        a[i] = read<int>();
    long double final_ans = 1e12;
    for (int k = 0; k <= a[n]; k++) {
        make_bigger(a + 1, a + n + 1, k);
        make_smaller(a + 1, a + n + 1, k);
        printf("%d: ", k);
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        putchar('\n');
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i];
        long double avr = (long double)(sum) / n;
        long double ans = 0;
        for (int i = 1; i <= n; i++)
            ans += (long double)(n) * (a[i] - avr) * (a[i] - avr);
        if (ans < final_ans) final_ans = ans;
    }
    printf("%llu", (unsigned long long)final_ans);
}