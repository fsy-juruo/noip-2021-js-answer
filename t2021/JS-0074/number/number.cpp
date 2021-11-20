#include <bits/stdc++.h>
#define MAXN (10000010)
using namespace std;
int t, x, r[MAXN+10], last;
bool p[2*MAXN+10], q[MAXN+10]; // ILLEGAL
int d[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int read() {
    int t = 0; char c;
    while(!isdigit(c = getchar())); t = c - '0';
    while( isdigit(c = getchar())) t = t * 10 + (c - '0');
    return t;
}
int main() {
    freopen("number.in",  "r", stdin);
    freopen("number.out", "w", stdout);
    for(int i = 0; i <= 6; i++)
        for(int j = 0; j <= 1000000; j++)
            p[(j/d[i])*d[i]*10+7*d[i]+(j%d[i])] = true;
    for(int i = 1; i <= MAXN; i++)
        if(p[i]) for(int j = 1; i*j <= MAXN; j++) q[i*j] = true;
    memset(r, -1, sizeof(r));
    for(int i = MAXN; i >= 1; i--) 
        if(!q[i]) r[i] = last, last = i;
    t = read();
    while(t--) {
        x = read();
        printf("%d\n", r[x]);
    }
}
