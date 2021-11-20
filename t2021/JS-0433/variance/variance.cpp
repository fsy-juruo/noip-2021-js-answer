#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int n;
int sum, sqsum;
int a[MAXN+1];

int main() {
    ios::sync_with_stdio(false);
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        sqsum += a[i]*a[i];
    }
    while(true) {
        int mingot = INT_MAX, mini;
        for(int i = 2; i < n; i++) {
            int after = a[i-1]+a[i+1]-a[i];
            int thissqsum = sqsum-a[i]*a[i]+after*after;
            int thissum = sum-a[i]+after;
            if(thissqsum*n*n-thissum*thissum*n < mingot) {
                mingot = thissqsum*n*n-thissum*thissum*n;
                mini = i;
            }
        }
        if(mingot >= sqsum*n*n-sum*sum*n) {
            cout << (sqsum*n*n-sum*sum*n)/n << endl;
            return 0;
        }
        int after = a[mini-1]+a[mini+1]-a[mini];
        sqsum = sqsum-a[mini]*a[mini]+after*after;
        sum = sum-a[mini]+after;
        a[mini] = a[mini-1]+a[mini+1]-a[mini];
    }
    return 0;
}
/*
d = (sqsum*n*n-2*sum*sum*n+sum*sum*n)/n
(sqsum*n*n-sum*sum*n)/n
*/